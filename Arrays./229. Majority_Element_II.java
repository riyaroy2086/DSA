//https://leetcode.com/problems/majority-element-ii/

//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
    public List<Integer> majorityElement(int[] nums) {

        HashMap<Integer,Integer> map=new HashMap<>();
        
        List<Integer> arr=new ArrayList<>();

        for(int i:nums)
        {
            if(map.containsKey(i)) map.put(i,map.get(i)+1);

            else map.put(i,1);
        }

        for(int i:map.keySet())
        {
            if(map.get(i)>(nums.length/3))
            {
                arr.add(i);
            }
        }

        return arr;
        
    }
}
