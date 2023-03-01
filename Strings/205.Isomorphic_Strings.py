class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        if(len(s)!=len(t)):
            return False

        w1={}
        w2={}

        x=True
        
        for i in range(0,len(s)):
            

            if(s[i] in w1 and t[i]!=w1[s[i]]):
                x=False
                break
            if(t[i] in w2 and s[i]!=w2[t[i]]):
                 x=False
                 break
            
            w1[s[i]]=t[i]
            w2[t[i]]=s[i]

        return x
