class Solution {
public:
    vector<pair<int, int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific (rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic (rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            dfs(i, 0, pacific, heights); // pacific vertical
            dfs(i, cols-1, atlantic, heights); // atlantic vertical
        }

        for (int j = 0; j < cols; j++)
        {
            dfs(0, j, pacific, heights); // pacific horizontal
            dfs(rows-1, j, atlantic, heights); // atlantic horizontal
        }

        vector<vector<int>> result;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] == true && atlantic[i][j] == true)
                {
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }

private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights)
    {
        ocean[r][c] = true;
        for (pair p: dirs)
        {
            int nr = r + p.first;
            int nc = c + p.second;

            if (nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && heights[nr][nc] >= heights[r][c] && !ocean[nr][nc])
            {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};
