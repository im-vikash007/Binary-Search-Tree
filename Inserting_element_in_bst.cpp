#include<iostream>
using namespace std;
struct bst{
	int data;
    struct bst* left;
    struct bst* right;
};
bst* newnode(int data)
{
	bst* root=new bst();
	root->data=data;
	root->left=root->right=NULL;
	return root;
}
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
bool Search(bst* root,int data)
{
	if(root==NULL)
		return false;
	else if(root->data==data)
	{
		return true;
	}
	else if(data<=root->data)
		return Search(root->left,data);
	else
	{
		return Search(root->right,data);
	}
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
   cout<<"enter data to be search : ";
   cin>>data;
	if(Search(root,data)==true)
		cout<<"found "<<data<<endl;
	else
		cout<<"not found!\n";
	return 0;

}
