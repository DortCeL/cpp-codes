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
    cout << val << " inserted at the end" << endl;
}

void listPrepend(node* &root, int val) {
    node* newNode = new node(val);
    newNode->next = root;
    root = newNode;
    cout << val << " inserted at the beginning" << endl;
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
    cout << val << " inserted at " << target << endl;
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
    cout << "Deleted Node at " << target << endl;
}

void listFind(node* &root, int target){ 
    node* temp = root;
    int tracker = 1;
    while (temp != NULL and temp->data != target) {
        temp = temp->next;
        tracker++;
    }

    if (temp == NULL) {
        cout << target << " not found";
    } 
    else {
        cout << target << " found at " << tracker << endl;
    }
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
    while (temp->next->next!= NULL) temp = temp->next;

    temp->next = NULL;
    cout << "Last Node Deleted!" << endl;
}

void deleteFirst(node* &root) {
    root = root->next;
    cout << "First Node Deleted!" << endl;
}

void printList(node* &root) {
    cout << endl;
    cout << "List : ";
    node* temp = root;
    while (temp->next != NULL) {
        cout << temp->data << " ==> ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl << endl;
}



int main (void) {

    node* root = new node(1);

    for (int i=2; i<=12; i++) listAppend(root, i);

    printList(root);

    listPrepend(root,-1);
    listPrepend(root,-2);

    printList(root);

    deleteLast(root);
    printList(root);
    deleteFirst(root);
    printList(root);

    insertAt(root, 2, 10);
    printList(root);
    deleteAt(root, 4);
    printList(root);

    listFind(root, 5);

    printNode(lastNode(root));
    printNode(previousOfLastNode(root));

}
