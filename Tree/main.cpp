#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
private:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    Node * insert(Node *root, int val)
    {
        Node *newNode = new Node();
        newNode->val = val;
        if (root == nullptr)
        {
            root = newNode;
        }
        else if (root->val < val)
        {
            root->right = insert(root->right, val);
        } else {
            root->left = insert(root->left, val);
        }
        return root;
    }
    
    void Preorder(Node *root)
    {
        
        if (root != nullptr) {
            cout << root->val << " ";
            Preorder(root->left);
            Preorder(root->right);
        }
    }
    
    void Inorder(Node *root)
    {
        if (root != nullptr) {
            Inorder(root->left);
            cout << root->val << " ";
            Inorder(root->right);
        }
    }
    
    void Postorder(Node *root)
    {
        if (root != nullptr) {
            Postorder(root->left);
            Postorder(root->right);
            cout << root->val << " ";
        }
    }
    
    int count(Node *root) {
        int x, y;
        
        if (root != nullptr) {
            x = count(root->left);
            y = count(root->right);
            
            return x + y + 1;
        }
        return 0;
    }
    
    int height(Node *root) {
        int x, y;
        
        if (root != nullptr) {
            x = height(root->left);
            y = height(root->right);
            
            if (x > y) {
                return x + 1;
            } else {
                return y + 1;
            }
        }
        return 0;
    }
    
    void rightView(Node *root) {
        queue<Node*> q;
        q.push(root);
        while (q.size() > 0) {
            int len = q.size();
            int count = 0;
            Node *current;
            while (count < len) {
                current = q.front();
                q.pop();
                
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
                
                count++;
            }
            cout << current->val << " ";
        }
    }
    
    void rightViewDFS(Node *root, int count, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        if (count >= result.size()) {
            result.push_back(root->val);
        }
        
        if (root->right != nullptr) {
            rightViewDFS(root->right, count+1, result);
        }
        if (root->left != nullptr) {
            rightViewDFS(root->left, count+1, result);
        }
    }
};

int main()
{
    Node *root = NULL;
    vector<int> arr = {10, 8, 9, 5, 7, 3, 4, 1, 2, 6};
    auto n = arr.size();
    
    for (int i = 0; i < n; i++)
    {
        root = root->insert(root, arr[i]);
    }
    cout << "Pre Order Traveral: " << endl;
    root->Preorder(root);
    cout << endl;
    cout << "In Order Traveral: " << endl;
    root->Inorder(root);
    cout << endl;
    cout << "Post Order Traveral: " << endl;
    root->Postorder(root);
    cout << endl;
    cout << "Number of nodes is: " << endl;
    cout << root->count(root);
    cout << endl;
    cout << "Height of tree is: " << endl;
    cout << root->height(root);
    cout << endl;
    cout << "Right view: " << endl;
    root->rightView(root);
    
    cout << endl;
    vector<int> result;
    cout << "Right view dfs: " << endl;
    root->rightViewDFS(root, 0, result);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
