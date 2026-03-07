class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int m, int n,
             int oldcolor, int newcolor, vector<vector<bool>>& vis) {

        if (sr < 0 || sc < 0 || sr >= m || sc >= n || vis[sr][sc] || image[sr][sc] != oldcolor){
            return;
        }

            vis[sr][sc] = true;
        image[sr][sc] = newcolor;
        dfs(image, sr + 1, sc, m, n, oldcolor, newcolor, vis);
        dfs(image, sr - 1, sc, m, n, oldcolor, newcolor, vis);
        dfs(image, sr, sc + 1, m, n, oldcolor, newcolor, vis);
        dfs(image, sr, sc - 1, m, n, oldcolor, newcolor, vis);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int m = image.size();
        int n = image[0].size();

        int oldcolor = image[sr][sc];

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dfs(image, sr, sc, m, n, oldcolor, color, vis);

        return image;
    }
};