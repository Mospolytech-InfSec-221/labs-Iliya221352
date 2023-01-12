#include <iostream>
#include <string>
#include <deque>

// структура пары координат
struct pair {
	double x;
	double y;
};


bool task1_deque_(std::string str) {
	std::deque <char> c1;
	for (int i = 0; i < str.length(); i++) {
		c1.push_front(str[i]);
	}
	for (int q = 0; q < c1.size() / 2; q++) {
		char& i = c1.back();
		if (i == ' ') {
			c1.pop_back();
			continue;
		}
		char& j = c1.front();
		if (j == ' ') {
			c1.pop_front();
			continue;
		}
		if (tolower(i) == tolower(j)) {
			c1.pop_front();
			c1.pop_back();
		}
		else {
			std::cout << "Не полиндром";
			return 0;

		}
	}
	std::cout << "Полиндром";
	return 1;
}


void min(pair* pairs, int num) { // наиболее приближённое к началу координат точка
	pair min = { pairs[0].x, pairs[0].y }; 

	for (int i = 0; i < num; i++) {
		if (pairs[i].x < min.x) {
			min.x = pairs[i].x;
			min.y = pairs[i].y;
			pair temp = { pairs[0].x, pairs[0].y };
			pairs[0] = { min.x, min.y };
			pairs[i] = { temp.x, temp.y };
		}
	}

}

double check(pair src, pair chk, pair checked) {
	return (chk.x - src.x) * (checked.y - chk.y) - (chk.y - src.y) * (checked.x - chk.x); // узнаём с какой строны вектора находится точка
}

void sort(pair* pairs, int num) { // сортирует по порядку против часовой стрелки
	for (int i = 1; i < num - 1; i++) {
		for (int j = 1; j < num - 2; j++) {
			if (check(pairs[0], pairs[j], pairs[j + 1]) <= 0) {
				pair temp = pairs[j];
				pairs[j] = pairs[j + 1];
				pairs[j + 1] = temp;
			}
			else {
				continue;
			}
		}
	}
}

void push(std::deque<pair>& alg, pair* pairs, int num) {
	alg.push_back(pairs[0]);
	alg.push_back(pairs[1]);
	for (int i = 2; i < num; i++) {
		if (check(alg.at(alg.size() - 2), alg.back(), pairs[i]) < 0) { //если угол < 180
			alg.pop_back();
		}
		if (check(alg.back(), pairs[i], pairs[i + 1]) > 0) { // если точка i+1 находится левее от вектора
			alg.push_back(pairs[i]);
		}

	}
}
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	std::string str;
	std::cin >> str;
	task1_deque_(str); //полиндром
	std::deque<pair> alg; // финальное множество
	const int num = 10;
	struct pair pairs[num] = { 1,4, 2,2, 4,6, 8,1, 6,4, 9,6, 2,7, 7,8, 4,9, 3,10 };
	min(pairs, num); // координата наиболее близкая к началу координат
	sort(pairs, num); // сортировка пар
	push(alg, pairs, num); //
	for (int i = 0; i < alg.size(); i++) {
		std::cout << alg[i].x << " " << alg[i].y << std::endl;
	}
}