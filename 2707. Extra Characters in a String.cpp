class Solution {
    public:
    int help(string& s, int i, unordered_map<string, int>& mp, vector<int>& dp) {
        if (i == s.length()) {
            return 0;
        }
        
        // Memoization check
        if (dp[i] != -1) 
        return dp[i];
        
        int minExtra = 1 + help(s, i + 1, mp, dp);
        
        string temp = "";
        for (int j = i; j < s.length(); j++) {
            temp += s[j];
            if (mp.count(temp))
            minExtra = min(minExtra, help(s, j + 1, mp, dp));
        }
        
        return dp[i] = minExtra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        for (auto& it : dictionary) {
            mp[it]++;
        }
        
        vector<int> dp(s.length(), -1);
        return help(s, 0, mp, dp);
    }
};
