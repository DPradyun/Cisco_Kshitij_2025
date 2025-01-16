// Solution for Problem Statement 1

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }
// This operator was supposedly mentioned to be <= in the buggy code.
// This would push the array out of bounds and add garbage values to the final result.
// Buggy code both in Line 21 and Line 24, changing the <= to < should work.
    while (i < a.size()) { 
        result.push_back(a[i++]);
    }
    while (j < b.size()) { // 
        result.push_back(b[j++]);
    }
    return result;
}

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
    vector<int> merged = mergeSortedArrays(a, b);
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
