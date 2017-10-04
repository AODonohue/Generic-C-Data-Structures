/*********************************************************************
 * FILE NAME: DSInterface.h
 * PURPOSE: Interface of generic data structures
 *********************************************************************/
#include "ListType.h"
#include <string.h>

// Linked-List Interface
///////////////////////////////////////////////////////////////////////

/*********************************************************************
 * FUNCTION NAME: initializeList
 * PURPOSE: Sets a List variable to the empty List.
 * ARGUMENTS: The address of the List variable to be initialized
 *            (List *) 
 * ENSURES: . Empty will return true (a nonzero integer).
 *          . Full will return false (0).
 *          . Length will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the List variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void initializeList (List *L);

/*********************************************************************
 * FUNCTION NAME: insertList
 * PURPOSE: Inserts an Item in a List.
 * ARGUMENTS: . The Item to be inserted (Item)
 *            . The position in the List
 *              where the Item should be inserted in (int) 
 *            . The address of the List (List *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             not greater than the length of the List.
 *           . The List should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Length will return the first integer greater
 *            than the length of the List before the call.
 *          . Peek in the same position will find
 *            the Item that was inserted.
 *********************************************************************/
extern void insertList (Item X, int position, List *L);

/*********************************************************************
 * FUNCTION NAME: deleteList
 * PURPOSE: Deletes an Item from a List.
 * ARGUMENTS: . The position in the List
 *              where the Item to be deleted is in (int) 
 *            . The address of the List (List *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the List.
 *           . The List should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Length will return the first integer lower
 *            than the length of the List before the call.
 *********************************************************************/
extern void deleteList (int position, List *L);

/*********************************************************************
 * FUNCTION NAME: fullList
 * PURPOSE: Determines whether a List is full.
 * ARGUMENTS: The address of the List (List *) 
 * RETURNS: True (a nonzero integer) if the List is full,
 *          false (0) otherwise
 *********************************************************************/
extern int fullList (List *L);

/*********************************************************************
 * FUNCTION NAME: emptyList
 * PURPOSE: Determines whether a List is empty.
 * ARGUMENTS: The address of the List (List *) 
 * RETURNS: True (a nonzero integer) if the List is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int emptyList (List *L);

/*********************************************************************
 * FUNCTION NAME: lengthList
 * PURPOSE: Finds the size of a List.
 * ARGUMENTS: The address of the List (List *) 
 * RETURNS: The size of the List (int)
 *********************************************************************/
extern int lengthList (List *L);

/*********************************************************************
 * FUNCTION NAME: peekList
 * PURPOSE: Finds an Item in a List.
 * ARGUMENTS: . The position in the List where the Item is in (int) 
 *            . The address of the List (List *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the List.
 *           . The List should not be empty.
 *********************************************************************/
extern void peekList (int position, List *L, Item *X);

/*********************************************************************
 * FUNCTION NAME: destroyList
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Delete.
 * ARGUMENTS: The address of the List to be destroyed (List *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void destroyList (List *L);

/*********************************************************************
 * FUNCTION NAME: reverseList
 * PURPOSE: Reverses a List
            (the first Item becomes the last and vice versa).
 * ARGUMENTS: The address of the List to be reversed (List *)
 * Note: some concepts borrowed from: 
 *       stackoverflow.com/questions/2434411
 *********************************************************************/
extern void reverseList (List *L);

///////////////////////////////////////////////////////////////////////


// Stack Interface
///////////////////////////////////////////////////////////////////////

/*********************************************************************
 * FUNCTION NAME: initializeStack
 * PURPOSE: Sets a Stack variable to the empty Stack.
 * ARGUMENTS: The address of the Stack variable to be initialized
 *            (Stack *) 
 * ENSURES: . Empty will return true (a nonzero integer).
 *          . Full will return false (0).
 *          . Length will return 0.
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Stack variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void initializeStack (Stack *S);

/*********************************************************************
 * FUNCTION NAME: pushStack
 * PURPOSE: Inserts an Item in a Stack.
 * ARGUMENTS: . The Item to be inserted (Item)
 *            . The position in the Stack
 *              where the Item should be inserted in (int) 
 *            . The address of the Stack (Stack *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             not greater than the length of the Stack.
 *           . The Stack should not be full.
 * ENSURES: . Empty will return false (0).
 *          . Length will return the first integer greater
 *            than the length of the Stack before the call.
 *          . Peek in the same position will find
 *            the Item that was inserted.
 *********************************************************************/
extern void pushStack (Item X, Stack *S);

/*********************************************************************
 * FUNCTION NAME: popStack
 * PURPOSE: Deletes an Item from a Stack.
 * ARGUMENTS: . The position in the Stack
 *              where the Item to be deleted is in (int) 
 *            . The address of the Stack (Stack *L)
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the Stack.
 *           . The Stack should not be empty.
 * ENSURES: . Full will return false (0).
 *          . Length will return the first integer lower
 *            than the length of the Stack before the call.
 *********************************************************************/
extern void popStack (Stack *S);

/*********************************************************************
 * FUNCTION NAME: fullStack
 * PURPOSE: Determines whether a Stack is full.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: True (a nonzero integer) if the Stack is full,
 *          false (0) otherwise
 *********************************************************************/
extern int fullStack (Stack *S);

/*********************************************************************
 * FUNCTION NAME: emptyStack
 * PURPOSE: Determines whether a Stack is empty.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: True (a nonzero integer) if the Stack is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int emptyStack (Stack *S);

/*********************************************************************
 * FUNCTION NAME: lengthStack
 * PURPOSE: Finds the size of a Stack.
 * ARGUMENTS: The address of the Stack (Stack *) 
 * RETURNS: The size of the Stack (int)
 *********************************************************************/
extern int lengthStack (Stack *S);

/*********************************************************************
 * FUNCTION NAME: topStack
 * PURPOSE: Finds an Item in a Stack.
 * ARGUMENTS: . The position in the Stack where the Item is in (int) 
 *            . The address of the Stack (Stack *L)
 *            . The address of the Item
 *              the Item found should be copied to
 * REQUIRES: . The position should be a nonnegative integer
 *             lower than the length of the Stack.
 *           . The Stack should not be empty.
 *********************************************************************/
extern void topStack (Stack *S, Item *X);

/*********************************************************************
 * FUNCTION NAME: destroyStack
 * PURPOSE: Frees memory that may have been allocated
 *          by Initialize, Insert or Delete.
 * ARGUMENTS: The address of the Stack to be destroyed (Stack *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void destroyStack (Stack *S);

/*********************************************************************
 * FUNCTION NAME: reverseStack
 * PURPOSE: Reverses a Stack
 (the first Item becomes the last and vice versa).
 * ARGUMENTS: The address of the Stack to be reversed (Stack *) 
 *********************************************************************/
extern void reverseStack (Stack *S);

///////////////////////////////////////////////////////////////////////


// BST Interface
///////////////////////////////////////////////////////////////////////

/*********************************************************************
 * FUNCTION NAME: initializeBST
 * PURPOSE: Sets a Tree variable to the empty Binary Search Tree.
 * ARGUMENTS: . The address of the Tree variable to be initialized
 *              (Tree *) 
 *            . A pointer to a copy function
 *              ---------------------------- 
 *              PURPOSE: Makes a copy of an item.
 *              ARGUMENTS: . NULL, or the address (void *) of  
 *                           the location in memory where the 
 *                           copy must be stored
 *                         . The address (void *) of the item 
 *                           to be copied
 *              RETURNS: The address (void *) of the location in
 *                       memory where the copy has been stored
 *              NOTES: If the first argument is NULL, the copy
 *                     function allocates memory for the copy,
 *                     and this memory should later be freed
 *                     by the destroy function below.
 *              -------------------------------
 *            . A pointer to a destroy function
 *              -------------------------------
 *              PURPOSE: Frees memory that may have been 
 *                       allocated by the copy function above.
 *              ARGUMENT: The address of the item to be destroyed
 *                        (void *); this address must have been
 *                        returned by the copy function called
 *                        with NULL as its first argument
 *              -------------------------------
 *            . A pointer to a compare function
 *              -------------------------------
 *              PURPOSE: Compares two items.
 *              ARGUMENTS: . A pointer to a first item (void *)
 *                         . A pointer to a second item (void *)
 *              RETURNS: The integer
 *                       -1 if the 1st item is less than the 2nd item,
 *                        0 if the two items are equal,
 *                        1 otherwise
 *              -----------------------
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Tree variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void initializeBST (Tree *T,
						void * (*copyItem) (void *, void *),
						void (*destroyItem) (void *),
						int (*compareItems) (void *, void *));

/*********************************************************************
 * FUNCTION NAME: insertBST
 * PURPOSE: Inserts an item in a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address of the item to be inserted (void *)
 *********************************************************************/
extern void insertBST (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: minimumBST
 * PURPOSE: Finds the least item (according to the compare 
 *          function whose address was passed to Initialize)
 *          of a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy 
 *              of the least item should be stored 
 * RETURNS: 1 if the minimum has been found,
 *          i.e., if the Tree is not empty,
 *          0 otherwise
 *********************************************************************/
extern int minimumBST (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: successorBST
 * PURPOSE: Finds the successor (according to the compare 
 *          function whose address was passed to Initialize)
 *          in a Binary Search Tree of the last item found by
 *          Successor or Minimum (whichever was called last).
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy 
 *              of the successor should be stored 
 * RETURNS: 1 if the successor has been found,
 *          i.e., if the Tree is not empty and if the
 *          last item found by Minimum or Successor
 *          was not the greatest element of the Tree,
 *          0 otherwise
 * NOTES: A call to Successor must be immediately
 *        preceded by a call to Successor or Minimum.
 *********************************************************************/
extern int successorBST (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: destroyBST
 * PURPOSE: Frees memory that may have been 
 *          allocated by Initialize and Insert.
 * ARGUMENTS: The address of the Tree to be destroyed (Tree *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void destroyBST (Tree *T);

///////////////////////////////////////////////////////////////////////


// AVL Tree Interface
///////////////////////////////////////////////////////////////////////

/*********************************************************************
 * FUNCTION NAME: initializeAVL
 * PURPOSE: Sets a Tree variable to the empty Binary Search Tree.
 * ARGUMENTS: . The address of the Tree variable to be initialized
 *              (Tree *) 
 *            . A pointer to a copy function
 *              ---------------------------- 
 *              PURPOSE: Makes a copy of an item.
 *              ARGUMENTS: . NULL, or the address (void *) of  
 *                           the location in memory where the 
 *                           copy must be stored
 *                         . The address (void *) of the item 
 *                           to be copied
 *              RETURNS: The address (void *) of the location in
 *                       memory where the copy has been stored
 *              NOTES: If the first argument is NULL, the copy
 *                     function allocates memory for the copy,
 *                     and this memory should later be freed
 *                     by the destroy function below.
 *              -------------------------------
 *            . A pointer to a destroy function
 *              -------------------------------
 *              PURPOSE: Frees memory that may have been 
 *                       allocated by the copy function above.
 *              ARGUMENT: The address of the item to be destroyed
 *                        (void *); this address must have been
 *                        returned by the copy function called
 *                        with NULL as its first argument
 *              -------------------------------
 *            . A pointer to a compare function
 *              -------------------------------
 *              PURPOSE: Compares two items.
 *              ARGUMENTS: . A pointer to a first item (void *)
 *                         . A pointer to a second item (void *)
 *              RETURNS: The integer
 *                       -1 if the 1st item is less than the 2nd item,
 *                        0 if the two items are equal,
 *                        1 otherwise
 *              -----------------------
 * NOTES: Initialize is the only function that may be used right
 *        after the declaration of the Tree variable or a call
 *        to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern void initializeAVL (Tree *T,
						void * (*copyItem) (void *, void *),
						void (*destroyItem) (void *),
						int (*compareItems) (void *, void *));

/*********************************************************************
 * FUNCTION NAME: insertAVL
 * PURPOSE: Inserts an item in a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address of the item to be inserted (void *)
 *********************************************************************/
extern void insertAVL (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: minimumAVL
 * PURPOSE: Finds the least item (according to the compare 
 *          function whose address was passed to Initialize)
 *          of a Binary Search Tree.
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy 
 *              of the least item should be stored 
 * RETURNS: 1 if the minimum has been found,
 *          i.e., if the Tree is not empty,
 *          0 otherwise
 *********************************************************************/
extern int minimumAVL (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: successorAVL
 * PURPOSE: Finds the successor (according to the compare 
 *          function whose address was passed to Initialize)
 *          in a Binary Search Tree of the last item found by
 *          Successor or Minimum (whichever was called last).
 * ARGUMENTS: . The address of the Tree (Tree *)
 *            . The address (void *) where a copy 
 *              of the successor should be stored 
 * RETURNS: 1 if the successor has been found,
 *          i.e., if the Tree is not empty and if the
 *          last item found by Minimum or Successor
 *          was not the greatest element of the Tree,
 *          0 otherwise
 * NOTES: A call to Successor must be immediately
 *        preceded by a call to Successor or Minimum.
 *********************************************************************/
extern int successorAVL (Tree *T, void *I);

/*********************************************************************
 * FUNCTION NAME: sizeAVL
 * PURPOSE: Finds the number of items stored in a Binary Search Tree.
 * ARGUMENT: The address of the Tree (Tree *) 
 * RETURNS: The number of items stored in the Tree
 *********************************************************************/
extern int sizeAVL (Tree *T);

/*********************************************************************
 * FUNCTION NAME: heightAVL
 * PURPOSE: Calculates the height of a Binary Search Tree.
 * ARGUMENT: The address of the Tree (Tree *) 
 * RETURNS: The height of the Tree
 * NOTES: The height of the empty Tree is -1.
 *********************************************************************/
extern int heightAVL (Tree *T);

/*********************************************************************
 * FUNCTION NAME: balancedAVL
 * PURPOSE: Checks whether a Binary Search Tree is balanced.
 * ARGUMENT: The address of the Tree (Tree *) 
 * RETURNS: 1 if the Tree is balanced, 0 otherwise
 * NOTES: A Tree is balanced if it is empty or if for any node N
 *        the heights of N's subTrees are equal or differ by 1.
 *********************************************************************/
extern int balancedAVL (Tree *T);

/*********************************************************************
 * FUNCTION NAME: Destroy
 * PURPOSE: Frees memory that may have been 
 *          allocated by Initialize and Insert.
 * ARGUMENTS: The address of the Tree to be destroyed (Tree *) 
 * NOTES: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void destroyAVL (Tree *T);

///////////////////////////////////////////////////////////////////////


// Heap Interface
///////////////////////////////////////////////////////////////////////

/*********************************************************************
 * FUNCTION NAME: initializeHeap
 * PURPOSE: Sets a Heap variable to the empty Heap.
 * ARGUMENTS: . The address of the Heap variable to be initialized
 *              (Heap *) 
 *			  . The requested capacity for the Heap (int)
 *            . A pointer to a copy function
 *              ---------------------------- 
 *              PURPOSE: Makes a copy of an item.
 *              ARGUMENTS: . NULL, or the address (void *) of  
 *                           the location in memory where the 
 *                           copy must be stored
 *                         . The address (void *) of the item 
 *                           to be copied
 *              RETURNS: The address (void *) of the location in
 *                       memory where the copy has been stored;
 *					     NULL if no copy could be made
 *              NOTE: If the first argument is NULL, the copy
 *                    function allocates memory for the copy,
 *                    and this memory should later be freed
 *                    by the destroy function below.
 *              -------------------------------
 *            . A pointer to a destroy function
 *              -------------------------------
 *              PURPOSE: Frees memory that may have been 
 *                       allocated by the copy function above.
 *              ARGUMENT: The address of the item to be destroyed
 *                        (void *); this address must have been
 *                        returned by the copy function called
 *                        with NULL as its first argument
 *              -------------------------------
 *            . A pointer to a compare function
 *              -------------------------------
 *              PURPOSE: Compares two items.
 *              ARGUMENTS: . A pointer to a first item (void *)
 *                         . A pointer to a second item (void *)
 *              RETURNS: The integer
 *                       -1 if the 1st item is less than the 2nd item,
 *                        0 if the two items are equal,
 *                        1 otherwise
 *              -----------------------
 * RETURNS: True (a nonzero integer) if the Heap could be initialized,
 *		    false (0) otherwise
 * NOTE: Initialize is the only function that may be used right
 *       after the declaration of the Heap variable or a call
 *       to Destroy, and it should not be used otherwise.
 *********************************************************************/
extern int initializeHeap (Heap *H,
					   int capacity,
					   void * (*copyItem) (void *, void *),
					   void (*destroyItem) (void *),
					   int (*compareItems) (void *, void *));

/*********************************************************************
 * FUNCTION NAME: insertHeap
 * PURPOSE: Inserts an item in a Heap.
 * ARGUMENTS: . The address of the Heap (Heap *)
 *            . The address of the item to be inserted (void *)
 * RETURNS: True (a nonzero integer) if the item could be inserted,
 *		    false (0) otherwise
 *********************************************************************/
extern int insertHeap (Heap *H, void *I);

/*********************************************************************
 * FUNCTION NAME: removeHeap
 * PURPOSE: Removes the largest item from a Heap.
 * ARGUMENT: The address of the Heap (Heap *)
 *********************************************************************/
extern void removeHeap (Heap *H);

/*********************************************************************
 * FUNCTION NAME: topHeap
 * PURPOSE: Finds the largest item in a Heap.
 * ARGUMENTS: . The address of the Heap (Heap *)
 *            . The address where a copy of the
 *			    largest item should be stored
 *********************************************************************/
extern void topHeap (Heap *H, void *I);

/*********************************************************************
 * FUNCTION NAME: fullHeap
 * PURPOSE: Determines whether a Heap is full.
 * ARGUMENT: The address of the Heap (Heap *) 
 * RETURNS: True (a nonzero integer) if the Heap is full,
 *          false (0) otherwise
 *********************************************************************/
extern int fullHeap (Heap *H);

/*********************************************************************
 * FUNCTION NAME: emptyHeap
 * PURPOSE: Determines whether a Heap is empty.
 * ARGUMENT: The address of the Heap (Heap *) 
 * RETURNS: True (a nonzero integer) if the Heap is empty,
 *          false (0) otherwise
 *********************************************************************/
extern int emptyHeap (Heap *H);

/*********************************************************************
 * FUNCTION NAME: destroyHeap
 * PURPOSE: Frees memory that may have been 
 *          allocated by Initialize and Insert.
 * ARGUMENT: The address of the Heap to be destroyed (Heap *) 
 * NOTE: The last function to be called should always be Destroy. 
 *********************************************************************/
extern void destroyHeap (Heap *H);

///////////////////////////////////////////////////////////////////////