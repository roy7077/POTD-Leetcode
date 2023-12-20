/*----------Method-1--------------*/
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        
        if(money>=(prices[0]+prices[1]))
        return money-(prices[0]+prices[1]);
        else
        return money;
    }
};

/*--------------Method-2----------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int buyChoco(vector<int>& prices, int money) {
        int min1=1e9;
        int min2=1e9;
        for(auto it:prices)
        {
            if(it<min1)
            {
                min2=min1;
                min1=it;
            }
            else if(it==min1)
            min2=it;
            else if(it<min2)
            min2=it;
        }
        
        if(money>=(min1+min2))
        return money-(min1+min2);
        else
        return money;
    }
};