#include <iostream>

using namespace std;

int pollard(int num, int i);
int factorial(int k);

int main()
{
  int num;
  cout << "Enter what number you want to factor: ";
  cin >> num;

  for(int i = 0; i < 5; i++)
  {
    cout << pollard(num, i);

  }

  return 0;
}

int pollard(int num, int i)
{
  return 2 * factorial(i) - 1;
}

int factorial(int k)
{
  if(k != 1)
    return (k * factorial(k-1));
}
