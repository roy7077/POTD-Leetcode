#define ll long long
class Solution {
    public:
    bool isPowerOfFour(int n) {
        
        ll i=1;
        while(1)
        {
            if(i==n)
            return 1;
            
            if(i>n)
            return 0;
            
            i*=4;
        }
        
        return 0;
    }
};