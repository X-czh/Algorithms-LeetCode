// My original solution
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int tmp = digits[n - 1] + 1;
        int carry = tmp / 10;
        digits[n - 1] = tmp % 10;
        for (int i = n - 2; i > -1; i--) {
            tmp = digits[i] + carry;
            carry = tmp / 10;
            digits[i] = tmp % 10;
        }
        
        if (carry == 0) {
            return digits;
        } else {
            int[] result = new int[n + 1];
            result[0] = 1;
            return result;
        }
    }
}

// A better solution without explicit carry
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for(int i= n - 1; i > -1; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        int[] newNumber = new int[n + 1];
        newNumber[0] = 1;

        return newNumber;
    }
}