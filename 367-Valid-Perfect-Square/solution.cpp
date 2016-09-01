class Solution {
public:
    bool isPerfectSquare(int num) {
        bool res = false;
        if ( 1==num )
            return true;
            
        for (int i=2; i*i <= num; i++)
        {
            int q = num / i;
            
            if ( 0 == (num - i * q))
            {
                int q2 = q / i;
                return ( 0 == (q - i * q2)) && isPerfectSquare(q2);
            }
        }
        return res;
    }
};