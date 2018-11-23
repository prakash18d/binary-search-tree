#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};

class tree
{

	node *createnode(int val)
	{
		node *temp = new node();
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
public:

	node *root = NULL;
	node* insert(node* node, int val)
	{
		if (node == NULL)
			return createnode(val);
		if (val < node->data)
			node->left = insert(node->left, val);
		else if (val > node->data)
			node->right = insert(node->right, val);

		return node;
	}
	void inorder(node* node)
	{
		if (node != NULL)
		{
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
		if (root == NULL)
			cout << "empty tree";



	}
	void postorder(node* node)
	{
		if (node != NULL)
		{
			postorder(node->left);
			postorder(node->right);
			cout << node->data << " ";
		}
		if (root == NULL)
			cout << "empty tree";

	}
	void preorder(node* node)
	{
		if (node != NULL)
		{
			cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);


		}
		if (root == NULL)
			cout << "empty tree";

	}


	void del(node* node)
	{

		if (node == NULL)
			return;
		else
		{
			del(node->left);
			del(node->right);
			cout << "delete node =" << node->data << endl;
			delete node;


		}
		root = NULL;

	}

	void delleast(node* node)
	{

		while (node->left->left != NULL)
		{
			node = node->left;

		}
		cout << " node delete" << node->left->data << endl;
		node->left = NULL;
		delete node->left;

	}
	void delhighest(node* node)
	{

		while (node->right->right != NULL)
		{
			node = node->right;

		}
		cout << " node delete" << node->right->data << endl;
		node->right = NULL;
		delete node->right;

	}


};

int main()
{
	tree t;

	t.root = t.insert(t.root, 50);
	t.insert(t.root, 40);
	t.insert(t.root, 45);
	t.insert(t.root, 35);
	t.insert(t.root, 30);
	t.insert(t.root, 60);
	t.insert(t.root, 55);
	t.insert(t.root, 70);
	t.insert(t.root, 75);
	cout << "inorder tree" << endl;
	t.inorder(t.root);
	cout << endl;
	cout << "postorder tree" << endl;
	t.postorder(t.root);
	cout << endl;
	cout << "preorder tree" << endl;
	t.preorder(t.root);
	cout << endl;
	cout << " delete least node" << endl;
	t.delleast(t.root);
	cout << endl;
	cout << " delete highest node" << endl;
	t.delhighest(t.root);
	cout << endl;
	t.inorder(t.root);
	cout << endl;
	cout << "delete all node" << endl;
	t.del(t.root);
	cout << endl;
	t.postorder(t.root);


}
