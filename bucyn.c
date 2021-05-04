#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
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

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {

    if(node==NULL) 
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
        node->right = _insert_AVL(avl,node->right,value);

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

    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0)
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;


typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;


void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_pushBack(SinglyList *list, int value);
void slist_remove(SinglyList *list, int value);
int slist_front(SinglyList *list);
int slist_getIndex(SinglyList *list, int value);


void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_getIndex(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        int _i=1;
        SListNode *temp;
        temp = list->_head;

        if (temp->data == value) {
            return _i;
        }

        while (temp != NULL && temp->data != value) {
            _i=_i+1;
            temp = temp->next;
            if (temp == NULL) return -1;
        }
        return _i;
    }else return 0;
}

void _postorder(AVLNode *root, SinglyList *list) {
    if (root) {
        _postorder(root->left, list);
        _postorder(root->right, list);
        slist_pushBack(list, root->data);
    }
}

void postorder(AVL *avl, SinglyList *list) {
    _postorder(avl->_root, list);
}

void _inorder(AVLNode *root, SinglyList *list) {
    if (root) {
        _inorder(root->left, list);
        slist_pushBack(list, root->data);
        _inorder(root->right, list);
    }
}

void inorder(AVL *avl, SinglyList *list) {
    _inorder(avl->_root, list);
}

void _reversedInorder(AVLNode *root, SinglyList *list) {
    if (root) {
        _reversedInorder(root->left, list);
        slist_pushFront(list, root->data);
        _reversedInorder(root->right, list);
    }
}

void reversedInorder(AVL *avl, SinglyList *list) {
    _reversedInorder(avl->_root, list);
}

void _preorder(AVLNode *root, SinglyList *list) {
    if (root) {
        _preorder(root->left, list);
        slist_pushBack(list, root->data);
        _preorder(root->right, list);
    }
}

void preorder(AVL *avl, SinglyList *list)
{
    _preorder(avl->_root, list);
}



int main(){
    SinglyList myList;
    slist_init(&myList);
    
    AVL avlavl;
    avl_init(&avlavl);

    int testcase;
    scanf("%d", &testcase);
    for(int i=1; i<=testcase; i++){
        char command [1000000];
        int angka;
        scanf(" %s", command);
        scanf("%d", &angka);

        if (strcmp(command, "Taro")==0){
            avl_insert(&avlavl, angka);
        }
        else if(strcmp(command, "Cari")==0){
                inorder(&avlavl, &myList);
                angka=slist_getIndex(&myList, angka);
                

            if(angka==-1)
                printf("Kasetnya gak ada!\n");
            else
                printf("Kasetnya ada di tumpukan ke - %d\n", angka);

            while (!slist_isEmpty(&myList)) slist_popFront(&myList);
        }
        else {
            printf("AKU TUH GATAU HARUS NGAPAIN!\n");
        }
    }
        return 0;
}
