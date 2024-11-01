Some prime numbers can be expressed as a sum of other consecutive prime numbers.

For Example

5
=
2
+
3
5=2+3,
17
=
2
+
3
+
5
+
7
17=2+3+5+7,
41
=
2
+
3
+
5
+
7
+
11
+
13
41=2+3+5+7+11+13.
Your task is to find out how many prime numbers which satisfy this property are present in the range 
3
3 to 
N
N subject to a constraint that summation should always start with number 
2
2.

Write code to find out the number of prime numbers that satisfy the above-mentioned property in a given range.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of a single integer 
N
N
Output Format
Print the total number of all such prime numbers which are less than or equal to 
N
N.

Constraints
1
≤
T
≤
1
0
5
1≤T≤10 
5
 
2
<
N
≤
1
0
5
2<N≤10 
5


// ---------------------------SOLUTION--------------------------------------- //

#include <bits/stdc++.h>
using namespace std;

const int lt = 1e5 + 1; // contraints given

vector < int > prime; // no. of prime numbers found in between the limit
vector < bool > isPrime(lt,true); // marks true or false for the nnumbers as prime

int main() {
    for(int i=2 ; i*i<=lt; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j=i*i; j<lt; j+=i)
                isPrime[j]=false;
        }
    }
    
    int T;
    cin >> T;
    // stack for plag
    vector < int > ans;
    
    while(T--){ // || while(T != 0)
        int N;
        cin >> N;
        int sum = 5; // 2+3
        int i = 2;
        int cnt = 0;
        
        while(sum <= N){
            if(isPrime[sum]) 
                cnt++;
            sum += prime[i];
            i++;
        }
        
        //cout << cnt << endl;
        ans.push_back(cnt);
    }
    
    // print the res
    for(int i : ans){
        cout << i << endl;
    }
    // while(!st.empty()){
    //     cout << st.top() << endl;
    //     st.pop();
    // }
    // return 0;
}
