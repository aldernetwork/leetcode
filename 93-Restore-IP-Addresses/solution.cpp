class Solution {
public:

    vector<string> restoreIp(string s, int num) {
        vector<string> res, res1;
        
        if (1 >= num || s.empty())
        {
            if (s.empty() || atoi(s.c_str()) > 255) 
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
        
        for (int sz = 1; sz < 4; sz++)
        {
            string ip = s.substr(0, sz);
            if (sz == 3 && atoi(ip.c_str()) > 255 || ((sz>1) && (ip[0] == '0')))
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