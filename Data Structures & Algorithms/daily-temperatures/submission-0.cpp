class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int,int>> s;
        int t_size = temperatures.size();
        vector<int> res(t_size);

        s.push({0, temperatures[0]});

        for (int i = 1; i < t_size; i++)
        {
            int size = s.size();
            for (int j = 0; j < size; j++)
            {
                std::pair curr = s.top();
                if (curr.second < temperatures[i])
                {
                    res[curr.first] = i - curr.first;
                    s.pop();
                }
            }
            s.push({i, temperatures[i]});
        }

        while (!s.empty())
        {
            std::pair curr = s.top();
            res[curr.first] = 0;
            s.pop();
        }

        return res;
    }
};
