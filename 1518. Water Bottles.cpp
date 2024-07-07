
class Solution {
    public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=0;
        while(numBottles>=numExchange)
        {
            int temp=numBottles/numExchange;
            cnt+=(temp*numExchange);
            numBottles=(numBottles%numExchange)+temp;
        }
        cnt+=numBottles;
        return cnt;
    }
};