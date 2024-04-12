//Method - 1
// Time complexity - O(N)
// Space complexity- O(N+N)
class Solution {
    public:
    int trap(vector<int>& height) {
        //calculation left maximum
        //and right maximum for each element
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        
         //left maximum for each element
        int maxi=0;
        for(int i=0;i<height.size();i++)
        {
            left_max[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        
         //right maximum for each element
        maxi=0;
        for(int i=height.size()-1;i>=0;i--)
        {
            right_max[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        
        //calculation of total water trap
        int waterTrap=0;
        for(int i=0;i<height.size();i++)
        {
            int currWater=min(left_max[i],right_max[i])-height[i];
            if(currWater>0)
            waterTrap+=currWater;
        }
        
        return waterTrap;
    }
};


//Method - 2
// Time complexity - O(N)
// Space complexity- O(N)
#define ll long long
class Solution {
    public:
    int trap(vector<int>& height) {
        //calculation left maximum
        //and right maximum for each element
        ll MAXI=1e5+3;
        vector<ll> maximum(height.size(),0);
    
         //left maximum for each element
        ll maxi=0;
        for(int i=0;i<height.size();i++)
        {
            ll left=maximum[i]/MAXI;
            ll right=maximum[i]%MAXI;
            maximum[i]=(maxi*MAXI)+right;
            if(maxi<height[i])
            maxi=height[i];
        }
        
         //right maximum for each element
        maxi=0;
        for(int i=height.size()-1;i>=0;i--)
        {
            ll left=maximum[i]/MAXI;
            ll right=maximum[i]%MAXI;
            maximum[i]=(left*MAXI)+maxi;
            if(maxi<height[i])
            maxi=height[i];
        }
        
        //calculation of total water trap
        int waterTrap=0;
        for(int i=0;i<height.size();i++)
        {
            int currWater=min(maximum[i]/MAXI,maximum[i]%MAXI)-height[i];
            if(currWater>0)
            waterTrap+=currWater;
        }
        
        return waterTrap;
    }
};