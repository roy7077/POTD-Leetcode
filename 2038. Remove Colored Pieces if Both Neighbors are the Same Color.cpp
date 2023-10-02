// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool winnerOfGame(string c) {
        
        int alice=0;
        int bob=0;
        
        int A=0;
        int B=0;
        
        for(int i=0;i<c.size();i++)
        {
            if(c[i]=='A')
            {
                bob+= B-2>=1? B-2:0;
                A++;
                B=0;
            }
            else
            {
                alice+= A-2>=1? A-2:0;
                B++;
                A=0;
            }
        }
        bob+= B-2>=1? B-2:0;
        alice+= A-2>=1? A-2:0;
        
        if(alice==bob)
        return false;
        else if(alice>bob)
        return true;
        else
        return false;
    }
};