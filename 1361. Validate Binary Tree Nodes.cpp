class Solution {
public:
    
    int count(vector<int>& L,vector<int>& R,int node)
    {
        if(node==-1)
        return 0;
        
        int left=count(L,R,L[node]);
        int right=count(L,R,R[node]);
        
        return left+right+1;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& L, vector<int>& R) {
        
        //every node has indegree equal to 1 , except root (0)
        //check for multiple roots - if yes then return 0 else return 1
        //count node 
        
        //for indegree
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            if(L[i]!=-1)
            {
                indegree[L[i]]++;
                if(indegree[L[i]]>1)
                return 0;
            }
            
            if(R[i]!=-1)
            {
                indegree[R[i]]++;
                if(indegree[R[i]]>1)
                return 0;
            }
             
        }
        
        //for multiple roots
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                if(root==-1)
                root=i;
                else
                return 0;
            }
        }
        
        if(root==-1)
        return 0;
        
        //count nodes
        int c=count(L,R,root);
        
        return c==n?1:0;
    }
};