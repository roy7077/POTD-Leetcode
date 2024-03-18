// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt=0;
        int b=points[0][1];
        for(auto it:points)
        {
            if(b>=it[0])
            b=min(b,it[1]);
            else
            {
                cnt++;
                b=it[1];
            }
        }
        cnt++;
        return cnt;
    }
};

// [1,10] [3,9] [4,11] [6,7] [6,9] [8,12] [9,12]

// 1 2 3 4 5 6 7 8 9 10
//     3 4 5 6 7 8 9
//       4 5 6 7 8 9 10 11
//           6 7
//           6 7 8 9
//               8 9 10 11 12
//                 9 10 11 12