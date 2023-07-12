Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


 

Constraints:
1 ≤ V, E ≤ 105


//----------------------------------------------SOLUTION-------------------------------------//


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V,vector<int> adj[]) {
        //vector<bool> visited(V,false); // Sc-> O(V)
        vector<int> visited(V,0);
        
        for(int v=0;v<V;++v)
        {
            if(!visited[v]) // traversing thru the visited vector 
            //if any node/vertex not visited and calling the DFS function
            {
                if(DFS(v,-1, visited, adj)) return true;
            }
        }
        return false;
    }
    
    bool DFS(int v,int parent,vector<int> &visited, vector<int> adj[])
    {
        //  the current vertex v as visited by setting the corresponding element in the visited array to true
        //visited[v] = true;
        visited[v] = 1;
        
        // for all the neighbouring nodes of a vertex
        for(int i :adj[v])
        {
            if(!visited[i])
            {
                if(DFS(i,v, visited, adj)) return true;
            }
            else if(i != v) return true; // node != parent
        }
        return false;
    }
};
