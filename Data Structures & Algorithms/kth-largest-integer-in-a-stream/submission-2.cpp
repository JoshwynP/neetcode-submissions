class KthLargest {
public:
    std::priority_queue<int, vector<int>, greater<int>> min_q;

    KthLargest(int k, vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++)
        {
            if (min_q.size() < k)
            {
                min_q.push(nums[i]);
            }
            else if (min_q.top() < nums[i])
            {
                min_q.pop();
                min_q.push(nums[i]);
            }
        }

        while (min_q.size() < k)
        {
            min_q.push(-1001);
        }
    }
    
    int add(int val) {
        if (min_q.top() < val)
        {
            min_q.pop();
            min_q.push(val);
        }

        return min_q.top();
    }
};
