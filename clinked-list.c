#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "clinked-list.h"

ListNode* createNode(int data) {
	ListNode* node = malloc(sizeof(ListNode));
	if (!node) { return NULL; }

	node->data = data;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

List* createList() {
	List* list = malloc(sizeof(List));
	if (!list) { return NULL; }

	ListNode* sentinil = createNode(INT_MIN);

	list->nil = sentinil;
	list->nil->next = list->nil;
	list->nil->prev = list->nil;

	return list;
}

ListNode* search(List* list, int data) {
	list->nil->data = data;
	ListNode* curr = list->nil->next;
	
	while (curr->data != data) {
		curr = curr->next;
	}

	if (curr == list->nil) {
		return NULL;
	}

	return curr;
}

void prepend(List* list, int data) {
	ListNode* node = createNode(data);
	if (node == NULL) { return; }

	node->next = list->nil->next;
	node->prev = list->nil;
	if (list->nil->next != NULL) {
		list->nil->next->prev = node;
	}
	list->nil->next = node;
}

void postpend(List* list, int data) {
	if (list->nil->next == list->nil) {
		return prepend(list, data);
	}

	ListNode* node = createNode(data);
	
	node->next = list->nil;
	node->prev = list->nil->prev;
	list->nil->prev->next = node;
}

// inserts x after y
void insertAt(List* list, int x, int y) {
	ListNode* existingNode = search(list, y);
	if (existingNode == NULL) { return; }
	ListNode* newNode = createNode(x);

	newNode->next = existingNode->next;
	newNode->prev = existingNode;
	existingNode->next->prev = newNode;
	existingNode->next = newNode;
}

void del(List* list, int data) {
	ListNode* node = search(list, data);
	if (node == NULL) { return; }

	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

void printList(List* list) {
	ListNode* curr = list->nil->next;
	if (list->nil->next == list->nil) {
		printf("NIL\n");
	}

	printf("NIL<->");
	while (curr != list->nil) {
		printf("[%d]<->", curr->data);
		curr = curr->next;
	}
	printf("NIL\n");
}

void delList(List* list) {
	ListNode* curr = list->nil->next;
	ListNode* tmp = NULL;
	while (curr != list->nil) {
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}

	free(list->nil);
	free(list);
}

int main() {
	List* list = createList();
	prepend(list, 10);
	prepend(list, 20);
	prepend(list, 30);
	prepend(list, 40);
	prepend(list, 50);
	prepend(list, 60);
	prepend(list, 70);
	prepend(list, 80);
	prepend(list, 90);

	printList(list);

	del(list, 60);

	printList(list);

	delList(list);

	return 0;
}
