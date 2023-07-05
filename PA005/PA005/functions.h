#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Functions for Main()

void RIRF();  //1
void OIRF();  //2
void RandomTest();

//1
void BST_RIRF();
void BBST_RIRF();

//2
void BST_OIRF();
void BBST_OIRF();


//Functions of Tree
struct BinarySearchTreeNode* FindBST(struct BinarySearchTreeNode* root, int data);
struct BinarySearchTreeNode* InsertBST(struct BinarySearchTreeNode* root, int data);
struct AVLTreeNode* FindAVLT(struct AVLTreeNode* root, int data);
struct AVLTreeNode* InsertAVLT(struct AVLTreeNode* root, int data);

//Other Functions
int RandomReturn(int in);