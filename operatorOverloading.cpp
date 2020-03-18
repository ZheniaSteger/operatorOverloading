//============================================================================
// Author      : Zhenia Steger
// College	   : California State University San Marcos
// Purpose     : Demonstrate operator overloading
// ============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TheMatrix;

// Prototype Functions
TheMatrix operator/(const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator-(const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator+(const TheMatrix& M1, const TheMatrix& M2);
TheMatrix operator*(const TheMatrix& M1, const TheMatrix& M2);
ifstream& operator>>(ifstream& is, TheMatrix& myMatrix);
ofstream& operator<<(ofstream& os, TheMatrix& myMatrix);
// End of prototypes

class TheMatrix
{
		friend TheMatrix operator/(const TheMatrix& M1, const TheMatrix& M2);
		friend TheMatrix operator-(const TheMatrix& M1, const TheMatrix& M2);
		friend TheMatrix operator+(const TheMatrix& M1, const TheMatrix& M2);
		friend TheMatrix operator*(const TheMatrix& M1, const TheMatrix& M2);
		friend ifstream& operator>>(const TheMatrix& M1, const TheMatrix& M2);
		friend ofstream& operator<<(const TheMatrix& M1, const TheMatrix& M2);
	public:
		int M[5][5];	// 5x5 matrix of integers

		TheMatrix();
		~TheMatrix();
};

// Default constructor
TheMatrix::TheMatrix()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			M[i][j] = 0;
}

// Default destructor
TheMatrix::~TheMatrix()
{
	// Nothing to do
}

// PURPOSE: This method asks the user to enter a file name and gets the data
//			from the file to place into the matrix. This fills up the matrix
//			with data and returns it.
ifstream& operator>> (ifstream& is, TheMatrix& myMatrix)
{
	string fileName;
	cout << "Enter a file name: " << endl;
	cin >> fileName;
	is.open(fileName.data());
	if((!is))
		cout << "The file does not exist." << endl;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			is >> myMatrix.M[i][j];
	is.close();
	return is;
}

// PURPOSE: This method prints the matrix on the screen
ofstream& operator<< (ostream& os, const TheMatrix& myMatrix)
{
	cout << "The matrix contains: " << endl;
	int j = 0;
	while(j < 5)
	{
		int i = 0;
		while(i < 5)
			{
				cout << "[" << myMatrix.M[i][j] << "]";
				i++;
			}
		cout << endl;
		j++;
	}
}

// PURPOSE: This method adds two matrices to create a new matrix containing the sum
TheMatrix operator+ (const TheMatrix& M1, const TheMatrix& M2)
{
	TheMatrix result;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			result.M[i][j] = M1.M[i][j] + M2.M[i][j];
	return result;
}

// PURPOSE: This method subtracts two matrices to create a new matrix containing the difference
TheMatrix operator- (const TheMatrix& M1, const TheMatrix& M2)
{
	TheMatrix result;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			result.M[i][j] = M1.M[i][j] - M2.M[i][j];
	return result;
}

// PURPOSE: This method multiplies two matrices to create a new matrix containing their product
TheMatrix operator* (const TheMatrix& M1, const TheMatrix& M2)
{
	TheMatrix result;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			result.M[i][j] = M1.M[i][j] * M2.M[i][j];
	return result;
}

// PURPOSE: This method divides two matrices to create a new matrix containing their quotient
TheMatrix operator/ (const TheMatrix& M1, const TheMatrix& M2)
{
	TheMatrix result;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			{
				if(M2.M[i][j] == 0)
					result.M[i][j] = 0;
				int (l) = M1.M[i][j] / M2.M[i][j];
				result.M[i][j] = l;
			}
	return result;
}

// Main method runs the program
int main()
{
	TheMatrix A, B, AddAB, MulAB, SubAB, DivAB;
	ifstream fin1, fin2;
	fin1 >> A;	// Calls the function to get info from file and load into A
	fin2 >> B;	// Calls the function to get info from file and load into B

	// call a function to operator+  to add Matrix A and B together and place the result into Matrix AddAB
	AddAB = A + B;
	// call a function to operator-  to subtract Matrix A from Matrix B  and place the result into Matrix SubAB
	SubAB = A - B;
	// call a function to operator*  to multiply Matrix A and B together and place the result into Matrix MulAB
	MulAB = A * B;
	// call a function to operator/  to divide Matrix A by matrix B and place the result into Matrix DivAB
	DivAB = A / B;

	// call the function operator<< to print matrix A
	cout << A;
	// call the function operator<< to print matrix B
	cout << B;
	// call the function operator<< to print matrix AddAB
	cout << AddAB;
	// call the function operator<< to print matrix SubAB
	cout << SubAB;
	// call the function operator<< to print matrix MulAB
	cout << MulAB;
	// call the function operator<< to print matrix DivAB
	cout << DivAB;
	return 0;
}
