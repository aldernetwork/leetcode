class Solution {
public:
    vector<int> grayCode(int n) {
        vector <int> res, res1;
        
        if (0 >= n)
        {
            res.push_back(0);
            return res;
        }
        else if (1 == n)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        res = res1 = grayCode(n-1);
        for(int i = res1.size()-1; i>= 0; i--)
        {
            int offset = (1<<(n-1));
            res.push_back(offset+res1[i]);
        }
        return res;
    }
};