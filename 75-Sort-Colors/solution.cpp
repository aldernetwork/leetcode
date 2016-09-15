class Solution {
public:
    void swap(vector<int>& nums, int i, int j)
    {
        if (i != j)
        {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    void sortColors(vector<int>& nums) {
        int lt = -1, sz = nums.size(), gt = sz, i=0;
        
        while(i < gt)   
        {
            if (0 == nums[i])  
            {
                swap(nums, lt+1, i);
                lt++;
                i++;
            }
            else if (1 == nums[i])
            {
                i++;    
            }
            else // 2
            {
                swap(nums, i, gt-1);
                gt--;
            }
        }
    }
};