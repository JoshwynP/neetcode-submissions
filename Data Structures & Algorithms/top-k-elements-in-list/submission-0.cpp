class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //pQueue and hash map

        // hash map key is number and value is occurences
        std::unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        // push value to stack based on k - keep track of occurences
        std::priority_queue<std::pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for (auto& entry : m)
        {
            heap.push({entry.second, entry.first});
            if (heap.size() > k)
            {
                heap.pop();
            }
        }

        vector<int> res;

        for (int i = 0; i < k; i++)
        {
            res.push_back(heap.top().second);
            heap.pop();
        }

        return res;
    }
};
