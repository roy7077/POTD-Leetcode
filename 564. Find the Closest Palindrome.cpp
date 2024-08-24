





#define ll long long
class Solution {
    public:
    
    // check is string palindrome or not
//     bool isPalindrome(string& str,string& s)
//     {
//         int i=0;
//         int j=str.length()-1;
//         while(i<=j)
//         {
//             if(str[i]!=str[j])
//             return 0;
            
//             i++;
//             j--;
//         }
        
        
//         if(str.length()>s.length())
//         return 1;
//         else if(s.length()>str.length())
//         return 0;
        
//         for(int i=0;i<s.length();i++)
//         {
//             if(str[i]>s[i])
//             return 1;
//         }
//         return 0;
    //     return 1;
    // }
    
    string nearestPalindromic(string n) {
        
        if(n.length()==1) 
        return to_string(stoi(n)-1); //Special case for single digit numbers
        
        // the first thing is that, i know for sure that there are two palindrome
        // if there are 5 digits then 
        // first palindrome would be 999 and 2nd palindrome would be 100001
        
        int digits=n.length();
       vector<ll>candidates;
       candidates.push_back(pow(10,digits-1)-1);//Case 1
       candidates.push_back(pow(10,digits)+1);//Case 2
        
        int mid=(digits+1)/2;
        ll prefix=stol(n.substr(0,mid));
        
       vector<ll>v={prefix,prefix+1,prefix-1};
       for(ll i:v)
       {
           string postfix=to_string(i);
           if(digits%2!=0) 
           postfix.pop_back(); // If the total length is odd number, pop the middle number in postfix
           
           reverse(postfix.begin(),postfix.end());
           string c=to_string(i)+postfix;
           candidates.push_back(stol(c));
       }
        
       ll mindiff=LONG_MAX;
       ll result;
       ll num=stol(n);
       for(int i=0;i<5;i++)
       {
           if(candidates[i]!=num and abs(candidates[i]-num)<mindiff)//Candidate must not be the same number and abs diff is minm
           {
               mindiff=abs(candidates[i]-num);
               result=candidates[i];
           }
           else if(abs(candidates[i]-num)==mindiff) result=min(result,candidates[i]);
       }
        return to_string(result);
        
        
        
//         string s=n;
//         int len=n.length();
//         int ind;
        
//         if(len&1)
//         ind=len/2;
//         else
//         ind=(len/2)-1;
                        
//         string ans1="";
//         // for palindrome number
//         // greater than current number
//         for(int i=ind;i>=0;i--)
//         {
//             for(char ch='0';ch<='9';ch++)
//             {
//                 n[i]=ch;
//                 string str;
                
//                 if(len%2==0)
//                 {
//                     string firstPart=n.substr(0,len/2);
//                     string rev=firstPart;
//                     reverse(rev.begin(),rev.end());
                    
//                     str=firstPart+rev;
//                 }
//                 else
//                 {
//                     string firstPart=n.substr(0,len/2);
//                     string rev=firstPart;
//                     reverse(rev.begin(),rev.end());
                    
//                     str=firstPart+n[len/2]+rev;
//                 }
                
//                 cout<<i<<" "<<str<<endl;
//                 bool ans=isPalindrome(str,s);
//                 if(ans)
//                 {
//                     ans1=str;
//                     break;
//                 }
//             }
            
//             if(ans1.length())
//             break;
            
//             n[i]='0';
//         }
        
        // for palindrome number less
        // than current number
//         for(int i=n/2;i>=0;i--)
//         {
//             for(char ch='0';ch<='9';ch++)
//             {
//                 n[i]=ch;
//                 string str;
                
//                 if(n%2==0)
//                 {
//                     string firstPart=n.substr(0,n/2);
//                     string rev=firstPart;
//                     reverse(rev.begin(),rev.end());
                    
//                     str=firstPart+rev;
//                 }
//                 else
//                 {
//                     string firstPart=n.substr(0,n/2);
//                     string rev=firstPart;
//                     reverse(rev.begin(),rev.end());
                    
//                     str=firstPart+n[i/2]+rev;
//                 }
                
//                 bool ans=isPalindrome(str);
//                 if(ans)
//                 {
//                     ans1=ans;
//                     break;
//                 }
//             }
            
//             if(ans1.length())
//             break;
            
//             n[i]='0';
//         }
        
//         return ans1;
        
        
    }
};


// 1234
// 2000

// 12999
    
// 12099

// 13031

// 199
    
// 202

// 4723
    
// 9999



