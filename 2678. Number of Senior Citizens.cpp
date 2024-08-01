// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto& it:details)
        {
            string strAge=it.substr(11,2);
            int intAge=stoi(strAge);
            if(intAge>60)
            cnt++;
        }
        return cnt;
    }
};
