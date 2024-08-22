// time complexity - O(logN)
// Space complexity- O(1)
class Solution {
    public:
    int findComplement(int num) {
        long long n=0;
        long long i=0;
        while(num>0)
        {
            if((num%2)==0)
            n+=(pow(2,i));
            
            num/=2;
            i++;
        }
        return n;
    }
};
