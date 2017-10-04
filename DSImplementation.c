/*********************************************************************
 * FILE NAME: DSImplementation.c
 * PURPOSE: Generic data structure implementation.
 *********************************************************************/

#include "DSInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Linked-List Implementation
///////////////////////////////////////////////////////////////////////

static void copyListItem (Item *Y, Item X) {
// Chenge to item ----------> InitializeItem(NameOfItem(X),Y);
}


static void destroyListItem (Item *X) {
// Chenge to item ----------> FreeItem(X);
}


static ListNode *moveListTo (int position, List *L) {
	int i;
	ListNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}

void initializeList (List *L) {
	L->size=0;
	L->first=NULL;
    assert(emptyList(L));
    assert(!fullList(L));
    assert(lengthList(L) == 0);
}

void insertList (Item X, int position, List *L) { 
    assert(position >= 0 );
    assert(position <= lengthList(L));
    assert(!fullList(L));

	ListNode *p, *q;
	int oldLength = lengthList(L);
	L->size++;
	q=(ListNode *)malloc(sizeof(ListNode));
	copyListItem(&q->item,X);
			 
	if(position==0) {
		q->next=L->first;
		L->first=q;
	} else {
		p=moveListTo(position-1,L);
		q->next=p->next;
		p->next=q;
	}
    
    Item peekTemp;
    peekList(position, L, &peekTemp);
    
    assert(!emptyList(L));
    assert(lengthList(L) == oldLength+1);
}

void deleteList (int position, List *L) {
    assert(position >= 0 );
    assert(position <= lengthList(L));
    assert(lengthList(L) > 0);
    
	ListNode *p, *q;
    
    int oldLength = lengthList(L);
	
	if(position==0) {
		q=L->first;
		L->first=q->next;
	} else {
		p=moveListTo(position-1,L);
		q=p->next;
		p->next=q->next;
	}
	
	destroyListItem(&q->item);
	free(q);
	L->size--;
    
    assert(!fullList(L));
    assert(lengthList(L) == oldLength-1);
}


int fullList (List *L) {
	return L->size==MAXLISTSIZE;
}


int emptyList (List *L) {
	return L->size==0;
}


int lengthList (List *L) {
	return L->size;
}

void peekList (int position, List *L, Item *X) {
    assert(position >= 0 );
    assert(position <= lengthList(L));
    assert(lengthList(L) > 0);

	ListNode *p;
	p=moveListTo(position,L);
	copyListItem(X,p->item);
}


void destroyList (List *L) {
    
	int i;
	ListNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyListItem(&q->item);
		free(q);
	}
}

void reverseList (List *L) {
    assert(L != NULL);
    
    ListNode *head, *remainder;
    List tempRest;
    
    head = L->first;
    remainder = head->next;
    if (remainder == NULL)
        return;
    tempRest.first = remainder;
    
    reverseList(&tempRest);
    
    head->next->next = head;
    head->next = NULL;    
    L->first = tempRest.first;
}

///////////////////////////////////////////////////////////////////////


// AVL Tree Implementation
///////////////////////////////////////////////////////////////////////

static void copyStackItem (Item *Y, Item X) {
// Chenge to item ----------> InitializeItem(NameOfItem(X),Y);
}


static void destroyStackItem (Item *X) {
// Chenge to item ----------> FreeItem(X);
}


static StackNode *moveStackTo (int position, Stack *L) {
	int i;
	StackNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}


void initializeStack (Stack *L) {
	L->size=0;
	L->first=NULL;
}


void pushStack (Item X, Stack *L) {
    StackNode *q;
	L->size++;
	q=(StackNode *)malloc(sizeof(StackNode));
    q->item = X;
    q->next = L->first;
    L->first = q;
}


void popStack (Stack *L) {
    assert(L != NULL);
    StackNode *tempNode;
    Item tempItem;

    topStack(L, &tempItem);
    tempNode = L->first;
    L->first = L->first->next;
	free(tempNode);
	L->size--;
}


int fullStack (Stack *L) {
	return L->size;
}


int emptyStack (Stack *L) {
	return L->size==0;
}


int lengthStack (Stack *L) {
	return L->size;
}


void topStack (Stack *L, Item *X) {
    *X = L->first->item;
}

void destroyStack (Stack *L) {
	int i;
	StackNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyStackItem(&q->item);
		free(q);
	}
}

void reverseStack (Stack *L) {
    assert(L != NULL);
    
    StackNode *head, *remainder;
    Stack tempRest;
    
    head = L->first;
    remainder = head->next;
    if (remainder == NULL)
        return;
    tempRest.first = remainder;
    
    reverseStack(&tempRest);
    
    head->next->next = head;
    head->next = NULL;    
    L->first = tempRest.first;
}

///////////////////////////////////////////////////////////////////////


// BST Implementation
///////////////////////////////////////////////////////////////////////

static TreeNode *minimum (TreeNode *N) {
	while(N->left!=NULL) N=N->left;
	return N;
}


static void destroy (TreeNode *N, Tree *T) {
	if(N!=NULL) {
		destroy(N->left,T);
		destroy(N->right,T);
		T->destroyItem(N->item);
		free(N);
	}
}


void initializeBST (Tree *T,
				 void * (*copyItem) (void *, void *),
				 void (*destroyItem) (void *),
				 int (*compareItems) (void *, void *)) {
	T->root=NULL;
	T->copyItem=copyItem;
	T->destroyItem=destroyItem;
	T->compareItems=compareItems;
}


void insertBST (Tree *T, void *I) {
	TreeNode *N, *P, *Q;
	
	N=malloc(sizeof(TreeNode));
	N->item=T->copyItem(NULL,I);
	N->right=NULL;
	N->left=NULL;
	P=T->root;
	Q=NULL;
	
	while(P!=NULL) {
		Q=P;
		if(T->compareItems(I,P->item)<0) P=P->left;
		else P=P->right;
	}
	
	N->parent=Q;
	if(Q==NULL) T->root=N;
	else if(T->compareItems(I,Q->item)<0) Q->left=N;
	else Q->right=N;
}


int minimumBST (Tree *T, void *I) {
	TreeNode *N;
	if(T->root==NULL) return 0;
	N=minimum(T->root);
	T->current=N;
	T->copyItem(I,N->item);
	return 1;
}


int successorBST (Tree *T, void *I) {
	TreeNode *N, *P;
	if(T->root==NULL) return 0;
	if((N=T->current->right)!=NULL) {
		P=minimum(N);
		T->current=P;
		T->copyItem(I,P->item);
		return 1;
	}
	N=T->current;
	P=N->parent;
	while(P!=NULL && N==P->right) {
		N=P;
		P=P->parent;
	}
	if(P==NULL) return 0;
	T->current=P;
	T->copyItem(I,P->item);
	return 1;
}


void destroyBST (Tree *T) {
	destroy(T->root,T);	
}

///////////////////////////////////////////////////////////////////////


// AVL Tree Implementation
///////////////////////////////////////////////////////////////////////

static TreeNode *insert (Tree *T, void *I) {
	TreeNode *N, *P, *Q;
	
	N=malloc(sizeof(TreeNode));
	N->item=T->copyItem(NULL,I);
	N->right=NULL;
	N->left=NULL;
	P=T->root;
	Q=NULL;
	
	while(P!=NULL) {
		Q=P;
		if(T->compareItems(I,P->item)<0) P=P->left;
		else P=P->right;
	}
	
	N->parent=Q;
	if(Q==NULL) T->root=N;
	else if(T->compareItems(I,Q->item)<0) Q->left=N;
	else Q->right=N;
	T->size++;
	return N;
}


static TreeNode *minimum (TreeNode *N) {
	while(N->left!=NULL) N=N->left;
	return N;
}


static int height (TreeNode *N) {
	int hleft, hright;
	if(N==NULL) return -1;
	hleft=height(N->left);
	hright=height(N->right);
	if(hleft<hright) return 1+hright;
	else return 1+hleft;
}


static int balanced (TreeNode *N) {
	int hleft, hright;
	if(N==NULL) return -1;
	hleft=balanced(N->left);
	if(hleft==-2) return -2;
	hright=balanced(N->right);
	if(hright==-2) return -2;
	if(hleft-hright<-1 || hleft-hright>1) return -2;
	if(hleft<hright) return 1+hright;
	else return 1+hleft;
}


static void destroy (TreeNode *N, Tree *T) {
	if(N!=NULL) {
		destroy(N->left,T);
		destroy(N->right,T);
		T->destroyItem(N->item);
		free(N);
	}
}


void initializeAVL (Tree *T,
				 void * (*copyItem) (void *, void *),
				 void (*destroyItem) (void *),
				 int (*compareItems) (void *, void *)) {
	T->root=NULL;
	T->copyItem=copyItem;
	T->destroyItem=destroyItem;
	T->compareItems=compareItems;
	T->size=0;
}


void insertAVL (Tree *T, void *I) {
	TreeNode *N, *A, *B, *C, *P;
	TreeNode *T1, *T2, *T3, *T4;
	int i;
	
	N=insert(T,I);
	if(N->parent==NULL || N->parent->parent==NULL) return;
	while(balanced(N->parent->parent)!=-2) {
		N=N->parent;
		if(N->parent->parent==NULL) return;
	}
	
	A=N; B=N->parent;
	C=B->parent; P=C->parent;
	if(P==NULL) i=0;
	else if(P->left==C) i=-1;
	else i=1;
	
	if(C->left==B) 
		if(B->left==A) {
			T2=A->right; T3=B->right; 
		}
		else {
			N=A; A=B; B=N;
			T2=B->left; T3=B->right; 
		}
	else 
		if(B->left==A) {
			N=A; A=C; C=B; B=N;
			T2=B->left; T3=B->right; 
		}
		else {
			N=A; A=C; C=N;
			T2=B->left; T3=C->left;
		}	
	
	T1=A->left; T4=C->right;
	A->right=T2; C->left=T3;
	B->left=A; B->right=C; 
	A->parent=B; C->parent=B;
	if(T1!=NULL) T1->parent=A; 
	if(T2!=NULL) T2->parent=A;
	if(T3!=NULL) T3->parent=C;
 	if(T4!=NULL) T4->parent=C;
	if(i==0) {T->root=B; B->parent=NULL;}
	else if(i==-1) {P->left=B; B->parent=P;}
	else {P->right=B; B->parent=P;}
}


int minimumAVL (Tree *T, void *I) {
	TreeNode *N;
	if(T->root==NULL) return 0;
	N=minimum(T->root);
	T->current=N;
	T->copyItem(I,N->item);
	return 1;
}


int successorAVL (Tree *T, void *I) {
	TreeNode *N, *P;
	if(T->root==NULL) return 0;
	if((N=T->current->right)!=NULL) {
		P=minimum(N);
		T->current=P;
		T->copyItem(I,P->item);
		return 1;
	}
	N=T->current;
	P=N->parent;
	while(P!=NULL && N==P->right) {
		N=P;
		P=P->parent;
	}
	if(P==NULL) return 0;
	T->current=P;
	T->copyItem(I,P->item);
	return 1;
}


int sizeAVL (Tree *T) {
	return T->size;
}


int heightAVL (Tree *T) {
	return height(T->root);
}


int balancedAVL (Tree *T) {
	if(balanced(T->root)==-2) return 0;
	return 1;
}


void destroyAVL (Tree *T) {
	destroy(T->root,T);	
}

///////////////////////////////////////////////////////////////////////


// Heap Implementation
///////////////////////////////////////////////////////////////////////

int initializeHeap (Heap *H,
				int capacity,
				void * (*copyItem) (void *, void *),
				void (*destroyItem) (void *),
				int (*compareItems) (void *, void *)) {
	H->heap=malloc(sizeof(void *)*(capacity+1));
	if(H->heap==NULL) return 0;
	H->capacity=capacity;
	H->numberOfItems=0;
	H->copyItem=copyItem;
	H->destroyItem=destroyItem;
	H->compareItems=compareItems;
	return 1;
}


int insertHeap (Heap *H, void *I) {
	int parent, child;
	void *temp;

	temp=H->copyItem(NULL,I);
	if(temp==NULL) return 0;
	H->numberOfItems++;
	H->heap[H->numberOfItems]=temp;
	
	child=H->numberOfItems;
	parent=child/2;
	while(child!=1 && H->compareItems(H->heap[child],H->heap[parent])>0) {
		temp=H->heap[parent];
		H->heap[parent]=H->heap[child];
		H->heap[child]=temp;
		child=parent;
		parent=child/2;
	}
	return 1;
}


void removeHeap (Heap *H) {
	int parent, child;
	void *temp;
	
	H->destroyItem(H->heap[1]);
	H->heap[1]=H->heap[H->numberOfItems];
	H->numberOfItems--;
	
	parent=1;
	child=2; 
	if(child<H->numberOfItems && H->compareItems(H->heap[child],H->heap[child+1])<0)
		child++;
	while(child<=H->numberOfItems && H->compareItems(H->heap[child],H->heap[parent])>0) {
		temp=H->heap[parent];
		H->heap[parent]=H->heap[child];
		H->heap[child]=temp;
		parent=child;
		child=parent*2;
		if(child<H->numberOfItems && H->compareItems(H->heap[child],H->heap[child+1])<0)
			child++;		
	}
}


void topHeap (Heap *H, void *I) {
	H->copyItem(I,H->heap[1]);
}


int fullHeap (Heap *H) {
	return H->numberOfItems==H->capacity;
}


int emptyHeap (Heap *H) {
	return H->numberOfItems==0;
}


void destroyHeap (Heap *H) {
	int i;
	for(i=1;i<=H->numberOfItems;i++)	
		H->destroyItem(H->heap[i]);
	free(H->heap);
}

///////////////////////////////////////////////////////////////////////