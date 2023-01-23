#include <iostream>
int max(int a,int b,int c)
{
	int max = b;
	if(a > max) max = a;
	else if(c > max ) max = c;
	return max;
}

typedef struct node
{
	int data;
	node *left = NULL, *right = NULL;
	node(int d){data = d;}
}node;

void preorder(node* head)
{
	if(head == NULL)
		return ;
	std::cout<<head->data<<" ";
	preorder(head->left);
	preorder(head->right);
}

void postorder(node *head)
{
	if(head == NULL)
		return ;
	postorder(head->left);
	postorder(head->right);
	std::cout<< head->data << " ";
}

void inorder(node *head)
{
	if (head == NULL)
		return ;
	inorder(head->left);
	std::cout<< head->data << " ";
	inorder(head->right);
}

int main()
{
	node* head = new node(1);
	head->left = new node(2);
	head->right = new node(3);
	head->left->left = new node(4);
	head->left->right = new node(5);
	head->right->left = new node(6);
	head->right->right = new node(7);

	std::cout<<"preorder : ";
	preorder(head);
	std::cout<<std::endl;
	
	std::cout<<"postorder : ";
	postorder(head);
	std::cout<<std::endl;

	std::cout<<"inorder : ";
	inorder(head);
	std::cout<<std::endl;

	return 0;
}
