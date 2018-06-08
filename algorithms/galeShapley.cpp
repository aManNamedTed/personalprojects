
/*
    As per the numberphile video

    Charlotte | Elizabeth | Jane | Lydia
    ====================================
    Bingley   | Wickham   | Bing | Bing
    Darcy     | Darcy     | Wick | Wick
    Collins   | Bingley   | Darc | Darc
    Wickham   | Collins   | Coll | Coll


    Bingley | Collins | Darcy | Wickham
    ===================================
    Jane    | Jane    | Eliz  | Lydia
    Eliz    | Eliz    | Jane  | Jane
    Lydia   | Lydia   | Char  | Eliz
    Char    | Char    | Lydia | Char

    [] implement gale-shapley
    [] implement a class to solve gale-shapley
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    //make women prefs, array per woman
    char charlotte[4] = {'B', 'D', 'C', 'W'};
    char elizabeth[4] = {'W', 'D', 'B', 'C'};
    char jane[4] =      {'B', 'W', 'D', 'C'};
    char lydia[4] =     {'B', 'W', 'D', 'C'};

    //make men prefs, array per man
    char bingley[4] = {'J', 'E', 'L', 'C'};
    char collins[4] = {'J', 'E', 'L', 'C'};
    char darcy[4] =   {'E', 'J', 'C', 'L'};
    char wickham[4] = {'L', 'J', 'E', 'C'};

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            
        }
    }

    vector<string> matches;
    matches.clear();
    string match = "";
    matches.push_back{match};
    return 0;
}    
