//https://leetcode.com/problems/permutations/

class Solution {

    void permute(List<List<Integer>> arr,ArrayList<Integer> element,int[] nums,boolean flags[])
    {
        if(element.size()==nums.length)
        {
            arr.add(new ArrayList<Integer>(element));
            return;
        }

        for(int i=0;i<nums.length;i++)
        {
            if(!flags[i])
            {
                flags[i]=true;
                element.add(nums[i]);
                permute(arr,element,nums,flags);
                element.remove(element.size()-1);
                flags[i]=false;
            }
        }

    }

    public List<List<Integer>> permute(int[] nums) {

        

        List<List<Integer>> arr=new ArrayList<>();

        ArrayList<Integer> element=new ArrayList<>();

        boolean flags[]=new boolean[nums.length];   //using extra space 

        permute(arr,element,nums,flags);

        return arr;
        
    }
}
