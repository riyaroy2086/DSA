Given an array of integers 
A
A, and an integer 
K
K find a number of happy elements.

Element 
X
X is happy if there exists at least 
1
1 element whose difference is less than 
K
K i.e. an element 
X
X is happy if there is another element in the range 
[
X
−
K
,
 
X
+
K
]
[X−K, X+K] other than 
X
X itself.

Input Format
The first line contains two integers 
N
N and 
K
K where 
N
N is the size of the array and 
K
K is a number as described above. The second line contains 
N
N integers separated by space.

Output Format
Print a single integer denoting the total number of happy elements.

Constraints
1
≤
N
≤
1
0
5
1≤N≤10 
5
 
0
≤
K
≤
1
0
5
0≤K≤10 
5
 
0
≤
A
[
i
]
≤
1
0
9
0≤A[i]≤10 
9
 
Sample 1:
Input
Output
6 3
5 5 7 9 15 2
5
Explanation:
Other than number 
15
15, everyone has at least 
1
1 element in the range 
[
X
−
3
,
X
+
3
]
[X−3,X+3]. Hence they are all happy elements. Since these five are in number, the output is 
5
5.

Sample 2:
Input
Output
3 2
1 3 5
3
Explanation:
All numbers have at least 
1
1 element in the range 
[
X
−
2
,
 
X
+
2
]
[X−2, X+2]. Hence they are all happy elements. Since these three are in number, the output is 
3
3.

// ------------------------------------------------------- SOLUTION ---------------------------------------------------- //

#include <bits/stdc++.h>
using namespace std;

// int countHappy(vector<int>&arr, int K){
//     int c = 0;
//     sort(arr.begin(),arr.end());
//     int N = arr.size();
    
//     for(int i=0;i<N;i++){
//         int l = arr[i]-K;
//         int u = arr[i]+K;
        
//         auto lower = lower_bound(arr.begin(),arr.end(),l);
//         auto upper = upper_bound(arr.begin(),arr.end(),u);
        
//         int countInRange = upper-lower;
        
//         if(countInRange > 1) // happy
//             c++;
//     }
//     return c;
// }


// --------------------------- APPROACH 2 --------------------------------- //

// int countHappy(const vector<int> &arr, int K){
//     int c = 0;
//     unordered_set<int> seen;
    
//     for(int i : arr){
//         for(int j=i-K;j<=i+K;j++){
//             if(seen.count(j)>0){
//                 c++;
//                 break;
//             }
//         }
//         seen.insert(i);
//     }
//     return c;
// }

// --------------------------- APPROACH 3 --------------------------------- //

int happy(int arr[], int N , int K){
    int c = 0;
    for(int i=0;i<N;i++){
        int curr = arr[i];
        int l = i;
        int u = i;
        
        if(i==0){
            while(arr[u+1]==curr)
                u++;
            if(arr[u+1]<=curr+K && arr[u+1]>=curr-K)
                c++;
        }
        else if(i<N-1){
            while(arr[u+1]==curr)
                u++;
            while(arr[l-1]==curr)
                l--;
            
            if (((arr[l - 1] <= curr + K) && (arr[l - 1] >= curr - K)) || 
                ((arr[u + 1] <= curr + K) && (arr[u + 1] >= curr - K)))
                c += 1;
        }else{
            while(arr[l-1]==curr)
                l--;
            
            if (((arr[l - 1] <= curr + K) && (arr[l - 1] >= curr - K)))
                c += 1;
        }
    }
    return c;
}

int main() {
// 	int N,K;
// // 	int arr[N];
//     vector<int> arr(N);
// 	cin >> N >> K;
// 	for(int i=0;i<N;i++){
// 	    cin >> arr[i];
// 	}
    int N, K;
    cin >> N >> K;
    int arr[N];
    // vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
	cout << happy(arr,N,K) << endl;
}
