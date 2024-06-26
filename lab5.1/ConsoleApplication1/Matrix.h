#pragma once
#pragma once
#include <vector>


using std::vector;


/// <summary>
/// The class for working with matrices
/// </summary>
class Matrix
{
private:
	int rows, cols;
	vector <double> els; // Matrix elements
public:
	/// <summary>
	/// Constructor
	/// </summary>
	Matrix();

	/// <summary>
	/// Destructor
	/// </summary>
	~Matrix();

	/// <summary>
	/// Matrix input function
	/// </summary>
	/// <param name="rows">- Number of rows</param>
	/// <param name="cols">- Number of columns</param>
	/// <param name="els">- Matrix elements</param>
	/// <returns>True if the input is successful, otherwise false</returns>
	bool input(int rows, int cols, vector <double>* els);

	/// <summary>
	/// Function to enter a matrix of the given &lt;rows&gt; &lt;cols&gt;
	///	filled with random values with an upper limit &lt;up_to&gt;
	///	and a lower limit of ten in the degree of the number of
	///	characters of the upper limit minus one.
	/// </summary>
	/// <param name="rows">- Number of rows</param>
	/// <param name="cols">- Number of columns</param>
	/// <param name="up_to">- Max random value</param>
	/// <returns>True if the input is successful, otherwise false</returns>
	bool rand_input(int rows, int cols, int up_to);

	/// <summary>
	/// Matrix output function
	/// </summary>
	void print();

	/// <summary>
	/// Function for getting the number of columns of the matrix
	/// </summary>
	/// <returns>Number of matrix columns</returns>
	int get_cols();

	/// <summary>
	/// Function for getting the number of rows of the matrix
	/// </summary>
	/// <returns>Number of matrix rows</returns>
	int get_rows();

	/// <summary>
	/// Function for getting the value of a matrix element with &lt;row&gt; and &lt;column&gt; coordinates
	/// </summary>
	/// <param name="row">- row number</param>
	/// <param name="col">- column number</param>
	/// <returns>The value of the matrix with &lt;row&gt; and &lt;column&gt; coordinates if exist, otherwise min double</returns>
	double get_elem(int row, int col);

	/// <summary>
	/// Function to get the trace of a matrix
	/// </summary>
	/// <returns>The trace of a matrix if it's square, otherwise min double</returns>
	double trace();

	/// <summary>
	/// Matrix multiplication function by a number
	/// </summary>
	/// <param name="num"> - the number by which the matrix will be multiplied</param>
	/// <returns>true if the multiplication was successful, otherwise false</returns>
	bool mult_by_num(double num);

	/// <summary>
	/// Matrix to matrix multiplication function
	/// </summary>
	/// <param name="matr">- matrix by which the first matrix will be multiplied</param>
	/// <returns>The object of this class</returns>
	Matrix mult_by_matr(Matrix* matr);

	/// <summary>
	/// The function of adding two matrices. The matrix to which the method is applied will be overwritten.
	/// </summary>
	/// <param name="matr">- matrix that will be added by the applied</param>
	/// <returns>true if the addition was successful, otherwise false</returns>
	bool sum(Matrix* matr);

	/// <summary>
	/// Function for calculating the determinant of a matrix
	/// </summary>
	/// <returns>The determinant of a matrix if it is square, otherwise min double</returns>
	double det();
};