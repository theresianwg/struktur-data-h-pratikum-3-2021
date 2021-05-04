#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct AVLNode {
    int data;
    AVLNode *left, *right;
    int height;
};

struct TrieNode {
    int node;
    bool cek;
    struct TrieNode *child[26];
}*head;

struct AVL{
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int value) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value) {
        
        if(node==NULL)
            return _avl_createNode(value);
        if(value < node->data)
            node->left = _insert_AVL(node->left,value);
        else if(value > node->data)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode* _remove_AVL(AVLNode* node,int value){
        if(node==NULL)
            return node;
        if(value > node->data)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->data)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->data=temp->data;
                node->right=_remove_AVL(node->right,temp->data);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

    void init() {
    head = new TrieNode();     
    head->cek = false;          
    head->node = 0;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }
    
    void insert(string kata) {
        TrieNode *current = head;
        current->node++;
        int temp=0;
        int panjang= kata.length();
        for(int i=0; i<panjang; i++)     {
            temp = (int)kata[i] - (int)'a';        
            if(current->child[temp] == NULL) {   
                current->child[temp] = new TrieNode();
            }
            current->child[temp]->node++;
            current = current->child[temp];        
        }
        current->cek = true;
    }

    bool search(string kata) {
        TrieNode *current = head;
        int temp=0;
        int panjang= kata.length();
        for(int i=0; i<panjang; i++) {
            temp=(int)kata[i]-(int)'a';     
            if(current->child[temp] == NULL){
                return false;        
            }
            current = current->child[temp];
        }
        return current->cek;
    }
};

int main(){
    AVL set;
    set.init();

    int testcase, casetest;
    string kata, cari_kata;
    cin >> testcase;
    for (int i=1; i<= testcase; i++){
        cin >> kata;
        set.insert(kata);
    }

    cin >> casetest;
    for (int i=1; i<= casetest; i++){
        cin >> cari_kata;
        if (set.search(cari_kata)){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }

    return 0;
}
