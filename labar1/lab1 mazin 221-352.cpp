#include <iostream>
#include <bitset>

void task_1() {
	// ФИО, номер группы
	std::cout << "Task 1.\n\tMazin Iliya, 221-352\n\n";
}

void task_2() {
	// минимальные и максимальные значения встроенных типов данных, а так же их размер; (10 баллов)
	//	int		uint	short	ushort 	 long	  double	char	bool
	std::cout << "Task 2.\n";
	std::cout << "\tInt size: " << sizeof(int)
		<< "\tMin int = " << INT_MIN
		<< "\t\tMax int = " << INT_MAX << '\n';

	// uint min равен нулю, так как этот тип данных не принимает отрицательных чисел
	std::cout << "\tUint size: " << sizeof(unsigned int)
		<< "\tMin uint = " << 0
		<< "\t\t\tMax uint = " << UINT_MAX << '\n';
	std::cout << "\tShort size: " << sizeof(short)
		<< "\tMin short = " << SHRT_MIN
		<< "\t\tMax short = " << SHRT_MAX << '\n';

	// ushort min равен нулю, так как этот тип данных не принимает отрицательных чисел
	std::cout << "\tUshort size: " << sizeof(unsigned short)
		<< "\tMin ushort = " << 0
		<< "\t\t\tMax ushort = " << USHRT_MAX << '\n';
	std::cout << "\tLong size: " << sizeof(long)
		<< "\tMin long = " << int(0b1000000000000000000000000000000000000000000000000000000000000000)
		<< "\t\tMax long = " << int(0b0111111111111111111111111111111111111111111111111111111111111111) << '\n';
	std::cout << "\tDouble size: " << sizeof(double)
		<< "\tMin double = " << DBL_MIN
		<< "\tMax double = " << DBL_MAX << '\n';
	std::cout << "\tChar size: " << sizeof(char)
		<< "\tMin char = " << CHAR_MIN
		<< "\t\t\tMax char = " << CHAR_MAX << '\n';
	std::cout << "\tBool size: " << sizeof(bool)
		<< "\tMin bool = " << "False"
		<< "\t\tMax bool = " << "True" << "\n\n";
}

void task_3() {
	std::cout << "Task 3.\n";
	int num;

	/*запросить у пользователя некоторое целое число
	  и вывести на экран это число в бинарном и
		  шестнадцатиричном виде,
	  а так же результат преобразования типов ко всем встроенным*/
	std::cout << "Введите число: ";
	std::cin >> num;

	std::cout << "\tBin: 0b" << std::bitset<8 * sizeof(int)>(num) << '\n';
	std::cout << "\tHex: 0x" << std::hex << num << '\n';
	std::cout << "\tBool:" << bool(num) << '\n';
	std::cout << "\tChar:" << char(num) << '\n';
	std::cout << "\tDouble:" << double(num) << "\n\n";
}

void task_4() {
	std::cout << "Task 4.\n";
	/* записать условие и полное решение уравнения вида
	𝑎 ∗ 𝑥 = 𝑏(a отлично от нуля),
	причем значения коэффициентов(целые числа) вводит пользователь */
	int a, b;
	std::cout << "Введите число a и b: ";
	std::cin >> a >> b;

	// Полное решение: 𝑎 ∗ 𝑥 = 𝑏
	std::cout << '\t' << a << " * x = " << b << '\n';
	std::cout << "\tx = " << b << " / " << a << '\n';
	std::cout << "\tx = " << float(b) / a << "\n\n";
}

void task_5() {
	std::cout << "Task 5.\n";
	/*записать программу для нахождения середины отрезка,
	заданного целыми координатами концевых точек*/
	int x1, x2;
	std::cout << "Введиет X1 и X2: ";
	std::cin >> x1 >> x2;

	std::cout << "Середина: " << (x1 + x2) / 2. << std::endl;
}

int main() {
	setlocale(LC_ALL, "");    // локализация кириллицы

	task_1();
	task_2();
	task_3();
	task_4();
	task_5();
} 
// лонг через двоичную
// 77 строка неявное преобразование 
// как по другому перевести в двоичгную систему