// Time complexity - O(1440*2)
// Space complexity- O(1440*2)
class Solution {
    public:
    int findMinDifference(vector<string>& timePoints) {
        int n=1440;
        vector<int> v(n,0);
        for(auto& it:timePoints)
        {
            int hr=stoi(it.substr(0,2));
            int min=stoi(it.substr(3));
            int time=(hr*60)+min;
            
            v[time]++;
            if(v[time]>1)
            return 0;
        }
        
        
        int minDiff=1e9;
        int prev=-1;
        for(int i=0;i<2*n;i++)
        {
            int ind=i%n;
            if(v[ind])
            {
                if(prev==-1)
                {
                    prev=ind;
                    continue;
                }
                
                minDiff=min(minDiff,abs(prev-i));
                prev=i;
            }
        }
        return minDiff;
    }
};
