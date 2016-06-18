// Name: David Amante
// Email: damante201@gmail.com
// Project: Make a program to plan out each hour of the day.
/* Allow:
    - Add Entry
        Hour 0-24,
    - Delete Entry
    - Print List
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::time;

void add_entry(vector<pair<int, string> > &event_list);
void delete_entry(vector<pair<int, string> > event_list);
void print_list(vector<pair<int, string> > event_list);

int main()
{
  vector<pair<int, string> > event_list;
  int option = 0;
  int command = 0;

  while(command != 4)
  {
    cout << "1: Add event entry" << endl;
    cout << "2: Delete event entry" << endl;
    cout << "3: Print event list" << endl;
    cout << "4: Quit" << endl;
    cout << "> ";
    cin >> command;

    switch(command)
    {
      case 1:
        add_entry(event_list);
        break;
      case 2:
        delete_entry(event_list);
        break;
      case 3:
        print_list(event_list);
        break;
      case 4:
        cout << "Goodbye!" << endl;
        break;
    }
  }
  return 0;
}

void add_entry(vector<pair<int, string> > &event_list)
{
  pair<int, string> event;
  event.first = -1;
  while(event.first < 0 || event.first > 24)
  {
    cout << "Enter an hour (0-24): ";
    cin >> event.first;
    cin.ignore(1, '\n');
  }
  cout << "Name your event: ";
  getline(cin, event.second);

  event_list.push_back(event);
}

void delete_entry(vector<pair<int, string> > event_list)
{

}

void print_list(vector<pair<int, string> > event_list)
{
  time_t tim;
  time(&tim);

  cout << ctime(&tim);
  cout << "=================================" << endl;
  for(int i = 0; i < 24; i++)
  {
    if(i == event_list[i].first)
    {
      if(i < 12)
      {
        cout << event_list[i].first << ":00AM -- :" << event_list[i].second << endl;
      }
      else if(i >= 12)
      {
        cout << event_list[i].first << ":00PM -- :" << event_list[i].second << endl;
      }
    }
  }
  cout << "=================================" << endl;
}
