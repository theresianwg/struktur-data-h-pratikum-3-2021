#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
 
typedef struct AVLNode_t
{
    int data;
    int id;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;
 
typedef struct AVL_t
{
    AVLNode *_root;
}AVL;
 
AVLNode* _avl_createNode(int value, int index) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->id = index;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
AVLNode* _search(AVLNode *root, int index) {
    while (root != NULL) {
        if (index < root->id)
            root = root->left;
        else if (index > root->id)
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
 
AVLNode* _rightRotate(AVLNode* pivotNode) {
 
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
 
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value, int index) {
 
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value, index);
    if(index < node->id)
        node->left = _insert_AVL(avl,node->left,value, index);
    else if(index > node->id)
            node->right = _insert_AVL(avl,node->right,value, index);
 
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right));
 
    int balanceFactor=_getBalanceFactor(node);
 
    if(balanceFactor > 1 && index < node->left->id) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && index > node->left->id) //
                return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && index > node->right->id)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && index < node->right->id)
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
 
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0)
        return _rightCaseRotate(node);
 
    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0)
        return _rightLeftCaseRotate(node);
 
    return node;
}
 
void avl_init(AVL *avl) {
    avl->_root = NULL;
}
 
bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}
 
bool avl_find(AVL *avl, int index) {
    AVLNode *temp = _search(avl->_root, index);
    if (temp == NULL)
        return false;
 
    if (temp->id == index)
        return true;
    else
        return false;
}
 
void avl_insert(AVL *avl,int value, int index){
    if(!avl_find(avl,index)){
        avl->_root=_insert_AVL(avl,avl->_root,value,index);
    }
 
}
 
void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
    }
 
}
 
void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}
 
int SumUtil(AVL *avl, int index)
{
    AVLNode *temp = _search(avl->_root, index);
    return temp->data;
}
 
int main(){
    AVL pohon;
    avl_init(&pohon);
 
    int banyakbarang, banyaktransaksi;
    int temp_idbarang, temp_harga;
    int sum = 0;
    int temp_banyakbeli, temp_idbeli;
    
    scanf("%d%d", &banyakbarang, &banyaktransaksi);
 
    for(int i = 0; i < banyakbarang; i++){
        scanf("%d%d", &temp_idbarang, &temp_harga);
 
        if(temp_idbarang != i + 1)
        {
            printf("ID harus urut\n");
            return 0;
        }
        else {
            avl_insert(&pohon, temp_harga, temp_idbarang);
        }
    }
 
    for(int i = 0; i < banyaktransaksi; i++){
        scanf("%d%d", &temp_banyakbeli, &temp_idbeli);
 
        if(temp_idbeli > banyakbarang || temp_idbeli < 0){
            printf("Maaf barang tidak tersedia\n");
        }
        else{
            sum = sum + (SumUtil(&pohon, temp_idbeli) * temp_banyakbeli);
        }
    }
    printf("%d\n", sum);
 
}
