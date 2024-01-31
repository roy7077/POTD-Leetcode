/* Method - 1 - TLE
brute force
Time complexity - O(N^2)
Space complexity- O(N)
*/
class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        for(int i=0;i<temp.size();i++)
        {
            int j=i+1;
            while(j<temp.size() and temp[j]<=temp[i])
            j++;
            
            if(j>=temp.size())
            ans[i]=0;
            else
            ans[i]=j-i;
            
        }
        return ans;
    }
};


/* Method - 2
Monotonic stack
Time complexity - O(N)
Space complexity- O(N+N)
*/
class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        stack<int> st;
        for(int i=temp.size()-1;i>=0;i--)
        {
            while(!st.empty() and temp[st.top()]<=temp[i])
            st.pop();
            
            if(st.empty())
            ans[i]=0;
            else
            ans[i]=st.top()-i;
            
            st.push(i);
        }
        return ans;
    }
};
