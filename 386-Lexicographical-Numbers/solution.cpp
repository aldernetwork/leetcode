class Solution {
public:
    int digits(int n) {
        int res = 0;
        if (n==0)
            return 1;
            
        while (n) {
            n /= 10;
            res++;
        }
        return res;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        vector<int> stack;
        res.push_back(1);
        int dn = digits(n);
        do {
            int top = res.back(), to_bt = 0;
            if (top < n)
            {
                int dtop = digits(top), ntop = top;
                if (dtop < dn) 
                {
                    int save = top+1, save_digits=digits(save);
                    if (save <= n && (save % 10) != 0)
                    {
                        stack.push_back(save);
                    }
                    ntop *= 10; 
                    if (ntop <= n)
                    {
                        res.push_back(ntop);
                    }
                    else
                    {
                        to_bt = 1;  
                    }
                }
                else
                {
                    int ttop = ntop, last, unit = 1;  
                    //while (ttop) {
                    if (ttop) {
                        last = ttop % 10;
                        if ( last < 9)
                        {
                            ntop += unit;
                            //break;
                            res.push_back(ntop);
                            
                        }
                        else
                        {
                            
                            to_bt = 1;
                        }
                        //unit *= 10;
                        //ttop /= 10;
                    }
                    //res.push_back(ntop);
                }
                
            }
            else
            {
                to_bt = 1;
            }
            
            if (to_bt) {
                if (stack.empty())
                {
                    break;
                }
                else
                {
                    top = stack.back();
                    stack.pop_back();
                    res.push_back(top);
                }
            }
        } while (1);
        return res;
    }
};