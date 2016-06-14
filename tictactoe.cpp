#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

void get_player_data(string &player_one, string &player_two);
void initialize_board(char board[3][3]);
void print_board(char board[3][3]);
bool who_goes_first(const string player_one, const string player_two);
void get_move(char piece, char board[3][3]);
bool not_occupied(char board[3][3], int row, int col);
void set_piece(char board[3][3], const char piece, int row, int col);
bool check_win(char board[3][3], string player_one, string player_two);

int main()
{
  char board[3][3];
  bool done = false;
  bool player_one_turn = true;
  string player_one;
  string player_two;

  get_player_data(player_one, player_two);
  player_one_turn = who_goes_first(player_one, player_two);
  initialize_board(board);

  while(!done)
  {
    if(player_one_turn == true)
    {
      cout << player_one << "'s Turn" << endl;
      print_board(board);
      get_move('X', board);
      player_one_turn = false;
    }
    else
    {
      cout << player_two << "'s Turn" << endl;
      print_board(board);
      get_move('O', board);
      player_one_turn = true;
    }

    done = check_win(board, player_one, player_two);
  }

  return 0;
}

bool check_win(char board[3][3], string player_one, string player_two)
{
  char x = 'X';
  char o = 'O';

  //column check
  if(board[1][1] == x && board[2][1] == x && board[3][1] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }
  else if(board[1][2] == x && board[2][2] == x && board[3][2] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }
  else if(board[1][3] == x && board[2][3] == x && board[3][3] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }

  //row check
  else if(board[1][1] == x && board[1][2] == x && board[1][3] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }
  else if(board[2][1] == x && board[2][2] == x && board[2][3] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }
  else if(board[3][1] == x && board[3][2] == x && board[3][3] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }

  //diagonals check
  else if(board[1][1] == x && board[2][2] == x && board[3][3] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }
  else if(board[3][1] == x && board[2][2] == x && board[1][3] == x)
  {
    cout << player_one << " wins!!" << endl;
    return true;
  }


//player O check
  if(board[1][1] == o && board[2][1] == o && board[3][1] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }
  else if(board[1][2] == o && board[2][2] == o && board[3][2] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }
  else if(board[1][3] == o && board[2][3] == o && board[3][3] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }

  //row check
  else if(board[1][1] == o && board[1][2] == o && board[1][3] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }
  else if(board[2][1] == o && board[2][2] == o && board[2][3] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }
  else if(board[3][1] == o && board[3][2] == o && board[3][3] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }

  //diagonals check
  else if(board[1][1] == o && board[2][2] == o && board[3][3] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }
  else if(board[3][1] == o && board[2][2] == o && board[1][3] == o)
  {
    cout << player_two << " wins!!" << endl;
    return true;
  }
}

void get_move(const char piece, char board[3][3])
{
  int row = 0;
  int col = 0;
  cout << "Enter the row: ";
  cin >> row;
  while(row < 1 || row > 3)
  {
    cout << "Invalid row, remember that tic-tac-toe is played on a 3x3 board." << endl;
    cin >> row;
  }

  cout << "Enter the column: ";
  cin >> col;
  while(col < 1 || col > 3)
  {
    cout << "Invalid col, remember that tic-tac-toe is played on a 3x3 board." << endl;
    cin >> col;
  }

  while(!not_occupied(board, row, col))
  {
    cout << "Oops! A game piece is already there!" << endl;
    cout << "Refer to the board below and edit your move." << endl;
    print_board(board);
    get_move(piece, board);
  }

  set_piece(board, piece, row, col);
}

void set_piece(char board[3][3], const char piece, int row, int col)
{
  board[row-1][col-1] = piece;
}

bool not_occupied(char board[3][3], int row, int col)
{
  if(board[row][col] == '-')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool who_goes_first(const string player_one, const string player_two)
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
  cout << "Enter Player One's Name: ";
  getline(cin, player_one);

  cout << "Enter Player Two's Name: ";
  getline(cin, player_two);
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
