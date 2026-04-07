class Solution {
public:
    int minEleInd(vector<int> &nums){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
           
            int mid = start + (end - start)/2;
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;
            //condition for min element
            if(nums[start]<=nums[end]) return start;
            if(nums[prev]>=nums[mid] && nums[next]>=nums[mid]){
                return mid;
            }

            if(nums[start] <= nums[mid]){//left sorted
                start = mid+1;//go in un-sorted
            }else{
                end = mid -1;//right sorted then go for left un sorted
            }
        }
        return -1;
    }
    int findMin(vector<int> &nums) {
        int ind = minEleInd(nums);
        return nums[ind];
    }
};
