class Node{
    public:
        Node *left;
        Node *right;
        int start;
        int end;
        int mid;
    
    Node(int x, int y){
        start = x;
        end = y;
        mid = (x+y)/2;
        left = NULL;
        right = NULL;
    }

};

class MyCalendar {
    public:
    Node * root;

    MyCalendar() {
        root = NULL;
    }
    Node * update(Node* curr, int i, int j)
    {
        int mid = (i+j)/2;
        if(!curr)
        {
            curr = new Node(i, j);
            if(!root) root=curr;
        }
        else if(curr->mid > mid)
        curr->left = update(curr->left, i, j);
        else
        curr->right = update(curr->right, i, j);
        
        return curr;
    }
    bool canInsert(Node * curr, int i, int j)
    {
        int mid = (i+j)/2;
        
        if(!curr) 
        return true;
        // if nodes dont overlap then we can insert a new node
        //not ({i..j}[start...end] or [start...end]{i...j})
        if(!(curr->start >= j || curr->end <= i)) 
        return false;

        if(curr->mid > mid)
        return canInsert(curr->left, i, j);
        else
        return canInsert(curr->right, i,j);
    }
    
    bool book(int start, int end) {
        bool ans = canInsert(root, start, end);
        if(ans)
        update(root, start,end);
        
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
