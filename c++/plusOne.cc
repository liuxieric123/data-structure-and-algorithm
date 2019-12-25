class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int pos = digits.size() - 1;
        while(pos >= 0) {
            digits[pos] = digits[pos] + carry;
            if (digits[pos] >= 10){
                carry = 1;
                digits[pos] = 0;
            } else {
                carry = 0;
                break;
            }
            --pos;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};