class Solution {
    const int MOD = 1337;
public:
    int quickPow(int a, int b) {
        int res = 1;
        if (1==a || 0 == b)
            return res;
        while (b)
        {
            if (b&1)
            {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int res = 1;
        
        if (b.empty())
            return 1;
        a %= MOD;
        for (int i=b.size()-1; i>=0; i--)
        {
            res = res * quickPow(a, b[i]) % MOD;
            a = quickPow(a, 10);
        }
        return res;
    
    }
};