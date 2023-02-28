class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        w={}
        l=[]

        for i in strs:
            c=''.join(sorted(i))
            if c not in w:
                w[c]=[]
            w[c].append(i)
        
        for j in w:
            l.append(w[j])

        return l
