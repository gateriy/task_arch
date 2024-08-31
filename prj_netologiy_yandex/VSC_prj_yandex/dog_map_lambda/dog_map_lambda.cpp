// dog_map_lambda.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs, const map<string, int>& max_amount,
    map<string, int>& shelter) {
    int result=count_if(new_dogs.begin(), new_dogs.end(), [&shelter, &max_amount](const string& name) {
        // в map в [] или at() это обращение к ключу!!!! именно к ключу!
        if (shelter[name] < max_amount.at(name)) {
         ++shelter[name];// при наличии ключа name увеличивает значение при отсутствуии создает новый ключ (!!!) name с 0 значением
            return true;
        }
        else { return false; }

        });

    /* return count_if(new_dogs.begin(), new_dogs.end(),
        [&max_amount, &shelter](const string& name) {
            int& current_amount = shelter[name];
            if (current_amount < max_amount.at(name)) {
                ++current_amount;
                return true;
            } else {
                return false;
            }
        });*/


    return result;

} 

int main() {

    map<string, int> shelter{{"shepherd"s, 1},{"corgi"s, 3},};
    map<string, int> max_amount{{"shepherd"s, 2},{"corgi"s, 3},{"shiba inu"s, 1},};

    cout << CountAndAddNewDogs({ "shepherd"s, "shiba inu"s, "shiba inu"s, "corgi"s }, max_amount, shelter) << endl;
}