class Solution {
private:
    int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    void safe_circles_dfs(int i, int j, vector<vector<char>>& board)
    {
        board[i][j] = '%';

        for (const auto& d: dirs)
        {
            int ud = i + d[0];
            int lr = j + d[1];

            if (ud >= 0 && lr >= 0 && ud < board.size() && lr < board[0].size() && (board[ud][lr] == 'O'))
            {
                safe_circles_dfs(ud, lr, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        // traverse all edges and when an O is hit, dfs
        // mark all connected Os as safe within unordered map
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (i == 0 || j == 0 || i == board.size()-1 || j == board[i].size()-1)
                {
                    if (board[i][j] == 'O')
                    {
                        safe_circles_dfs(i, j, board);
                    }
                }
            }
        }
        // traverse the matrix (ignoring outermost rows/cols)
        // any O that is found, check if it is in the safe map
        // if its not, convert to an X
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '%')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
