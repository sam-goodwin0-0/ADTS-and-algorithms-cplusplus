//a height-balanced BST

#include <algorithm>
using namespace std;

class TreeNode{
public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    int value;

    TreeNode(int v) : value(v) {}

    ~TreeNode(){
        delete left;
        delete right;
    }
};

class AVLTree{
    TreeNode* root = nullptr;

public:
    int height(TreeNode* subtree){
        if (subtree == nullptr) return -1;

        int lHeight = height(subtree->left);
        int rHeight = height(subtree->right);

        return max(lHeight, rHeight) + 1;
    }

    int check(bool &AVL, TreeNode* subtree){
        if (!subtree) return -1;

        int lHeight = check(AVL, subtree->left);
        if (!AVL) return -2;
        int rHeight = check(AVL, subtree->right);
        if (!AVL) return -2;

        if (abs(lHeight-rHeight) > 1){
            AVL = false;
            return -2;
        }
        return max(lHeight,rHeight) + 1;
    }

    bool isAVL(){
        bool AVL = true;
        check(AVL, root);
        return AVL;
    }

    void left_rotate(TreeNode* &subtree){
        // right child should become parent, parent becomes left child
        TreeNode* parent = subtree->right;
        subtree->right = parent->left;
        parent->left = subtree;
        subtree = parent;
    }

    void right_rotate(TreeNode* &subtree){
        // left child should become parent, parent becomes right child
        TreeNode* parent = subtree->left;
        subtree->left = parent->right;
        parent->right = subtree;
        subtree = parent;
    }

};

