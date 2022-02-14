//https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // if(nums.size()==1)
        //     return nums[0];
        int product=1;
       int maxP=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            product*=nums[i];
            maxP=max(maxP,product);
            if(product==0)
            {
                product=1;
            }
        }
        //-2,0,-1
        product=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            product*=nums[i];
            maxP=max(maxP,product);
            if(product==0)
            {
                product=1;
            }
            
        }
        return maxP;
    }
};
