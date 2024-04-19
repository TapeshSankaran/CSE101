// Filename: linkedlist.cpp
// 
// Contains the class LinkedList that represents a linked list. This contains some basic operations, such as insert, delete, find, length
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

// Default constructor sets head and tail to null
LinkedList :: LinkedList()
{
	head = NULL;
}

// Insert(int val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
void LinkedList :: insert(int val)
{
	Node *to_add = new Node; // creates new Node
	to_add->data = val; // sets the data to hold input val
	
    to_add->next = head; // make to_add point to existing head
    head = to_add; // set head to to_add
}

// find(int val): Finds a Node with data "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node* LinkedList :: find(int val)
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    while(curr != NULL) //looping over list
    {
        if (curr->data == val) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node* LinkedList :: deleteNode(int val)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL) // loop over list, starting from head
    {
        if(curr->data == val) // we found Node with val, so break
            break; 
        //otherwise, proceed list
        prev = curr; // move prev by one Node
        curr = curr->next; // move curr by one Node
    }
    // at this point, curr points to Node with val. If curr is null, then val is not in the list.
    if (curr == NULL) // val not found
        return NULL; 
    // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
    // Otherwise, we delete the Node after prev.
    if (prev == NULL) // we need to delete head
        head = head->next; // delete head
    else // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    return curr;
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void LinkedList :: deleteList()
{
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    Node *temp = NULL;

	// curr will loop over list. At every iteration, we first store a pointer to the next Node, and then delete the current Node.
    while(curr != NULL){ // Looping over list
		temp = curr->next; // store pointer to next Node in the list
		delete(curr); // delete the current Node
		curr = temp; // update curr to proceed through list
	}
	head = NULL;
    return;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string LinkedList :: print()
{
    string list_str = ""; // string that has list
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	// curr will loop over list. It prints the content of curr, and then moves curr to next Node.
	while(curr != NULL){ // looping over list
        list_str = list_str + to_string(curr->data) + " "; //append string with current Node's data
		curr = curr->next; // proceed through list
	}
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back(); // remove the last (extra) space from string
    return list_str;
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LinkedList :: length()
{
    int length = 0; // initialize length to zero
	Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	
	while(curr != NULL){ // looping over list
		length++; // increment length
		curr = curr->next; // proceed to next Node
	}
	return length;
}

void LinkedList :: HeadRotate(int k) {
    if (head == NULL || head->next == NULL || head->data == k) return;
    
    Node *curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == k) {
            Node *klink = curr->next;
            curr->next = curr->next->next;
            klink->next = head;
            head = klink;
            return;
        }
        curr = curr->next;
    }
}

Node* LinkedList :: Reverse(Node *h) {
    Node *prev = NULL;
    Node *curr = h;
    Node *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void LinkedList :: Rotate(int k) {
    if (head == NULL || head->next == NULL || k == 0) return;
    
    Node *curr = head;
    int len = 1;
    while (curr->next != NULL) {
        len++;
        curr = curr->next;
    }
    
    Node *oldtail = curr;
    k = k % len;
    curr = head;

    for (int i = 0; i < len - k - 1; i++) {
        curr = curr->next;
    }

    Node *nh = curr->next;
    curr->next = NULL;
    oldtail->next = head;
    head = nh;
}

void LinkedList :: ReverseTail(int k) {
    Node* curr = head;
    Node* nh = NULL;
    Node *prev = NULL;
    while (curr != NULL && curr->data == k) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        return;
    }
    nh = Reverse(curr);
    prev->next = nh;
}

bool LinkedList :: isPalindrome() {
    int vals[32] = {};
    Node *curr = head;
    int length = 0;

    while (curr != NULL) {
        vals[length] = curr->data;
        length++;
        curr = curr->next;
    }

    for (int i = 0; i < length; i++) {
        int j = length - i - 1;
        if (vals[i] != vals[j]) {
            return false;
        }
    }
    return true;
}

void LinkedList :: DeleteLast(int k) {    
    Node *curr = head;
    int last = -1;
    for (int i = 0; i < length(); i++) {
        if (curr->data == k) last = i;
        curr = curr->next;
    }
    
    if (last < 0) return;
    curr = head;

    for (int i = 0; i < last-1; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
}

void LinkedList :: Dedup(int k) {    
    if (head == NULL || head->next == NULL) return;
    Node *curr = head;
    bool firstf = false;
    if (curr->data == k) firstf = true;
    while (curr->next != NULL) {
        if (curr->next->data == k) {
            if (firstf == true) {
                curr->next = curr->next->next;
                continue;
            }
            firstf = true;
        }
        curr = curr->next;
    }
}
