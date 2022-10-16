/* C program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* pull off the front node of the source and put it in dest */
void MoveNode(struct Node** destRef, struct Node** sourceRef);

/* Takes two lists sorted in increasing order, and splices
their nodes together to make one big sorted list which
is returned. */
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	/* a dummy first node to hang the result on */
	struct Node dummy;

	/* tail points to the last result node */
	struct Node* tail = &dummy;

	/* so tail->next is the place to add new nodes
	to the result. */
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the
source, and move it to the front of the dest.
It is an error to call this with the source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
	/* the front source node */
	struct Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}


/* Function to insert a node at the beginning of the
linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* res = NULL;
	struct Node* a = NULL;
	struct Node* b = NULL;

	/* Let us create two sorted linked lists to test
	the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	printf("Merged Linked List is: \n");
	printList(res);

	return 0;
}

//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *temp = NULL, *first = NULL, *second = NULL, *third = NULL, *last = NULL;

struct Node* Create (int A[], int n)
{
    int i;
    struct Node *t, *last;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = A[0];
    temp->next = NULL;
    last = temp;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return temp;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d ", p->data);
        p = p->next;
    }
}

void Merge(struct Node *first, struct Node *second)
{
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    if (first != NULL)
        last->next = first;
    else
        last->next = second;
}

int main()
{
    int A[] = { 3, 4, 7, 9 };
    int B[] = { 2, 5, 6, 8 };
    first = Create (A, 4);
    second = Create (B, 4);

    printf ("1st Linked List: ");
    Display (first);

    printf ("\n2nd Linked List: ");
    Display (second);

    Merge (first, second);

    printf ("\n\nMerged Linked List: \n");
    Display (third);
  return 0;
}