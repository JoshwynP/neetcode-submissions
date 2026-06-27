class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map stores key: nums[i or j], value: index
        std::unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = target - nums[i];

            if (m.find(curr) != m.end())
            {
                return {m[curr], i};
            }
            
            m[nums[i]] = i;
        }

        return {};
    }
};
