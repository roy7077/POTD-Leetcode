// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    int maximumSwap(int num) {
        
        string s=to_string(num);
        string temp=to_string(num);
        sort(temp.begin(),temp.end(),greater<char>());
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<temp[i])
            {
                for(int k=s.length()-1;k>=0;k--)
                {
                    if(s[k]==temp[i])
                    {
                        s[k]=s[i];
                        s[i]=temp[i];
                        return stoi(s);
                    }
                }
            }
        }
        
        return num;
        
//         int maxi=-1;
//         int ind=-1;
//         int i=0;
//         int tempNum=num;
//         int prev=-1;
//         while(tempNum)
//         {
//             if(tempNum%10 > maxi)
//             {
//                 maxi=tempNum%10;
//                 ind=i;
//             }
            
//             prev=tempNum%10;
//             tempNum/=10;
//             i++;
//         }
        
//         i--;
        
//         // 2nd step
//         if(prev==maxi)
//         return num;
        
//         int j=0;
//         tempNum=num;
//         int newNum=0;
//         while(tempNum)
//         {
//             if(j==i)
//             {
//                 int num1=maxi*pow(10,j);
//                 num1+=newNum;
//                 newNum=num1;
//                 break;
//             }
            
//             if(ind==j)
//             {
//                 int num1=prev*pow(10,j);
//                 num1+=newNum;
//                 newNum=num1;
//             }
//             else
//             {
//                 int num1=(tempNum%10)*pow(10,j);
//                 num1+=newNum;
//                 newNum=num1;
//             }
//             tempNum/=10;
//             j++;
//         }
        
//         return newNum;
    }
};
