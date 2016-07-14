#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  for(int i = 0; i != 30; i++)
  {
    cout << "Number: " << i << endl;
    cout << "Square: " << i * i << endl;
    cout << "Cube: " << i * i * i << endl;
    cout << "Cuartic: " << i * i * i * i << endl;
    cout << "Fifth: " << i * i * i * i * i << endl;
    cout << endl << endl;
  }
}
