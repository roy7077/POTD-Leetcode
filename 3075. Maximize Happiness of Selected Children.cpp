#define ll long long
class Solution {
    public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end(),greater<int>());
        ll sum=0;
        int dec=0;
        for(int i=0;i<k;i++)
        {
            h[i]-=dec;
            
            if(h[i]<=0)
            continue;
            
            sum+=h[i];
            dec++;
        }
        
        return sum;
    }
};