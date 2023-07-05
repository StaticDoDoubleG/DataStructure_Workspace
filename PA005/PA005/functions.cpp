#include "functions.h"

clock_t start;
clock_t end;

int z = 0;

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode* left;
	struct BinarySearchTreeNode* right;
};

struct AVLTreeNode {
	int data;
	struct AVLTreeNode* left;
	struct AVLTreeNode* right;
	int height;
};

//1
void BST_RIRF() {
	struct BinarySearchTreeNode* root = NULL;
	for (int h = 0; h <= 10; h++) {
		start = clock();
		for (int i = 1; i <= 100000; i++) {
			root = InsertBST(root, RandomReturn((h + 1) * 100000) + 1);
		}
		end = clock();
		printf("%7d일 때 Random Insert 소요시간: %lfms\n", h * 100000, (end - start) / 100000.0);
		start = clock();
		for (int i = 1; i <= 100000; i++) {
			FindBST(root, RandomReturn((h + 1) * 100000) + 1);
		}
		end = clock();
		printf("%7d일 때 Random Find   소요시간: %lfms\n", h * 100000, (end - start) / 100000.0);
	}
	free(root);
}

void BBST_RIRF() {
	struct AVLTreeNode* root = NULL;
	for (int h = 0; h <= 10; h++) {
		start = clock();
		for (int i = 1; i <= 100000; i++) {
			root = InsertAVLT(root, RandomReturn((h + 1) * 100000) + 1);
		}
		//printf("for를 넘긴 했니");
		end = clock();
		printf("%7d일 때 Random Insert 소요시간: %lfms\n", h * 100000, (end - start) / 100000.0);
		start = clock();
		for (int i = 1; i <= 100000; i++) {
			FindAVLT(root, RandomReturn((h + 1) * 100000) + 1);
		}
		end = clock();
		printf("%7d일 때 Random Find   소요시간: %lfms\n", h * 100000, (end - start) / 100000.0);
	}
	free(root);
}

//2
void BST_OIRF() {
	struct BinarySearchTreeNode* root = NULL;
	for (int h = 0; h <= 5; h++) {
		start = clock();
		for (int i = 1 + h * 1000; i <= 1000 + h * 1000; i++) {
			root = InsertBST(root, i);
		}
		end = clock();
		printf("%4d번일 때 Ordered Insert 소요시간: %lfms\n", h * 1000, (end - start) / 1000.0);
		start = clock();
		for (int i = 1; i <= 1000; i++) {
			//printf("      Random  %d", RandomReturn((h + 1) * 1000));
			FindBST(root, RandomReturn((h + 1) * 1000) + 1);
		}
		end = clock();
		printf("%4d번일 때 Random Find    소요시간: %lfms\n", h * 1000, (end - start) / 1000.0);
	}
	free(root);
}

void BBST_OIRF() {
	struct AVLTreeNode* root = NULL;
	for (int h = 0; h <= 5; h++) {
		start = clock();
		for (int i = 1 + h * 1000; i <= 1000 + h * 1000; i++) {
			//printf("%d ", i);
			//z++;
			root = InsertAVLT(root, i);
			//printf("Recursive Call: %d\n", z);
			//z = 0;
		}
		end = clock();
		//printf("으악 %d %d %d\n",start, end,  end - start);
		printf("%4d번일 때 Ordered Insert 소요시간: %lfms\n", h * 1000, (end - start) / 1000.0);
		start = clock();
		for (int i = 1; i <= 1000; i++) {
			//printf("      Random  %d", RandomReturn((h + 1) * 1000));
			FindAVLT(root, RandomReturn((h + 1) * 1000) + 1);
		}
		end = clock();
		//printf("으악 %d %d %d\n",start, end,  end - start);
		printf("%4d번일 때 Random Find    소요시간: %lfms\n", h * 1000, (end - start) / 1000.0);
	}
	free(root);
}

//BST related
struct BinarySearchTreeNode* FindBST(struct BinarySearchTreeNode* root, int data) {
	//printf("%d ", data);
	if (root == NULL) {
		return NULL;
	}
	while (root) {
		if (data == root->data) {
			return root;
		}else if (data > root->data) {
			root = root->right;
		}
		else {
			root = root->left;
		}
	}
	return NULL;
}

struct BinarySearchTreeNode* InsertBST(struct BinarySearchTreeNode* root, int data) {
	//printf("%d ", data);
	if (root == NULL) {
		root = (struct BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
		if (root == NULL) {
			printf("Memory Error");
			return NULL;
		}
		else {
			//printf("M");
			root->data = data;
			root->left = root->right = NULL;
		}
	}
	else {
		if (data < root->data) {
			//printf("L");
			root->left = InsertBST(root->left, data);
		}
		else if (data > root->data) {
			//printf("R");
			root->right = InsertBST(root->right, data);
		}
	}
	return root;
}

//BBST related
int Height(struct AVLTreeNode* root) {
	if (!root) {
		return -1;
	}
	else {
		return root->height;
	}
}

int max(int height1, int height2) {
	if (height1 > height2) {
		return height1;
	}
	else{
		return height2;
	}
}

struct AVLTreeNode* Rotate_Right(struct AVLTreeNode* X) {
	struct AVLTreeNode* W = X->left;
	//printf("RR ");
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W;
}

struct AVLTreeNode* Rotate_Left(struct AVLTreeNode* W) {
	//printf("RL ");
	struct AVLTreeNode* X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	X->height = max(W->height, Height(X->right)) + 1;
	return X;
}

struct AVLTreeNode* Rotate_LeftRight(struct AVLTreeNode* Z) {
	Z->left = Rotate_Left(Z->left);
	return Rotate_Right(Z);
}

struct AVLTreeNode* Rotate_RightLeft(struct AVLTreeNode* X) {
	X->right = Rotate_Right(X->right);
	return Rotate_Left(X);
}

struct AVLTreeNode* FindAVLT(struct AVLTreeNode* root, int data) {
	//printf("%d ", data);
	if (root == NULL) {
		//printf("N");
		return NULL;
	}
	while (root) {
		if (data == root->data) {
			//printf("M");
			return root;
		}
		else if (data > root->data) {
			//printf("R");
			root = root->right;
		}
		else {
			//printf("L");
			root = root->left;
		}
	}
	return NULL;
}

struct AVLTreeNode* InsertAVLT(struct AVLTreeNode* root, int data) {
	//printf("%d ", data);
	if (root == NULL) {
		root = (struct AVLTreeNode*)malloc(sizeof(struct AVLTreeNode));
		if (root == NULL) {
			printf("Memory Error");
			return NULL;
		}
		else {
			root->data = data;
			root->height = 0;
			root->left = root->right = NULL;
		}
	}
	else if (data < root->data) {
		//printf("L");
		root->left = InsertAVLT(root->left, data);
		//z++;
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (data < root->left->data) //LL
				root = Rotate_Right(root);
			else root = Rotate_LeftRight(root); //LR
		}
	}
	else if (data > root->data) {
		//printf("R");
		root->right = InsertAVLT(root->right, data);
		//z++;
		if ((Height(root->right) - Height(root->left)) == 2) {
			//printf("X");
			if (data > root->right->data) //RR
				root = Rotate_Left(root);
			else root = Rotate_RightLeft(root); //LL
		}
	}
	//printf("E");
	root->height = max(Height(root->left), Height(root->right)) + 1;
	return root;
}

//Random related
int RandomReturn(int in) {
	return ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) \
		* ((in + 1) - 1)) + 1);
}

