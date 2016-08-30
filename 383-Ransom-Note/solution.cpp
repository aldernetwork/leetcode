class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        bool res = true;
        for(int i= 0; i<magazine.length(); i++)
        {
            map[magazine[i]]++;
        }
        for(int i= 0; i<ransomNote.length(); i++)
        {
            if (map[ransomNote[i]] <= 0)
            {
                res = false;
                break;
            }
            else
            {
                map[ransomNote[i]]--;
            }
        }
        return res;
    }
};