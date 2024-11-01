Three characters {#, *, .} represents a constellation of stars and galaxies in space. Each galaxy is demarcated by # characters. There can be one or many stars in a given galaxy. Stars can only be in the shape of vowels {
A
,
E
,
I
,
O
,
U
A,E,I,O,U}. A collection of * in the shape of the vowels is a star. A star is contained in a 3×3 block. Stars cannot be overlapping. The dot(.) character denotes empty space.

Given 
3
×
N
3×N matrix comprising of { #, *, . } character, find the galaxy and stars within them.

Note: Please pay attention to how vowel A is denoted in a 
3
×
3
3×3 block in the examples section below.

Input Format
Input consists of a single integer 
N
N denoting the number of columns.
Output Format
The output contains vowels (stars) in order of their occurrence within the given galaxy. The galaxy itself is represented by the # character.

Constraints
3
≤
N
≤
1
0
5
3≤N≤10 
5


// ---------------------------- SOLUTION ------------------------------ //


#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;cin>>n;
    char co[3][n];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        cin>>co[i][j];
    }
    for(int i=0;i<n-2;i++)
    {
        if(co[0][i]=='#') {cout<<"#";continue;}
        if(co[0][i]=='.' && co[0][i+1]=='*' && co[0][i+2]=='.')
        {
            if(co[1][i]=='*' && co[1][i+1]=='*' && co[1][i+2]=='*')
            if(co[2][i]=='*' and co[2][i+1]=='.' and co[2][i+2]=='*')
            cout<<"A";i+=2;continue;
        }
        if(co[0][i]=='*' and co[0][i+1]=='*' and co[0][i+2]=='*')
        {
            if (co[1][i]=='*' and co[1][i+1]=='*' and co[1][i+2]=='*')
            {
                if (co[2][i]=='*' and co[2][i+1]=='*' and co[2][i+2]=='*')
                {cout<<"E";i+=2;continue;}
            }
            else if(co[1][i]=='.' and co[1][i+1]=='*' and co[1][i+2]=='.')
            {
                 if (co[2][i]=='*' and co[2][i+1]=='*' and co[2][i+2]=='*')
                 {cout<<"I";i+=2;continue;}
            }
            else if(co[1][i]=='*' and co[1][i+1]=='.' and co[1][i+2]=='*')
            {
                if(co[2][i]=='*' and co[2][i+1]=='*' and co[2][i+2]=='*')
                {cout<<"O";i+=2;continue;}
            }
        }
        if(co[0][i]=='*' and co[0][i+1]=='.' and co[0][i+2]=='*')
        if(co[1][i]=='*' and co[1][i+1]=='.' and co[1][i+2]=='*')
        if(co[2][i]=='*' and co[2][i+1]=='*' and co[2][i+2]=='*')
        {cout<<"U";i+=2;continue;}
    }
}
