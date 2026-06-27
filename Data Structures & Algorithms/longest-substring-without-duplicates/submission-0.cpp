class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.length();
        if (size < 2)
        {
            return size;
        }

        std::unordered_map<char, int> m;
        int l = 0;
        int res = 0;

        for (int i = 0; i < size; i++)
        {
            if (m.find(s[i]) != m.end())
            {
                l = max(l, m[s[i]] + 1);
            }
            m[s[i]] = i;
            res = max(res, i - l + 1);
        }

        return res;
    }
};
