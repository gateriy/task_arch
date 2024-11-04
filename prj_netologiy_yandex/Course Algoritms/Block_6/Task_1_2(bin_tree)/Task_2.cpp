#include"Task_2.h"

/*
Задача 2. «Путешествие» по пирамиде
Вам нужно организовать «путешествие» пользователя по пирамиде.

Дан массив, в котором хранится пирамида. Ваша задача — 
дать пользователю возможность «путешествовать» по ней.

В начале программы пользователь начинает свой путь в корне пирамиды. 
Программа спрашивает пользователя, куда он хочет пойти. 
Пользователь должен ответить на этот вопрос, используя одну из команд:

up — перейти к родителю;
left — перейти к левому потомку;
right — перейти к правому потомку;
exit — завершить работу программы.
Перед каждым вводом команды программа выводит сообщение 
Вы находитесь здесь:  и элемент, на котором сейчас находится пользователь. 
Элемент выводится аналогично тому, как выводились элементы в прошлом задании.

После каждого ввода команды программа выводит результат её выполнения. 
Если команда была выполнена успешно, выведите на консоль Ок. 
Если выполнить команду не удалось, например, вы ввели команду up, 
находясь в корне пирамиды, выведите на консоль сообщение об ошибке и причину 
её возникновения: например, Ошибка! Отсутствует родитель.

Программа предлагает пользователю вводить команды до тех пор, 
пока пользователь не введёт команду exit. Если пользователь ввёл команду, 
которой нет в списке, сообщите ему об этом.

Перед началом работы с пользователем выведите на экран исходный массив в виде 
массива и в виде пирамиды, как в прошлом задании.

Для проверки работы программы используйте пирамиды:

1 3 6 5 9 8;
94 67 18 44 55 12 6 42;
16 11 9 10 5 6 8 1 2 4.

Пример работы программы
Исходный массив: 1 3 6 5 9 8
Пирамида:
0 root 1
1 left(1) 3
1 right(1) 6
2 left(3) 5
2 right(3) 9
2 left(6) 8

Вы находитесь здесь: 0 root 1
Введите команду: right
Ок
Вы находитесь здесь: 1 right(1) 6
Введите команду: right
Ошибка! Отсутствует правый потомок
Вы находитесь здесь: 1 right(1) 6
Введите команду: left
Ок
Вы находитесь здесь: 2 left(6) 8
Введите команду: right
Ошибка! Отсутствует правый потомок
Вы находитесь здесь: 2 left(6) 8
Введите команду: left
Ошибка! Отсутствует левый потомок
Вы находитесь здесь: 2 left(6) 8
Введите команду: up
Ок
Вы находитесь здесь: 1 right(1) 6
Введите команду: up
Ок
Вы находитесь здесь: 0 root 1
Введите команду: up
Ошибка! Отсутствует родитель
Вы находитесь здесь: 0 root 1
Введите команду: exit
*/

std::pair<bool, std::string> go_math_pyramid(const std::vector<int>& array, int i) {
	int count{ 0 };
	std::string text{ "" };	

	if (i < array.size() && i >= 0) {
	
		if (i == 0) {
			text = "0 root " + std::to_string(array[i]);
			return { true, text };
		}
		else {
			if (i % 2 != 0) {
				count = Level_Piramid((i - 1) / 2);
				text = std::to_string(count) + " left(" + std::to_string(array[(i - 1) / 2]) + ") " + std::to_string(array[i]);
			} 
			else {
				count = Level_Piramid((i - 2) / 2);
				text = std::to_string(count) + " right(" + std::to_string(array[(i - 2) / 2]) + ") " + std::to_string(array[i]);
			}
			return { true, text };
		}
	}
	else {
		return { false, "" };
	}	
}

void go_piramid(const std::vector<int>& array) {
	std::string command{ "" }, var_L_R{ "" };
	int i{ 0 };
	std::pair<bool, std::string> res{ 0,"" };

	std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;

	do {
		std::cout << "Введите команду: ";
		std::cin >> command;

		if (command == "up") {
			if (i % 2 != 0) {
				i = (i - 1) / 2;
				if (go_math_pyramid(array, i).first) {
					std::cout << "Ok" << std::endl;
					std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
				}
				else {
					std::cout << "Ошибка! Отсутствует родитель" << std::endl;
					i = 2 * i + 1;
					std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
				}
			}
			else {
				i = (i - 2) / 2;
				if (go_math_pyramid(array, i).first) {
					std::cout << "Ok" << std::endl;
					std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
				}
				else {
					std::cout << "Ошибка! Отсутствует родитель" << std::endl;
					i = 2 * i + 2;
					std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
				}
			}
		} 
		else if (command == "left") {	
				i = 2 * i + 1;
			if (go_math_pyramid(array, i).first) {
				std::cout << "Ok" << std::endl;
				std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
			}
			else {
				std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
				i = (i - 1) / 2;				
				std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
			}
		}
		else if (command == "right") {
				i = 2 * i + 2;
			if (go_math_pyramid(array, i).first) {
				std::cout << "Ok" << std::endl;
				std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
			}
			else {
				std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
				i = (i - 2) / 2;
				std::cout << "Вы находитесь здесь: " << go_math_pyramid(array, i).second << std::endl;
			}
		}
		else if (command == "exit") {
			std::cout << "-----------------------------" << std::endl;
			break;
		}
		else { std::cout << "Уточните комманду!" << std::endl; }
		
	} while (true);
}

void Task_2() {

	std::vector < int> arr_1{ 1, 3, 6, 5, 9, 8 };

	print_array(arr_1);
	print_pyramid(arr_1);
	go_piramid(arr_1);

};