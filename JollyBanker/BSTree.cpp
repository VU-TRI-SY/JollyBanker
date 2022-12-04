#include <iostream>
#include "BSTree.h"
using namespace std;
BSTree::BSTree(){
    root_ = nullptr;
}

BSTree::BSTree(const BSTree& tree){
    //go through all nodes off input 'tree' and insert to this true
}

BSTree::~BSTree(){

}

bool BSTree::Insert(Account* account){
    root_ = insert(root_, account);
    return true;
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

// void printTree(Node* root)