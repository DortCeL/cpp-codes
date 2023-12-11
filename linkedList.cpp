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

void insertAt(node* &root, int target, int val) {
    node* newNode = new node(val);
    node* temp = root;
    int tracker = 1;
    while (temp->next != NULL) {
        if (tracker == target)
            break;
        temp = temp->next;
        tracker++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteAt(node* &root, int target) {
    node* temp = root;
    int tracker = 1;
    while (temp->next != NULL) {
        if (tracker == target)
            break;
        temp = temp->next;
        tracker++;
    }
    if (temp->next->next != NULL) {
        temp->next = temp->next->next;
    }
}

int listFind(node* &root, int target){ 
    node* temp = root;
    int tracker = 1;
    while (temp != NULL and temp->data != target) {
        temp = temp->next;
        tracker++;
    }

    if (temp == NULL) return -1;
    else return tracker;
}

node* lastNode(node* &root) {
    node* temp = root;
    while (temp->next != NULL) temp = temp->next;
    return temp;
}

void printNode(node* nd) {
    if (nd != NULL)
        cout << nd->data << endl;
}

node* previousOfLastNode(node* &root) {
    node* temp = root;
    if (temp->next == NULL) return NULL;
    while (temp->next->next != NULL)
        temp = temp->next;
    return temp;
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
        cout << temp->data << " ==> ";
        temp = temp->next;
    }
    cout << temp->data;
}

int main (void) {

    node* root = new node(1);

    for (int i=2; i<=12; i++) listAppend(root, i);

    listPrepend(root,-1);
    listPrepend(root,-2);

    deleteLast(root);
    deleteFirst(root);

    insertAt(root, 2, 10);
    deleteAt(root, 4);

    printList(root);
    
    cout << endl << "5 found at position " << listFind(root, 5) << endl;

    printNode(lastNode(root));
    printNode(previousOfLastNode(root));

}