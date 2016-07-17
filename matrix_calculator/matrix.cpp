/*
  Name: David Amante
  Date: 16 July 2016
  Project: Find solutions to a matrix of the form, (x + y = c), up to 2 equations.
           For future reference, try to solve these other matrix problems:
            - [n x n]
            - [n x m]
            - [n x n][n x n]
            - [n x n][n x m]
              *Define when ragged matrices do not compute correctly.
               There are certain matrices dimensions that can not be
               combined.

*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  double x_1 = 0;
  double y_1 = 0;
  double c_1 = 0;
  double x_2 = 0;
  double y_2 = 0;
  double c_2 = 0;
  double Dx, Dy, D;

  cout << "Enter the values of your system of equations." << endl;
  cout << "Follow the form of: " << endl;
  cout << "ax_1 + by_1 = c_1" << endl;
  cout << "ax_2 + by_2 = c_2" << endl;

  cout << "Enter a for x_1: ";
  cin >> x_1;
  cout << "Enter b for y_1: ";
  cin >> y_1;
  cout << "Enter c_1: ";
  cin >> c_1;

  cout << "Enter a for x_2: ";
  cin >> x_2;
  cout << "Enter b for y_2: ";
  cin >> y_2;
  cout << "Enter c_2: ";
  cin >> c_2;

  /*
    Of the form:
    =============
    x_1 y_1 | c_1
    x_2 y_2 | c_2
    =============
    Dx =  | c_1 y_1 | => (c_1 * y_2) - (c_2 * y_1) => Dx
          | c_2 y_2 |

    Dy =  | x_1 c_1 | => (x_1 * c_2) - (x_2 * c_1) => Dy
          | x_2 c_2 |

    Dx =  | x_1 y_1 | => (x_1 * y_2) - (x_2 * y_1) => D
          | x_2 y_2 |

    Solution = (Dx/D, Dy/D)
  */
  Dx = c_1 * y_2 - c_2 * y_1;
  Dy = x_1 * c_2 - x_2 * c_1;
  D = x_1 * y_2 - x_2 * y_1;

  cout << "The solution to your solution is," << endl;
  cout << "X = " << Dx << " / " << D << endl;
  cout << "Y = " << Dy << " / " << D << endl;
  cout << endl;
  cout << "As an ordered pair: (" << Dx << " / " << D << ", " << Dy << " / " << D << ")" << endl;

  return 0;
}
