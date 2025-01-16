/*Solution for Probem Statement 3
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int countGoodStrings(int low, int high, int zero, int one) {
    const int MOD = 1e9 + 7;
    vector<int> ways(high + 1, 0);
    ways[0] = 1;

    for (int length = 0; length < high; ++length) {
// Bug Fix 1: If the ways[i] == 0 implies there cannot be a way to add any strings to it, 
//we had initialised it to be ways[length] >= 0, which would bypass all the cases.
        if (ways[length] == 0) continue;
        if (length + zero <= high) {
            ways[length + zero] = ways[length + zero] + ways[length] % MOD;
        }
        if (length + one <= high) {
            ways[length + one] = ways[length + one] + ways[length] % MOD;
        }
    }

    int count = 0;
// Bug Fix 2: ways[i] means the number of possible such strings that can be possible with length i.
/// Therefore for number of strings possible inclusive of high, i <= high rather than i < high. 
    for (int i = low; i <= high; ++i) {
        count = (count + ways[i]) % MOD;
    }

    return count;   
}


int main()
{
    int low = 3, high = 5, zero = 2, one = 3;
    cout << countGoodStrings(low, high, zero, one);
    return 0;
}
