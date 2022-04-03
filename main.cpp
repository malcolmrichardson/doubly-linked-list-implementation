#include <iostream>

using namespace std;

//Node structure
struct dLinkedList {    
    int data;
    struct dLinkedList *nextNode;
    struct dLinkedList *prevNode;
};
typedef struct dLinkedList node;
node *start = NULL;

//Function declarations
node* getNode();
void createList(int n);
void traverseList();
int countNodes (node* start);
void deleteFromEnd();
void insertAtBeginning();

int main (){
    int n; 
    cout<<"Creating a doubly linked list of 'n' nodes: "<<endl;
    cout<<"How many nodes would you like to add to the doubly linked list?: ";
    cin>>n;
    createList(n);
    traverseList();
    cout<<"\n";
    cout<<"Deleting a node at the end of the doubly linked list: "<<endl;;
    deleteFromEnd();
    traverseList();
    cout<<"\n";
    cout<<"Inserting a node at the beginning of the doubly linked list: "<<endl;
    insertAtBeginning();
    traverseList();
    cout<<"\n";
    return 0;
}

// Function for creating a new node in the doubly linked list.
node* getNode(){    
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    cout<<"Enter the data for the new node: ";
    cin>>newNode->data;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

//Function for creating a doubly linked list with n nodes.
void createList(int n){     
    node *newNode, *temp;
    for (int i = 0; i < n; i++){
        newNode = getNode();
        if (start == NULL){
            start = newNode;
        }
        else {
            temp = start;
            while (temp->nextNode != NULL){
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
            newNode->prevNode = temp;
        }
    }
}

//Function for traversing through the doubly linked list.
void traverseList(){    
    node *temp;
    temp = start;
    cout<<"The contents of the list from left to right are as follows: ";
    if (start == NULL){
        cout<<"List is empty.";
    }
    else {
        while (temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->nextNode;
        }
    }
    free(temp);
    cout<<endl;
}

//Recursive function for counting the number of nodes in a doubly linked list.
int countNodes (node* start) {  
    if (start == NULL){
        return 0;
    }
    return (1+countNodes(start->nextNode));
}

//Function for deleting the last node of the doubly linked list.
void deleteFromEnd(){   
    node *temp;
    if (start == NULL){
        cout<<"Linked List is empty";
        return;
    }
    else {
        temp = start;
        while (temp->nextNode != NULL){
            temp = temp->nextNode;
        }
        temp->prevNode->nextNode = NULL;
    }
    free(temp);
}

//Funtion for inserting a node at the beginning of the doubly linked list.
void insertAtBeginning(){   
    node *newNode;
    newNode = getNode();
    if (start == NULL){
        start = newNode;
    }
    else {
        newNode->nextNode = start;
        start->prevNode = newNode;
        start = newNode;
    }
}
