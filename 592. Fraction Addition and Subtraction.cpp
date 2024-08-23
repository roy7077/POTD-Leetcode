// I could use inbuild LCM & GCD funtion but i did not use
// I always prefer write to code by my own. this will make
// you feel independent and also help you in OA and interview
// and help you to get more in depth knowledge

class Solution {
    public:
    
    // find the lcm of a numbers
    int LCM(vector<int> v)
    {
        sort(v.begin(),v.end());
        for(int i=v.back();i<=(v.back()*2+1);i++)
        {
            bool flag=1;
            for(auto& it:v)
            {
                if(it%i)
                {
                    flag=0;
                    break;
                }
            }
            
            if(flag)
            return i;
        }
        
        int pro=1;
        for(auto& it:v)
        pro*=it;
        
        return pro;
    }
    
    // find the HCF of two numbers
    int HCF(int a,int b)
    {
        int mini=min(a,b);
        for(int i=mini;i>=2;i--)
        {
            if(a%i==0 and b%i==0)
            return i;
        }
        return -1;
    }
    
    string fractionAddition(string exp) {
        vector<int> deno;
        vector<int> nemo;
        
        for(int i=0;i<exp.length();i++)
        {
            // for numerator
            if(i==0 and (exp[0]!='+' and exp[0]!='-'))
            {
                int num;
                if(exp[i]=='1' and exp[i+1]=='0')
                num=10;
                else
                num=exp[i]-'0';
                
                nemo.push_back(num);
                continue;
            }
            
            if(exp[i]=='+' or exp[i]=='-')
            {
                int num;
                if(exp[i+1]=='1' and exp[i+2]=='0')
                num=10;
                else
                num=exp[i+1]-'0';
                
                if(exp[i]=='+')
                nemo.push_back(num);
                else
                nemo.push_back(-1*num);
            }
            
            // for denominator
            if(exp[i]=='/')
            {
                int num;
                if(exp[i+1]=='1' and exp[i+2]=='0')
                num=10;
                else
                num=exp[i+1]-'0';
                
                deno.push_back(num);
            }
        }
        
        int lcm=LCM(deno);
        int upper=0;
        
        for(int i=0;i<nemo.size();i++)
        upper+=(lcm/deno[i])*nemo[i];
        
        bool isNegative=0;
        if(upper<0)
        {
            isNegative=1;
            upper*=-1;
        }
        
        while(1)
        {
            int fact=HCF(upper,lcm);
            if(fact==-1)
            break;
            
            upper/=fact;
            lcm/=fact;
        }
        
        string up=to_string(upper);
        string lo=to_string(lcm);
        
        if(upper==0)
        return "0/1";
        
        if(isNegative)
        return "-"+up+'/'+lo;
        else
        return up+'/'+lo;
    }
};
