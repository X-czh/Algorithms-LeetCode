// 1. You can directly use haystack.indexOf(needle)
// 2. Converting to char array improves performance

class Solution {
    public int strStr(String haystack, String needle) {
        char[] haystack_arr = haystack.toCharArray();
        char[] needle_arr = needle.toCharArray();
        
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle_arr.length) return i;
                if (i + j >= haystack_arr.length) return -1;
                if (needle_arr[j] != haystack_arr[i + j]) break;
            }
        }
    }
}