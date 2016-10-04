class Solution {
public:
    string toHex(int num) {
        string s;
        unsigned int n = (unsigned int)num;
        
        unsigned int rem;
        char c;
        
        do
        {
            rem = n % 16;
            if (rem < 10)
            {
                c = rem + '0';
            }
            else 
            {
                c = (rem - 10) + 'a';
            }
            s.push_back(c);
            n /= 16;
        } while(n);
        
        reverse(s.begin(), s.end());
        return s;
    }
};