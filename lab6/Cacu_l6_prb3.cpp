/*Cacu Razvan lab6 prb3 
Starting from the example that uses Matrix class, consider as private attributes the matrix
given by a double pointer to allocate an array of pointers to the rows of the matrix (or, simple
pointer to the contiguous dynamic allocation of the matrix), and two private attributes of type
int for the number of rows and columns. The two-parameter constructor will dynamically
allocate space for the array by initializing the elements with 0. Implement an explicit
destructor to free up the matrix space. Define a public method void setElement(int r, int c, int
v) that will set an element with the value v, on row r and column c. Declare a global function
void readMatrix(Matrix m) that will have as parameter a matrix object that will have the
dimensions validated in main() so that the dimensions are correct if they are >=1 and <= 10.
The function will read the elements of the matrix from the keyboard (it will also use the public
method setElement()). The method displayMatrix() from the class will be defined as a global
function just like readMatrix() considering the getElement() public method. The method of
displaying a column will not validate the column number, the column being validated in
main().
Fill in the written code specific methods for:
- displaying the elements from the main diagonal of the matrix, in case the matrix is square;
if not, display a significant message.
- displaying the elements which are below the secondary diagonal.
- displaying a matrix that has identical dimensions with the original matrix and its elements
can have as possible values 0’s (if the corresponding element is less than a previously
read value of the threshold) or 1 (otherwise), and check if the matrix is rare, > = 67% of
the elements are zero);
Redo the application in which you consider the getElement() and setElement() private
methods and the readMatrix() and displayMatrix() functions, public member methods within
the class.
*/

#include<iostream>
#include<assert.h>
using namespace std;


class Matrix {
	int** m, rows, collumns;
	void setElement(int, int, int);
	int  getElement(int, int);
public: 
	Matrix(int ,int);
	~Matrix();
	void setRows(int x) { rows = x; }
	int getRows() { return rows; }
	void setCollumns(int x) { collumns = x; }
	int getCollumns() { return collumns; }
	void mainDiagonal();
	void readMatrix();
	void belowSecondaryDiagonal();
	void printMatrix();
	void rareCheck(int);
};

void readMatrix(int, int, Matrix);
void displayMatrix(int, int, Matrix);
void mainDiagonal(int, int, Matrix);
int main()
{
	int rows, collumns, value;
	cout << "Number of rows : ";
	cin >> rows;
	cout << "\nNumber of collumns : ";
	cin >> collumns;
	Matrix m1(rows, collumns);
	m1.setRows(rows);
	m1.setCollumns(collumns);
	m1.readMatrix();
	m1.printMatrix();
	//readMatrix(rows, collumns, m1);
	m1.mainDiagonal();
	m1.belowSecondaryDiagonal();
	cout << "\nSet the comparation value : ";
	cin >> value;
	m1.rareCheck(value);
}

Matrix::Matrix(int rows,int collumns)
{
	cout << "\nConstructor called... ";
	m = (int**)calloc(rows,sizeof(int*));
	for (int i{}; i < rows; i++)
		m[i] = (int*)calloc(collumns, sizeof(int));

}

Matrix::~Matrix()
{
		(m == NULL)
			? cout << "\nDestructor called for NULL pointer ! .."
			: cout << "\nDestructor called ... ";
		for (int i = 0; i < rows; ++i)
			delete[] m[i];
		delete[] m;
}

void Matrix::setElement(int v, int r , int c)
{
	this->m[c][r] = v;
}

int Matrix::getElement(int r,  int c){
	return this->m[r][c];
}

 /*void readMatrix(int rows, int collumns, Matrix x)
{
	assert(rows >= 1 && rows <= 10);
	assert(collumns >= 1 && collumns <= 10);
	int v;
	for (int i{}; i < rows; i++) {
		for (int j{}; j < collumns; j++) {
			cout << "\n Enter the element [" << i << "][" << j << "] ";
			cin >> v;
			x.setElement(v, i, j);
		}
	}
}
*/

void Matrix::readMatrix()
{
	assert(rows >= 1 && rows <= 10);
	assert(collumns >= 1 && collumns <= 10); 
	for (int i{}; i < rows; i++) {
		for (int j{}; j < collumns; j++) {
			cout << "\n Enter the element [" << i << "][" << j << "] ";
			cin >> m[i][j];
		}
	}


}
void Matrix::printMatrix()
{
	for (int i{}; i < rows; i++) {
		for (int j{}; j < collumns; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}


}
void Matrix::mainDiagonal() {

	if (rows != collumns)
		cout << "\nThe matrix is not square  ! ";
	else {
		cout << "The elements from the main diagonal are : ";
		for (int i{}; i < rows; i++) {
			for (int j{}; j < collumns; j++)
				if (i == j)
					cout <<m[i][j] << " ";
		}
	}

}
void Matrix::belowSecondaryDiagonal() {
	int aux;
	(rows >= collumns)
		? aux = collumns
		: aux = rows;
	cout << "\nThe elements below the secondary diagonal are : ";
		for (int i{}; i < rows; i++) {
			for (int j{}; j < collumns; j++)
				if (i+j>aux-1)
					cout << m[i][j] << " ";
		}
	}

void Matrix::rareCheck(int value) {

	int** arr, sum = 0;
	arr = (int**)calloc(rows,sizeof(int*));
	for (int i{}; i < rows; i++)
		arr[i] = (int*)calloc(collumns , sizeof(int));

	for (int i{}; i < rows; i++) {
		for (int j{}; j < collumns; j++)
		{
			if (m[i][j] > value)
				arr[i][j] = 1;
			cout << arr[i][j] << " ";
			sum += arr[i][j];
		 } 
		cout << endl;
	}

	float result = (float)(sum * 100 / (rows * collumns));
	(result >= 67)
		? cout << "\nThe matrix is rare ! "
		: cout << "\nThe matrix is not rare !";

}/