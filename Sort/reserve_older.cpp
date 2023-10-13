// Author: Sardinary
// Date: 2023-08-11

#ifndef SORT_RESERVE_OLDER_CPP_
#define SORT_RESERVE_OLDER_CPP_

#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int>& nums, int l, int r, int m) {
    vector<int> temp(r - l + 1);
    int p = 0;
    int p1 = l;
    int p2 = m + 1;
    int res = 0;
    while (p1 <= m && p2 <= r) {
        res += nums[p1] > nums[p2] ? (m-p1+1) : 0;
        temp[p++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];

    }
    while (p1 <= m) {
        temp[p++] = nums[p1++];
    }
    while (p2 <= r) {
        temp[p++] = nums[p2++];
    }
    for (int i = 0; i < r - l + 1; i++) {
        nums[l + i] = temp[i];
    }
    return res;
}
int process(vector<int>& nums, int l, int r) {
    int m = l + ((r - l) >> 2);
    if (l == r) {
        return 0;
    }
    return process(nums, l, m) + process(nums, m + 1, r) + merge(nums, l, r, m);
}
int reversePairs(vector<int>& nums) {
    return  process(nums, 0, nums.size() - 1);
}




int main() {
    vector<int> v;
    v.push_back(7);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);
    cout << reversePairs(v);
}


#endif  // SORT_RESERVE_OLDER_CPP_