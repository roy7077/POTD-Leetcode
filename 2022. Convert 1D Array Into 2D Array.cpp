// Time complexity - O(N)
// Space complexity- O(N*M + N)
class Solution {
    public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if((n*m)!=original.size())
        return {};
        
        vector<vector<int>> ans;
        int cnt=0;
        vector<int> temp;
        for(auto& it:original)
        {
            temp.push_back(it);
            cnt++;
            
            if(!(cnt%n))
            {
                ans.push_back(temp);
                temp.resize(0);
            }
        }
        return ans;
    }
};
