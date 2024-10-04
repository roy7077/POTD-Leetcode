#define ll long long
class Solution {
    public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(),skill.end());
        int sum=skill[0]+skill[skill.size()-1];
        int i=1;
        int j=skill.size()-1-1;
        ll pro=skill[0]*skill[skill.size()-1];
        
        while(i<j)
        {
            int tempSum=skill[i]+skill[j];
            if(tempSum!=sum)
            return -1;
            
            pro+=(skill[i]*skill[j]);
            i++;
            j--;
        }
        
        return pro;
    }
};
