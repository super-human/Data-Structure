#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define ll long long
#define mod 1000000007

int path[1000];
class tree_node
{
public: 
	int data;
	tree_node *lchild, *rchild;
	tree_node()
	{
		lchild = rchild = NULL;
	}
};

class tree:public tree_node
{
	tree_node *root;
public:
	tree()
	{
		root = NULL;
	}
	void create_tree();
	void preorder()
	{
		preorder(root);
	}
	void preorder(tree_node* q);
	void postorder()
	{
		postorder(root);
	}
	void postorder(tree_node* q);
	void inorder()
	{
		inorder(root);
	}
	void inorder(tree_node* q);
	void levelorder()
	{
		levelorder(root);
	}
	void levelorder(tree_node*);
	int count()
	{
		count(root);
	}
	int count(tree_node*);
	int height()
	{
		height(root);
	}
	int height(tree_node*);
	int recursivemaximum()
	{
		recursivemaximum(root);
	}
	int recursivemaximum(tree_node*);
	int iterativemaximum()
	{
		iterativemaximum(root);
	}
	int iterativemaximum(tree_node*);
	void rdeletebinarytree()
	{
		rdeletebinarytree(root);
	}
	void rdeletebinarytree(tree_node*);
	void levelorderdeletion()
	{
		levelorderdeletion(root);
	}
	void levelorderdeletion(tree_node*);
	int delete_element(int x)
	{
		delete_element(root,x);
	}
	int delete_element(tree_node*,int);
	void printpath(int pathlen)
	{
		printpath(root,pathlen);
	}
	void printpath(tree_node*,int);
	void printArray(int[], int);
};

void tree::create_tree()
{
	tree_node *temp, *p;
	int x;
	std::cout<<"Enter the root node "<<'\n';
	std::cin>>x;
	root = new tree_node;
	root->data = x;
	std::queue<tree_node*> q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		std::cout<<"Enter left child"<<'\n';
		std::cin>>x;
		if(x != -1 )
		{
			p = new tree_node;
			p->data = x;
			temp->lchild = p;
			q.push(p);
		}
		std::cout<<"Enter right child"<<'\n';
		std::cin>>x;
		if(x != -1)
		{
			p = new tree_node;
			p->data = x;
			temp->rchild = p;
			q.push(p);
		}
	}
}

void tree::preorder(tree_node* q)
{
	if(q == NULL)
		return;
	std::cout<<q->data<<" ";
	preorder(q->lchild);
	preorder(q->rchild);
}

void tree::inorder(tree_node *q)
{
	if(q!=NULL)
	{
		inorder(q->lchild);
		std::cout<<q->data<<" ";
		inorder(q->rchild);
	}
}

void tree::postorder(tree_node *q)
{
	if(q!=NULL)
	{
		postorder(q->lchild);
		postorder(q->rchild);
		std::cout<<q->data<<" ";
	}
}

void tree::levelorder(tree_node* t)
{
	std::queue<tree_node*> q;
	q.push(t);
	std::cout<<t->data<<" ";
	while(!q.empty())
	{
		t = q.front();
		q.pop();
		if(t->lchild != NULL)
		{
			std::cout<<t->lchild->data<<" ";
			q.push(t->lchild);
		}
		if(t->rchild != NULL)
		{
			std::cout<<t->rchild->data<<" ";
			q.push(t->rchild);
		}
	}
}

int tree::count(tree_node* q)
{
	if(q!=NULL)
		return count(q->lchild) + count(q->rchild) + 1;
	return 0;
}

int tree::height(tree_node* q)
{
	int x = 0, y = 0;
	if(q == NULL)
		return 0;
	x = height(q->lchild);
	y = height(q->rchild);
	if(x>y)
		return x+1;
	else
		return y+1;
}

int tree::recursivemaximum(tree_node *root)
{
	int max_value = INT_MIN;
	if(root != NULL)
	{
		int root_val = root->data;
		int lresult = recursivemaximum(root->lchild);
		int rresult = recursivemaximum(root->rchild);
		if(lresult > rresult)
			max_value = lresult;
		else
			max_value = rresult;
		if(root_val > max_value)
			max_value = root_val;
	}
	return max_value;
}

int tree::iterativemaximum(tree_node* root)
{
	int max = INT_MIN;
	std::queue<tree_node*> q;
	q.push(root);
	while(!q.empty())
	{
		tree_node* temp = q.front();
		q.pop();
		if(temp->data > max)
			max = temp->data;
		if(temp->lchild)
			q.push(temp->lchild);
		if(temp->rchild)
			q.push(temp->rchild);
	}
	return max;
}

void tree::rdeletebinarytree(tree_node* root)
{
	if(root == NULL)
		return;
	rdeletebinarytree(root->lchild);
	rdeletebinarytree(root->rchild);
	free(root);
}

void tree::levelorderdeletion(tree_node* root)
{
	if(root == NULL)
		return;
	std::queue<tree_node*> q;
	q.push(root);
	while(!q.empty())
	{
		tree_node* temp = new tree_node;
		q.pop();
		if(temp->lchild)
			q.push(temp->lchild);
		if(temp->rchild)
			q.push(temp->rchild);
		free(temp);
	}
}
 
int tree::delete_element(tree_node* root, int x)
{
	int y = -1;
	if(root == NULL)
		return y;
	std::queue<tree_node*> q;
	q.push(root);
	while(!q.empty())
	{
		tree_node* temp = q.front();
		q.pop();
		if(temp->data == x)
		{
			y = temp->data;
			free(temp);
			return y;
		}
		if(temp->lchild)
			q.push(temp->lchild);
		if(temp->rchild)
			q.push(temp->rchild);
	}
	return y;
}

void tree::printpath(tree_node* root,int pathlen)
{
	if(root == NULL)
		return;
	path[pathlen++] = root->data;
	if(root->lchild == NULL && root->rchild == NULL)
		printArray(path,pathlen);
	else
	{
		printpath(root->lchild,pathlen);
		printpath(root->rchild,pathlen);
	}
}

void tree::printArray(int x[], int len)
{
	for(int i = 0;i<len; i++)
		std::cout<<x[i]<<" ";
	std::cout<<'\n';
}

int main()
{
	tree t;
	t.create_tree();
	std::cout<<"Preorder Traversal: ";
	t.preorder();
	std::cout<<'\n';
	std::cout<<"postorder Traversal: ";
	t.postorder();
	std::cout<<std::endl;
	std::cout<<"inorder Traversal: ";
	t.inorder();
	std::cout<<'\n';
	std::cout<<"levelorder Traversal: ";
	t.levelorder();
	std::cout<<'\n';
	std::cout<<"No. of nodes "<<t.count()<<'\n';
	std::cout<<"Height of the tree "<<t.height()<<'\n';
	std::cout<<"Maximum element in the tree using Recursive approach "<<t.recursivemaximum()<<'\n';
	std::cout<<"Maximum element in the tree using Iterative approach "<<t.iterativemaximum()<<'\n';
	std::cout<<t.delete_element(8)<<'\n';
	t.printpath(0);
	return 0;
}
