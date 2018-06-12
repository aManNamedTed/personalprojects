
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
    int arrLen = 5;
    //make women prefs, array per woman
    char charlotte[arrLen] = {'c', 'B', 'D', 'C', 'W'};
    char elizabeth[arrLen] = {'e', 'W', 'D', 'B', 'C'};
    char jane[arrLen] =      {'j', 'B', 'W', 'D', 'C'};
    char lydia[arrLen] =     {'l', 'B', 'W', 'D', 'C'};

    //make men prefs, array per man
    char bingley[arrLen] = {'b', 'J', 'E', 'L', 'C'};
    char collins[arrLen] = {'c', 'J', 'E', 'L', 'C'};
    char darcy[arrLen] =   {'d', 'E', 'J', 'C', 'L'};
    char wickham[arrLen] = {'w', 'L', 'J', 'E', 'C'};

    string tentativeMatches[arrLen]
    return 0;
}    

