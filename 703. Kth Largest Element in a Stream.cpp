// Time complexity - O(Nlogk)
// Space complexity- O(k)
class KthLargest {
    public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k=0;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto& it:nums)
        {
            if(pq.size()<k)
            pq.push(it);
            else
            {
                if(pq.top()<it)
                {
                    pq.pop();
                    pq.push(it);
                }
            }
        }
    }
    
    int add(int val) {
        if(this->pq.size()<k)
        this->pq.push(val);
        else
        {
            if(this->pq.top()<val)
            {
                pq.pop();
                pq.push(val);
            }
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
