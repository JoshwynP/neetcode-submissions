class Solution {
private:
    vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if (i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1)
        {
            return 0;
        }

        int total = 0;


        if (grid[i][j] == 1)
        {
            total++;
            grid[i][j] = 0;
            for (const auto& d: dirs)
            {
                total+= dfs(i + d.first, j + d.second, grid);
            }
            
        }

        return total;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;

        // traverse through grid
        for (int i=0; i<grid.size();i++)
        {
            for (int j=0; j<grid[i].size();j++)
            {
                //if hit a 1, call dfs on surrounding nodes
                if (grid[i][j] == 1)
                {
                    count = max(count, dfs(i, j, grid));
                }
            }
        }
        
        return count;
    }
};
