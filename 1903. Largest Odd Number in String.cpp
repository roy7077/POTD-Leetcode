// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        
        for(int i=num.length()-1;i>=0;i--)
        {
            int temp=(num[i]-48);
            if(temp&1)
            return num.substr(0,i+1);
        }
        return "";
    }
};
