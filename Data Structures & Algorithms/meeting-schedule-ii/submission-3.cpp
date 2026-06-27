/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // empty check
        if (intervals.size() < 1)
        {
            return 0;
        }

        // sort the intervals first
        sort (intervals.begin(), intervals.end(), [](auto& x, auto& y) {return x.start < y.start;});
        
        priority_queue<int, vector<int>, greater<int>> minheap;

        // loop through and create a start and end time vector
        for (int i = 0; i < intervals.size(); i++)
        {
            if (!minheap.empty() && minheap.top() <= intervals[i].start)
            {
                minheap.pop();
            }
            minheap.push(intervals[i].end);
        }

        return minheap.size();
    }
};
