#include <iostream>

using namespace std;

int main()
{
  int A = 10845;

  for(int i = 0; i < A; i++)
  {
    if(A % i == 0)
    {
      cout << i << endl;
    }
  }

  return 0;
}
