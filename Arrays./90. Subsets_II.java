class Solution {

    public void subs(int[] a,Set<List<Integer>> ans,List<Integer> arr,int i) 
    {
        if(i==a.length)
        {
            ans.add(new ArrayList<Integer>(arr));
            return;
        } 


        arr.add(a[i]);
        subs(a,ans,arr,i+1);
        arr.remove(arr.size()-1);
        subs(a,ans,arr,i+1);

    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        Set<List<Integer>> ans=new HashSet<>();  //to avoid addition of duplicate elements
        List<Integer> curr=new ArrayList<>();

        Arrays.sort(nums); //sorted the array to form subsets in same chronology

        subs(nums,ans,curr,0);

        return new ArrayList<>(ans); 
        
    }
}
