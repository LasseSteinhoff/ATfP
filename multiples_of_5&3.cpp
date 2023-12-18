//
// Created by LasseSteinhoff on 12/18/2023.
//
#include <iostream>
#include <cassert>

using namespace std;

int find_multiples_of_5_3(int n)
{
    if(n > 2 ) {
        int multipler = 1;
        int sum = 0;
        int multiple_of_5;
        int multiple_of_3;

        while (true) {
            multiple_of_5 = 5 * multipler;
            multiple_of_3 = 3 * multipler++;
            if (multiple_of_5 < n)
                sum += multiple_of_5;
            if (multiple_of_3 < n && multiple_of_3 % 15 != 0)
                sum += multiple_of_3;
            if(n < multiple_of_3)
                break;
        }
        return sum;
    }
    else
        return 0;
}

int main()
{
    cout << "Mulitples of 5 & 3 until threshold n" << endl;
    cout << find_multiples_of_5_3(1000) << endl;
    assert(23 == find_multiples_of_5_3(10));
    assert(0 == find_multiples_of_5_3(2));
    return 0;
}