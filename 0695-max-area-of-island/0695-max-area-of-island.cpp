class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,
            int m, int n) {

        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] ||
            grid[i][j] != 1) {
            return 0;
        }

        vis[i][j] = true;
        int area = 1;
        area += dfs(grid, vis, i + 1, j, m, n);
        area += dfs(grid, vis, i - 1, j, m, n);
        area += dfs(grid, vis, i, j + 1, m, n);
        area += dfs(grid, vis, i, j - 1, m, n);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {

                    int area = dfs(grid, vis, i, j, m, n);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};