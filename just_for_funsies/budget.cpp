#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::pair;
using std::make_pair;
using std::setw;
using std::setfill;
using std::setprecision;
using std::right;

void print_list(const vector<pair<string, double> > budget_list);
void add_entry(vector<pair<string, double> > &budget_list);
void edit_entry(vector<pair<string, double> > &budget_list);
void delete_entry(vector<pair<string, double> > &budget_list);
void quit();

int main()
{
  vector<pair<string, double> > budget_list;
  int option = 0;
  bool done = false;

  while(!done)
  {
    print_list(budget_list);
    cout << "Select an option" << endl;
    cout << "1: Add an entry" << endl;
    cout << "2: Edit an entry" << endl;
    cout << "3: Delete an entry" << endl;
    cout << "4: Quit" << endl;
    cout << ">>> ";
    cin >> option;
    while(option < 0 || option > 2)
    {
      cout << "Invalid entry. Please try again." << endl;
      cout << ">>> ";
      cin >> option;
    }

    switch(option)
    {
      case 1:
        add_entry(budget_list);
        break;
      case 2:
        edit_entry(budget_list);
        break;
      case 3:
        delete_entry(budget_list);
        break;
      case 4:
        quit();
        break;
    }
  }
  cout << "Goodbye!" << endl;

  return 0;
}

void add_entry(vector<pair<string, double> > &budget_list)
{
  string item;
  double price;
  cout << "Enter the item name: ";
  cin.ignore(1, '\n');
  getline(cin, item);

  cout << "Enter the price of the item: $";
  cin >> price;

  budget_list.push_back(make_pair(item, price));
}

void edit_entry(vector<pair<string, double> > &budget_list)
{
  string item;
  char response = 'n';

  cout << "Enter the name of the entry you want to edit: ";
  getline(cin, item);

  for(int i = 0; i < budget_list.size(); i++)
  {
    if(item == budget_list[i].first)
    {
      cout << "Would you like to edit the name?(Y/N)" << endl;
      cin >> response;
      if(response == 'y' || response == 'Y')
      {
        cout << "Enter the new name: ";
        getline(cin, item);
        budget_list[i].first = item;
      }

      response = 'n';
      cout << "Would you like to edit the price?(Y/N)" << endl;
      cin >> response;
      if(response == 'y' || response == 'Y')
      {
        cout << "Enter the new price: ";
        cin >> budget_list[i].second;
      }
    }
  }
}

void delete_entry(vector<pair<string, double> > &budget_list)
{
  string item;

  cout << "Enter the name of the item you want to delete: ";
  cin.ignore(1, '\n');
  getline(cin, item);

  for(int i = 0; i < budget_list.size(); i++)
  {
    if(item == budget_list[i].first)
    {
      budget_list.erase(budget_list.begin() + i);
    }
  }
}

void quit()
{
  cout << "Good job on budgeting!" << endl;
}

void print_list(const vector<pair<string, double> >budget_list)
{
  double grand_total = 0;

  cout << "====================" << endl;
  for(int i = 0; i < budget_list.size(); i++)
  {
    cout << budget_list[i].first << ": \t\t" << "$" << budget_list[i].second << endl;
    grand_total += budget_list[i].second;
  }
  if(budget_list.size() > 0)
  {
    cout << "...................." << endl;
    cout << "Total: \t\t" << "$" << grand_total << endl;
    cout << "====================" << endl;
  }
}

/*
V1.1 Draft
=======================================
Allow:
  add Item,price
  edit item,price

Item...............$0.00
Item...............$0.00
Item...............$0.00
Item...............$0.00
Item...............$0.00
Grand Total........$0.00




V1.0 Draft
=======================================
Groceries:
  Fridge Food................$0.00
  Eating Out.................$0.00
    Groceries subtotal..........$0.00

Living:
  Phone.......................$0.00
  Rent........................$0.00
  Electricity.................$0.00
  Gas/Utilities...............$0.00
  Water.......................$0.00
    Living subtotal.............$0.00

Grand Total....................$00.00

*/
