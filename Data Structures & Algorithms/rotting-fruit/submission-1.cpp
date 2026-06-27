class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        std::queue<std::pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) // search entire matrix to get fruit counts
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) {fresh++;}
                if (grid[i][j] == 2) {q.push({i,j});}
            }
        }

        if (fresh == 0) return 0;

        std::vector<std::pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int time = 0;

        while (!q.empty())
        {
            int current_rotten = q.size();
            bool rotted_any = false;
            for (int k = 0; k < current_rotten; k++)
            {
                std::pair<int,int> r = q.front();
                q.pop();
                
                for (const auto& p: dirs)
                {
                    int i = r.first + p.first;
                    int j = r.second + p.second;

                    if ( 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size())
                    {
                        if (grid[i][j] == 1)
                        {
                            grid[i][j] = 2;
                            q.push({i,j});
                            fresh--;
                            rotted_any = true;
                        }
                    }
                    
                }
            }
            if(rotted_any) time++;
        }
        return fresh == 0 ? time : -1;
    }
};
