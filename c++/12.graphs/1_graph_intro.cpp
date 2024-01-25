// components of a graph

// nodes->These are the states or vertex. 
// edges -> Links between states in a graph 

// two types -> undirected->one way edges(->) and directed -> two way edges(<->)
// acyclic and cyclic also is there
// path -> a node cannot appear twice in a path, and adjacent  nodes should have connectivity in a graph
// degree of a graph
// property -> total degree of a graph = 2* number of edges
// directed graph -> indegree , outdegree 

// graph representation in c++
// input
// n(nodes) and m(edges)
// m lines which will represent edges
// two ways to store 

// Adjacency matrix and Adjacency List

// Adjacency matrix -> 2d array of size (n+1)*(n+1) where n is number of nodes (1 based indexing)
// costly thing 
// Adjacency list -> array of size n where n is number of nodes
// in c++ its array of lists vector<int> adj[n+1]

// in weighted graph we store weight in the adjacency matrix , rather than 0 and 1
// to store weight graph in list , we store pairs (2,1) and all in the list






// dfs ->stack
// bfs ->queue
// dfs has 3 states -> preorder, inorder, postorder
// preorder->first time when call comes on the node
// inorder->when call works inside subtree
// postorder->when call comes back to the node, after this call wont come on the same node
// bfs -> level order traversal
// bfs if node is visited then all the nodes attached with it are added to the queue, after moving to next node its elements are also added to the queue
// different properties of components of a graph
// weighted nodes - values are associated with nodes
// weighted edges - values are associated with edges
