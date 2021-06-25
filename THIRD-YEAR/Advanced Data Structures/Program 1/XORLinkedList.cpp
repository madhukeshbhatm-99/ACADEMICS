
#include <bits/stdc++.h> 
#include <inttypes.h>

using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node* npx; 
}; 

Node* head = NULL;

Node* XOR (Node *a, Node *b) 
{ 
	return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 

void insertBegin(int data) 
{ 
	Node *new_node = new Node(); 
	new_node->data = data; 
	new_node->npx = head; 
	if (head != NULL) 
	{ 
		head->npx = XOR(new_node, head->npx); 
	} 
	head = new_node; 
} 

void insertRear(int data) 
{ 
	Node *new_node = new Node(); 
	new_node->data = data;
    if(head == NULL)
        {
            new_node->npx = XOR(head, NULL);
            head = new_node;
        }
    else
    {
        Node* curr;
        Node* prev=NULL;
        Node* next;
        curr = head;
        while(XOR(prev,curr->npx)!=NULL)
        {
            next = XOR(prev,curr->npx);
            prev = curr;
            curr = next;
        }
        new_node->npx = curr;
        curr->npx = XOR(prev,new_node);
    }
}

void printList () 
{ 
	Node *curr = head; 
	Node *prev = NULL; 
	Node *next; 
	cout << "The nodes of Linked List: "; 
	while (curr != NULL) 
	{ 
		cout << curr->data << " "; 
		next = XOR (prev, curr->npx); 
		prev = curr; 
		curr = next; 
	}
    cout << endl;
} 

int main () 
{ 
	//Node *head = NULL; 
	int n;
    
    cout << "Enter the number of elements to be inserted at the beginning: ";
    cin >> n;
    cout << "Elements: ";
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        insertBegin(ele);
    }
    
    printList ();

//    cout << head->data;

    cout << "Enter the number of elements to be inserted at the end: ";
    cin >> n;
    cout << "Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        insertRear(ele);
    }

	printList (); 

	return (0); 
} 
