/* intuition
1st) Frequency of Char need's to be same there both of string as we can do Transform every occurrence of one existing character into another existing character

2nd) All the unique char which there in String1 need's to there as well In string2
*/
// Time complexity - O(N)
// Space complexity- O(4*N)

class Solution {
    public:
    bool closeStrings(string word1, string word2) {
        
        //different length -> return 0
        if(word1.length()!=word2.length())
        return 0;
        
        //storing the frequency of characters of string
        unordered_map<char,int> mp1,mp2;
        for(auto it:word1)
        mp1[it]++;
        
        for(auto it:word2)
        mp2[it]++;
        
        //matching
        for(auto it:mp1)
        {
            if(mp2.count(it.first)==0)
            return 0;
        }
        
        
        unordered_map<int,int> mp3,mp4;
        for(auto it:mp1)
        mp3[it.second]++;
        
        for(auto it:mp2)
        {
            if(mp3[it.second]<=0)
            return 0;
            else
            mp3[it.second]--;
        }
        
        //size of unordered map
        if(mp1.size()!=mp2.size())
        return 0;
        
        return 1;
    }
};

// a - 3
// b - 4
// c - 2
// d - 2
// e - 5
// f - 5
    
// 3
// 4
// 2
// 5
    
//     a - 5
//     b - 2
//     c - 3
//     d - 3
//     e - 4
//     f - 4