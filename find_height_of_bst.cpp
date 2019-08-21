#include<iostream>
#include<algorithm>
using namespace std;
// user defind data tyepe we define it according to our need
struct bst{
	int data;
    struct bst* left;
    struct bst* right;
};
// function to create newnode
bst* newnode(int data)
{
	bst* root=new bst();
	root->data=data;
	root->left=root->right=NULL;
	return root;
}
// function to insert element
bst* Insert(bst* root,int data)
{
	if(root==NULL)
	{
		root=newnode(data);
		return root;
	}
	else if(root->data>data)
	{
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
}
// height function
int find_height(bst* node)
{
	if(node==NULL)// for null node height is -1
		return -1;
	return(std::max(find_height(node->left),find_height(node->right))+1);
}
int main()
{
	bst* root=NULL;
	int data,n;
	cin>>n;
	cin>>data;
	root=Insert(root,data);
	while(n-1>0)
   {
	cin>>data;
	Insert(root,data);
	n--;
   }
   cout<<"height of tree is : "<<find_height(root);
	return 0;
}
