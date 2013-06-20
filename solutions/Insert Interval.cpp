/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        
        if(intervals[0].start > newInterval.end)
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
                
        int i = 0;
        for(; i < intervals.size(); i++)
        {
            if(intervals[i].end >= newInterval.start)
            {
                if(intervals[i].start > newInterval.end)
		 intervals.insert(intervals.begin() + i, newInterval);
	       else	
		 intervals[i].start = min(intervals[i].start, newInterval.start);
                break;
            }
        }
        if(i == intervals.size())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int j = intervals.size()-1;
        for(; j >= i; j--)
        {
            if(intervals[j].start <= newInterval.end)
            {
                intervals[i].end = max(intervals[j].end, newInterval.end);
                break;
            }
        }
        
        if(j == i+1)
            intervals.erase(intervals.begin()+j);
        else if(j > i + 1)
            intervals.erase(intervals.begin()+i+1, intervals.begin()+j+1);

        return intervals;
    }
};