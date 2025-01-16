// Merge Sorted vectors 
// Find the errors in the code for a seamless code run

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
    while (i <= a.size()) { 
        result.push_back(a[i++]);
    }
    while (j <= b.size()) { 
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
