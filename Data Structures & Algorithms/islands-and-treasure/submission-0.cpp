class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = pow(2,31) - 1;
        vector<pair<int,int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        std::queue<std::pair<int,int>> q;

        int outer_s = grid.size();
        int inner_s = grid[0].size();

        for (int i = 0; i < outer_s; i++)
        {
            for (int j = 0; j < inner_s; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }

        int distance = 0;

        while (!q.empty())
        {
            int qsize = q.size();
            distance++;

            for (int k = 0; k < qsize; k++)
            {
                pair curr = q.front();
                q.pop();

                for (pair p: dirs)
                {
                    int v = curr.first + p.first;
                    int h = curr.second + p.second;

                    if ( v >= 0 && v < outer_s && h >= 0 && h < inner_s)
                    {
                        if (grid[v][h] == inf)
                        {
                            grid[v][h] = distance;
                            q.push({v,h});
                        }
                    }
                }
            }
        }
    }
};
