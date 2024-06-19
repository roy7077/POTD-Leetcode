#define ll long long
class Solution {
    public:
//     int help(vector<int>& v,int i,int m,int& k)
//     {
//         //base case
//         if(i>=v.size())
//         {
//             if(m==0)
//             return 0;
//             else
//             return -1e9;
//         }
        
//         //recursive calls
//         //and small calculation
//         int a=help(v,i+1,m,k);
//         if((i+k-1)>=v.size())
//         return a;
        
//         int j=i;
//         int maxi=-1e9;
//         while(j<(i+k))
//         {
//             maxi=max(maxi,v[j]);
//             j++;
//         }
        
//         int b=help(v,j,m-1,k);
//         return max({a,b,maxi});
//     }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=0;
        for(auto& it:bloomDay)
        maxi=max(maxi,it);
        
        int s=1;
        int e=maxi;
        ll ans=1e18;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int subCnt=0;
            int cnt=0;
            for(int i=0;i<bloomDay.size();i++)
            {
                int element=bloomDay[i];
                if(mid>element)
                element=0;
                else
                element-=mid;
                
                if(element==0)
                cnt++;
                else
                cnt=0;
                
                if(cnt==k)
                {
                    subCnt++;
                    cnt=0;
                }
            }
            
            if(subCnt>=m)
            {
                if(mid<ans)
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            
        }
        return ans>=1e18 ? -1:(int)ans;
    }
};

// 0 1 2 3 4