class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char, int> ss;
       char res = 0xff;
       for (int i = 0; i < s.length(); i++) {
           ss[s[i]]++;
       }
       
       for (int i = 0; i < t.length(); i++) {
            ss[t[i]]--;
       }
   
       for ( auto it = ss.begin(); it != ss.end(); ++it ) {
            if (it->second < 0 ) {
                res = it->first;
                break;
            } else if (it->second > 0) {
                //res = it->first;
                break;
            }
        }
        return res;
    }
};