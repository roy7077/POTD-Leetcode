// Time complexity - O(N+M)
// Space complexity- O(1)
class Solution {
    public:
    int compareVersion(string ver1, string ver2) {
        int i=0;
        int j=0;
        while(i<ver1.length() or j<ver2.length())
        {
            int v1=0;
            int v2=0;
            while(i<ver1.length() and ver1[i]!='.')
            {
                v1*=10;
                v1+=(ver1[i]-'0');
                i++;
            } 
            
            while(j<ver2.length() and ver2[j]!='.')
            {
                v2*=10;
                v2+=(ver2[j]-'0');
                j++;
            }
             
            if(v1>v2)
            return 1;
            else if(v1<v2)
            return -1;
            
            i++;
            j++;
        }
        return 0;
    }
};