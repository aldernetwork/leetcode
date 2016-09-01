class Solution {
public:
    bool isPerfectSquare(int num) {
        bool res = false;

        int low = 1, high = num;
        while (low <= high)
        {
            int mid = low + ((high-low)>>1);
            long long delta = mid * mid - num;
            if (0 == delta)
            {
                res = true;
                break;
            }
            else if (delta > 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};