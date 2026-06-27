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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort intervals based on start time, and also 
        // check if any have the same start time, return false

        // then just go through the list checking the neighbours
        for (int i = 0; i < intervals.size(); i++)
        {
            for (int j = 0; j < intervals.size(); j++)
            {
                if (j==i) {continue;}

                if (intervals[i].start < intervals[j].start)
                {
                    if (intervals[i].end > intervals[j].start)
                    {
                        std::cout << intervals[i].end << " " << intervals[j].start;
                        return false;
                    }
                }
                else
                {
                    if (intervals[i].start < intervals[j].end)
                    {
                        std::cout << intervals[i].end << " " << intervals[j].start;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
