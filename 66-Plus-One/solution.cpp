class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 0;
        for (auto p = digits.begin(); p != digits.end(); p++)
        {
            if (0 == *p)
            {
                *p = 1;
                carry = 0;
                break;
            }
            else
            {
                *p = 0;
                carry = 1;
            }
        }
        if (carry)
        {
            digits[digits.size()] = 1;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};