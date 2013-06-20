/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool myfunction(Interval i, Interval j) { return i.start < j.start;}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), myfunction);
        
        for(int i = 0; i < intervals.size(); i++)
        {
            int j = i+1;
            while(j < intervals.size())
            {
                if(intervals[i].end >= intervals[j].start)
                {
                    intervals[i].end = max(intervals[i].end, intervals[j].end);
                    intervals.erase(intervals.begin()+j);
                }
                else
                    break;
            }
        }
        
        return intervals;
        
    }
};