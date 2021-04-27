// code by NH

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int>pq;
        
        int rooms = 0;
        
        for (int i=0; i<intervals.size(); i++) {
            if (i==0) {
                pq.push(-intervals[i][1]);
            }
            else {
                while((-pq.top() <= intervals[i][0]) && !pq.empty()) {
                    pq.pop();
                }
                
                pq.push(-intervals[i][1]);
            }
            
            rooms = max(rooms, (int)pq.size());
            // cout << pq.size() << endl;
        }
        
        return rooms;
    }
};