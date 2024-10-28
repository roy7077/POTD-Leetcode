
// TESTING -> can give TLE
#define ll long long
class Solution {
    public:
    bool isSquare(int& n) 
    {
        int root = sqrt(n);
        return root * root == n;
    }
    
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        vector<ll> v;
        unordered_set<ll> st(nums.begin(), nums.end());

        for (auto& it : nums) 
        {
            if (isSquare(it)) {
                v.push_back(it);
            }
        }

        sort(v.begin(), v.end());
        int maxLen = -1;

        for (int i = 0; i < v.size(); i++) {
            
            int len=0;
            if(st.count(sqrt(v[i])))
            len=1;
            
            len++;
            ll next = v[i] * v[i];

            while(st.count(next)) 
            {
                len++;
                next *= next;

                // Prevent overflow for next potential square
                if (next > 1e10) 
                break;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen > 1 ? maxLen : -1;
    }
};
