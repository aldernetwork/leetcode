class Solution {
    const char SPACE   = 0x20;
public:
    int lengthOfLastWord(string s) {
            char *str = (char *)s.c_str();
            int len = 0;
            char *p = str, *q = str;

            while (*q)
            {
            while (*q && *q != SPACE)
            {
                q++;
            }
            len = q - p;
            
            while (*q && *q == SPACE)
            {
                q++;
            }
            
            p = q;
            }
            
           return len;           
            
        
    }
};