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
	if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
	
}

int findmin(bst* root)
{
	 if(root==NULL)
	  {	cout<<"tree is empty ";
	   return 0;
	  }
	 if(root->left==NULL)
	 	return root->data;
	 else
	 {
	 	return findmin(root->left);
	 }
}
int findmax(bst* root)
{
	 if(root==NULL)
	  {	cout<<"tree is empty ";
	   return 0;}
	 if(root->right==NULL)
	 	return root->data;
	 else
	 {
	 	return findmax(root->right);
	 }
}

int main()
{
	int n;//number of element want to insert
	int data;// to store data 
	bst* root=NULL;
	cin>>n;
	for(int i=0;i<n;i++)
	{
       cin>>data;
       root=Insert(root,data);
	}
	int choice=0;
	cout<<"enter 1 to find max 2 for min \n";
	cin>>choice;
    if(choice==1)
    	  cout<<"max : "<<findmax(root);
    else
     cout<<"min : "<<findmin(root);
    
  return 0;

}
