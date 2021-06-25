#include <bits/stdc++.h> 

using namespace std; 

class Node 
{ 
	public: 
	int data; 
	Node* next; 
}; 

Node *reverse (Node *head, int k) 
{ 
	Node* current = head; 
	Node* next = NULL; 
	Node* prev = NULL; 
	int count = 1; 
	
	while (current != NULL && count <= k) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
		count++; 
	} 

	if (next != NULL) 
	head->next = reverse(next, k); 

	return prev; 
} 

void insert(Node** head, int ele) 
{ 
	Node* temp = new Node(); 
    temp->data = ele;
    temp->next = 0;
    if (*head == 0)
        *head = temp;
    else
    {
        Node *temp1 = *head;
        while(temp1->next != 0)
            temp1 = temp1->next;
        temp1->next = temp;
    }
} 

void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

int main() 
{ 
	Node* head = NULL; 
	int n, k;
	cout << "Enter the list elements: ";
	do
	{
		cin >> n;
		if (n == -999)
			break;
		else 
			insert(&head, n);
	} while (1);
	
	cout << "Enter the value of k: ";
	cin >> k;

	cout << "Given linked list \n"; 
	printList(head); 
	head = reverse(head, k); 

	cout << "\nReversed Linked list \n"; 
	printList(head); 

	return 0; 
} 