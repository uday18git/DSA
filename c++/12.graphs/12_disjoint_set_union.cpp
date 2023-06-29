//union and find
//disjoint set union
// set -> S = {1,2,3,4} P= {4,5,6,9}
// every set has a leader 
//let ,  Parent[1]=Parent[2]=Parent[3]=Parent[4]=2  used to identify the set

// 1 2 3 4
// union (1,2), union(3,4)
// 1   3
// ^   ^
// |   |
// 2   4
// union(2,4) 

// naive implementation
void make(int v)
{
    parent[v]=v;
}
