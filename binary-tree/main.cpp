#include<iostream>
#include <map>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    Node *right;
    Node *left;
    Node *parent;
    bool visited = false;
};

class Tree : Node {
public:
    Tree() {
        root = nullptr;
    }

    /// right is greater left is smaller
    void addNewElement (int a) {
        Node *l = new Node();
        Node *current = new Node();
        if (root == nullptr) {
            root = l;
            root->val = a;
            root->right = nullptr;
            root->left = nullptr;
            root->parent = nullptr;
        }
        else {
            current = root;
            while (true) {
                if (current->val < a) {
                    if (current->right == nullptr) {
                        /// create a new pointer
                        current->right = l;
                        l->parent = current;
                        l->val = a;
                        l->left = nullptr;
                        l->right = nullptr;
                        break;
                    }
                    current = current->right;
                }
                else {
                    if (current->left == nullptr) {
                        /// create a new pointer
                        current->left = l;
                        l->parent = current;
                        l->val = a;
                        l->left = nullptr;
                        l->right = nullptr;
                        break;
                    }
                    current = current->left;
                }
            }
        }
    }

    void treeTriversal() {
        Node *current = new Node();
        current = root;
        while (current->left != nullptr)
            current = current->left;

        while (current != root) {
            if (!current->visited) {
                cout << current->val << " ";
                current->visited = true;
            }

            if (current->left != nullptr && !current->left->visited) {
                current = current->left;
                continue;
            }

            if (current->right != nullptr && !current->right->visited) {
                current = current->right;
                continue;
            }

            current = current->parent;
        }

        current = root;
        root->visited = true;
        cout << " | " <<current->val << " | ";

        while (current->right != nullptr)
            current = current->right;

        while (current != root) {
            if (!current->visited) {
                cout << current->val << " ";
                current->visited = true;
            }

            if (current->left != nullptr && !current->left->visited) {
                current = current->left;
                continue;
            }

            if (current->right != nullptr && !current->right->visited) {
                current = current->right;
                continue;
            }

            current = current->parent;
        }
    }

private:
    Node *root;
};


int main() {

    Tree tree;
    tree.addNewElement(9);
    tree.addNewElement(3);
    tree.addNewElement(4);
    tree.addNewElement(1);
    tree.addNewElement(10);
    tree.addNewElement(11);
    tree.addNewElement(12);
    tree.addNewElement(100);
    tree.addNewElement(10);




    tree.treeTriversal();


    return 0;
}
