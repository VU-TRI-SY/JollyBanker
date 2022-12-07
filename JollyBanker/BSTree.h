/*Linh Huynh
CSS 342
Instructor:Professor Dimpsey
Program 5*/
#ifndef BSTREE_H_
#define BSTREE_H_
#include "Account.h"
class BSTree {
public:
    BSTree();
    BSTree(const BSTree& tree);
    ~BSTree();
    bool Insert(Account* account);
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int& account_id, Account*& account) const;
    // Delete object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Delete(const int& account_id, Account*& account);
    // BSTree& operator=(const BSTree& tree);
    // displays the contents of a tree to cout; you could also overload operator << 
    void Display() const;
    // int Size() const;
    // friend ostream operator<< (ostream&os, const BSTree& tree);
    void printSt(){
        cout << root_->p_acct->getId() << endl;
        cout << root_->right->p_acct->getId() << endl;
    }
    
private:
    struct Node
    {
        Account* p_acct;
        Node* right;
        Node* left;
        Node(Account* account){
            p_acct = account;
            right = nullptr;
            left = nullptr;
        }
    };
    Node* root_;
    Node* retrieve(Node* root, const int& account_id) const{
        if(root == nullptr){
            return nullptr;
        }else{
            if(account_id == root->p_acct->getId()){
                return root;
            }else{
                if(account_id < root->p_acct->getId()){
                    return retrieve(root->left, account_id);
                }else{
                    return retrieve(root->right, account_id);
                }
            }
        }
    }
    void printTree(Node* root) const{
        if(root == nullptr){
            return;
        }else{
            printTree(root->left);
            root->p_acct->displayFunds();
            cout << endl;
            printTree(root->right);
        }
    }

    void printTree(Node* root, ostream &os) const{
        if(root == nullptr){
            return;
        }else{
            printTree(root->left);
            root->p_acct->displayFunds();
            os << endl;
            printTree(root->right);
        }
    }

    //ancestor is the parent of the node to be deleted
    Node* minValueNode(Node* node)
    {
        Node* current = node;
    
        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;
    
        return current;
    }

    Node* deleteNode(Node* root, const int& account_id){
        if(root == nullptr){
            return root;
        }

        if(account_id < root->p_acct->getId()){ //key < data of current node -> move to left and delete
            root->left = deleteNode(root->left, account_id);
        }else{
            if(account_id > root->p_acct->getId()){ //key > data of current node -> move to right and delete
                root->right = deleteNode(root->right, account_id);
            }else{
                if(root->left == nullptr){ //deleted node has only right child
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }else{
                    if(root->right ==  nullptr){ //deleted node has only right child
                        Node * temp = root->left;
                        delete root;
                        return temp;
                    }
                }
                //deleted Node has 2 children (has sub tree)
                Node* temp = minValueNode(root->right);
                root->p_acct->setId(temp->p_acct->getId());
                root->right = deleteNode(root->right, temp->p_acct->getId());
            }
        }
        return root;
    }

};
#endif


// George Jones Account ID: 500
//     Money Market: $0
//     Prime Money Market: $0
//     Long-Term Bond: $0
//     Short-Term Bond: $0
//     500 Index Fund: $0
//     Capital Value Fund: $0
//     Growth Equity Fund: $0
//     Growth Index Fund: $0

// Johnny Cash Account ID: 1001
//     Money Market: $0
//     Prime Money Market: $3012
//     Long-Term Bond: $10442
//     Short-Term Bond: $14540
//     500 Index Fund: $0
//     Capital Value Fund: $54
//     Growth Equity Fund: $15053
//     Growth Index Fund: $10931

// Hank Williams Account ID: 1253
//     Money Market: $10000
//     Prime Money Market: $0
//     Long-Term Bond: $0
//     Short-Term Bond: $5000
//     500 Index Fund: $10000
//     Capital Value Fund: $10000
//     Growth Equity Fund: $10000
//     Growth Index Fund: $10000