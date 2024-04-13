
// Method - 1
// Time complexity - O(logN)
// Space complexity- O(32) - constant
/*
I am simply reversing the bits of a number and then 
converting those reversed bits into decimal
*/
#define ll long long
class Solution {
    public:
    ll help(ll n)
    {
        //decimal to binary
        vector<int> binary;
        while(n)
        {
            if(n%2)
            binary.push_back(1);
            else
            binary.push_back(0);
            
            n/=2;
        }
        
        for(int i=binary.size();i<31;i++)
        binary.push_back(0);
        
        //reversing the binary 
        //calculate decimal for this binary
        ll ans=0;
        for(int i=binary.size()-1;i>=0;i--)
        {
            if(binary[i])
            ans+=pow(2,binary.size()-i);
        }
        return ans;
    }
    long long reversedBits(long long x) {
        return help(x);
    }
};

// Method - 2
// Bit Manipulation
// Time complexity - O(32) - constant
// Space complexity- O(1)  - constant
/*
I am checking if each bit is set, and if it is, I include 
it in the answer. I iterate from 0 to 31 to take the reversed bits

To optimize time complexity, I've utilized the expression 
power = (power * 2) % mod instead of relying on the pow function, 
which can incur time complexities up to O(log N), potentially reaching 
O(32 * log N)
*/

#define ll long long
ll mod=1e10+7;
class Solution {
    public:
    ll help(ll n)
    {
        ll ans=0;
        ll power=1;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<(31-i)))
            ans+=power;
            power=(2*power)%mod;
        }
        return ans;
    }
    long long reversedBits(long long x) {
        return help(x);
    }
};
