class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        bool res = true;
        int i = 0, j = 0;

        while (i < ransomNote.length() )
        {
            if (0 == map[ransomNote[i]])
            {
                while (j < magazine.length() )
                {
                    map[magazine[j]]++;
                    if (magazine[j++] == ransomNote[i])
                        break;
                }
            }
  
            if (map[ransomNote[i]] > 0 )
            {
                map[ransomNote[i]]--;
            }
            else
            {
                res = false;
                break;
            }
            i++;
        }
        return res;
    }
};