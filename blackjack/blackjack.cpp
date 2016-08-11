#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Deck
{
  public:
    void shuffle();

  private:


}

void Deck::shuffle()
{
  cout << "shuffling deck" << endl;
}

int main()
{
  Deck deck;

  deck.shuffle();

  return 0;
}
