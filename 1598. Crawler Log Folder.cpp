// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int minOperations(vector<string>& logs) {
        int track=0;
        for(auto& it:logs)
        {
            if(it[0]!='.')
            track++;
            else if(it[0]=='.' and it[1]=='.')
            track= track >0 ? --track : 0;
        }
        return track;
    }
};
