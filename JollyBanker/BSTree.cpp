#include <iostream>
#include "BSTree.h"
using namespace std;
BSTree::BSTree(){
    root_ = nullptr;
}

BSTree::BSTree(const BSTree& tree){
    
}

BSTree::~BSTree(){
    cleantree(root_);
    root_ = nullptr;
}

bool BSTree::Insert(Account* account){
    if(root_ == nullptr){
        root_ = new Node(account);
        return true;
    }else{
        Node*temp = root_;
        Node* cur = nullptr;
        while(temp != nullptr){
            if(account->getId() < temp->p_acct->getId()){
                cur = temp;
                temp = temp->left;
            }else{
                if(account->getId() > temp->p_acct->getId()){
                    cur = temp;
                    temp = temp->right;
                }else{
                    return false;
                }
            }
        }
        if(account->getId() < cur->p_acct->getId()){
            cur->left = new Node(account);
        }else{
            cur->right = new Node(account);
        }
        return true;
    }
}

bool BSTree::Retrieve(const int& account_id, Account*& account) const{
    Node* res = retrieve(root_, account_id);
    if(res == nullptr){
        account = nullptr;
        return false;
    }else{
        account = res->p_acct;
        return true;
    }
}

void BSTree::Display() const{
    printTree(root_);
}

bool BSTree::Delete(const int& account_id, Account*& account){
    Node* res = deleteNode(root_, account_id);
    account = res->p_acct;
    return account != nullptr;
}
