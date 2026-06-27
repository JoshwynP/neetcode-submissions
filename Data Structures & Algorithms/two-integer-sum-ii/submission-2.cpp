class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {    
        int l = 0;
        int r = numbers.size() - 1;

        while(true)
        {
            if (numbers[l] + numbers[r] > target)
            {
                r--;
                continue;
            }
            else if (numbers[l] + numbers[r] < target)
            {
                l++;
                continue;
            }
            else
            {
                break;
            }
        }

        return {l+1, r+1};
    }
};
