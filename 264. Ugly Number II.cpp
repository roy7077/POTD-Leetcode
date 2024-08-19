// class Solution {
//     public:
//     static int* arr;
    
//     Solution(){
//         arr=new int[1691];
//         help();
//     }
//     static void help()
//     {
//         int n=1690;
//         int cnt=1;
//         int i=2;
//         int k=1;
//         arr[1]=1;
        
//         while(cnt<n)
//         {
//             for(int j=2;j<=i;j++)
//             {
//                 bool flag=0;
//                 while(i%j==0)
//                 {
//                     if(j>5)
//                     {
//                         flag=1;
//                         arr[k]=i;
//                         break;
//                     }
//                     i/=j;
//                 }
                
//                 if(flag)
//                 {
//                     cnt++;
//                     k++;
//                     break;
//                 }
//             }
//             i++;
//         }
//     }
    
//     int nthUglyNumber(int n) {
        
//         return arr[n];
//     }
// };


class Solution {
public:
    static int* arr;

    Solution() {
        arr = new int[1691]; // Assuming a maximum of 1690 ugly numbers
        help();
    }

    static void help() {
        int n = 1690;
        int cnt = 1;
        int i2 = 1, i3 = 1, i5 = 1;
        int next2 = 2, next3 = 3, next5 = 5;
        arr[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int nextUgly = min(next2, min(next3, next5));
            arr[i] = nextUgly;
            
            if (nextUgly == next2) {
                i2++;
                next2 = arr[i2] * 2;
            }
            if (nextUgly == next3) {
                i3++;
                next3 = arr[i3] * 3;
            }
            if (nextUgly == next5) {
                i5++;
                next5 = arr[i5] * 5;
            }
        }
    }

    int nthUglyNumber(int n) {
        return arr[n];
    }
};

int* Solution::arr = nullptr;
