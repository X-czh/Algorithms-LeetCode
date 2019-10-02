// My original solution

// Time complexity: O(n).
// Space complexity: O(1) extra space.

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        assert(len > 0);
        
        if (len == 1) return true;
        
        // last bit can't be 1
        if (bits[len - 1] == 1) return false;
        
        // now last bit must be 0
        if (bits[len - 2] == 0) return true; // ends with 00, true
        
        // now it ends with 10
        int cnt = 0;
        int i = len - 2;
        while (i >= 0 && bits[i] == 1) {
            i--;
            cnt++;
        }
        return ((cnt % 2) == 0); // if odd cnt (must be several "11" with a "10"), false, otherwise true
    }
};

/* 
 * When reading from the i-th position, if bits[i] == 0, the next character must have 1 bit; 
 * else if bits[i] == 1, the next character must have 2 bits. 
 * We increment our read-pointer i to the start of the next character appropriately. 
 * At the end, if our pointer is at bits.length - 1, then the last character must have a size of 1 bit.
 */

// Time complexity: O(n).
// Space complexity: O(1) extra space.

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            i += bits[i] + 1;
        }
        return i == bits.size() - 1;
    }
};
