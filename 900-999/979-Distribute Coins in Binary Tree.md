# 979-Distribute Coins in Binary Tree

[Problem](https://leetcode.com/problems/distribute-coins-in-binary-tree/)

## Approach 1: DFS

### Intuition

If the leaf of a tree has 0 coins (balance = -1), then we should push a coin from its parent onto the leaf. If it has say, 4 coins (balance = +3), then we should push 3 coins off the leaf. In total, the number of moves from that leaf to or from its parent is abs(balance). For a node with its leaves, just add up the balances of its leaves (for its leaves) plus the coins it has minus one (for itself), and we get the balance for this subtree. In total, the number of moves from that subtree to or from its parent is abs(balance).

### Solution

Add up the moves from bottom to up, and we get the answer. The process is easily simulated with DFS.

Time complexity: O(n).

Space complexity: O(h) extra space.

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        int balance = distributeCoinsRecu(root);
        assert(balance == 0);
        return moves;
    }
private:
    int moves;

    int distributeCoinsRecu(TreeNode* root) {
        if (!root) return 0;

        int balance = root->val - 1;
        balance += distributeCoinsRecu(root->left);
        balance += distributeCoinsRecu(root->right);

        moves += abs(balance);
        return balance;
    }
};
```
