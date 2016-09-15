class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, so_far = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
                max = nums[i];
        }
        if (max < 0)
            return max;
            
            
        max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            so_far += nums[i];
            if (so_far < 0)
                so_far = 0;
                
            if (so_far > max)
                max = so_far;
                
        }
        
        return max;
    }
};