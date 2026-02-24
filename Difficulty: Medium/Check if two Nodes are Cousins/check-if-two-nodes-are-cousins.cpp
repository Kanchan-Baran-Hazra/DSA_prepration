/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    bool helper(Node* root, int x, int y) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int parent1 = -1, parent2 = -1;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left) {
                    if (node->left->data == x) parent1 = node->data;
                    if (node->left->data == y) parent2 = node->data;
                    q.push(node->left);
                }

                if (node->right) {
                    if (node->right->data == x) parent1 = node->data;
                    if (node->right->data == y) parent2 = node->data;
                    q.push(node->right);
                }
            }

            // after processing one level
            if (parent1 != -1 && parent2 != -1)
                return parent1 != parent2; // same level, diff parent
            if (parent1 != -1 || parent2 != -1)
                return false; 
        }

        return false;
    }

    bool isCousins(Node* root, int x, int y) {
        if (!root || root->data == x || root->data == y)
            return false;
        return helper(root, x, y);
    }
};