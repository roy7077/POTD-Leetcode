#define ll long long
class Solution {
    public:
    long long minimumSteps(string s) {
        ll cnt=0;
        ll oneCnt=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                cnt+=(s.length()-oneCnt-(i+1));
                oneCnt++;
            }
        }
        return cnt;
    }
};

// 0 1 2 3 4 5
