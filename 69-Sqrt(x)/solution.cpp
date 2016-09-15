class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
            
        int l = 1, h = x;
        long long square;
        while (l < h)
        {
            long long mid = l + ((h-l) >> 1);
            square = mid * mid;
            if (square > x)
            {
                h = mid -1;
            }
            else if (square == x)
            {
                return mid;
            }
            else
            {
                l = mid + 1;
            }
            
        }
        square = l;
        square = square * square;
        if (square > x)
            l--;
        return l;
        
    }
};