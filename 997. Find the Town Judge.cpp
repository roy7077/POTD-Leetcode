// Method - 1
// Time complexity - O(N)
// Space complexity- O(2*N)
typedef pair<int,int> pi;
class Solution {
    public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pi> arr(n+1,pi{0,0});
        for(auto it:trust)
        {
            arr[it[0]].first++;
            arr[it[1]].second++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(arr[i].first==0 and arr[i].second==n-1)
            return i;
            
        }
        return -1;
    }
};

// Method - 2
// Time complexity - O(N)
// Space complexity- O(N)
typedef pair<int,int> pi;
class Solution {
    public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1,0);
        int maxi=2000;
        for(auto it:trust)
        {
            //first
            int a=arr[it[0]]/maxi;
            int b=arr[it[0]]%maxi;
            
            a++;
            arr[it[0]]=(a*maxi)+b;
            
            //second
            int c=arr[it[1]]/maxi;
            int d=arr[it[1]]%maxi;
            
            d++;
            arr[it[1]]=(maxi*c)+d;   
        }
        
        for(int i=1;i<=n;i++)
        {
            int a=arr[i]/maxi;
            int b=arr[i]%maxi;
            
            if(a==0 and b==n-1)
            return i;
        }
        return -1;
    }
};

// Method - 3
/* Method - 3
   Time complexity - O(N)
   Space complexity- O(N)
*/
typedef pair<int,int> pi;
class Solution {
    public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1,0);
        for(auto it:trust)
        {
            arr[it[0]]--;
            arr[it[1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==n-1)
            return i;
        }
        return -1;
    }
};