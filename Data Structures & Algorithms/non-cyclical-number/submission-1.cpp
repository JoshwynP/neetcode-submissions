class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> h_set;

        int curr = n;
        
        while (true)
        {
            int sum = 0;
            while (curr > 0)
            {
                sum += pow(curr % 10, 2);
                curr = curr / 10;
            }

            if (sum == 1)
            {
                return true;
            }
            if (h_set.contains(sum))
            {
                return false;
            }

            h_set.insert(sum);
            curr = sum;
        }
    }
};
