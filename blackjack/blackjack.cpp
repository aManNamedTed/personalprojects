#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

class Deck
{
  public:
    void shuffle();
    bool is_empty();
    void show_list();

  private:
    vector<string> card_list;
};

void Deck::show_list()
{
  for(int i = 0; i < card_list.size(); i++)
  {
    cout << card_list[i] << " ";
  }

}

bool Deck::is_empty()
{
  cout << "checking if empty" << endl;
}

void Deck::shuffle()
{
  int kings = 4;
  int queens = 4;
  int jacks = 4;
  int tens = 4;
  int nines = 4;
  int eights = 4;
  int sevens = 4;
  int sixes = 4;
  int fives = 4;
  int fours = 4;
  int threes = 4;
  int twos = 4;
  int aces = 4;

  while(card_list.size() != 52)
  {
    int num = (rand() % 14) + 1;

    if(num % 11 == 0 && aces > 0)
    {
      card_list.push_back("A");
      aces--;
    }
    else if(num % 10 == 0 && tens > 0)
    {
      card_list.push_back("10");
      tens--;
    }
    else if(num % 14 == 0 && jacks > 0)
    {
      card_list.push_back("J");
      jacks--;
    }
    else if(num % 13 == 0 && queens > 0)
    {
      card_list.push_back("Q");
      queens--;
    }
    else if(num % 12 == 0 && kings > 0)
    {
      card_list.push_back("K");
      kings--;
    }
    else if(num % 9 == 0 && nines > 0)
    {
      card_list.push_back("9");
      nines--;
    }
    else if(num % 8 == 0 && eights > 0)
    {
      card_list.push_back("8");
      eights--;
    }
    else if(num % 7 == 0 && sevens > 0)
    {
      card_list.push_back("7");
      sevens--;
    }
    else if(num % 6 == 0 && sixes > 0)
    {
      card_list.push_back("6");
      sixes--;
    }
    else if(num % 5 == 0 && fives > 0)
    {
      card_list.push_back("5");
      fives--;
    }
    else if(num % 4 == 0 && fours > 0)
    {
      card_list.push_back("4");
      fours--;
    }
    else if(num % 3 == 0 && threes> 0)
    {
      card_list.push_back("3");
      threes--;
    }
    else if(num % 2 == 0 && twos > 0)
    {
      card_list.push_back("2");
      twos--;
    }
  }
}

int main()
{
  srand(time(NULL));
  Deck deck;

  deck.shuffle();
  deck.show_list();
  deck.is_empty();

  return 0;
}
