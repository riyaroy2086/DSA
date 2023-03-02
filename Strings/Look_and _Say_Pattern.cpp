string solve(int n){
      if(n==1)return "1";
      string temp=solve(n-1);
      string ans="";
      for(int i=0;i<temp.length();i++){
          char curr=temp[i];
          int count=0;
          while(temp[i]==curr and i<temp.length()){
              count++;
              i++;
          }
          string c=to_string(count);
          ans+=c;
          ans+=curr;
          i--;
      }
      return ans;
  }

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        return solve(n);
    }   
};
