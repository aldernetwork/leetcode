class Solution {
public:
    bool isPerfectSquare(int num) {
        bool res = false;
        for (int i=0; ; i++)
        {
            int square = i * i;
            if (square == num)
            {
                res = true;
                break;
            }
            else if ( square > num)
            {
                break;
            }
        }
        return res;
    }
};