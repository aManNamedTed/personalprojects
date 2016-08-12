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
  ifstream in2;
  string pw;
  char c;

  cout << setw(console_width / 2) << "Welcome." << endl;
  getchar();
  while(pw != "poop")
  {
    cout << setw(console_width / 3) << "Password: ";
    getline(cin, pw);
    if(pw != "poop")
    {
      cout << setw(console_width / 3) << "You have " << tries << " tries left." << endl;
      tries--;
    }
    if(tries == 0)
    {
      //input the files you want to delete
      in.open("dec1.txt");
      in2.open("dec2.txt");

      while(in.get(c))
      {
        in << "poop" << endl;
      }
      while(in2.get(c))
      {
        in2 << "poop" << endl;
      }
    }
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
