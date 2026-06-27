class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int> range;
        for (int i = 0; i < n; i++)
        {
            range.push_back(i);
        }

        // now we have our range vecotr and input vector;
        int XOR_result = 0;
        for (int i = 0; i < n; i++)
        {
            XOR_result = XOR_result ^ range[i];
            if (i < nums.size())
            {
                XOR_result = XOR_result ^ nums[i];
            }
        }

        return XOR_result;
    }
};
