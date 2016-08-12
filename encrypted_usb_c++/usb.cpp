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

int check_alphabet(char c);
string get_password();

int main()
{
  const int console_width = 70;
  int tries = 4;
  ifstream in;
  string pw;

  cout << setw(console_width / 2) << "Welcome." << endl;
  getchar();
  cout << setw(console_width / 3) << "Password: " << endl;
  while(pw != "poop")
  {
    cout << "You have " << tries << " tries left." << endl;
    getline(cin, pw);
  }

  check_alphabet('a');
  return 0;
}

int check_alphabet(char c)
{
  switch(c)
  {
    case 'a':
      break;
    case 'b':
      break;

  }
}
