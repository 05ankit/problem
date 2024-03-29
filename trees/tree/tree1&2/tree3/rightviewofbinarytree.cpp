#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};
struct Node* newNode(int object)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = object;
	temp->left = temp->right = NULL;
	return temp;
}
void rightViewUtil(struct Node* root, int level, int* max_level)
{
	if (root == NULL)
		return;
	if (*max_level < level) {
		cout << root->data << "\t";
		*max_level = level;
	}
	rightViewUtil(root->right, level + 1, max_level);
	rightViewUtil(root->left, level + 1, max_level);
}
void rightView(struct Node* root)
{
	int max_level = 0;
	rightViewUtil(root, 1, &max_level);
}
