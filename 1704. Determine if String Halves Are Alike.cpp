/*--------method - 1-----------------*/
// Time complexity - O(N)
// Space complexity- O(10)
class Solution {
    public:
    bool flag=0;
    unordered_map<char,int> map;
    void help()
    {
      map['A']=map['E']=map['I']=map['O']=map['U']=1;
      map['a']=map['e']=map['i']=map['o']=map['u']=1; 
      flag=1;
    }
    bool halvesAreAlike(string s) {
        
        if(s.length()&1)
        return 0;
        
        if(!flag)
        help();
        
        int cnt1=0;
        int cnt2=0;
        
        for(int i=0;i<s.length();i++)
        {
            char it=s[i];
            if(i>=(s.length()/2) and map.count(it))
            cnt1++;
            
            if(i<(s.length()/2) and map.count(it))
            cnt2++;
        }
        
        if(cnt1==cnt2)
        return 1;
        else
        return 0;
       
    }
};


/*--------method - 2--------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool halvesAreAlike(string s) {
        
        if(s.length()&1)
        return 0;
        
        int cnt1=0;
        int cnt2=0;
        
        for(int i=0;i<s.length();i++)
        {
            char it=s[i];
            if(it=='A' or it=='E' or it=='I' or it=='O' or it=='U' or 
              it=='a' or it=='e' or it=='i' or it=='o' or it=='u')
             cnt1++;
            
            if(i<(s.length()/2) and (it=='A' or it=='E' or it=='I' or it=='O' or it=='U' or 
              it=='a' or it=='e' or it=='i' or it=='o' or it=='u'))
                cnt2++;
        }
        
        if(cnt1-cnt2==cnt2)
        return 1;
        else
        return 0;
       
    }
};