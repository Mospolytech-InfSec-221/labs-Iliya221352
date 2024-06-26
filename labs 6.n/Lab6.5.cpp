#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <map>
void task_list() {
	std::map <int, std::string> group;
	std::cout << "Чтобы остановить ввод введите 0" << std::endl;
	std::cout << "Введите номер группы и фамилию студента через пробел: ";
	std::string str;
	std::list <int> list1;
	std::list <int> list2;
	while (str != "0") {
		int index = 0;
		std::getline(std::cin, str);
		std::string* mas = new std::string[100];
		std::string new_str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ') {
				new_str += str[i];
			}
			if ((str[i] == ' ') or (i == str.length() - 1)) {
				mas[index] = new_str;
				index++;
				new_str = ' ';
			}
		}
		group[std::stoi(mas[0])] += mas[1];
		list1.push_front(std::stoi(mas[0]));
		delete[] mas;
	}
	list1.sort();
	list1.unique();
	for (int i = 0; i < list1.size()+ 1; i++) {
		std::cout << "Группа " << list1.back() << " Студенты" << group[list1.back()] << std::endl;
		list1.pop_back();
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	task_list();
}