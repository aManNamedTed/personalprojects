#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
  ifstream in;
  string file_name;

  cout << "Welcome to the /name/ interpreter." << endl;
  cout << "Enter the name of the file you would like to interpret: ";
  getline(cin, file_name);

  

  return 0;
}
