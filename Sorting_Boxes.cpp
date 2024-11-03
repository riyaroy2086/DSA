Little Jill jumbled up the order of the letters in our dictionary. Now, Jack uses this list to find the smallest lexicographical string that can be made out of this new order. Can you help him?

You are given a string 
P
P that denotes the new order of letters in the English dictionary.

You need to print the smallest lexicographic string made from the given string 
S
S.

Input Format
The first line contains number of test cases 
T
T
The second line has the string 
P
P
The third line has the string 
S
S
Output Format
Print a single string in a new line for every test case giving the result

Constraints
1
≤
T
≤
1000
1≤T≤1000
Length 
(
P
)
=
26
(P)=26
1
≤
1≤ length 
(
S
)
≤
100
(S)≤100
Sample 1:
Input
Output
2
polikujmnhytgbvfredcxswqaz
abcd
qwryupcsfoghjkldezxvbintma
ativedoc
bdca


// ---------------------------------------------- SOLUTION ----------------------------------------------------- //

#include <bits/stdc++.h>
using namespace std;

string lex(string &P,string &S){
    unordered_map<char,int> mp;
    for(int i=0;i<P.size();i++){
        mp[P[i]] = i;
    }
    
    vector<char> sorted(S.begin(),S.end());
    sort(sorted.begin(), sorted.end(), [&](char a, char b) {
        return mp[a] < mp[b];
    });
    
    return string(sorted.begin(),sorted.end());
}

int main() {
	int T;
	cin >> T;
	cin.ignore();
	
	for (int i = 0; i < T; i++) {
        string P, S;
        getline(cin, P);
        getline(cin, S);

        cout << lex(P,S) << endl;
    }

}
