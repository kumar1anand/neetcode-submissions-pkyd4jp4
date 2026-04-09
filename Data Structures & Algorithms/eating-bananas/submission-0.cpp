class Solution {
public:
    int maxEle(vector<int>& piles){
        int maxVal = INT_MIN;
        for(auto it:piles){
            maxVal = max(maxVal,it);
        }
        return maxVal;
    }
    int rate(vector<int>&nums,int k){
        int time=0;
        for(int i=0;i<nums.size();i++){
            time += (nums[i]+k-1)/k;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxEle(piles);
        while(low<=high){
            int mid = low +(high-low)/2;
            int k = rate(piles,mid);
            if(k<=h){
                high = mid -1 ;
            }else{
                low  = mid+1;
            }
        }
        return low;
    }
};
