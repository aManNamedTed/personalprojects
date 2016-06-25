#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int factorial(int n)

int main()
{
  cout << factorial(3);

  return 0;
}

int factorial(int n)
{
  if(n != 1)
    return n * factorial(n-1);
}
