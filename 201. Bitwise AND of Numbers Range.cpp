// Time complexity - O(32)
// Space complexity- O(1)
class Solution {
    public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left)
        {
            right=right&(right-1);
        }
        return right;
    }
};