/*
  Name: David Amante;
  Created: July 14 2016
  Project: Create a program that can calculate the law of cosines. Make sure these restrictions are acknowledged:
    - No negative answers. If negative, respond with why, either
    - no angles >= 178 because the triangle needs 3 angles, and the other two's lowest angle value can be 1 degree.
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::sin;

const double PI = 3.14159265;
const double ONE_EIGHTY = 180.0;

int main()
{
  cout << "Welcome to the Law of Sines calculator." << endl;
  double angle_a = 0;
  double a = 0;

  double angle_b = 0;
  double b = 0;

  double angle_c = 0;
  double c = 0;

  char side_to_find;
  double answer = -1;

  while(answer <= 0)
  {
    cout << "Enter 0 for the value you want to find." << endl;
    cout << "value of side a: ";
    cin >> a;
    cout << "value of side b: ";
    cin >> b;
    cout << "value of side c: ";
    cin >> c;

    cout << endl;
    cout << "Enter 0 if the value is unknown for the designated side's angle." << endl;
    cout << "value of angle a:";
    cin >> angle_a;
    cout << "value of angle b:";
    cin >> angle_b;
    cout << "value of angle c:";
    cin >> angle_c;

    if(angle_a == 0)
    {
      side_to_find = 'a';
    }
    else if(angle_b == 0)
    {
      side_to_find = 'b';
    }
    else if(angle_c == 0)
    {
      side_to_find = 'c';
    }
    if(answer < 0)
    {
      cout << "Error: Negative side/angle value." << endl;
      cout << "       Please check your values." << endl;
      cout << endl << endl;
    }
    else if(answer > 0)
    {
      cout << "Side " << side_to_find << " is: " << answer << "." << endl;
    }
  }
  return 0;
}
