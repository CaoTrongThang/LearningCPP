#include "algorithms.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool LuhnAlgorithm(const unsigned long long &cardNumber)
{
    string cardNumberStrCopy = to_string(cardNumber);

    if (cardNumberStrCopy.length() != 16)
    {
        return false;
    }

    for (int i = 0; i < cardNumberStrCopy.length(); i++)
    {
        if (i % 2 == 0)
        {
            int result = 0;
            result = (cardNumberStrCopy[i] - '0') * 2;
            if (result > 9)
            {
                cardNumberStrCopy.replace(i, 1, to_string(result - 10 + 1));
            }
            else
            {
                cardNumberStrCopy.replace(i, 1, to_string(result));
            }
        }
    }

    int result = 0;
    for (int i = 0; i < cardNumberStrCopy.length(); i++)
    {
        result = result + (cardNumberStrCopy[i] - '0');
    }

    return result % 10 == 0;
}

void MemoryLeaksFunc()
{
    while (true)
    {
        int *p = new int[10];
    }
}

#pragma region BogoSort
void Shuffle(int a[], int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}

bool isSorted(int a[], int n)
{
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
#pragma endregion