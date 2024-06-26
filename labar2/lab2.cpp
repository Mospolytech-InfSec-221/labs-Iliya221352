#include <iostream>

using std::cout;
using std::cin;

void task1(int n) {
	std::cout << '\n';
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << j << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "\n\n";
}

void task2() {
	cout << "\nВведите число: ";
	int n;
	long double  c;
	cin >> n;
	c = n;
	cout << 1 << ' ';
	for (int k = 1; k <= n; k++){
		cout << c << ' ';
		c *= (n - k);
		c /= (k + 1);
	}
	cout << '\n';
}

void task3() {
	cout << '\n';
	int input_num;
	int count = 0;
	int sum = 0;

	cout << "Вводите числа: ";

	while (1 == 1) {
		cin >> input_num;

		if (input_num == '\n')
			break;
		else if (input_num == 0)
			break;

		sum += input_num;
		count++;
	}
	cout << float(sum) / count;
	cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, ""); // локализация кириллицы

	short choice = 0; // переменная выбора задачи
	while (choice != 4) {
		std::cout << "1. Числовой треугольник\n";
		std::cout << "2. Биномиальные коэффициенты\n";
		std::cout << "3. Cреднее арифметическое\n";
		std::cout << "4. Выход\n";
		std::cout << "Введите номер задачи: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			int q;
			std::cout << "\nВведите число: ";
			std::cin >> q;
			task1(q);
			break;
		}
		case 2: {
			task2();
			break;
		}
		case 3: {
			task3();
			break;
		}
		}
	}
	std::cout << "\nКонец!\n";
}