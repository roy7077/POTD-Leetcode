// Time complexity - O(NLogN)
// Space complexity- O(N)
class SeatManager {
    private:
    priority_queue <int, vector<int>, greater<int>> pq;
    public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
        pq.push(i); 
    }
    
    int reserve() {
        
        if(pq.empty())
        return -1;
        
        int num=pq.top();
        pq.pop();
        return num;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
