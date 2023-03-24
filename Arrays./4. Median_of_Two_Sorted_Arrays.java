class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        List<Integer> arr =new ArrayList<Integer>();

        for(int i:nums1)
        {
            arr.add(i);
        }

        for(int j:nums2)
        {
            arr.add(j);
        }

        Collections.sort(arr);

        int m=(arr.size()/2)-1;

        if(arr.size()%2!=0)
        {
            return (double)arr.get(m+1);
        }

        else
        {
            return (double)(arr.get(m)+arr.get(m+1))/2;
        }

    }
}
