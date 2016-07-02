/*
  Name: David Amante
  Created: 1 July 2016
  Project: Create a program that calculates the root of a cubic equation assuming delta is > 0.
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::pow;

class Rational 
{
  public:
    Rational();
    
    ostream& operator<<(const Rational r);
  
  private:
    int _num;
    int _denom;
}

Rational::Rational()
{
}

ostream& operator<<(const Rational r)
{
  cout << r._num << " / " << r.denom;
  
}

int main()
{
  int p = 6;
  int q = 7;
  
  cout << "Enter your value of P: ";
  cin >> p;

  cout << "Enter your value of Q: ";
  cin >> q;
  
  cout << "Delta = " << pow(q, 2) << " / " << 4 << " + " << pow(p, 3) << " / " << 27;
  
}
