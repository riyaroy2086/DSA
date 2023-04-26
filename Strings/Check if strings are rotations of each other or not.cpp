// TC-> O(N) 
// SC-> O(1)

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int c=0;
        if(s1==s2)
            return true;
        
        //if doesn't match then
        while(s1!=s2 && c<s1.size())
        {
            //storing 1st
            char ch = s1[0];
            //erasing 0th index upto 1 length
            s1.erase(0,1);
            //pushing it at the back of the string
            s1.push_back(ch);
            c++;
        }
        if(c==s1.size()) return false;
        
        return true;
    }
};
