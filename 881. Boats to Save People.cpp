// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int cnt=0;
        int i=0;
        int j=p.size()-1;
        while(i<=j)
        {
            if(i==j)
            {
                cnt++;
                break;
            }
            
            if((p[i]+p[j])>limit)
            {
                cnt++;
                j--;
            }
            else
            {
                cnt++;
                i++;
                j--;
            }
        }
        return cnt;
    }
};