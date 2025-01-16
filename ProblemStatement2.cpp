#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, int target, vector<int> mountainArr, bool reversed) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (reversed) {
            if (mountainArr[mid] > target)
                low = mid;
            else
                high = mid;
        } else {
            if (mountainArr[mid] < target)
                low = mid;
            else
                high = mid;
        }
    }
    return low;
}

int findPeakIndex(int low, int high, vector<int> mountainArr) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mountainArr[mid] < mountainArr[mid + 1]) {
            low = mid;
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
