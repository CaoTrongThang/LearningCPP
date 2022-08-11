#include "mygames.h"
#include <iostream>

using namespace std;

bool OverUnder(int *money)
{
    cout << "YOUR MONEY: " << *money << endl;

    srand(time(NULL));

    int betMoney = 0;

    int dice1[6] = {1, 2, 3, 4, 5, 6};
    int dice2[6] = {1, 2, 3, 4, 5, 6};
    int dice3[6] = {1, 2, 3, 4, 5, 6};

    string OverOrUnder;

    while (true)
    {
        cout << "Enter how much money you wanna bet: ";
        cin >> betMoney;
        int result = *money - betMoney;
        if(result >= 0)
        {
            break;
        }
    }

    cout << "Over or Under: ";
    cin >> OverOrUnder;

    int randDice1 = dice1[rand() % 6];
    int randDice2 = dice2[rand() % 6];
    int randDice3 = dice3[rand() % 6];

    int result = randDice1 + randDice2 + randDice3;
    
    if(result >= 4 && result <= 10 && OverOrUnder == "under")
    {
        *money = (*money - betMoney) + (betMoney * 2);
    } else if(result >= 11 && result <= 17 && OverOrUnder == "over")
    {
        *money = (*money - betMoney) + (betMoney * 2);
    } else if (result >= 4 && result <= 10 && OverOrUnder == "over")
    {
        *money -= betMoney;
    } else if(result >= 11 && result <= 17 && OverOrUnder == "under")
    {
        *money -= betMoney;
    }

    return true;
}