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
    BSTree& operator=(const BSTree& tree);
    // displays the contents of a tree to cout; you could also overload operator << 
    void Display() const;
    int Size() const;
    friend ostream operator<< (ostream&os, const BSTree& tree);
    
private:
    struct Node
    {
        Account* p_acct;
        Node* right;
        Node* left;
        Node(Account* account){
            p_acct = account;
        }
    };

    Node* root_;
    Node* insert(Node* root, Account* account){
        if(root == nullptr){
            return new Node(account);
        }else{
            if(account->getId() < root->p_acct->getId()){
                root->left = insert(root->left, account);
            }else{
                if(account->getId() > root->p_acct->getId()){
                    root->right = insert(root->right, account);
                }
            }
            return root;
        }
    }
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