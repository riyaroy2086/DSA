class Solution {

    List<List<Integer>> ans=new ArrayList<>();
    List<Integer> arr=new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {

        backTrack(ans,arr,nums,0);
        return ans;
        
    }

    public void backTrack(List<List<Integer>> ans,List<Integer>current,int nums[],int i)
    {
        if(i==nums.length)
        {
            ans.add(new ArrayList<Integer>(current)); //adding the totally formed subsets into the main List

            return;
        }
        current.add(nums[i]);               //forming the current subset
        backTrack(ans,current,nums,i+1);
        current.remove(current.size()-1);   //backtracking to other possible subsets
        backTrack(ans,current,nums,i+1);
    }

}
