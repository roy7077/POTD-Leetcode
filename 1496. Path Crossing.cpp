// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int i=0;
        int j=0;
        st.insert({i,j});
        for(auto it:path)
        {
            if(it=='N')
            j++;
            else if(it=='S')
            j--;
            else if(it=='E')
            i++;
            else
            i--;
            
            if(st.count({i,j}))
            return 1;
            
            st.insert({i,j});
        }
        return 0;
    }
};