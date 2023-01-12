#include <map>
#include <iostream>
#include <string>
void task_map_() {
	std::cout << "Введите строку, с которой будем работать: ";
	std::string str;
	int j = 0;
	int main_count = 0;
	std::string* mas = new std::string[1000];
	std::getline(std::cin, str);
	std::map <std::string, int> letters;
	std::string new_str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			new_str += str[i];
		}
		if ((i == str.length() - 1) or (str[i] == ' ')) {
			//std::cout << new_str << std::endl;
			letters[new_str]++;
			bool ex = false;
			for (int q = 0; q <= j; q++) {
				if (mas[q] == new_str) {
					ex = true;
					break;
				}
			}
			if (ex == 0) {
				mas[j] = new_str;
				j++;
			}
			main_count++;
			//std::cout << new_str<< " " << letters[new_str];
			new_str = "";
		}
	}
	for (int i = 0; i < j; i++)
	{
		std::cout << "Количество слов \"" << mas[i] << "\" в тексте:" << " " << letters[mas[i]];
		std::cout << ", процентное содержание: " << (letters[mas[i]] / float(main_count)) * 100 << "%" << std::endl;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	task_map_();
}