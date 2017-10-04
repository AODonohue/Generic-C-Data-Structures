/*********************************************************************
 * FILE NAME: DSType.h
 * PURPOSE: Generic data structure definition.
 *********************************************************************/

// Chenge to item ----------> #include "ItemInterface.h"
// Chenge to item ----------> typedef Object Item;


#define MAXLISTSIZE 4

typedef struct ListNodeTag {
	Item item;
	struct ListNodeTag *next;
} ListNode;

typedef struct {
	int size;
	ListNode *first;
} List;

typedef struct TreeNodeTag {
	void *item;
	struct TreeNodeTag *left, *right, *parent;
} TreeNode;

typedef struct {
	TreeNode *root;
	TreeNode *current;
	void * (*copyItem) (void *, void *);
	void (*destroyItem) (void *);
	int (*compareItems) (void *, void *);
} Tree;

typedef struct {
	void **heap;
	int capacity;
	int numberOfItems;
	void * (*copyItem) (void *, void *);
	void (*destroyItem) (void *);
	int (*compareItems) (void *, void *);
} Heap;

typedef struct StackNodeTag {
	Item item;
	struct StackNodeTag *next;
} StackNode;

typedef struct {
	int size;
	StackNode *first;
} Stack;