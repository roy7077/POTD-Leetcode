// Time complexity - O(N)
// SPace complexity -O(1)
class Solution {
    public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int maxi=0;
        int s=0;
        int i=0;
        int j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                s++;
                power-=tokens[i];
                i++;
            }
            else
            {
                if(s==0)
                break;
                
                power+=tokens[j];
                s--;
                j--;
            }
            maxi=max(maxi,s);
        }
        return maxi;
    }
};
