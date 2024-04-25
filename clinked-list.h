#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H

typedef struct listNode {
	int data;
	struct listNode* prev;
	struct listNode* next;
} ListNode;

typedef struct list {
	ListNode* nil;
} List;

ListNode* createNode(int data);
List* createList();
ListNode* search(List* list, int data);
void prepend(List* list, int data);
void postpend(List* list, int data);
void insertAt(List* list,int x, int y);
void del(List* list, int data);
void delList(List* list);
void printList(List* list);
void printReverse(List* list);
void reverseList(List* list);
#endif
