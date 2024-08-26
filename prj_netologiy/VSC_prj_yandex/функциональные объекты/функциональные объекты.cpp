﻿// функциональные объекты.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Animal {
    string name;
    int age;
    double weight;
};

template <typename Container, typename KeyMapper>
void SortBy(Container& container, KeyMapper key_mapper, bool reverse=false) {
    if (reverse) {
        sort(container.begin(), container.end(), [key_mapper](const auto& lhs, const auto& rhs) {
            return key_mapper(lhs) > key_mapper(rhs);
            });
    } else {
        sort(container.begin(), container.end(), [key_mapper](const auto& lhs, const auto& rhs) {
            return key_mapper(lhs) < key_mapper(rhs);
            });
    }
}

void PrintNames(const vector<Animal>& animals) {
    for (const Animal& animal : animals) {
        cout << animal.name << ' ';
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Animal> animals = {
        {"Мурка"s, 10, 5},
        {"Белка"s, 5, 1.5},
        {"Георгий"s, 2, 4.5},
        {"Рюрик"s, 12, 3.1},
    };

    PrintNames(animals);
    SortBy(animals, [](const Animal& animal) { return animal.name; }, true);
    PrintNames(animals);
    SortBy(animals, [](const Animal& animal) { return animal.weight; });
    PrintNames(animals);
    return 0;

    return 0;
}