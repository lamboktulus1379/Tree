#include <iostream>
#include <vector>

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
        
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        Preorder(root->left);
        Preorder(root->right);
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
    
    return 0;
}
