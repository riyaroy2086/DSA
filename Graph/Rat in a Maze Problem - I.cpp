Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1

//-------------------------------------------------------SOLUTION----------------------------------------------------------//

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // using DFS
        vector<string> res;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        dfs(0,0,n,visited,"",res,m);
        
        return res;
    }
    
    void dfs(int i,int j,int n,vector<vector<bool>> &visited,string store,vector<string> &res,vector<vector<int>> &m)
    {
        if(i<0 || j<0 || i>=n || j>=n || visited[i][j] == true) return;
        
        if(m[i][j] == 1 && i == n-1 && j == n-1) // passage 
        {
            res.push_back(store);
        }
        else // UDLR movement
        {
            if(m[i][j] == 1)
            {
                visited[i][j] = true;
                dfs(i-1,j,n,visited,store+"U",res,m);
                dfs(i+1,j,n,visited,store+"D",res,m);
                dfs(i,j-1,n,visited,store+"L",res,m);
                dfs(i,j+1,n,visited,store+"R",res,m);
                visited[i][j] = false; // the new position is not visited yet
            }
        }
    }
};

