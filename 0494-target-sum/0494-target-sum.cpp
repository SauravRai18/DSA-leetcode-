class Solution {
public:
    int solve(vector<int>& nums, int i, int sum, int n, int target,
              vector<unordered_map<int, int>>& dp) {

        if (i == n) {
            if (sum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[i].find(sum) != dp[i].end()) {
            return dp[i][sum];
        }

        int p = solve(nums, i + 1, sum + nums[i], n, target, dp);

        int m = solve(nums, i + 1, sum - nums[i], n, target, dp);

        return dp[i][sum] = p + m;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);

        return solve(nums, 0, 0, n, target, dp);
    }
};