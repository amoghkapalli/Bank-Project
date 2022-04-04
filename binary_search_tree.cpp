#include "binary_search_tree.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	count_ = 0;
}
BinarySearchTree::~BinarySearchTree()
{
	Delete();
}
int BinarySearchTree::getCount()
{
	return count_;
}
bool BinarySearchTree::Insert(int account_id, Account* insAc)
{
	if (account_id < 1000 || account_id > 9999)
	{
		cerr << "ERROR: Account ID "<< account_id<<" is not four digits" << endl;
		return false;
	}
	return helperInsert(this->root, insAc);
}
void BinarySearchTree::Delete(){
	if (this->root != nullptr)
	{
		helperDelete(root);
	}
}
void BinarySearchTree::Display()
{
	Node* temp = root;
	if (temp != nullptr)
	{
		displayHelper(temp);
	}
	else
	{
		cout << "The Account Tree is Empty" << endl;
	}
}
bool BinarySearchTree::Contains(const int& acID) const
{
	Node* temp = this->root;
	while (temp != nullptr)
	{
		if (temp->p_account.getID() == acID)
		{
			return true;
		}
		if (temp->p_account.getID() < acID)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
	return false;
}
bool BinarySearchTree::Retreieve(int account_id, Account*& p_acc)
{
	Node* temp = this->root;
	while (temp != nullptr)
	{
		if (temp->p_account.getID() == account_id)
		{
			p_acc=&temp->p_account;
			return true;
		}
		if (temp->p_account.getID() < account_id)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
	return false;
}
bool BinarySearchTree::IsEmpty() const
{
	return (this->root == nullptr);
}
bool BinarySearchTree::helperInsert(Node* &current, Account* insAC){
    if(current==nullptr){
        Node* temp = new Node;
		temp->p_account = *insAC;
        current=temp;
        current->right = nullptr;
        current->left = nullptr;
		return true;
    }
    else if (insAC->getID() < current->p_account.getID())
	{
		 helperInsert(current->left, insAC);
	}
    else if (insAC->getID() > current->p_account.getID())
	{
		 helperInsert(current->right, insAC);
	}
    return false;
}
void BinarySearchTree::helperDelete(Node* current)
{
	if (current != nullptr)
	{
		helperDelete(current->left);
		helperDelete(current->right);
		delete(current);
	}
}
void BinarySearchTree::displayHelper(Node* current){
	if(current!=nullptr){
		displayHelper(current->left);
		displayHelper(current->right);
		cout<<current->p_account << endl;
	}
}