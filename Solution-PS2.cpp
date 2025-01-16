#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, int target, vector<int> mountainArr, bool reversed) {
// Bug fix 1: low < high and not low <= high, which might render time limit being exceeded when not taken care of.
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (reversed) {
            if (mountainArr[mid] > target)
// Bug Fix 2: low should be always initialised to variable next to the mid, so as to prevent a TLE for the while loop between 2 values.
                low = mid+1;
            else
                high = mid;
        } else {
            if (mountainArr[mid] < target)
// Bug Fix 3: low should be always initialised to variable next to the mid, so as to prevent a TLE for the while loop between 2 values.
                low = mid+1;
            else
                high = mid;
        }
    }
    return low;
}

int findPeakIndex(int low, int high, vector<int> mountainArr) {
// Bug fix 4: low < high and not low <= high, which might render time limit being exceeded when not taken care of.
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (mountainArr[mid] < mountainArr[mid + 1]) {
// Bug Fix 5: low should be always initialised to variable next to the mid, so as to prevent a TLE for the while loop between 2 values.
            low = mid+1;
        } else {
            high = mid;
        }
    }
    return low;
}

int findInMountainArray(int target, vector<int> mountainArr) {
    int length = mountainArr.size();

    int peakIndex = findPeakIndex(1, length - 1, mountainArr);

    int increasingIndex = binarySearch(0, peakIndex, target, mountainArr, false);
    if (mountainArr[increasingIndex] == target)
        return increasingIndex;

    int decreasingIndex = binarySearch(peakIndex + 1, length - 1, target, mountainArr, true);
    if (mountainArr[decreasingIndex] == target)
        return decreasingIndex;

    return -1;
}

int main() {
    vector<int> mountainArr = {0, 1, 2, 4, 2, 1};
    int target = 3;
    cout << findInMountainArray(target, mountainArr);
    return 0;
}
