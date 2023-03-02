class Solution {
    public int minSetSize(int[] arr) {

        HashMap<Integer,Integer> map=new HashMap<>();
        for(int x: arr)
        {
            map.put(x,map.getOrDefault(x,0)+1);

            //storing the elements and their frequency as keys and values
        }
        
        int af[]=new int[map.size()];
        int k=0;
        for(Integer i:map.values())
        {
            af[k++]=i;             //storing the frequencies of the elements
        }
        Arrays.sort(af);
        int c=0;
        int removed=0;
        
        while(removed<arr.length/2)
        {
            removed+=af[af.length-1-c];      //calculating the frequencies of numbers removed
            c++;
        }
        return c;
    }
}
