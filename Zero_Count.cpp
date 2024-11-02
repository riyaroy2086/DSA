You are given a binary string B of length L which contains K ones and remaining zeros. You are required to place the K ones in the binary string in such a way that the longest consecutive zeros have the least length possible. Once such a binary string is constructed, you are required to print the length of the contiguous block of zeros, which has the largest length.

Input Format
Single line consisting of two space separated integers denoting 
L
L and 
K
K.

Output Format
Print a single integer denoting the length of the longest consecutive zeros as per the problem.

Constraints
0
≤
K
≤
L
0≤K≤L
1
≤
L
≤
1
0
6
1≤L≤10 
6
 
Sample 1:
Input
Output
3 1
1
Explanation:
B is of length 3 and it has 1 one’s.
So the possible strings as per the problem are 010, 001, 100.
In the first case, the maximum length of consecutive zeros is 1 whereas in the other two cases it is 2. Hence the constructed binary string is 010 and the output is 1.

Sample 2:
Input
Output
3 3
0
Explanation:
B is of length 3 and it has all three one’s. There is no block of zeros, hence the output is 0.


// -------------------------------------------------------- SOLUTION ---------------------------------------------------------------------- //

#include <bits/stdc++.h>
using namespace std;

int longest(int l,int k){
    if(k == 0) return k;
    else if(k == l) return 0;
    else{
        int min = (l-k)/(k+1);
        return min;
    }
}

int main() {
	int L,K;
	cin >> L >> K;
    cout << longest(L,K) << endl;
}
