#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode n1={1, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={20, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root= &n6;

int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode *pop()
{
	TreeNode *p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode *root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

int inorder_node_count(TreeNode *node)
{
  int inorder_count=0;
  if( node != NULL )
    inorder_count = 1 + inorder_node_count(node->left)+ 
	inorder_node_count(node->right);
	printf("inorder 호출 횟수 %d회\n\n", ++inorder_count);
	return inorder_count;
}


void inorder(TreeNode* node) {
	{	

        if (node != NULL) {
               printf("node->left(%d)로 이동\n", node->left);
               inorder(node->left);
               printf("root의 주소 = %d, 값 = %d\n", node, node->data);
               printf("node->right(%d)로 이동\n", node->right);
               inorder(node->right);
               printf("\n");
        }
	}
}
int main(void)
{
	printf("중위 순회=\n");
	inorder(root);
	printf("\n");
}



