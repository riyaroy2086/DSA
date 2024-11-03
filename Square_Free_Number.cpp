In the theory of numbers, square free numbers have a special place. A square free number is one that is not divisible by a perfect square (other than 
1
1). Thus 
72
72 is divisible by 
36
36 (a perfect square), and is not a square free number, but 
70
70 has factors 
1
,
2
,
5
,
7
,
10
,
14
,
35
1,2,5,7,10,14,35 and 
70
70. As none of these are perfect squares (other than 
1
1), 
70
70 is a square free number.

For some algorithms, it is important to find out the square free numbers that divide a number. Note that 
1
1 is not considered a square free number.

In this problem, you are asked to write a program to find the number of square free numbers that divide a given number.

Input Format
The only line of the input is a single integer 
N
N which is divisible by no prime number larger than 
19
19.
Output Format
One line containing an integer that gives the number of square free numbers (not including 
1
1).
Constraints
N
<
1
0
9
N<10 
9
 
Sample 1:
Input
Output
20
3
Explanation:
N
=
20
N=20

If we list the numbers that divide 
20
20, they are

1
,
2
,
4
,
5
,
10
,
20
1,2,4,5,10,20

1
1 is not a square free number, 
4
4 is a perfect square, and 
20
20 is divisible by 
4
4, a perfect square. 
2
2 and 
5
5, being prime, are square free, and 
10
10 is divisible by 
1
,
2
,
5
1,2,5 and 
10
10, none of which are perfect squares. Hence the square free numbers that divide 
20
20 are 
2
,
5
,
10
2,5,10. Hence the result is 
3
3.

Sample 2:
Input
Output
72
3
Explanation:
N
=
72
N=72. The numbers that divide 
72
72 are

1
,
2
,
3
,
4
,
6
,
8
,
9
,
12
,
18
,
24
,
36
,
72
1,2,3,4,6,8,9,12,18,24,36,72

1
1 is not considered square free. 
4
,
9
4,9 and 
36
36 are perfect squares, and 
8
,
12
,
18
,
24
8,12,18,24 and 
72
72 are divisible by one of the. Hence only 
2
,
3
2,3 and 
6
6 are square free. (It is easily seen that none of them are divisible by a perfect square). The result is 
3
3.

// ------------------ SOLUTION ----------------------------------- //

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    // Declare variables
    long int n;                     // The number 'n' to check divisors for
    double sqnum;                   // Variable to store the square root of a divisor
    long int i, j = 0, chksqr;      // Variables for loops and temporary storage
    vector<long int> temp;          // Using a vector to store perfect square divisors
    int count = 0, k;               // Variables for counting divisors and iterating through the temp vector
    
    // Take user input for the number 'n'
    cin >> n;
    
    // Loop to find all divisors of 'n' from 2 to n/2
    for(i = 2; i <= n / 2; i++)
    {
        // If 'i' is a divisor of 'n'
        if(n % i == 0)
        {    
            count++;  // Increment divisor count
            sqnum = sqrt(i);  // Compute the square root of 'i'
            chksqr = sqnum;   // Store the square root result as an integer
            
            // Check if 'i' is a perfect square
            if(chksqr == sqnum)
            {
                count--;      // If 'i' is a perfect square, decrement the count
                temp.push_back(i);  // Store perfect square divisors in the vector 'temp'
                j++;          // Increment the number of perfect square divisors
            }
            else
            {
                // Check if 'i' is divisible by any previously found perfect square divisors
                for(k = 0; k < j; k++) 
                {
                    // If 'i' is greater than the perfect square divisor in temp and j is not 0
                    if(i > temp[k] && j != 0)
                    {
                        // If 'i' is divisible by a previously stored perfect square divisor
                        if(i % temp[k] == 0)
                        {    
                            count--;  // Decrement count if divisible
                            k = j + 1;  // Exit the loop early as no further checks are needed
                        }
                    }
                    else
                        break;  // Break loop if no further perfect square divisors to check
                }
            }
        }
    }

    // Print the final count of divisors excluding perfect squares and divisors of perfect squares
    cout << count << endl;
}
