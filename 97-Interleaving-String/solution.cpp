class Solution {
public:
    string str1, str2, str3;
    int dp(int n1, int n2, vector<vector<int> > arr) {
        
        if (arr[n1][n2] != 0)
            return arr[n1][n2];

        string s1, s2, s3;

        if (n1 < str1.szie())
            s1 = str1.substr(n1, str1.size()-n1);

        if (n2 < str2.szie())
            s2 = str2.substr(n2, str2.size()-n2);


        if ((n1+n2) < str3.szie())
            s3 = str3.substr(n1+n2, str3.size()-n1-n2);
        
        int res = -1;
            
        if (s1.empty())
        {
            res = (s2 == s3)? 1 : -1;
            arr[n1][n2] = res;
            return res;
        }
        
        if (s2.empty())
        {
            res = (s1 == s3)? 1 : -1;
            arr[n1][n2] = res;
            return res;
        }
        
           
        if (s3.empty())
        {
            arr[n1][n2] = res;
            return res;
        }
         
        if (s3[0] != s1[0] && s3[0] != s2[0])
        {
            arr[n1][n2] = res;
            return res;
        }

        int b1 = dp(n1+1, n2, arr), b2 = dp(n1, n2+1, arr);
            
        if (s3[0] == s1[0] && s3[0] != s2[0])
            res = b1;
        else if (s3[0] != s1[0] && s3[0] == s2[0])
            res = b2;
        else if (s3[0] == s1[0] && s3[0] == s2[0])
            res = (b1>0 || b2>0) ? 1 : -1;        
       
       arr[n1][n2] = res;
       return res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        str1 = s1;
        str2 = s2;
        str3 = s3;
        
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
            
        vector<vector<int> > arr;
        return (dp(0, 0, arr) > 0) ? true : false;
 
    }
};