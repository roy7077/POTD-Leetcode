typedef pair<int,int> pi;
class Solution {
    public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int targetAT=times[t][0];
        sort(times.begin(),times.end());
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        set<int> st;
        int maxSeat=0;
        for(auto& it:times)
        {
            int AT=it[0];
            int LT=it[1];
            
            while(!pq.empty() and pq.top().first<=AT)
            {
                int seat=pq.top().second;
                pq.pop();
                st.insert(seat);
            }
            
            int seat;
            if(st.size()==0)
            {
                seat=maxSeat;
                maxSeat++;
            }
            else
            {
                seat=*(st.begin());
                st.erase(seat);
            }
    
            pq.push({LT,seat});
            
            if(AT==targetAT)
            return seat;
        }
        return -1;
    }
};
