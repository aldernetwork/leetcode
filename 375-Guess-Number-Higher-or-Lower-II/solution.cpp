class Solution {
public:
    int _getMatrix(int *result, int n, int i, int j)
    {
        return *(result + n * i + j);
    }
    void _setMatrix(int *result, int n, int i, int j, int val)
    {
        *(result + n * i + j) = val;
    }
    int _getMoneyAmount(int from, int to, int *result, int n) {
        int val = _getMatrix(result, n, from, to);
        if (-1 != val) 
            return val;
        int res = INT_MAX;
        for (int mid = from+1; mid < to; mid++)
        {
            int cost11 = _getMoneyAmount(from, mid-1, result, n);
            int cost12 = _getMoneyAmount(mid+1, to, result, n);
            int cost1 = (cost11>=cost12)? cost11 : cost12;
            cost1 += mid;
            if (cost1 < res)
                res = cost1;
            
        }
        _setMatrix(result, n, from, to, res);
        return res;
    }
    int getMoneyAmount(int n) {
        int n1= n+1;
        int *result = (int *)malloc(n1*n1*sizeof(int));
        memset(result, -1, n1*n1*sizeof(int));
        for (int i=1; i<n1; i++)
        {
            _setMatrix(result, n1, i, i, 0);
            if ((i+1) < n1)
            _setMatrix(result, n1, i, i+1, i);
        }
        return _getMoneyAmount(1,n, result, n1);
    }
};