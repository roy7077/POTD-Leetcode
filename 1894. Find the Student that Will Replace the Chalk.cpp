// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum=0;
        for(auto& it:chalk)
        sum+=it;
        
        k%=sum;
        
        int n=chalk.size();
        for(int i=0;i<n;i++)
        {
            if(chalk[i]>k)
            return i;
            
            k-=chalk[i];
        }
        return 0;
    }
};

