class Solution {
public:
    bool isPerfectSquare(int num) {
#if 0
		long long L = 1, R = (num >> 1) + 1;
		while (L <= R) {
			long long m = L + ((R - L) >> 1);
			long long mul = m * m;
			if (mul == num) return true;
			else if (mul > num) R = m - 1;
			else L = m + 1;
		}
		return false;
#else
        bool res = false;

        int low = 1, high = (num>>1) + 1;
        while (low <= high)
        {
            long long mid = low + ((high-low)>>1);
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
#endif //0
    }
};