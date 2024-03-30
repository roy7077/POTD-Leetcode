// Method - 1
class Solution {
    public:
    int subarraysWithKDistinct(vector<int>& nums, int limit) {
        int cnt=0;
        int i=0;
        int j=0;
        unordered_map<int,int> mp1;
        while(j<nums.size())
        {
            mp1[nums[j]]++;
            
            //if size exceed , then erase
            while(mp1.size()>limit and i<=j)
            {
                mp1[nums[i]]--;
                if(mp1[nums[i]]==0)
                mp1.erase(nums[i]);
                
                i++;
            }
            
            //if size equals to k
            unordered_map<int,int> temp;
            int k=i;
            while(mp1.size()==limit and k<=j)
            {
                cnt++;
                temp[nums[k]]++;
                mp1[nums[k]]--;
                if(mp1[nums[k]]==0)
                mp1.erase(nums[k]);
                
                k++;
            }
            
            //pushing back to mp1
            for(auto it:temp)
            mp1[it.first]+=it.second;
            
            j++;
        }
        return cnt;
    }   
};      


// Method - 2
class Solution {
    public:
    int atMostKDistinct(vector<int>& A,int n,int k)
    {
        int cnt=0;
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        while(j<n)
        {
            //add current element in the map
            mp[A[j]]++;
            while(mp.size() > k)
            {
                mp[A[i]]--;
                if(mp[A[i]] == 0)
                mp.erase(A[i]);

                i++;
            }

            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& A, int k) {
        int n = A.size();
        return atMostKDistinct(A,n,k) - atMostKDistinct(A,n,k-1);
    }
};




