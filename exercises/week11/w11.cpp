#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* TaoNode(int x) {
    TreeNode *p = new TreeNode;
    p->data = x;
    p->left = p->right = nullptr;
    return p;
}

TreeNode* Chen(TreeNode *root, int x) {
    if (root == nullptr) return TaoNode(x);
    if (x < root->data) root->left  = Chen(root->left,  x);
    else if (x > root->data) root->right = Chen(root->right, x);
    return root;
}

TreeNode* Tim(TreeNode *root, int x) {
    if (root == nullptr || root->data == x) return root;
    if (x < root->data) return Tim(root->left, x);
    return Tim(root->right, x);
}

TreeNode* TimLonNhat(TreeNode *root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

TreeNode* TimNhoNhat(TreeNode *root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

TreeNode* Xoa(TreeNode *root, int x) {
    if (root == nullptr) return nullptr;
    if (x < root->data) {
        root->left = Xoa(root->left, x);
    } else if (x > root->data) {
        root->right = Xoa(root->right, x);
    } else {
        if (root->left == nullptr) {
            TreeNode *tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == nullptr) {
            TreeNode *tmp = root->left;
            delete root;
            return tmp;
        } else {
            TreeNode *successor = TimNhoNhat(root->right);
            root->data = successor->data;
            root->right = Xoa(root->right, successor->data);
        }
    }
    return root;
}

TreeNode* Xoa01(TreeNode *root, int x) {
    if (root == nullptr) return nullptr;
    if (x < root->data) {
        root->left = Xoa01(root->left, x);
    } else if (x > root->data) {
        root->right = Xoa01(root->right, x);
    } else {
        if (root->left == nullptr) {
            TreeNode *tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == nullptr) {
            TreeNode *tmp = root->left;
            delete root;
            return tmp;
        } else {
            TreeNode *successor = TimLonNhat(root->left);
            root->data = successor->data;
            root->left = Xoa01(root->left, successor->data);
        }
    }
    return root;
}

void Preorder(TreeNode* root) { 
    if (root != nullptr) {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main(){
    TreeNode* root = nullptr;

    root = Chen(root, 50);
    root = Chen(root, 30);
    root = Chen(root, 20);
    root = Chen(root, 40);
    root = Chen(root, 70);
    root = Chen(root, 60);
    root = Chen(root, 80);

    cout << "--- KHOI TAO CAY BST ---" << endl;
    cout << "Cay ban dau (Duyet Preorder): ";
    Preorder(root);
    cout << "\n\n";

    int giaTriCanTim = 100;
    cout << "--- KIEM TRA TIM KIEM ---" << endl;
    if (Tim(root, giaTriCanTim) != nullptr) {
        cout << "-> Tim thay nut " << giaTriCanTim << " trong cay." << endl;
    } else {
        cout << "-> Khong tim thay nut " << giaTriCanTim << " trong cay." << endl;
    }
    cout << "\n";

    cout << "--- KIEM TRA XOA (DELETE) ---" << endl;

    cout << "1. Xoa nut 20 (Nut la):" << endl;
    root = Xoa(root, 20);
    cout << "   Cay sau khi xoa: ";
    Preorder(root);
    cout << "\n\n";

    cout << "2. Xoa nut 30 (Nut co 1 con):" << endl;
    root = Xoa(root, 30);
    cout << "   Cay sau khi xoa: ";
    Preorder(root);
    cout << "\n\n";

    cout << "3. Xoa nut goc 50 (Nut co 2 con):" << endl;
    root = Xoa(root, 50);
    cout << "   Cay sau khi xoa: ";
    Preorder(root);
    cout << "\n";

    // Đổi tên thành root2 để không trùng khai báo biến
    TreeNode* root2 = nullptr;

    root2 = Chen(root2, 50);
    root2 = Chen(root2, 30);
    root2 = Chen(root2, 20);
    root2 = Chen(root2, 40);
    root2 = Chen(root2, 70);
    root2 = Chen(root2, 60);
    root2 = Chen(root2, 80);

    cout << "\n--- KHOI TAO CAY BST 2 ---" << endl;
    cout << "Cay ban dau (Duyet Preorder): ";
    Preorder(root2);
    cout << "\n\n";

    giaTriCanTim = 100;
    cout << "--- KIEM TRA TIM KIEM CAY 2 ---" << endl;
    if (Tim(root2, giaTriCanTim) != nullptr) {
        cout << "-> Tim thay nut " << giaTriCanTim << " trong cay." << endl;
    } else {
        cout << "-> Khong tim thay nut " << giaTriCanTim << " trong cay." << endl;
    }
    cout << "\n";

    cout << "--- KIEM TRA XOA01 (DELETE) ---" << endl;

    cout << "1. Xoa nut 20 (Nut la):" << endl;
    root2 = Xoa01(root2, 20);
    cout << "   Cay sau khi xoa: ";
    Preorder(root2);
    cout << "\n\n";

    cout << "2. Xoa nut 30 (Nut co 1 con):" << endl;
    root2 = Xoa01(root2, 30);
    cout << "   Cay sau khi xoa: ";
    Preorder(root2);
    cout << "\n\n";

    cout << "3. Xoa nut goc 50 (Nut co 2 con):" << endl;
    root2 = Xoa01(root2, 50);
    cout << "   Cay sau khi xoa: ";
    Preorder(root2);
    cout << "\n";
    
    return 0;
}