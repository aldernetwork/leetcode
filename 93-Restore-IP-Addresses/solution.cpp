class Solution {
public:

    vector<string> restoreIp(string s, int num) {
        vector<string> res, res1;
        
        if (0 >= num || s.empty())
            return res;
            
        if (1 == num || s.empty())
        {
            if (s.empty() || s.size() >= 4 || atoi(s.c_str()) > 255) 
            {
                return res;
            }
            
            if (s.size()>1 && s[0] == '0')
            {
                return res;
            }
            res.push_back(s);
            return res;
            
        }
        
        int max = min(3, (int)(s.size()));
        for (int sz = 1; sz <= max; sz++)
        {
            string ip = s.substr(0, sz);
            if (sz == 3 && atoi(ip.c_str()) > 255 || ((sz>=2) && (ip[0] == '0')))
                break;
            
            if (num <= 1 || s.size() <= sz)
                break;
            res1 = restoreIp(s.substr(sz, s.size()-sz), num-1);
 
            for (int i = 0; i < res1.size(); i++)  
            {
                string ipStr = ip;
                ipStr += ".";
                ipStr += res1[i];               
                res.push_back(ipStr);
            }

            
        }
        return res;
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        return restoreIp(s, 4);
    }
};