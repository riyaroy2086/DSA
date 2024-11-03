In a Super market we will find many variations of the same product. In the same way we can find many types of rice bags which differ in its quantity, price, brand, and type of rice in it. Many variations of same products exist in a super market. Consider rice for example. We get it in varying quantities 
(
q
)
(q) and at different prices 
(
p
)
(p).
Thus rice bag is unique combination of 
q
,
p
q,p. Customers want to buy the rice bags of their own choices. Each bag has two attributes price and the quantity of rice. The customers have some conditions for buying the rice bags, they have a specific price and quantity that have to be compared with the rice bags before buying them. If the price of rice bag is less than or equal to the customer’s preference and if the quantity is more than given preference, then he/she will buy it. There is only one bag of each type and each customer can buy at most one bag.
Given 
n
n,
m
m representing the number of customers and rice bags respectively, along with the variations of rice bags available in the market and the preferences of customers, find the maximum number of bags that can be sold by the end of the day.

Input Format
The first line contains two space separated integers 
n
n and 
m
m denoting the number of customers and number of rice bags respectively.
Next 
n
n lines consist of two space separated integers 
a
a and 
b
b denoting customer’s preferences viz. customer’s quantity and cost preferences, respectively.
Lastly, the next 
m
m lines consist of two space separated integers q and p denoting the bags quantity and cost, respectively.
Output Format
Print the maximum number of rice bags that can be sold.

Constraints
1
≤
n
,
m
≤
1000
1≤n,m≤1000
1
≤
a
,
b
≤
1
0
5
1≤a,b≤10 
5
 
1
≤
p
,
q
≤
1
0
5
1≤p,q≤10 
5
 
Sample 1:
Input
Output
5 4
35 2400
70 5500
87 6000
20 1700
12 500
50 2500
75 4875
100 7000
25 1250
2
Explanation:
Since price of bag should be less than or equal to customer’s preference and the quantity should be greater than the preferred quantity, customer 2 can buy bag 2 and customer 4 can buy bag 4.
So, in total, 2 bags can be sold to the customers.

Sample 2:
Input
Output
4 7
32 1500
58 5000
87 6200
45 3000
20 1200
60 4500
100 6000
80 5500
35 1400
40 2000
50 2800
4
Explanation:
Since price of bag should be less than or equal to customer’s preference and the quantity should be greater than the preferred quantity, customer 1 can buy bag 5, customer 2 can buy bag 2, customer 3 can buy bag 3 and customer 4 can buy 7th bag.
So, in total, 4 bags can be sold to the customers.

// ----------------------------- Solution ------------------------------------- //


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;

    vector<vector<int>> cust;
    for(int i=0;i<n;i++){
        int q,p;
	    cin >> q >> p;
	    cust.push_back({p,q});
    }
    
    sort(cust.begin(),cust.end());
    
    vector<vector<int>> rice;
    for(int i=0;i<m;i++){
        int q,p;
	    cin >> q >> p;
	    rice.push_back({p,q});
    }
    
    sort(rice.begin(),rice.end());
    
    vector<int> used(m,0);
    int res = 0;
    
    // iterate thru each cust
    for(int i=0;i<n;i++){
        int qty, idx;
        qty = idx = -1;
        // int qty = -1; 
        // int idx = -1;
        
        for(int j=0;j<m;j++){
            if(!used[j]){
                if(rice[j][0] > cust[i][0]) break;
                if(rice[j][1] > cust[i][1]){
                    if(qty == -1){
                        qty = rice[j][1];
                        idx = j;
                    }else{
                        if(qty > rice[j][1]){
                            idx = j;
                            qty = rice[j][1];
                        }
                    }
                }
            }
        }
        if(idx!= -1){
            used[idx] = 1;
            res++;
        }
    }
    cout << res;
}
