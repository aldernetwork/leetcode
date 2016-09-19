class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool res = false;
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l3 != (l1 + l2))
        {
            return res;
        }
        
        if (s1.empty())
            return s2 == s3;
        
        if (s2.empty())
            return s1 == s3;
            
        if (s3.empty())
            return res;
         
        if (s3[0] != s1[0] && s3[0] != s2[0])
            return res;

        bool b1 = isInterleave(s1.substr(1, l1-1), s2, s3.substr(1, l3-1)), b2 = isInterleave(s1, s2.substr(1, l2-1), s3.substr(1, l3-1));
            
        if (s3[0] == s1[0] && s3[0] != s2[0])
            return b1;
            
        if (s3[0] != s1[0] && s3[0] == s2[0])
            return b2;
            
        if (s3[0] == s1[0] && s3[0] == s2[0])
            return b1 || b2;
            
        return res;    
    }
};