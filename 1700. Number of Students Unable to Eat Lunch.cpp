// queue
// Time complexity - O(N^2)
// Space complexity- O(N)
class Solution {
    public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(auto it:students)
        q.push(it);
        
        int i=0;
        while(1)
        {
            int tempSize=q.size();
            int size=q.size();
            while(size--)
            {
                int front=q.front();
                q.pop();
                if(front==sandwiches[i])
                i++;
                else
                q.push(front);  
            }
            if(q.size()==tempSize or q.size()==0)
            break;
        }
        
        return q.size()==0 ? 0 : q.size();
    }
};