#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "Account.h"

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool Retreieve(int account_id, Account*& p_account);
        bool Insert(int account_id, Account* account);

        bool IsEmpty() const;
        int getCount();
        void Delete();
        void Display();
        bool Contains(const int& acID) const;
    private:
        struct Node{
            int key;
            Account p_account;
            Node* left;
            Node* right;
        };
        Node* root=nullptr;
        int count_;
        bool helperInsert(Node* &current, Account* insAC);
        void helperDelete(Node* current);
        void displayHelper(Node* current);
};
#endif