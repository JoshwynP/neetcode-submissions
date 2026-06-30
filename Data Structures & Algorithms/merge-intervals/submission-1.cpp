class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= result.back()[1])
            {
                int start = result.back()[0];
                int end = result.back()[1];

                result.pop_back();
                result.push_back({start, max(intervals[i][1],end)});
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
