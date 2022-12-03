#include<iostream>
using namespace std;
template<class T>
class Node{
    T data;
    Node* left;
    Node* right;
    public:
        Node(T data){ //creat a Node by data t
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

template<class T>
class BSTree{
    Node* root;
    private: 
        Node* insert(Node* parent, T key){
            if(parent == nullptr){
                return new Node(key); //if current Node = null -> create new Node and return created Node
            }else{
                if(key < parent->data){
                    parent->left = insert(parent->left, key);
                }else{
                    if(key > parent->data){
                        parent->right = insert(parent->right, key);
                    }
                }
                return parent;
            }
        }//create a Node with data and insert to BSTree

        Node* search(Node* root, T key){
            if(root == nullptr){ //nothing to search
                return nullptr;
            }else{
                if(key == root->data){
                    return root;
                }else{
                    if(key < root->data){
                        return search(root->left, key); //continue search in left side of current root(current Node)
                        // if search(root->left, key) found Node with that key -> return search(root->left, key)
                        // -> return the result of  search(root->left, key)
                    }else{
                        return search(root->right, key);
                    }
                }
            }
        }
        //pre-order: parent->left->right: in ra parent truoc nhat
        //in-order: left->parent->right: in ra parent o giua
        //post-order:left->right->parent: in ra parent sau nhat
        void display(Node* node){
            if(node == nullptr)
                return;
            
            display(node->left); //display the part that smaller than current node(parent)
            cout << node->data << " "; //display data of parent
            display(node->right); //display the part that greater than data of parent
        }
    public:
        BSTree(){
            root = nullptr;
        }

        void insertData(T key){
            this->root = insert(this->root, key);
        }

        Node* searchWithKey(T key){
            return search(this->root, key);
        }//find the Node that holds data = key

        void displayIncreaseOrder(){//increase order
            display(this->root);
        }//display BSTree following increase order

        Node* deleteNode(T key){//optional

        }//delete Node that has data = key
};

int main(){
    BSTree bst;
    // bst.insertData(t);
}

//queue: data structure
