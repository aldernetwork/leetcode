class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int res = -1;
        for (int i=0; i<s.length(); i++)
        {
            map[s[i]]++;
        }
        for (int i=0; i<s.length(); i++)
        {
            if (map[s[i]] == 1)
            {
               res = i;
               break;
            }
        }
        return res;
    }
};