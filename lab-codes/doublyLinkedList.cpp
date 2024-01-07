#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    node* next;
    node* prev;
    
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
} node;

node* head = NULL;
node* tail = NULL;

void insertFirst(int val) {
    node* newNode = new node(val);
    if (!head && !tail) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int val) {
    node* newNode = new node(val);

    if (!head and !tail) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFirst() {
    if (!head and !tail) 
        return;
    else if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
}

void deleteLast() {
    if (!head and !tail) 
        return;
    else if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
}


void insertAt(int target, int val) {
    node* newNode = new node(val);

    node* temp = head;
    int tracker = 1;
    while (temp->next != NULL) {
        if (tracker == target)
            break;
        temp = temp->next;
        tracker++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    temp->next->prev = NULL;
    temp->next->prev = newNode;


}

void deleteAt(int target) {

    node* temp = head;
    int tracker = 1;
    while (temp->next != NULL) {
        if (tracker == target)
            break;
        temp = temp->next;
        tracker++;
    }

    node* second = temp->next->next;
    second->prev = temp;
    temp->next = temp->next->next;
    
}


void listSize() {
    int count = 0;
    node* temp = head;
    while (!temp) 
        count++;
    cout << "List Size : " << count << endl;
}


void listFind(int target){ 
    if (!head and !tail) {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
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

void lastNode(node* &root) {
    cout << "Last Node : " << tail->data << endl;
}

void previousOfLastNode() {
    if (tail->prev == NULL)
        return;
    cout << "Previous of Last Node : " << tail->prev->data << endl;
}

void printNode(node* nd) {
    if (nd != NULL)
        cout << nd->data << endl;
}

void printForward() {
    if (!head) {
        cout << "List : " << endl;
        return;
    }
    cout << "List : ";
    node* temp = head;
    while(temp->next != NULL) {
        cout << temp->data << " ==> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void printBackward() {
    if (!tail) {
        cout << "List : " << endl;
        return;
    }
    cout << "List : ";
    node* temp = tail;
    while(temp->prev != NULL) {
        cout << temp->data << " <== ";
        temp = temp->prev;
    }
    cout << temp->data << endl;
}



int main (void) {
    system("cls");

    insertFirst(3);
    insertFirst(2);
    insertFirst(1);

    insertLast(4);
    insertLast(5);

    insertAt(2,10);

    printForward();
    printBackward();

}