A Company has decided to give some gifts to all of its employees. For that, the company has given some rank to each employee. Based on that rank, the company has made certain rules for distributing the gifts.
The rules for distributing the gifts are:

Each employee must receive at least one gift.
Employees having higher ranking get a greater number of gifts than their neighbors.
What is the minimum number of gifts required by the company?

Input Format
The first line contains integer T, denoting the number of test cases.
For each test case:
The first line contains integer N, denoting the number of employees.
The second line contains N space-separated integers, denoting the rank of each employee.
Output Format
For each test case print the number of minimum gifts required on a new line.

Constraints
1
<
T
<
10
1<T<10
1
<
N
<
1
0
5
1<N<10 
5
 
1
<
R
a
n
k
<
1
0
9
1<Rank<10 
9
 
Sample 1:
Input
Output
2
5
1 2 1 5 2
2
1 2
7
3
Explanation:
adhering to the rules mentioned above,
Employee # 1 whose rank is 1 gets one gift
Employee # 2 whose rank is 2 gets two gifts
Employee # 3 whose rank is 1 gets one gift
Employee # 4 whose rank is 5 gets two gifts
Employee # 5 whose rank is 2 gets one gift
Therefore, total gifts required is 1 + 2 + 1 + 2 + 1 = 7
Similarly, for test case 2, adhering to the rules mentioned above,
Employee # 1 whose rank is 1 gets one gift
Employee # 2 whose rank is 2 gets two gifts
Therefore, the total gifts required is 1 + 2 = 3

// ------------------------------ SOLUTION ----------------------------- //

#include <bits/stdc++.h>
using namespace std;

long long arr[100010];
long long arr2[100010];

// vector <int > ans;

int main() {
	int T;
	cin >> T;
	
	for(int i=1; i<=T; i++){
	    int N;
	    cin >> N;
	    long long gift=0, temp=0;
	    
	    for(int i=0; i<N; i++)
	        cin >> arr[i];
	        
        // ----------FORWARD PASS---------- //
        
	    arr2[0] = 1;
	    for(int i=1;i<N;i++){
	        if(arr[i]>arr[i-1])
	            arr2[i] = arr2[i-1] + 1;
	        else 
	            arr2[i]=1;
	    }
	    
	    // ----------BACKWARD PASS---------------//
	    
	    gift = arr2[N-1];
	    for(int i=N-2;i>=0;i--){
	        if(arr[i]>arr[i+1])
	            temp = arr2[i+1] + 1;
	        else 
	            temp=1;
	        
	        gift = gift + max(temp,arr2[i]);
	    
	        arr2[i]=temp;
	    }
	    cout << gift << endl;
	    
	   // ans.push_back(gift);
	   // for(int i : ans)
	   //     cout << i << endl;
	    
	}
}
