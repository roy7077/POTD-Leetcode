// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> findArray(vector<int>& pref) {
        int i=pref.size()-1;
        while(i>=1)
        {
            pref[i]=pref[i]^pref[i-1];
            i--;
        }
        return pref;
    }
};

/*-------------Explanation------------------

Since pref is the prefix array,
it's calculated from arr one by one,
we can doing this process reverssely to recover the original array.

Since
pref[i] = pref[i-1] ^ A[i]
so we have
pref[i] ^ pref[i-1] = A[i]

So we simply change - to ^ in the intuition solution

The reverse operation of + is -
The reverse operation of ^ is still ^
More general, we can apply this solution to prefix of any operation.
*/
