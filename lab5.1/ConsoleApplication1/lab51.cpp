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
	int size_menu = 8;
	vector <string> funcs =
	{
		"Input matrix",
		"Print matrix",
		"Get element",
		"Matrix trace",
		"Matrix mult by num",
		"Sum of matrices",
		"Matrix mults",
		"Matrix determinant"
	};


	for (int i = 0; i < size_menu; i++)
	{
		if (i != 3)
		{
			cout << " " << i + 1 << ". " << funcs[i] << "\t " << "\n";
		}
		else
		{
			cout << " " << i + 1 << ". " << funcs[i] << "\t\t " << "\n";
		}
	}
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
			cout << "\nEnter count of mrows and mcolumns then the mmatrix: ";
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
			cout << '\n';
			matr.print();
			cout << '\n';

			break;
		case 3:
			cout << "\nEnter the row and col: ";
			cin >> row;
			cin >> col;

			if (matr.get_elem(row, col) != numeric_limits<double>::min()) cout << "\n\nElement with row=m" << row << " column=m" << col
				<< " is " << matr.get_elem(row, col) << "\n\n";
			else cout << "\nElement with row=m" << row << " column=m" << col << " doesn't exist\n\n";

			break;
		case 4:
			if (matr.trace() != numeric_limits<double>::min()) cout << "\nThe trace of the matrix is " << matr.trace() << "\n\n";
			else cout << "\nThe trace of the matrix doesn't exist\n\n";

			break;
		case 5:
			cout << "\nEnter the number by which matrix will be multiplied: ";
			cin >> tmp;

			if (matr.mult_by_num(tmp)) cout << "\nThe matrix was successfully multiplied by the number\n\n";
			else cout << "\nThe matrix wasn't multiplied by the number\n\n";

			break;
		case 6:
			if (matr.get_cols() == 0)
			{
				cout << "m\nFirst you need to enter the first matrix\n\n";
				break;
			}

			cout << "\nHow would you like to enter the second matrix\n"
				"1. Input matrix\n"
				"2. Random input matrix\n";
			cin >> choise2;

			switch (choise2)
			{
			case 1:
				cout << "\nEnter count of [36mrows and [36mcolumns then the [36mmatrix: ";
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
					cout << "\nThe matrix has been successfully entered\n\n";
					matr2.print();
				}
				else cout << "\nThe matrix is not entered\n";

				break;
			case 2:
				cout << "\nEnter the size of the matrix (rows and columns) "
					"and the number above which the numbers will not randomize: ";
				cin >> rows;
				cin >> cols;
				cin >> up_to;

				if (matr2.rand_input(rows, cols, up_to))
				{
					cout << "\nThe matrix has been successfully entered\n\n";
					matr2.print();
				}
				else cout << "\nThe matrix is not entered\n";

				break;
			default:
				cout << "\nThere are no functions with the entered identifier\n\n";
				break;

			}

			if (matr.sum(&matr2)) cout << "\nThe matrices have been successfully stacked\n\n";
			else cout << "\nThe matrices weren't stacked\n\n";

			break;
		case 7:
			if (matr.get_cols() == 0)
			{
				cout << "m\nFirst you need to enter the first matrix\n\n";
				break;
			}

			cout << "\nHow would you like to enter the second matrix\n"
				"1. Input matrix\n"
				"2. Random input matrix\n";
			cin >> choise2;

			switch (choise2)
			{
			case 1:
				cout << "\nEnter count of [36mrows and [36mcolumns then the [36mmatrix: ";
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
					cout << "\nThe matrix has been successfully entered\n\n";
					matr2.print();
				}
				else cout << "\nThe matrix is not entered\n";

				break;
			case 2:
				cout << "\nEnter the size of the matrix (rows and columns) "
					"and the number above which the numbers will not randomize: ";
				cin >> rows;
				cin >> cols;
				cin >> up_to;

				if (matr2.rand_input(rows, cols, up_to))
				{
					cout << "\nThe matrix has been successfully entered\n\n";
					matr2.print();
				}
				else cout << "\nThe matrix is not entered\n";

				break;
			default:
				cout << "\nThere are no functions with the entered identifier\n\n";
				break;

			}

			matr3 = matr.mult_by_matr(&matr2);
			if (matr3.get_cols() != 0)
			{
				cout << "\n\nResult of matrix multiplication\n\n";
				matr3.print();
				cout << '\n';
			}
			else cout << "\nMatrices cannot be multiplied\n\n";

			break;
		case 8:
			tmp = matr.det();

			if (tmp != numeric_limits<double>::min()) cout << "\nThe determinant of the matrix is " << tmp << "\n\n";
			else cout << "\nThe determinant of the matrix doesn't exist\n\n";

			break;
		default:
			cout << "\nThere are no functions with the entered identifier\n\n";

			break;
		}
	}

}