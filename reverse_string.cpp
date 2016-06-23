#include <iostream>
#include <string>

using namespace std;

int main()
{
  string phrase;
  cout << "Enter a string to be reversed: ";
  getline(cin, phrase);

  for(int i = phrase.size()-1; i >= 0; i--)
  {
    cout << phrase[i];
  }

  return 0;
}
