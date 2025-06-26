#include <iostream>
using namespace std;

class Node 
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    //Constructor for the node class
    Node()
    {
        leftchild = nullptr; // intialize left child to null
        rightchild = nullptr; // intialize right child to null
    }
};

class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // intializing ROOT to null
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        //This function searches the currentnode of the 
        //specifiied node as well as the current Node of this empty
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr)&& (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void insert()
    {
        int x;
        cout << "Masukan Nilai : ";
        cin >> x;

        // step 1: Allocate memory for the new node
        Node *newNode = new Node ();

        // Step 2 : Asign value to the data filed of new node
        newNode->info = x;

        // Step 3 : make the left and right child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // Step 4 :  Locate the node which wiill be the pperent of the node to be insertd
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // Step 5 : If parent is NULL (tree is empty)
        if (parent == nullptr)
        {
            // 5a : mark the new node as ROOT
            ROOT = newNode;

            //5b : Exit 
            return;
        }

        // Step 6 : If the value in the data filed of new node is lass then taht of parent
        if (x < parent->info)
        {
            // 6a: Make the left child of parent point to the new node
            parent->leftchild = newNode;

            // 6b : Exit 
            return;
        }

        // Step 7 : if the va;ue in the data filed of the new node is greater than thatof the
        else if (x, parent->info)
        {
            // 7a : make the right child of the parent poin to the new node
            parent->rightchild = newNode;

            // 7b : Exit 
            return;
        }
    }

    bool isEmpty()
    {
        // checks if the tree is empty
        return ROOT == nullptr;
    }

    void inorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
            
        inorder(ptr->leftchild);
        cout << ptr->info << " "; //parent
        inorder(ptr->rightchild);
    }

     void preorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        cout << ptr->info << " "; //parent

        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
