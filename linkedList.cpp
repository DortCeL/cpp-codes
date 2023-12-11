#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    node* next;
    
    node(int val) {
        data = val;
        next = NULL;
    }
} node;

void listAppend(node* &root, int val) {
    node* newNode = new node(val);

    node* temp = root;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

}

void listPrepend(node* &root, int val) {
    node* newNode = new node(val);
    newNode->next = root;
    root = newNode;
}

void insert_anywhere(node* &root, int target, int val) {
    node* newNode = new node(val);
    node* temp = root;
    int tracker = 1;
    while (temp->next != NULL) {
        tracker++;
        temp = temp->next;
        if (tracker == target)
            break;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}



// ***************************************
// gotta think for list with 1 element;
// ***************************************
void deleteLast(node* &root) {
    node* temp = root;
    while (temp->next->next != NULL) temp = temp->next;

    temp->next = NULL;
}

void deleteFirst(node* &root) {
    root = root->next;
}

void printList(node* &root) {
    node* temp = root;
    while (temp->next != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
}

int main (void) {

    node* root = new node(20);
    listAppend(root,21);
    listAppend(root,22);
    listAppend(root,23);
    listAppend(root,24);
    listAppend(root,25);


    listPrepend(root,12);
    listPrepend(root,10);

    deleteLast(root);
    deleteFirst(root);

    insert_anywhere(root, 2, 69);



    printList(root);
    

}