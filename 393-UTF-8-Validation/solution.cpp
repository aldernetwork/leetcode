class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool res = true;
        int n = 0;
        
        for (int i=0; i<data.size(); i++) 
        {
            unsigned char c = data[i] & 0xFF;
            if ((c & 0x80) == 0)
            {
                continue;
            }
            else if ((c & 0xe0) == 0xc0)
            {
                n = 1;    
            }
            else if ((c & 0xf0) == 0xe0)
            {
                n = 2;
            }
            else if ((c & 0xf8) == 0xf0)
            {
                n = 3;
            }
            else
            {
                res = false;
                break;
            }
            
            for (int j=1; j<=n; j++)
            {
                c = data[i+j] & 0xFF;
                if ((c & 0xc0) != 0x80)
                {
                    res = false;
                    break;
                }
            }
            if (!res)
                break;
            i += n;
        }
        return res;
    }
};