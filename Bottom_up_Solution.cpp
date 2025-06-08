#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to perform standard house robber logic on a subrange
    // (ignores circular adjacency by excluding first or last house)
    int robRange(vector<int>& nums, int start, int end) {
        int prev1 = 0; // Stores the max sum up to the previous house
        int prev2 = 0; // Stores the max sum up to the house before previous

        for (int i = start; i < end; i++) {
            int curr = max(prev2 + nums[i], prev1); // Rob this or skip
            prev2 = prev1; // Shift the window
            prev1 = curr;
        }

        return prev1;
    }

    // Main function to solve House Robber II (houses in a circle)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house, rob it

        // Case 1: Rob from first house to second last house (exclude last)
        int ans1 = robRange(nums, 0, n - 1);

        // Case 2: Rob from second house to last house (exclude first)
        int ans2 = robRange(nums, 1, n);

        // Return the maximum of the two cases
        return max(ans1, ans2);
    }
};
