/*------------METHOD 1-----------*/

// Complexity
// Time complexity:
// O(N*logN)

// Space complexity:
// O(1)

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());

//         int i=0;
//         int j=0;
//         while(i<s.length() and j<t.length())
//         {
//             if(s[i]!=t[j])
//             return t[j];

//             i++;
//             j++;
//         }

//         return t[j];
//     }
// };


/*----------------METHOD-2----------------*/
// EASY AND BEST SOLUTION


// Time complexity:
// O(N)

// Space complexity:
// O(N)

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
        
//         unordered_map<char,int> mp1;
//         unordered_map<char,int> mp2;
//         for(auto it:s)
//         mp1[it]++;

//         for(auto it:t)
//         mp2[it]++;

//         for(auto it:mp2)
//         {
//             if(mp1[it.first]!=it.second)
//             return it.first;
//         }

//         return 't';
//     }
// };