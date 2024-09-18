class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> st;
        for(auto& ch:x)
        {
            switch(ch)
            {
                case '{':
                case '[':
                case '(': st.push(ch);
                          break;
                
                case '}':
                          if(st.empty())
                          return 0;
                          
                          if(st.top()=='{')
                          st.pop();
                          else
                          return 0;
                          break;
                case ']':
                          if(st.empty())
                          return 0;
                          
                          if(st.top()=='[')
                          st.pop();
                          else
                          return 0;
                          break;
                case ')':
                          if(st.empty())
                          return 0;
                          
                          if(st.top()=='(')
                          st.pop();
                          else
                          return 0;
                          break;
            }
        }
        
        return st.empty();
    }

};
