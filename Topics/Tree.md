# Tree

## Traversal

![tree_traveral](../img/tree_traverse.png)

### Inorder (DFS)

Time complexity: O(n).

Space complexity: O(n).

Recusive:

```c++
void helper(TreeNode* root, vector<int>& result) {
    if (root) {
        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    helper(root, result);
    return result;
}
```

Iterative:

```c++
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    stack<TreeNode*> s;
    auto curr = root;

    while (curr || !s.empty()) {
        // go left as far as possible
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }

        // add the root
        curr = s.top();
        s.pop();
        inorder.push_back(curr->val);

        // turn right
        curr = curr->right;
    }

    return inorder;
}
```

### Preorder (DFS)

Time complexity: O(n).

Space complexity: O(n).

Recusive:

```c++
void helper(TreeNode* root, vector<int>& result) {
    if (root) {
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    helper(root, result);
    return result;
}
```

Iterative:

```c++
vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> preorder;
    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        auto curr = s.top();
        s.pop();
        preorder.push_back(curr->val);

        if (curr->right) {
            s.push(curr->right);
        }
        if (curr->left) {
            s.push(curr->left);
        }
    }

    return preorder;
}
```

### Postorder (DFS)

Time complexity: O(n).

Space complexity: O(n).

Recusive:

```c++
void helper(TreeNode* root, vector<int>& result) {
    if (root) {
        helper(root->left, result);
        helper(root->right, result);
        result.push_back(root->val);
    }
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    helper(root, result);
    return result;
}
```

Iterative:

```c++
vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};

    deque<int> postorder;
    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        auto curr = s.top();
        s.pop();
        postorder.push_front(curr->val);
        if (curr->left) {
            s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }

    return vector<int>(postorder.begin(), postorder.end());
}
```

### Level Order (BFS)

Time complexity: O(n).

Space complexity: O(n).

```c++
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> level_order;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> level;
        int level_size = q.size();
        for (int i = 0; i < level_size; i++)
            auto curr = q.front();
            q.pop();
            level.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        level_order.push_back(level);
    }

    return level_order;
}
```

### Vertical Order

## Dynamic Programming On Tree
