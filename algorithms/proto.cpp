#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/*
		Given 2n players,
			each player has a rating of skill (1-10)
			split into two teams of n
			such that the players are divided as unfairly as possible
			show how to do this in o(nlogn) time

		so basically sort into two sets with highest possible difference between
		groups
	*/

	vector<int> players;
	players.push_back(3);
	players.push_back(4);
	players.push_back(2);
	players.push_back(7);
	players.push_back(8);
	players.push_back(10);
	players.push_back(10);
	players.push_back(7);
	players.push_back(2);
	players.push_back(3);
	players.push_back(5);
	players.push_back(1);
	players.push_back(1);
	mergesort(players);

	return 0;
}

void mergesort(vector<int> *players)
{
	cout << players.size();
}

