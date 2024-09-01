п»ї// 6_task_bus.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses,
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator>>(istream& is, Query& q) {
    string type;
    is >> type;

    if (type == "NEW_BUS"s) {
        int stop_count = 0;

        q.type = QueryType::NewBus;

        is >> q.bus;
        is >> stop_count;

        q.stops.resize(stop_count);
        for ( auto& stop : q.stops) {
            is >> stop;
        }
    }
    else if (type == "BUSES_FOR_STOP"s) {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (type == "STOPS_FOR_BUS"s) {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else if (type == "ALL_BUSES"s) {
        q.type = QueryType::AllBuses;
    }

    return is;
}

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) {
        os << "No stop"s;
    }
    else {
        bool first = true;
        for (const auto& bus : r.buses) {
            if (!first) {
                os << " "s;               
            }
            first = false;            
            os << bus;
            }
        }   
    return os;
}

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        os << "No bus"s;
    }
    else {
        int i = 0;
        for (const auto& bus_stops : r.stops) {
            os << "Stop "s << bus_stops.first << ":"s;
            ++i;
            if (bus_stops.second.size()>1) {

                for (const auto& bus_x : bus_stops.second) {
                    if (bus_x != r.bus) {
                        os << " "s << bus_x;
                    }
                }
                if (i != r.stops.size()) {
                    os << endl;
                }
            } else { 
                os << " no interchange"s;
                if (i != r.stops.size()) {
                    os << endl;
                }
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_stops;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
    if (r.buses_stops.empty()) {
        os << "No buses"s;
    }
    else {
        for (const auto& [bus, stops] : r.buses_stops) {
            os << "Bus " << bus << ":"s;
            for (auto& stop : stops) {
                os << " "s << stop;
            }
            os << endl;
        }      
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        for (const auto& stop : stops) {
            stops_in_bus_[bus].push_back(stop);
            buses_in_stop_[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse result;
        if (buses_in_stop_.count(stop) != 0) {
            result.buses = buses_in_stop_.at(stop);//РЅРµ РїСѓСЃС‚РѕР№ РІРµРєС‚РѕСЂ
        }
        else {
            result.buses.clear();//РїСѓСЃС‚РѕР№ РІРµРєС‚РѕСЂ
        }
        return result;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse result;

        if (stops_in_bus_.count(bus) != 0) {

            vector<pair<string, vector<string>>> buses = {};

            for (const auto& stops : stops_in_bus_.at(bus)) {

                buses.push_back({ stops, buses_in_stop_.at(stops) });
            }        
            result.stops = buses;
            result.bus = bus;
        }
        else {
            result.stops.clear();
            result.bus = bus;
        }
        return result;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse result;
        if (!stops_in_bus_.empty()) {
            result.buses_stops = stops_in_bus_;
        }
        return result;
    }

private:
    map<string, vector<string>> stops_in_bus_;
    map<string, vector<string>> buses_in_stop_;

};

// Р РµР°Р»РёР·СѓР№С‚Рµ С„СѓРЅРєС†РёРё Рё РєР»Р°СЃСЃС‹, РѕР±СЉСЏРІР»РµРЅРЅС‹Рµ РІС‹С€Рµ, С‡С‚РѕР±С‹ СЌС‚Р° С„СѓРЅРєС†РёСЏ main
// СЂРµС€Р°Р»Р° Р·Р°РґР°С‡Сѓ "РђРІС‚РѕР±СѓСЃРЅС‹Рµ РѕСЃС‚Р°РЅРѕРІРєРё"

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }
}

