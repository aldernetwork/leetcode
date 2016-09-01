class Solution {
public:
    int _getMoneyAmount(int from, int to) {
        if (from >= to)
            return 0;
        
        if (to == (from+1))
            return from;
    
        if (to == (from+2))
            return from+1;
            
        int res = INT_MAX;
        for (int mid = from+1; mid < to; mid++)
        {
            int cost11 = _getMoneyAmount(from, mid-1);
            int cost12 = _getMoneyAmount(mid+1, to);
            int cost1 = (cost11>=cost12)? cost11 : cost12;
            cost1 += mid;
            if (cost1 < res)
                res = cost1;
            
        }

        return res;
    }
    int getMoneyAmount(int n) {

        return _getMoneyAmount(1,n);
    }
};