п»ї// exemple_matvey_avtor.cpp : Р­С‚РѕС‚ С„Р°Р№Р» СЃРѕРґРµСЂР¶РёС‚ С„СѓРЅРєС†РёСЋ "main". Р—РґРµСЃСЊ РЅР°С‡РёРЅР°РµС‚СЃСЏ Рё Р·Р°РєР°РЅС‡РёРІР°РµС‚СЃСЏ РІС‹РїРѕР»РЅРµРЅРёРµ РїСЂРѕРіСЂР°РјРјС‹.
#include <algorithm>
#include <cassert>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// РџРµСЂРµС‡РёСЃР»РёРјС‹Р№ С‚РёРї РґР»СЏ СЃС‚Р°С‚СѓСЃР° Р·Р°РґР°С‡Рё
enum class TaskStatus {
    NEW,          // РЅРѕРІР°СЏ
    IN_PROGRESS,  // РІ СЂР°Р·СЂР°Р±РѕС‚РєРµ
    TESTING,      // РЅР° С‚РµСЃС‚РёСЂРѕРІР°РЅРёРё
    DONE          // Р·Р°РІРµСЂС€РµРЅР°
};

// Р’С‹РґРµР»РёРј РІ РѕС‚РґРµР»СЊРЅСѓСЋ С„СѓРЅРєС†РёСЋ РїРѕР»СѓС‡РµРЅРёРµ СЃР»РµРґСѓСЋС‰РµРіРѕ РїРѕ РїСЂРёРѕСЂРёС‚РµС‚Сѓ С‚РёРїР° Р·Р°РґР°С‡Рё
// Р¤СѓРЅРєС†РёСЏ РЅР°Р»Р°РіР°РµС‚ С‚СЂРµР±РѕРІР°РЅРёРµ РЅР° РІС…РѕРґРЅРѕР№ РїР°СЂР°РјРµС‚СЂ: РѕРЅ РЅРµ РґРѕР»Р¶РµРЅ Р±С‹С‚СЊ СЂР°РІРµРЅ DONE
// РџСЂРё СЌС‚РѕРј task_status СЏРІРЅРѕ РЅРµ СЃСЂР°РІРЅРёРІР°РµС‚СЃСЏ СЃ DONE, С‡С‚Рѕ РїРѕР·РІРѕР»СЏРµС‚
// СЃРґРµР»Р°С‚СЊ СЌС‚Сѓ С„СѓРЅРєС†РёСЋ РјР°РєСЃРёРјР°Р»СЊРЅРѕ СЌС„С„РµРєС‚РёРІРЅРѕР№
TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

// РћР±СЉСЏРІР»СЏРµРј С‚РёРї-СЃРёРЅРѕРЅРёРј РґР»СЏ map<TaskStatus, int>,
// РїРѕР·РІРѕР»СЏСЋС‰РµРіРѕ С…СЂР°РЅРёС‚СЊ РєРѕР»РёС‡РµСЃС‚РІРѕ Р·Р°РґР°С‡ РєР°Р¶РґРѕРіРѕ СЃС‚Р°С‚СѓСЃР°
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // РџРѕР»СѓС‡РёС‚СЊ СЃС‚Р°С‚РёСЃС‚РёРєСѓ РїРѕ СЃС‚Р°С‚СѓСЃР°Рј Р·Р°РґР°С‡ РєРѕРЅРєСЂРµС‚РЅРѕРіРѕ СЂР°Р·СЂР°Р±РѕС‚С‡РёРєР°
    const TasksInfo& GetPersonTasksInfo(const string& person) const;

    // Р”РѕР±Р°РІРёС‚СЊ РЅРѕРІСѓСЋ Р·Р°РґР°С‡Сѓ (РІ СЃС‚Р°С‚СѓСЃРµ NEW) РґР»СЏ РєРѕРЅРєСЂРµС‚РЅРѕРіРѕ СЂР°Р·СЂР°Р±РѕС‚С‡РёРєР°
    void AddNewTask(const string& person);

    // РћР±РЅРѕРІРёС‚СЊ СЃС‚Р°С‚СѓСЃС‹ РїРѕ РґР°РЅРЅРѕРјСѓ РєРѕР»РёС‡РµСЃС‚РІСѓ Р·Р°РґР°С‡ РєРѕРЅРєСЂРµС‚РЅРѕРіРѕ СЂР°Р·СЂР°Р±РѕС‚С‡РёРєР°
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count);

private:
    map<string, TasksInfo> person_tasks_;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
    return person_tasks_.at(person);
}

void TeamTasks::AddNewTask(const string& person) {
    ++person_tasks_[person][TaskStatus::NEW];
}

// Р¤СѓРЅРєС†РёСЏ РґР»СЏ СѓРґР°Р»РµРЅРёСЏ РЅСѓР»РµР№ РёР· СЃР»РѕРІР°СЂСЏ
void RemoveZeros(TasksInfo& tasks_info) {
    // РЎРѕР±РµСЂС‘Рј С‚Рµ СЃС‚Р°С‚СѓСЃС‹, РєРѕС‚РѕСЂС‹Рµ РЅСѓР¶РЅРѕ СѓР±СЂР°С‚СЊ РёР· СЃР»РѕРІР°СЂСЏ
    vector<TaskStatus> statuses_to_remove;
    for (const auto& task_item : tasks_info) {
        if (task_item.second == 0) {
            statuses_to_remove.push_back(task_item.first);
        }
    }
    for (const TaskStatus status : statuses_to_remove) {
        tasks_info.erase(status);
    }
}


tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
    const string& person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;

    const bool has_person = person_tasks_.count(person);

    // Р—РґРµСЃСЊ Рё РґР°Р»РµРµ РјС‹ Р±СѓРґРµРј РїРѕР»СЊР·РѕРІР°С‚СЊСЃСЏ С‚РµРј С„Р°РєС‚РѕРј, С‡С‚Рѕ РІ std::map РѕРїРµСЂР°С‚РѕСЂ []
    // РІ СЃР»СѓС‡Р°Рµ РѕС‚СЃСѓС‚СЃС‚РІРёСЏ РєР»СЋС‡Р° РёРЅРёС†РёР°Р»РёР·РёСЂСѓРµС‚ Р·РЅР°С‡РµРЅРёРµ РїРѕ СѓРјРѕР»С‡Р°РЅРёСЋ,
    // РµСЃР»Рё СЌС‚Рѕ РІРѕР·РјРѕР¶РЅРѕ.
    // std::map::operator[] ->
    // http://ru.cppreference.com/w/cpp/container/map/operator_at
    TasksInfo& tasks = person_tasks_[person];

    // РџРѕСЃС‡РёС‚Р°РµРј, СЃРєРѕР»СЊРєРѕ Р·Р°РґР°С‡ РєР°Р¶РґРѕРіРѕ РёР· СЃС‚Р°С‚СѓСЃРѕРІ РЅСѓР¶РЅРѕ РѕР±РЅРѕРІРёС‚СЊ,
    // РїРѕР»СЊР·СѓСЏСЃСЊ С‚РµРј С„Р°РєС‚РѕРј, С‡С‚Рѕ РїРѕ СѓРјРѕР»С‡Р°РЅРёСЋ enum class РёРЅС†РёР°Р»РёР·РёСЂСѓРµС‚ Р·РЅР°С‡РµРЅРёСЏ
    // РѕС‚ РЅСѓР»СЏ РїРѕ РІРѕР·СЂР°СЃС‚Р°РЅРёСЋ.
    // enum class -> http://ru.cppreference.com/w/cpp/language/enum
    for (TaskStatus status = TaskStatus::NEW;
        status != TaskStatus::DONE;
        status = Next(status)) {
        // РЎС‡РёС‚Р°РµРј РѕР±РЅРѕРІР»С‘РЅРЅС‹Рµ
        updated_tasks[Next(status)] = min(task_count, tasks[status]);
        // РЎС‡РёС‚Р°РµРј, СЃРєРѕР»СЊРєРѕ РѕСЃС‚Р°Р»РѕСЃСЊ РѕР±РЅРѕРІРёС‚СЊ
        task_count -= updated_tasks[Next(status)];
    }

    // РћР±РЅРѕРІР»СЏРµРј СЃС‚Р°С‚СѓСЃ С‚РµРєСѓС‰РёС… Р·Р°РґР°С‡ РІ СЃРѕРѕС‚РІРµС‚СЃС‚РІРёРё СЃ РёРЅС„РѕСЂРјР°С†РёРµР№ РѕР± РѕР±РЅРѕРІР»С‘РЅРЅС‹С…
    // Рё РЅР°С…РѕРґРёРј РєРѕР»РёС‡РµСЃС‚РІРѕ РЅРµС‚СЂРѕРЅСѓС‚С‹С…
    for (TaskStatus status = TaskStatus::NEW;
        status != TaskStatus::DONE;
        status = Next(status)) {
        untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
        tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
    }
    // РџРѕ СѓСЃР»РѕРІРёСЋ, DONE Р·Р°РґР°С‡Рё РЅРµ РЅСѓР¶РЅРѕ РІРѕР·РІСЂР°С‰Р°С‚СЊ РІ РЅРµ РѕР±РЅРѕРІР»С‘РЅРЅС‹С… Р·Р°РґР°С‡Р°С…
    tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

    // РџРѕ СѓСЃР»РѕРІРёСЋ РІ СЃР»РѕРІР°СЂСЏС… РЅРµ РґРѕР»Р¶РЅРѕ Р±С‹С‚СЊ РЅСѓР»РµР№
    RemoveZeros(updated_tasks);
    RemoveZeros(untouched_tasks);
    RemoveZeros(person_tasks_.at(person));

    if (!has_person) {
        person_tasks_.erase(person);
    }

    return { updated_tasks, untouched_tasks };
}