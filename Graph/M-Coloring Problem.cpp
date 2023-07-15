Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0
Your Task:
Your task is to complete the function graphColoring() which takes the 2d-array graph[], the number of colours and the number of nodes as inputs and returns true if answer exists otherwise false. 1 is printed if the returned value is true, 0 otherwise. The printing is done by the driver's code.
Note: In Example there are Edges not the graph.Graph will be like, if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.Function will be contain 2-D graph not the edges.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 20
1 ≤ E ≤ (N*(N-1))/2
1 ≤ M ≤ N

//--------------------------------------------------------------------SOLUITON-------------------------------------------------------------------//

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> st;
        stack<int> num;
        int n = 0;
        for(char i :s)
        {
            if(isdigit(i)) // if the element is a digit
                n=n*10 + (i - '0');
            else if(i == '[') // if open brackets
            {
                st.push(res);
                // st.push(to_string(n));
                num.push(n);
                n=0;
                res ="";
                //string str = decodeString(s.substr(i+1)); // elements inside brackets decoded / seperated and added into res n no. of times
                // for(int j=0;j<n;++j)
                // {
                //     res+=str;
                // }
                // n=0;
                // excluding brackets both
                //The index i is also updated to point to the character after the closing square bracket (])
                // i =  i + str.length()-1; // updating i 
            }
            else if(i == ']')
            {
                string temp = res;
                res =st.top();
                st.pop();
                //int c = stoi(st.top());
                // st.pop();
                // res = temp + res*c;
                for(int j = num.top();j>0;--j) res+= temp;
                num.pop();
            }
            else
            {
                res+= i;
            }   
        }

        return res;
    }
};

// Stack based solution gives TLE

// ----------------------------------------------------------------SOLUTION : 2 -------------------------------------------------------------------- //

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) 
    {
        vector<int> color(n,0);
   
        if(func(0,color,graph,m,n)) return true;
        
        return false;
    }
    
    bool func(int v,vector<int> &color,bool graph[101][101], int m, int n)
    {
        if(v == n) return true;
        
        for(int i=1;i<=m;++i)
        {
            if(check(v,color,graph,i,n))
            {
                color[v]=i;
                if(func(v+1,color,graph,m,n)) return true;
                color[v]=0;
            }
        }
        return false;
    }
    bool check(int v,vector<int> &color,bool graph[101][101],int col,int n)
    {
        for(int i=0;i<n;++i)
        {
           if(i!=v && graph[i][v] == 1 && color[i] == col) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
