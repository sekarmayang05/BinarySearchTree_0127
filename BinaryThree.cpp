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
    }