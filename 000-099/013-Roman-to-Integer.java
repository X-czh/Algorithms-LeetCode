class Solution {
    public int romanToInt(String s) {
        int total = 0;
        int num = 0;
        int prev = 0;
        
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'I':
                    num = 1;
                    break;
                case 'V':
                    num = 5;
                    break;
                case 'X':
                    num = 10;
                    break;
                case 'L':
                    num = 50;
                    break;
                case 'C':
                    num = 100;
                    break;
                case 'D':
                    num = 500;
                    break;
                case 'M':
                    num = 1000;
                    break;
                default:
                    throw new IllegalArgumentException("Illegal Input");
            }
            total += num;
            
            // subtraction
            if (num > prev) {
                total -= 2 * prev;
            } 
        
            prev = num;
        }
        
        return total;
    }
}