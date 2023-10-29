class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0)nn=-1*nn;
        while(nn)
        {
            if(nn%2)
            {
                ans=ans*x;
                nn--;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) ans= (double)(1.0)/(double)(ans);
        return ans;
    }
};


// brute

// class Solution {
// public:
//     double myPow(double x, int n) {
//         double ans=1;
//         if(n>0)
//         {
//             for(long long i=0;i<n;i++)
//             {
//                 ans = (x*ans);
//             }
//         }
//         // we have to take long long because there is an edge case when extreme negative value will overflow because see the range of int
//         else if(n<0)
//         {
//             for(long long i=0;i<-n;i++)
//             {
//                 ans = (ans/x);
//             }
//         }        
//         return ans;
//     }
// };