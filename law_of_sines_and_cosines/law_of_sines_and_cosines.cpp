/*
  Name: David Amante;
  Created: July 19 2016
  Project: Create a program that can calculate the law of sines. Use law of cosines if values permit.
           Make sure these restrictions are acknowledged:
    - No negative answers. If negative, respond with why, either
    - no angles >= 178 because the triangle needs 3 angles, and the other two's lowest angle value can be 1 degree.
*/

//libraries for function use
#include <iostream>
#include <cmath>

//'namespace syntax' which is essentially an extended library for further function use
using std::cin;
using std::cout;
using std::endl;
using std::sin;
using std::asin;
using std::cos;
using std::acos;
using std::sqrt;

//declaring constants and setting them to a value
const double PI = 3.14159265;
const double ONE_EIGHTY = 180.0;

int main()
{
  bool valid = false;
  //lowercase for sides
  //double is a data type that uses enough data to show decimals
  double a = 0;
  double b = 0;
  double c = 0;

  //uppercase for angles, initialized to flag the input for values while loop
  double A = 100;
  double B = 100;
  double C = 100;

  //'cout' prints whatever is between the " " to the screen for the user to read
  cout << "Law of Sines/Law of Cosines" << endl;
  cout << "Enter 0 if you do not know the value." << endl;

  //get side values;
  //make sure zeroes and impossible triangles cannot be input

  while(valid == false)
  {
    cout << "Side a: ";
    cin >> a;
    cout << "Side b: ";
    cin >> b;
    cout << "Side c: ";
    cin >> c;

    //checks for invalid triangles
      //a + b >= c is valid
      //a + b < c is invalid
    if(a > b && a > c)
    {
      if(b + c >= a)
      {
        valid = true;
      }
      else if(b + c < a)
      {
        valid = false;
      }
    }
    else if(b > a && b > c)
    {
      if(a + c >= b)
      {
        valid = true;
      }
      else if(a + c < b)
      {
        valid = false;
      }
    }
    else if(c > a && c > b)
    {
      if(a + b >= c)
      {
        valid = true;
      }
      else if(a + b < c)
      {
        valid = false;
      }
    }
    if(valid == false)
    {
      cout << "Values are invalid." << endl;
      cout << "Please check your values and try again." << endl;
    }
  }

  //get angle values
  //'while([...])' is a loop that says, while these conditions are true, keep doing whatever is between the {}s
  while(A + B + C > 180)
  {
    cout << "Angle A: ";
    cin >> A;
    cout << "Angle B: ";
    cin >> B;
    cout << "Angle C: ";
    cin >> C;

    //'if([...])' is a loop that checks if the conditions in the () is/are true, if it is true, do whatever is in the {}s
    if(A + B + C > 180)
    {
      cout << "Angles are invalid." << endl;
      cout << "Please check your values and try again." << endl;
      cout << endl;
    }
  }

  //this while loop keeps cycling through the {}s until every value is non-zero
  while(a == 0 || b == 0 || c == 0 || A == 0 || B == 0 || C == 0)
  {
    //law of cosines: SSS
    if(a != 0 && b != 0 && c != 0)
    {
      A = acos(((c * c) - (a * a) + (b * b)) / (2 * b * c)) * ONE_EIGHTY / PI;
      B = acos(((c * c) + (a * a) - (b * b)) / (2 * c * a)) * ONE_EIGHTY / PI;
      C = acos((-(c * c) + (a * a) + (b * b)) / (2 * a * b)) * ONE_EIGHTY / PI;
    }

    //law of cosines: SAS
    else if(C != 0 && a != 0 && b != 0)
    {
      a = sqrt(((b * b) + (c * c) - 2 * b * c * (cos(A * PI) / ONE_EIGHTY)));
      b = sqrt(((a * a) + (c * c) - 2 * a * c * (cos(B * PI) / ONE_EIGHTY)));
      c = sqrt(((a * a) + (b * b) - 2 * a * b * (cos(C * PI) / ONE_EIGHTY)));
    }

    //find missing sides
    //the (a == 0 && B != 0 && b!= 0) is saying, if side a == 0--meaning if it is unknown--
    //AND angle B != 0--is known--AND side b != 0--is also known--to do whatever is in the {}s
    //the || means or. so either the left side of the ||, OR the right side has to be true to
    //do whatever is in the {}s
    //law of sines
    else if((a == 0 && B != 0 && b != 0) || (a == 0 && C != 0 && c != 0))
    {
      //checks to see whether the B/b's are known or the C/c's are known
      if(B != 0 && b != 0)
      {
        a = (b * sin(A * PI / ONE_EIGHTY) / sin(B * PI / ONE_EIGHTY));
      }
      if(C != 0 && c != 0)
      {
        a = (c * sin(A * PI / ONE_EIGHTY) / sin(C * PI / ONE_EIGHTY));
      }
    }
    else if((b == 0 && C != 0 && c != 0) || (b == 0 && A != 0 && a != 0))
    {
      if(A != 0 && a != 0)
      {
        b = (a * sin(B * PI / ONE_EIGHTY) / sin(A * PI / ONE_EIGHTY));
      }
      if(C != 0 && c != 0)
      {
        b = (c * sin(B * PI / ONE_EIGHTY) / sin(C * PI / ONE_EIGHTY));
      }
    }
    else if((c == 0 && A != 0 && a != 0) || (c == 0 && B != 0 && b != 0))
    {
      if(A != 0 && a != 0)
      {
        c = (a * sin(C * PI / ONE_EIGHTY) / sin(A * PI / ONE_EIGHTY));
      }
      if(A != 0 && a != 0)
      {
        c = (b * sin(C * PI / ONE_EIGHTY) / sin(B * PI / ONE_EIGHTY));
      }
    }

    //find missing angles
    if(A == 0 && B != 0 && C != 0)
    {
      A = ONE_EIGHTY - (C + B);
    }
    if(B == 0 && C != 0 && A != 0)
    {
      B = ONE_EIGHTY - (A + C);
    }
    if(C == 0 && A != 0 && B != 0)
    {
      C = ONE_EIGHTY - (A + B);
    }
  }

  //outputs the values for each side
  cout << "Values================" << endl;
  cout << "Side a: " << a << endl;
  cout << "Side b: " << b << endl;
  cout << "Side c: " << c << endl;
  cout << "Angle A: " << A << endl;
  cout << "Angle B: " << B << endl;
  cout << "Angle C: " << C << endl;
  return 0;
}
