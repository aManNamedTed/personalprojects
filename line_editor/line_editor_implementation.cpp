#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "line_editor_header.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::getline;
using std::setw;

void line_editor_menu()
{
  bool done = false;
  int option = 0;

  while(!done)
  {
    cout << "Welcome to David Amante's Super Line Editor!" << endl << endl;
    cout << "Please select from the options below:" << endl;
    cout << "1: Create a new file" << endl;
    cout << "2: Open an existing file" << endl;
    cout << "3: Exit" << endl;
    cin >> option;

    while(option < 1 || option > 3)
    {
      cout << "Invalid choice, please try again." << endl;
      cin >> option;
    }
    switch(option)
    {
      case 1:
        create_new_file();
        break;
      case 2:
        open_new_file();
        break;
      case 3:
        cout << endl << "Thank you for using David Amante's Super Line Editor!" << endl << endl;
        done = true;
        break;
    }
  }
}
void create_new_file()
{
  string file_name;
  vector<string> program;
  ofstream out;

  cout << "Enter what you want to name your new file as: ";
  cin >> file_name;

  out.open(file_name.c_str());

  //initializing new file with lines
  for(int i = 0; i < 5; i++)
  {
    program.push_back("//initialization buffer");
  }

  write_menu(program, file_name);

  out.close();
}

void open_new_file()
{
  string file_name, line;
  vector<string> program;
  ifstream in;
  ofstream out;

  cout << "Enter the file you'd like to open and edit: ";
  cin >> file_name;

  if(in.fail())
  {
    cout << "File does not exist. Exiting..." << endl;
    exit(1);
  }
  else
  {
    in.open(file_name.c_str());

    while(getline(in, line))
    {
      program.push_back(line);
    }

    in.close();

    write_menu(program, file_name);
  }
}

void write_menu(vector<string> &program, string file_name)
{
  int option = 0;

  while(option != 4)
  {
    print_program(program);

    cout << "Choose from the menu below:" << endl;
    cout << "1: Insert Text -- Accepts one line of input, then asks the line number you want to insert the line before." << endl;
    cout << "2: Append Text -- Accepts from a character to a line of input, then asks the three characters you want it to be appended to." << endl;
    cout << "3: Delete Lines -- Asks for line number, or a range of line numbers to delete." << endl;
    cout << "4: Write File -- Saves all new additions, exits file editing, and returns to main menu." << endl;
    cin >> option;

    while(option < 1 || option > 4)
    {
      cout << "Invalid choice, please try again." << endl;
      cin >> option;
    }

    switch(option)
    {
      case 1:
        insert_text(program);
        break;
      case 2:
        append_text(program);
        break;
      case 3:
        delete_lines(program);
        break;
      case 4:
        write_program(program, file_name);
        break;
    }
  }
}

void insert_text(vector<string> &program)
{
  vector<string>::iterator it;
  int line_number;
  string line;

  cout << "Enter the line of text you would like to insert: ";
  cin.ignore(1, '\n');
  getline(cin, line);

  cout << "Enter the line number you want to insert the text before: ";
  cin >> line_number;
  while(line_number < 1 || line_number > program.size())
  {
    cout << "Invalid line number, please refer to the above output, and enter a valid line number.";
    cin >> line_number;
  }

  program.insert(program.begin()+line_number-1, line);
}

void append_text(vector<string> &program)
{
  string appendage, line;
  int line_number, nth_character;

  //get line number
  cout << "Enter the line number you want to append: ";
  cin >> line_number;
  while(line_number < 1 || line_number > program.size())
  {
    cout << "Invalid line number, please refer to the above output, and enter a valid line number: ";
    cin >> line_number;
  }

  //get the text user wants to append
  cout << line_number << " " << program[line_number-1] << endl;
  cout << "Enter the text you want to append to line " << line_number << ": ";
  cin.ignore(1, '\n');
  getline(cin, appendage);

  //print the line, and ask for where to append the new appendage
  line = program[line_number-1];
  for(int i = 0; i < line.size(); i++)
  {
    if(i < 9)
    {
      cout << line[i] << " ";
    }
    else if(i > 9 || i < 100)
    {
      cout << line[i] << "   ";
    }
    else if(i > 100)
    {
      cout << line[i] << "   ";
    }
  }

  cout << endl;

  for(int i = 0; i < line.size(); i++)
  {
    if(i < 10)
    {
      cout << i+1 << " ";
    }
    else if(i > 10 || i < 101)
    {
      cout << i+1 << "  ";
    }
    else if(i > 101)
    {
      cout << i+1 << "   ";
    }
  }

  cout << endl << "Enter the nth character you want to append your change before: ";
  cin >> nth_character;
  while(nth_character < 0 || nth_character > line.size())
  {
    cout << "Invalid number, please refer to the above output, and enter a valid nth character number: ";
    cin >> nth_character;
  }

  line.insert(nth_character-1, appendage);

  cout << line << endl;

  program.erase(program.begin()+line_number-1);
  program.insert(program.begin()+line_number-1, line);
}

void delete_lines(vector<string> &program)
{
  int range_start = 0;
  int range_end = 0;
  int line_number = 0;
  int option = 0;

  cout << "Choose between the following:" << endl;
  cout << "1: Delete a single line" << endl;
  cout << "2: Delete multiple lines" << endl;
  cin >> option;
  while(option < 1 || option > 2)
  {
    cout << "Invalid choice, please try again." << endl;
    cin >> option;
  }

  switch(option)
  {
    case 1:
      print_program(program);
      cout << "Enter the line number of the line you would like to delete: ";
      cin >> line_number;
      while(line_number < 1 || line_number > program.size())
      {
        cout << "Invalid line number, please refer to the above output, and enter a valid line number: ";
        cin >> line_number;
      }

      program.erase(program.begin()+line_number-1);
      break;

    case 2:
      print_program(program);
      cout << "Enter the line number of the beginning of the range of lines you want to delete: ";
      cin >> range_start;
      while(range_start < 1 || range_start > program.size())
      {
        cout << "Invalid line number, please refer to the above output, and enter a valid line number: ";
        cin >> range_start;
      }

      cout << "Enter the line number of the end of the range of lines you want to delete: ";
      cin >> range_end;
      while(range_end <= range_start || range_end > program.size())
      {
        cout << "Invalid line number, please refer to the above output, and enter a valid line number: ";
      }

      for(int i = range_start; i <= range_end; i++)
      {
        program.erase(program.begin()+i-1);
      }
      break;
  }
}

void write_program(vector<string> program, string file_name)
{
  ofstream out;

  out.open(file_name.c_str());
  for(int i = 0; i < program.size(); i++)
  {
    out << program[i] << endl;
  }

  cout << "Writing to file, " << file_name << ", successful!" << endl << endl;
}

void print_program(vector<string> program)
{
  cout << endl << "START FILE=====================" << endl;
  for(int i = 0; i < program.size(); i++)
  {
    cout << i+1 << ' ' << program[i] << endl;
  }
  cout << "END FILE=======================" << endl << endl;
}
