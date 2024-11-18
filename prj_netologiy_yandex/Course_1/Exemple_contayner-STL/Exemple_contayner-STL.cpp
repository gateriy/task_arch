п»ї// Exemple_contayner-STL.cpp : 
// РїСЂРёРјРµСЂС‹ РєРѕРЅС‚РµР№РЅРµСЂРѕРІ STL

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>



int main()
{
	int var_1{ 5 }, var_2{ 7 }, var_3{ 3 };
	bool status;
	
	std::array<int, 10>		array_x		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int>		vector_x	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::deque<int>			deque_x		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::forward_list<int>	f_list_x	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::list<int>			list_x		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


	std::cout << "- array -" << std::endl;
	var_2 = array_x.at(3);
	array_x[3] = var_1;
	var_3 = array_x.front();
	var_2 = array_x.back();
	sort((array_x.begin() + 2), (array_x.end() - 3), [](const int a, const int& b) {return a > b; });
	status = array_x.empty();
	var_3 = array_x.size();
	array_x.fill(5);//Р·Р°РїРѕР»РЅСЏРµС‚ РІРµСЃСЊ РјР°СЃСЃРёРІ РїСЏС‚РµСЂРєРѕР№
	for (const auto& i : array_x) {	std::cout << i <<" "; }
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;


	std::cout << "- vector -" << std::endl;
	var_2 = vector_x.at(3);
	vector_x[3] = var_1;
	var_3 = vector_x.front();
	var_2 = vector_x.back();
	sort((vector_x.begin() + 2), (vector_x.end() - 3), [](const int a, const int& b) {return a > b; });
	status = vector_x.empty();
	var_3 = vector_x.size();
	vector_x.push_back(77);
	vector_x.pop_back();
	vector_x.insert((vector_x.begin()+5), 777);
	vector_x.insert((vector_x.end() - 4), 555);
	var_3 = vector_x.capacity();//СЂР°Р·РІРµСЂ С‚РµРєСѓС‰РµРіРѕ РјР°СЃСЃРёРІР° РІС‹РґРµР»РµРЅРЅРѕРіРѕ РґР»СЏ РІРµРєС‚РѕСЂР° 
	vector_x.erase((vector_x.begin() + 2));
	vector_x.erase((vector_x.begin() + 2), (vector_x.end()-3));
	vector_x.shrink_to_fit();//СѓРјРµРЅСЊС€Р°РµС‚ СЂР°Р·РјРµСЂ РёСЃРїРѕР»СЊР·СѓРµРјРѕР№ РїР°РјСЏС‚Рё
	for (const auto& i : vector_x) {	std::cout << i <<" "; }
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;


	std::cout << "- deque -" << std::endl;
	var_2 = deque_x.at(3);
	deque_x[3] = var_1;
	var_3 = deque_x.front();
	var_2 = deque_x.back();
	sort((deque_x.begin() + 2), (deque_x.end() - 3), [](const int a, const int& b) {return a > b; });
	status = deque_x.empty();
	var_3 = deque_x.size();
	deque_x.shrink_to_fit();//СѓРјРµРЅСЊС€Р°РµС‚ СЂР°Р·РјРµСЂ РёСЃРїРѕР»СЊР·СѓРµРјРѕР№ РїР°РјСЏС‚Рё
	deque_x.push_back(77);
	deque_x.pop_back();
	deque_x.push_front(888);
	deque_x.pop_front();
	deque_x.insert((deque_x.begin() + 5), 777);
	deque_x.insert((deque_x.end() - 4), 555);
	deque_x.erase(deque_x.begin());
	deque_x.erase((deque_x.begin() + 1), (deque_x.end() - 7));	
	for (const auto& i : deque_x) {	std::cout << i << " "; }
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;
	

	std::cout << "- forward_list -" << std::endl;

	var_3 = f_list_x.front();
	status = f_list_x.empty();
	f_list_x.sort();
	f_list_x.remove(2);//СѓРјРµРЅСЊС€Р°РµС‚ СЂР°Р·РјРµСЂ РёСЃРїРѕР»СЊР·СѓРµРјРѕР№ РїР°РјСЏС‚Рё
	f_list_x.pop_front();
	f_list_x.push_front(777);
	f_list_x.insert_after(f_list_x.begin(), 777);
	f_list_x.erase_after(f_list_x.begin());
	f_list_x.remove(3);
	f_list_x.unique();//СѓРґР°Р»СЏРµС‚ РїРѕРІС‚РѕСЂСЏСЋС‰РёРµСЃСЏ СЌР»РµРјРµРЅС‚С‹
	for (const auto& i : f_list_x) { std::cout << i << " "; }
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;


	std::cout << "- list -" << std::endl;
	var_3 = list_x.front();
	var_2 = list_x.back();
	list_x.sort();
	status = list_x.empty();
	var_3 = list_x.size();
	list_x.push_back(77);
	list_x.pop_back();
	list_x.push_front(888);
	list_x.pop_front();
	list_x.insert((list_x.begin()), 777);
	list_x.insert(std::find(list_x.begin(), list_x.end(), 2),  555);
	list_x.erase(list_x.begin());
	list_x.remove(3);
	f_list_x.unique();//СѓРґР°Р»СЏРµС‚ РїРѕРІС‚РѕСЂСЏСЋС‰РёРµСЃСЏ СЌР»РµРјРµРЅС‚С‹
	for (const auto& i : list_x) { std::cout << i << " "; }
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;


}

