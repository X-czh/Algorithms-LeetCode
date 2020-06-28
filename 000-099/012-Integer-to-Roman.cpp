class Solution {
public:
    string intToRoman(int num) {
        assert(num >= 1 && num <= 3999);
        
        string ans;
        
        int thousands = num / 1000;
        for (int i = 0; i < thousands; i++) {
            ans += "M";
        }
        
        num %= 1000;
        int hundards = num / 100;
        if (hundards == 9) {
            ans += "CM";
        } else if (hundards == 4) {
            ans += "CD";
        } else {
            if (hundards >= 5) {
                ans += "D";
            }
            for (int i = 0; i < hundards % 5; i++) {
                ans += "C";
            }
        }
        
        num %= 100;
        int tens = num / 10;
        if (tens == 9) {
            ans += "XC";
        } else if (tens == 4) {
            ans += "XL";
        } else {
            if (tens >= 5) {
                ans += "L";
            }
            for (int i = 0; i < tens % 5; i++) {
                ans += "X";
            }
        }
        
        num %= 10;
        if (num == 9) {
            ans += "IX";
        } else if (num == 4) {
            ans += "IV";
        } else {
            if (num >= 5) {
                ans += "V";
            }
            for (int i = 0; i < num % 5; i++) {
                ans += "I";
            }
        }
        
        return ans;
    }
};