// netologiy 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>

int main() {

    std::string znac, pol;
    int age = 0;
    bool man_woman = false;
    bool erth_woter = false;
    bool age_m = false;
    bool age_w = false;
    bool correct = true;


    std::cout << "Введите Ваш пол: ";
    std::cin >> pol;
    std::cout << "Введите Ваш знак зодиакка: ";
    std::cin >> znac;
    std::cout << "Введите Ваш возраст: ";
    std::cin >> age;

    if (pol == "м") {
        man_woman = true;
    }
    else if (pol != "ж" || pol != "м") {
        correct = false;
    }

    if (age < 40 && man_woman == true) {
        age_m = true;
    }

    if (age >= 15 && age <= 30 && man_woman == false) {
        age_w = true;
    }

    if (znac == "Телец" || znac == "Дева" || znac == "Козерог") {
        erth_woter = true;
    }
    else if (znac == "Рак" || znac == "Рыбы" || znac == "Рак") {
            erth_woter = false;
    }
    else { correct == false; }
    
 

 
  


    if (man_woman == true && age_m == true && erth_woter == false && correct == true) {
        std::cout << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным.\n";
    }
    else if (man_woman == false && age_w == true && erth_woter == true && correct == true) {
        std::cout << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок. Будет не только весело, но и интересно: найдётся дело, которое увлечёт всех.\n";
    }
    else {
        if (correct == true) {
            std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)\n";
        }
        else if ( correct == false) { std::cout << "ошибка ввода"; }

    }
}