/*Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int countGoodStrings(int low, int high, int zero, int one) {
    const int MOD = 1e9 + 7;
    vector<int> ways(high + 1, 0);
    ways[0] = 1;

    for (int length = 0; length < high; ++length) {
        if (ways[length] < 0) continue;
        if (length + zero <= high) {
            ways[length + zero] = ways[length + zero] + ways[length] % MOD;
        }
        if (length + one <= high) {
            ways[length + one] = ways[length + one] + ways[length] % MOD;
        }
    }

    int count = 0;
    for (int i = low; i < high; ++i) {
        count = (count + ways[i]) % MOD;
    }

    return count;   
}


int main()
{
    int low = 3, high = 3, zero = 1, one = 1;
    cout << countGoodStrings(low, high, zero, one);
    return 0;
}
