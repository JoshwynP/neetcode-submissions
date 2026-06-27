class Solution {
private:
    bool hasCycle(int k, vector<vector<int>> &adj, vector<int> &state) {
        state[k] = 1;
        for (int v: adj[k])
        {
            if (state[v] == 1) return true;
            if (state[v] == 0)
            {
                if (hasCycle(v, adj, state)) return true;
            }
        }

        state[k] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1 || prerequisites.size() < 2)
        {
            return true;
        }

        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> state(adj.size(),0);
        for (int i = 0; i < state.size(); i++)
        {
            if (state[i] == 0)
            {
                if (hasCycle(i, adj, state))
                {
                    return false;
                }
            }
        }



        return true;
    }
};
