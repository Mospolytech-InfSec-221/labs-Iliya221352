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
	int size_menu = 9;
	vector <string> funcs =
	{
		"Input matrix",
		"Random input matrix",
		"Print matrix",
		"Get element",
		"Matrix trace",
		"Matrix mult by num",
		"Sum of matrices",
		"Matrix mults",
		"Matrix determinant"
	};

	cout << "+-----------------------+\n";
	for (int i = 0; i < size_menu; i++)
	{
		if (i != 3)
		{
			cout << "|" << i + 1 << ". " << funcs[i] << "\t|" << "\n";
		}
		else
		{
			cout << "|" << i + 1 << ". " << funcs[i] << "\t\t|" << "\n";
		}
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
	int choise = 0, row = 0, col = 0, rows = 0,
		cols = 0, up_to = 0, choise2 = 0;
	double tmp = 0;
	vector <double> els, els2;
	Matrix matr, matr2, matr3;

	while (true)
	{
		menu();
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "\nEnter count of \x1B[33mrows\033[0m and \x1B[33mcolumns\033[0m then the \x1B[33mmatrix\033[0m: ";
			cin >> rows;
			cin >> cols;

			els.resize(rows * cols);
			for (size_t i = 0; i < rows * cols; i++)
			{
				cin >> tmp;
				els[i] = tmp;
			}
			if (matr.input(rows, cols, &els)) cout << "\x1B[32m\nThe matrix has been successfully entered\n\n\033[0m";
			else cout << "\x1B[31m\nThe matrix is not entered\n\n\033[0m";

			break;
		case 2:
			cout << "\nEnter the size of the matrix (rows and columns) "
				"and the number above which the numbers will not randomize: ";
			cin >> rows;
			cin >> cols;
			cin >> up_to;

			if (matr.rand_input(rows, cols, up_to)) cout << "\x1B[32m\nThe matrix has been successfully entered\n\n\033[0m";
			else cout << "\x1B[31m\nThe matrix is not entered\n\n\033[0m";

			break;
		case 3:
			cout << '\n';
			matr.print();
			cout << '\n';

			break;
		case 4:
			cout << "\nEnter the row and col: ";
			cin >> row;
			cin >> col;

			if (matr.get_elem(row, col) != numeric_limits<double>::min()) cout << "\n\nElement with row=\x1B[33m" << row << "\033[0m column=\x1B[33m" << col
				<< "\033[0m is \x1B[32m" << matr.get_elem(row, col) << "\033[0m\n\n";
			else cout << "\nElement with row=\x1B[33m" << row << "\033[0m column=\x1B[33m" << col << "\033[0m \x1B[31mdoesn't exist\033[0m\n\n";

			break;
		case 5:
			if (matr.trace() != numeric_limits<double>::min()) cout << "\nThe trace of the matrix is \x1B[32m" << matr.trace() << "\033[0m\n\n";
			else cout << "\x1B[31m\nThe trace of the matrix doesn't exist\n\n\033[0m";

			break;
		case 6:
			cout << "\nEnter the number by which matrix will be multiplied: ";
			cin >> tmp;

			if (matr.mult_by_num(tmp)) cout << "\x1B[32m\nThe matrix was successfully multiplied by the number\n\n\033[0m";
			else cout << "\x1B[31m\nThe matrix wasn't multiplied by the number\n\n\033[0m";

			break;
		case 7:
			if (matr.get_cols() == 0)
			{
				cout << "\x1B[33m\nFirst you need to enter the first matrix\n\n\033[0m";
				break;
			}

			cout << "\nHow would you like to enter the second matrix\n"
				"1. Input matrix\n"
				"2. Random input matrix\n";
			cin >> choise2;

			switch (choise2)
			{
			case 1:
				cout << "\nEnter count of \x1B[36mrows\033[0m and \x1B[36mcolumns\033[0m then the \x1B[36mmatrix\033[0m: ";
				cin >> rows;
				cin >> cols;

				els2.resize(rows * cols);
				for (size_t i = 0; i < rows * cols; i++)
				{
					cin >> tmp;
					els2[i] = tmp;
				}
				if (matr2.input(rows, cols, &els2))
				{
					cout << "\x1B[32m\nThe matrix has been successfully entered\n\n\033[0m";
					matr2.print();
				}
				else cout << "\x1B[31m\nThe matrix is not entered\n\033[0m";

				break;
			case 2:
				cout << "\nEnter the size of the matrix (rows and columns) "
					"and the number above which the numbers will not randomize: ";
				cin >> rows;
				cin >> cols;
				cin >> up_to;

				if (matr2.rand_input(rows, cols, up_to))
				{
					cout << "\x1B[32m\nThe matrix has been successfully entered\n\n\033[0m";
					matr2.print();
				}
				else cout << "\x1B[31m\nThe matrix is not entered\n\033[0m";

				break;
			default:
				cout << "\x1B[31m\nThere are no functions with the entered identifier\n\n\033[0m";
				break;

			}

			if (matr.sum(&matr2)) cout << "\x1B[32m\nThe matrices have been successfully stacked\n\n\033[0m";
			else cout << "\x1B[31m\nThe matrices weren't stacked\n\n\033[0m";

			break;
		case 8:
			if (matr.get_cols() == 0)
			{
				cout << "\x1B[33m\nFirst you need to enter the first matrix\n\n\033[0m";
				break;
			}

			cout << "\nHow would you like to enter the second matrix\n"
				"1. Input matrix\n"
				"2. Random input matrix\n";
			cin >> choise2;

			switch (choise2)
			{
			case 1:
				cout << "\nEnter count of \x1B[36mrows\033[0m and \x1B[36mcolumns\033[0m then the \x1B[36mmatrix\033[0m: ";
				cin >> rows;
				cin >> cols;

				els2.resize(rows * cols);
				for (size_t i = 0; i < rows * cols; i++)
				{
					cin >> tmp;
					els2[i] = tmp;
				}
				if (matr2.input(rows, cols, &els2))
				{
					cout << "\x1B[32m\nThe matrix has been successfully entered\n\n\033[0m";
					matr2.print();
				}
				else cout << "\x1B[31m\nThe matrix is not entered\n\033[0m";

				break;
			case 2:
				cout << "\nEnter the size of the matrix (rows and columns) "
					"and the number above which the numbers will not randomize: ";
				cin >> rows;
				cin >> cols;
				cin >> up_to;

				if (matr2.rand_input(rows, cols, up_to))
				{
					cout << "\x1B[32m\nThe matrix has been successfully entered\n\n\033[0m";
					matr2.print();
				}
				else cout << "\x1B[31m\nThe matrix is not entered\n\033[0m";

				break;
			default:
				cout << "\x1B[31m\nThere are no functions with the entered identifier\n\n\033[0m";
				break;

			}

			matr3 = matr.mult_by_matr(&matr2);
			if (matr3.get_cols() != 0)
			{
				cout << "\n\nResult of matrix multiplication\n\n";
				matr3.print();
				cout << '\n';
			}
			else cout << "\x1B[31m\nMatrices cannot be multiplied\n\n\033[0m";

			break;
		case 9:
			tmp = matr.det();

			if (tmp != numeric_limits<double>::min()) cout << "\nThe determinant of the matrix is \x1B[32m" << tmp << "\n\n\033[0m";
			else cout << "\x1B[31m\nThe determinant of the matrix doesn't exist\n\n\033[0m";

			break;
		default:
			cout << "\x1B[31m\nThere are no functions with the entered identifier\n\n\033[0m";

			break;
		}
	}

}