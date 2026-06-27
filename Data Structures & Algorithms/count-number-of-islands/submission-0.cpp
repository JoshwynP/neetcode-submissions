class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        void dfsGraph(vector<vector<char>>& grid, std::pair<int, int> index);

        int count = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '0') {continue;}
                else
                {
                    count++;
                    grid[i][j] = '0';
                    dfsGraph(grid, {i,j});
                }
            }
        }

        return count;
    }
};

void dfsGraph(vector<vector<char>>& grid, std::pair<int, int> index)
{
    const vector<std::pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    for (auto p: dirs)
    {
        int ud = p.first;
        int lr = p.second;

        if ((index.first == 0 && ud == -1) || (index.first == (grid.size() - 1) && ud == 1) || index.second == 0 && lr == -1 || index.second == (grid[0].size() - 1) && lr == 1)
        {
            continue;
        }
        int i = index.first + ud;
        int j = index.second + lr;

        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
            dfsGraph(grid, {i,j});
        }
    }
}
