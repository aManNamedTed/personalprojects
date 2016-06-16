// Name: David Amante
// Email: damante201@gmail.com
// Project:

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print_events(vector<string> event_list);
string get_event();

int main()
{
  vector<string> event_list;
  string event;
  cout << "Welcome to David Amante's hourly planner." << endl;

  while(!done)
  {

    print_events(event_list);



  }
  return 0;
}

void print_events(vector<string> event_list)
{
  for(int i = 0; i < event_list.size(); i++)
  {
    cout << i << ":00";
    if(i < 12)
    {
      cout << "AM: ";
    }
    else
    {
      cout << "PM: ";
    }
    cout << event_list[i];
  }
}
