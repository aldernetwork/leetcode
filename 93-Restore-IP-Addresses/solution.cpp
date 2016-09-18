class Solution {
public:

    vector<string> restoreIp(string s, int num) {
        vector<string> res, res1;
        
        if (1 == num)
        {
            if (s.empty() || atoi(s.c_str()) > 255) 
            {
                return res;
            }
            res.push_back(s);
            return res;
            
        }
        
        for (int sz = 1; sz < 4; sz++)
        {
            string ip = s.substr(0, sz);
            if (sz == 3 && atoi(ip.c_str()) > 255)
                break;
            res1 = restoreIp(s.substr(sz, s.size()-sz), num-1);
            if (res1.empty())
                break;
           
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