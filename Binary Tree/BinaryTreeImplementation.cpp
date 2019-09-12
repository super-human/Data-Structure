#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>

// Binary Tree Creation & Traversal(Inorder,PreOrder,PostOrder,LevelOrder)

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
	std::cout<<t.count()<<'\n';
	std::cout<<t.height()<<'\n';
	return 0;
}
