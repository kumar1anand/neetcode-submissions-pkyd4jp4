class Solution {
    public int trap(int[] height) {// brute force
        int n = height.length;
        int ans = 0;
        for(int i=1;i<n;i++){
            int leftMax = 0;
            int rightMax = 0;
            //left
            for(int j=0;j<=i;j++){
                leftMax = Math.max(leftMax,height[j]);
            }
            //right
            for(int j=i;j<n;j++){
                rightMax = Math.max(rightMax,height[j]);
            }
            int water = Math.min(leftMax,rightMax)-height[i];
            ans +=(water);
        }
        return ans;
    }
}
