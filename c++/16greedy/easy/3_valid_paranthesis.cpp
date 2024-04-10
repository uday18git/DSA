class Solution {
public:
    bool checkValidString(string s) {
        int leftMin=0;
        int leftMax=0;
        int n=s.size();
        if(n==1 && s[0]=='(')return false;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                leftMin++;
                leftMax++;
            }
            else if(s[i]==')')
            {
                leftMin--;
                leftMax--;
            }
            else
            {
                leftMin--;
                leftMax++;
            }
            if(leftMax<0)
            {
                return false;
            }
            if(leftMin<0)
            {
                leftMin=0;
            }
        }
        return leftMin==0;


    }
};

// brute force solution is to do a descision tree(recursion)
// almost a crime to think the solution that u thought using stack + recursion