#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::getchar;
using std::setw;

int main()
{
  ifstream in;
  char c;

  const int console_width = 70;

  cout << setw(console_width / 2) << "Welcome." << endl;
  getchar();
  cout << setw(console_width / 3) << "Password: " << endl;

  in.open("file.txt");

  if(in.fail())
  {
    cout << "File does not exist." << endl;
    exit(1);
  }

  while(in.get(c))
  {
    cout << c+1;
  }



  in.close();

  return 0;
}
