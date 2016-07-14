#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int my_atoi(string buffer, int i);

int main()
{
  string buffer;

  cout << "Enter the string you want to convert to an integer:";
  cin >> buffer;

  for(int i = 0; i < buffer.size(); i++)
  {
    while(buffer[i] != '\0')
    {
      cout << my_atoi(buffer, i);
    }

  }
  return 0;
}

int my_atoi(string buffer, int i)
{
  return static_cast<int>(buffer[i]);
}
