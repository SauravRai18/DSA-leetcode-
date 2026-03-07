class Solution {
public:
    void dfs(vector<vector<bool>> & vis, vector<vector<char>>& grid, int i,
             int j, int m, int n) {


        if(i < 0 || j< 0 || i>=m || j>=n || vis[i][j] || grid[i][j] != '1'){
            return;
        }

        vis[i][j] = true;
        dfs(vis, grid, i + 1, j, m, n);
        dfs(vis, grid, i - 1, j, m, n);
        dfs(vis, grid, i, j + 1, m, n);
        dfs(vis, grid, i, j - 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {

        int island = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(vis, grid, i, j, m, n);
                    island++;
                }
            }
        }
        return island;
    }
};