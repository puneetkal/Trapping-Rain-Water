//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans=0;
        int l=0;
        int r=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=leftmax){
                    leftmax=height[l];
                }
                else{
                    ans+=leftmax-height[l];
                }
                l++;
            }
            else{
                if(height[r]>=rightmax){ // greater and equal to
                    rightmax=height[r];
                }
                else{
                    ans+=rightmax-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};