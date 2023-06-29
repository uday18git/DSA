//real life example
//in dynamic programming we learn from the mistakes
//those who do not remember the past are condemned to repeat it
// properties of dynamic programming
// optimal substructure -> if we can write a recurrence relation, then a problem is said to have optimal substructure
// overlapping subproblems -> if a problem can be broken down into subproblems which are reused several times, then it is said to have overlapping subproblems
// example of dynamic programming
// fib 
//         fib(4)
//         /     \
//     fib(3)    fib(2)
//     /    \     /    \
// fib(2) fib(1) fib(1) fib(0)
// we can see that fib(1) is repeating no need to calculate it again and again
// also we can write a recurrence relation for fib ie fib(n)=fib(n-1)+fib(n-2)
// ways to handle overlapping subproblems
// memoization(top-down) -> A lookup table is maintained and checked before computation of any state . Recursion is involved , the time complexity is reduced in exchange of space complexity of the program
// tabulation(bottom-up) -> Solution is built from base . IT is an iterative process
// memoization
int fib[200]={-1};
int computeFib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(fib[n]!=-1)
    {
        return fib[n];
    }
    int res=fib[n-1]+fib[n-2];
    fib[n]=res; //memoization (storing the results of expensive function calls and returning the cached result when the same inputs occur again)
    return fib[n];
}
// tabulation (we are building from base)
// int n;
// cin>>n;
// vector<int> fib(n+1);
// fib[1]=0,fib[2]=1;
// for(int i=2;i<=n;i++)
// {
//     fib[i]=fib[i-1]+fib[i-2];
// }
// cout<<fib[n]<<endl;
// key points 
// Minimization and maximization problems are generally solved with dp where we want exhaustive solution (Sometimes with binary search on answer).
// "Find number of ways" is also a very popular type of dp problem.
// Wherever we can form recurrance relation or given in question can be solved using DP (sometimes with matrix exponentiation).  