/*
  

*/

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
  char c;

  //cout << "Welcome to the /name/ interpreter." << endl;
  //cout << "Enter the name of the file you would like to interpret: ";
  //getline(cin, file_name);
  in.open("example.txt");

  //ignore single and multi-lined comments
  while(in.get(c))
  {
    if(c == '@')
    {
      while(c != '\n')
      {
        in.get(c);
      }
    }
    else if(c == '\n')
    {
      //effectively takes all spacing \n's out
    }
    else if(c == '#')
    {
      in.get(c);
      if(c == ' ')
      {

      }
      else
      {
        cout << "Your # declaration "
      }


    }
    else
    {
      cout << c;
    }
  }

  in.close();

  return 0;
}
