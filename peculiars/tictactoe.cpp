#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

//VERSION 1.1

void initialize_board(char board[3][3]);
void print_board(char board[3][3]);
void get_player_data(string &player_one, string &player_two);
bool who_goes_first(string player_one, string player_two);
void get_move(const char piece, char board[3][3], int &row, int &col);
bool check_win(const char x, const char o, char board[3][3], string player_one, string player_two);
void set_piece(const char piece, char board[3][3], int row, int col);

int main()
{
  char board[3][3];
  string player_one, player_two;
  bool player_one_turn = false;
  bool done = false;
  int row = 0;
  int col = 0;

  initialize_board(board);
  get_player_data(player_one, player_two);
  player_one_turn = who_goes_first(player_one, player_two);

  while(!done)
  {
    print_board(board);
    if(player_one_turn == true)
    {
      get_move('X', board, row, col);
      set_piece('X', board, row, col);
      player_one_turn = false;
    }
    else
    {
      get_move('O', board, row, col);
      set_piece('O', board, row, col);
      player_one_turn = true;
    }

    done = check_win('X', 'O', board, player_one, player_two);
  }

  return 0;
}

void set_piece(const char piece, char board[3][3], int row, int col)
{
  board[row-1][col-1] = piece;
}

void get_move(const char piece, char board[3][3], int &row, int &col)
{
  cout << "Enter row: ";
  cin >> row;
  while(row < 1 || row > 3)
  {
    cout << "Enter a valid row (1-3): ";
    cin >> row;
  }

  cout << "Enter column: ";
  cin >> col;
  while(col < 1 || col > 3)
  {
    cout << "Enter a valid column (1-3): ";
    cin >> col;
  }

  while(board[row-1][col-1] != '-')
  {
    cout << "Error: A piece already exists there. Please try again." << endl;
    cout << "Enter row: ";
    cin >> row;
    while(row < 1 || row > 3)
    {
      cout << "Enter a valid row (1-3): ";
      cin >> row;
    }

    cout << "Enter column: ";
    cin >> col;
    while(col < 1 || col > 3)
    {
      cout << "Enter a valid column (1-3): ";
      cin >> col;
    }
  }
}

bool check_win(const char x, const char o, char board[3][3], string player_one, string player_two)
{
  bool value;
  char winner;

  if((board[0][0] == x && board[0][1] == x && board[0][2] == x) ||
     (board[1][0] == x && board[1][1] == x && board[1][2] == x) ||
     (board[2][0] == x && board[2][1] == x && board[2][2] == x))
  {
    value = true;
    winner = x;
  }
  else if((board[0][0] == x && board[1][0] == x && board[2][0] == x) ||
          (board[0][1] == x && board[1][1] == x && board[2][1] == x) ||
          (board[0][2] == x && board[1][2] == x && board[2][2] == x))
  {
    value = true;
    winner = x;
  }
  else if((board[0][0] == x && board[1][1] == x && board[2][2] == x) ||
          (board[0][2] == x && board[1][1] == x && board[2][0] == x))
  {
    value = true;
    winner = x;
  }
  else if((board[0][0] == o && board[0][1] == o && board[0][2] == o) ||
     (board[1][0] == o && board[1][1] == o && board[1][2] == o) ||
     (board[2][0] == o && board[2][1] == o && board[2][2] == o))
  {
    value = true;
    winner = o;
  }
  else if((board[0][0] == o && board[1][0] == o && board[2][0] == o) ||
          (board[0][1] == o && board[1][1] == o && board[2][1] == o) ||
          (board[0][2] == o && board[1][2] == o && board[2][2] == o))
  {
    value = true;
    winner = o;
  }
  else if((board[0][0] == o && board[1][1] == o && board[2][2] == o) ||
          (board[0][2] == o && board[1][1] == o && board[2][0] == o))
  {
    value = true;
    winner = o;
  }
  else
  {
    value = false;
  }

  if(value == true)
  {
    print_board(board);
    if(winner == x)
    {
      cout << player_one << " wins!" << endl;
    }
    else if (winner == o)
    {
      cout << player_two << " wins!" << endl;
    }
  }

  return value;
}

bool who_goes_first(string player_one, string player_two)
{
  if(player_one > player_two)
  {
    cout << player_one << " goes first!" << endl;
    return true;
  }
  else
  {
    cout << player_two << " goes first!" << endl;
    return false;
  }
}

void get_player_data(string &player_one, string &player_two)
{
  cout << "Enter player one's name: ";
  getline(cin, player_one);

  cout << "Enter player two's name: ";
  getline(cin, player_two);
  while(player_two == player_one)
  {
    cout << "Player names cannot be the same." << endl;
    cout << "Please enter a different name, player two." << endl;
    cout << "Name: ";
    getline(cin, player_two);
  }
}

void print_board(char board[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

void initialize_board(char board[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      board[i][j] = '-';
    }
  }
}
