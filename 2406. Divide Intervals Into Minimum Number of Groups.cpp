
typedef pair<int,int> pi;
class Solution {
    public:
    int minGroups(vector<vector<int>>& intervals) {
            sort(begin(intervals), end(intervals));
            priority_queue<int, vector<int>, greater<int>> pq;
            for (auto &i : intervals) 
            {
                if (!pq.empty() and pq.top() < i[0])
                pq.pop();
                pq.push(i[1]);
            }
            return pq.size();
//         int n=intervals.size();
//         vector<pi> v;
//         for(auto& it:intervals)
//         v.push_back({it[0],it[1]});
            
//         sort(v.begin(),v.end());
        
        
//         // for(auto& it:v)
//         // cout<<it.first<<" "<<it.second<<endl;
        
//         queue<pi> q;
//         for(auto& it:v)
//         q.push(it);
        
//         int cntGrp=0;
//         while(!q.empty())
//         {
//             int start=q.front().first;
//             int end=q.front().second;
//             q.pop();
            
//             int size=q.size();
//             while(size--)
//             {
//                 int s=q.front().first;
//                 int e=q.front().second;
//                 q.pop();
                
//                 if(s>end)
//                 {
//                     start=min(s,start);
//                     end=max(e,end);
//                 }
//                 else
//                 q.push({s,e});
//             }
//             cntGrp++;
//         }
//         return cntGrp;
    }
};


// [[5,10],[6,8],[1,5],[2,3],[1,10]]

// 2 3 3 2 3 3 3 3 2 2 2

// 1,10
// 1,5
// 2,3
// 5,10
// 6,8


// 2,3   
// 5,10  
   
    
// 1,10  
    
// 1,5
// 6,8
