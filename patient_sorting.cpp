#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printLongestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> piles, backlink(n), topidx(n);

    for (int i = 0; i < n; i++) {
        int j = lower_bound(piles.begin(), piles.end(), nums[i]) - piles.begin();
        backlink[i] = (j > 0) ? topidx[j - 1] : -1;
        if (j == piles.size()) {
            piles.push_back(nums[i]);
        } else {
            piles[j] = nums[i];
        }
        topidx[j] = i;
    }


    int len = piles.size();
    vector<int> ans(len);
    for (int i = topidx[len - 1]; i >= 0; i = backlink[i]) {
        ans[--len] = nums[i];
    }

    cout << "Longest increasing subsequence: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    printLongestIncreasingSubsequence(nums);
    return 0;
}
