#include <iostream>
#include <vector>
#include "Matrix.h"


using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::numeric_limits;


void menu()
{
	int size_menu = 4;
	vector <string> funcs =
	{
		"Input matrix",
		"Print matrix",
		"Sum of matrices",
		"Matrix mults",
	};

	cout << "+-----------------------+\n";
	for (int i = 0; i < size_menu; i++)
	{
		cout << "|" << i + 1 << ". " << funcs[i] << "\t|" << "\n";

		if (i != size_menu - 1)
		{
			cout << "|-----------------------|\n";
		}
	}
	cout << "+-----------------------+\n";
	cout << "\nEnter the action number: ";

	vector<string>().swap(funcs);
}

int main()
{
	int choise = 0, choise2 = 0, row = 0, col = 0,
		rows = 0, cols = 0, up_to = 0;
	double tmp = 0;
	vector <double> els, els2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix matr, matr2(3, 3), matr3(3, 3, &els2), matr4;

	while (true)
	{
		menu();
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "\n1. Input with elements\n"
				"2. Input without elements\n";
			cin >> choise2;
			switch (choise2)
			{
			case 1:
				cout << "\nEnter count of  and columns then the matrix: ";
				cin >> rows;
				cin >> cols;

				els.resize(rows * cols);
				for (size_t i = 0; i < rows * cols; i++)
				{
					cin >> tmp;
					els[i] = tmp;
				}
				if (matr.input(rows, cols, &els)) cout << "\nThe matrix has been successfully entered\n\n";
				else cout << "\nThe matrix is not entered\n\n";

				break;
			case 2:
				cout << "\nEnter count of  and columns then the matrix: ";
				cin >> rows;
				cin >> cols;

				if (matr.input(rows, cols)) cout << "\nThe matrix has been successfully entered\n\n";
				else cout << "\nThe matrix is not entered\n\n";
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << '\n';
			matr.print();
			cout << '\n';

			break;
		case 3:
			cout << "\n1. Sum with size\n"
				"2. Sum without size\n";
			cin >> choise2;

			if (matr.get_cols() == 0)
			{
				cout << "\nFirst you need to enter the first matrix\n\n";
				break;
			}

			switch (choise2)
			{
			case 1:
				matr.sum(&els2);
				break;
			case 2:
				matr.sum(&els2, 9);
				break;
			default:
				break;
			}
			break;
		case 4:
			cout << "\n1. Mult with size\n"
				"2. Mult without size\n";
			cin >> choise2;

			if (matr.get_cols() == 0)
			{
				cout << "\nFirst you need to enter the first matrix\n\n";
				break;
			}

			switch (choise2)
			{
			case 1:
				matr4 = matr.mult_by_matr(&els2);
				matr4.print();
				break;
			case 2:
				matr4 = matr.mult_by_matr(&els2, 9);
				matr4.print();
				break;
			default:
				break;
			}
			break;
		default:
			cout << "\nThere are no functions with the entered identifier\n\n";

			break;
		}
	}

}