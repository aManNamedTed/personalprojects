#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int factorial(int n);

int main()
{
  int row, term;

  cout << "First 5 rows of Pascal's Triangle" << endl << endl;
  cout << "Rows: Terms" << endl;
  cout << "  0 : 1" << endl;
  cout << "  1 : 1  1" << endl;
  cout << "  2 : 1  2  1" << endl;
  cout << "  3 : 1  3  3  1" << endl;
  cout << "  4 : 1  4  6  4  1" << endl;
  cout << "  5 : 1  5  10 10 5  1" << endl;
  cout << "Enter the necessary information to calculate a term of Pascal's Triangle" << endl;
  cout << "Enter row: ";
  cin >> row;
  cout << "Enter term: ";
  cin >> term;

  cout << "The term for row " << row << ", term " << term << ", is: " << (factorial(row) / (factorial(term) * factorial(row - term)));
  return 0;
}

int factorial(int n)
{
  if(n != 1)
    return n * factorial(n-1);
}
