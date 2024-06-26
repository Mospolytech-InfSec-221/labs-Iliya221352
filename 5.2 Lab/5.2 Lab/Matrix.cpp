#include "Matrix.h"

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::to_string;
using std::numeric_limits;

Matrix Matrix::service_sum_matr(int in_rows, vector<double>* matr_els, int size)
{
	Matrix matr;

	if (size % in_rows == 0)
	{
		matr.cols = size / in_rows;
		matr.rows = size / matr.cols;
		matr.els = *matr_els;
	}

	return matr;
}

Matrix Matrix::service_mult_matr(int in_cols, vector<double>* matr_els, int size)
{
	Matrix matr;

	if (size % in_cols == 0)
	{
		matr.rows = in_cols;
		matr.cols = size / matr.rows;
		matr.els = *matr_els;
	}
	return matr;
}

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	vector<double> els;
}

Matrix::Matrix(int in_rows, int in_cols)
{
	rows = in_rows;
	cols = in_cols;
	els.resize(rows * cols);
}

Matrix::Matrix(int in_rows, int in_cols, vector <double>* in_els)
{
	rows = in_rows;
	cols = in_cols;
	els = *in_els;
}

Matrix::~Matrix()
{
	if (!els.empty()) vector<double>().swap(els);
}

bool Matrix::input(int in_rows, int in_cols, vector <double>* in_els)
{
	Matrix::~Matrix();
	rows = in_rows;
	cols = in_cols;
	els = *in_els;
	return true;
}

bool Matrix::input(int in_rows, int in_cols)
{
	Matrix::~Matrix();
	vector<double> tmp(rows * cols, 0);
	rows = in_rows;
	cols = in_cols;
	els.resize(rows * cols);

	return true;
}

bool Matrix::rand_input(int in_rows, int in_cols, int up_to)

/*Generates a matrix of row and column sizes with numbers of the same bit depth as the maximum number.
If the number is a power of ten, then up to the number minus one.*/

{
	Matrix::~Matrix();
	int fst_val = 0;
	rows = in_rows;
	cols = in_cols;

	if (std::fmod(log10(up_to), 1) == 0) fst_val = std::stoi("1" + string(int(log10(up_to)) - 1, '0'));
	else fst_val = std::stoi("1" + string(int(log10(up_to)), '0'));

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, up_to - 1);

	els.resize(rows * cols);
	for (size_t i = 0; i < rows * cols; i++)
	{
		els[i] = double(distrib(gen));
	}
	return true;
}

void Matrix::print()
{
	if (rows != 0)
	{
		// Finding the maximum length of a number in a matrix
		size_t mx_len = 0;
		string tmp = "\0";
		for (size_t i = 0; i < rows * cols; i++)
		{
			if (to_string(els[i]).find_last_not_of("0") > mx_len)
			{

				mx_len = to_string(els[i]).find_last_not_of("0");
			}
		}

		// indexes for columns
		cout << string(to_string(rows).length() + 2, ' ');
		for (size_t i = 0; i < cols; i++)
		{
			cout << "" << std::setw(mx_len + 1) << i << " ";
		}
		cout << '\n';

		// "^" for columns
		cout << string(to_string(rows).length() + 2, ' ');
		for (size_t i = 0; i < cols; i++)
		{
			cout << "" << std::setw(mx_len + 2) << "^ " << "";
		}
		cout << '\n';

		// matrix
		for (size_t i = 0; i < rows; i++)
		{
			cout << string(to_string(rows).length() - to_string(i).length(), ' ') << "" << i << "< ";
			for (size_t j = 0; j < cols; j++)
			{
				cout << std::setw(mx_len + 1) << els.operator[](i* cols + j) << ' ';
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "Matrix doesn't exist\n";
	}
}

int Matrix::get_cols()
{
	return cols;
}

int Matrix::get_rows()
{
	return rows;
}

double Matrix::get_elem(int row, int col)
{
	if (Matrix::get_cols() > col && Matrix::get_rows() > row) return els[row * cols + col];
	else return numeric_limits<double>::min();
}

double Matrix::trace()
{
	double trace = 0;
	if (rows == cols)
	{
		for (int i = 0; i < rows; i++)
		{
			trace += Matrix::get_elem(i, i);
		}
		return trace;
	}
	else return numeric_limits<double>::min();
}

bool Matrix::mult_by_num(double num)
{
	for (size_t i = 0; i < rows * cols; i++)
	{
		els[i] *= num;
	}

	return true;
}

Matrix Matrix::mult_by_matr(Matrix* matr)
{
	Matrix result;

	result.els.resize(rows * matr->cols);
	result.cols = matr->cols;
	result.rows = rows;

	if (cols == matr->rows)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t row = 0; row < matr->cols; row++)
			{
				for (size_t col = 0; col < cols; col++)
				{
					result.els[i * matr->cols + row] += els[i * cols + col] * matr->els[col * matr->cols + row];
				}
			}
		}
	}
	else
	{
		result.cols = 0;
		result.rows = 0;
		return result;
	}
	return result;
}

Matrix Matrix::mult_by_matr(vector<double>* matr_els)
{
	int size = int(matr_els->size());
	Matrix matr = service_mult_matr(this->cols, matr_els, size);

	return this->mult_by_matr(&matr);
}

Matrix Matrix::mult_by_matr(vector<double>* matr_els, int size)
{
	Matrix matr = service_mult_matr(this->cols, matr_els, size);

	return this->mult_by_matr(&matr);
}

bool Matrix::sum(Matrix* matr)
{
	if (matr->cols != cols || matr->rows != rows) return false;

	for (size_t i = 0; i < rows * cols; i++)
	{
		els[i] += matr->els[i];
	}

	return true;
}

bool Matrix::sum(vector<double>* matr_els)
{
	int size = int(matr_els->size());
	Matrix matr = service_sum_matr(this->rows, matr_els, size);

	return this->sum(&matr);
}

bool Matrix::sum(vector<double>* matr_els, int size)
{
	Matrix matr = service_sum_matr(this->rows, matr_els, size);

	return this->sum(&matr);
}

double Matrix::det() // if the matrix is larger than 50x50 long double is missing
{
	// if the matrix isn't square
	if (rows != cols) return numeric_limits<double>::min();

	// if a one-to-one matrix
	if (rows == 1) return els[0];

	// if a two-by-two matrix
	if (rows == 2) return els[0] * els[3] - els[1] * els[2];

	// if a n-to-n matrix
	Matrix new_matr;
	vector<double> new_els;
	double tmp = 0, tmp_row = 0;
	long double sum_main_dgl = 0, sum_side_dgl = 0;

	new_matr.els.resize((rows * 2 - 1) * cols);
	new_matr.rows = rows * 2 - 1;
	new_matr.cols = cols;
	new_els.resize((rows * 2 - 1) * cols);
	new_els = els;
	for (size_t i = 0; i < ((rows * 2 - 1) * cols) - (rows * cols); i++) new_els.push_back(els[i]);
	new_matr.els = new_els;

	// The sum for the main diagonal
	for (size_t shift = 0; shift < rows; shift++)
	{
		tmp_row = double(shift);
		tmp = 1;
		for (size_t col = 0; col < rows; col++)
		{
			tmp *= new_matr.els[unsigned __int64(tmp_row * cols + col)];
			tmp_row++;
		}
		sum_main_dgl += tmp;
	}

	// The sum for the side diagonal
	for (size_t shift = 0; shift < rows; shift++)
	{
		tmp_row = double(shift);
		tmp = 1;
		for (int col = cols; col > 0; col--)
		{
			tmp *= new_matr.els[unsigned __int64(tmp_row * cols + col)];
			tmp_row++;
		}
		sum_side_dgl += tmp;
	}

	return sum_main_dgl - sum_side_dgl;
}