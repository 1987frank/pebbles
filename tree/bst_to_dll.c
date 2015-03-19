#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
}Node;
 
/* utility that allocates a new Node with the given key  */
Node* newNode(int key)
{
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void inorder(Node* root){

if(root){
inorder(root->left);
printf("%d ",root->key);
inorder(root->right);

}
//printf("\n");
}

void fixleft(Node *root) {

static Node *prev=NULL;
if(root) {

	fixleft(root->left);
	root->left=prev;
	prev=root;
	fixleft(root->right);
}
}

Node *treetodll(Node *root){

Node *curr=root;
Node *prev=NULL;
fixleft(root);

while(curr->right)
	curr=curr->right;

while(curr){
	curr->right=prev;
	prev=curr;
	curr=curr->left;
	
	}
return prev;
}

void traverselist(Node *head){

Node *temp=head;
while(temp){
printf("%d ",temp->key);
temp=temp->right;
}
printf("\n");

}

void main() {

	Node *head;
    Node * root = newNode(5);	
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);
    //root->right->left->right = newNode(8);

	inorder(root);
	printf("\n");
	head=treetodll(root);
	traverselist(head);
}


