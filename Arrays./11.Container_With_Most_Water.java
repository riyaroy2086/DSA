class Solution {
    public int maxArea(int[] height) {
        
        int l=0 , r=height.length-1; //Initializing the left and right pointer
        int max=0;   
        while(l<r)
        {
            int w=r-l;     //calculating the width
            int h=Math.min(height[l],height[r]); //taking the minimum of left and right as the height 
            int area=h*w;
            max=Math.max(max,area);
            if(height[l]<height[r])
            {
                l++;  //moving the left pointer to right if the left is lower than the right
            }
            else if(height[r]<height[l])
            {
                r--;  //moving the right pointer to left if the right is lower than the left
            }
            else
            {
                l++;     //if equal then moving both the pointers
                r--;
            }
        }
        return max;

    }
}
