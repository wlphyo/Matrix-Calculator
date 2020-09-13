/*
Wai Lwi Phyo
CruzID: wlphyo
pa2
*/
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
//Structures
// private NodeObj type
typedef struct NodeObj{
   void* data;
   struct NodeObj* next;
   struct NodeObj* previous;

} NodeObj;
// private Node type
typedef NodeObj* Node;
//private ListObj type
typedef struct ListObj
{
	Node front,back; //pointer to front node and back node
	Node cursor; //walking pointer
	int length, index;
} ListObj;

//Constructors-Destructors
//make new Node
Node newNode(void* data)
{
	Node N = malloc(sizeof(NodeObj));
	N->data = data;
	N->next = NULL;
	N->previous = NULL;
	return(N);
}
//free memory
void freeNode(Node* pN)
{
	if(pN!= NULL && *pN!=NULL)
	{
		free(*pN);
		*pN = NULL;
	}
}
//Returns reference to new empty List object
List newList(void)
{
	List L;
	L = malloc(sizeof(ListObj));
	L->front = L->back = L->cursor = NULL;
	L->length = 0;
	L->index = -1;
	return(L);
}
//Frees all memory associated to List
void freeList(List* pL)
{
		clear(*pL);	
		//free(*pL);
		*pL = NULL;

}

//Access functions
//Returns the number of elements in L
int length(List L)
{
	if(L==NULL)
	{
		printf("List Error: length() NULL List reference\n");
		exit(1);
	}
	return(L->length);
}
//returns index of cursor element if defined, -1 otherwise
int index(List L)
{
	if(L==NULL)
	{
		printf("List Error: front() NULL List reference\n");
		exit(1);
	}	
	if(L->cursor == NULL) return -1;
	return(L->index);
}
//returns front element of L
//length has to be > 0
void* front(List L)
{

	if(L==NULL)
	{
		printf("List Error: front() NULL List reference\n");
		exit(1);
	}
	if(length(L) <= 0)
	{
		printf("1 List is empty\n");
		exit(1);
	}
	return(L->front->data);
}
//returns back element of L
//Length has to be > 0
void* back(List L)
{
	if(L==NULL)
	{
		printf("List Error: back() NULL List reference\n");
		exit(1);
	}
	if(length(L) <= 0)
	{
		printf("2 List is empty\n");
		exit(1);
	}
	return(L->back->data);
}
//returns cursor element of L
//length has to be > 0 and index should be >=0
void* get(List L)
{
	if(L==NULL)
	{
		printf("List Error: get() NULL List reference\n");
		exit(1);
	}
	if(index(L) < 0)
	{
		printf("Undefined Cursor Position");
		exit(1);
	}
	if(length(L) == 0)
	{
		printf("3 List is empty\n");
		exit(1);
	}
	return(L->cursor->data);
}

//Maniplation Procedures
//resets L to empty state
void clear(List L)
{
	if(L==NULL)
	{
		printf("Cannot clear on NULL List\n");
		exit(1);
	}
	while(L->front!=NULL)	deleteFront(L);
	L->front = L->back = L->cursor = NULL;
	L->length = 0;
	L->index = -1;
}
//if L is not empty, cursor is under front, otherwise none
void moveFront(List L)
{

	if(L==NULL)
	{
		printf("List Error: moveFront() NULL List reference\n");
		exit(1);
	}
	if(length(L) > 0)
	{
		L->cursor = L->front;
		L->index = 0;
	}
}
//if L is not empty, cursor is under back, otherwise none
void moveBack(List L)
{	
	if(L==NULL)
	{
		printf("List Error: moveBack() NULL List reference\n");
		exit(1);
	}

	if(length(L)>0)
	{
		L->cursor = L->back;
		L->index = length(L) -1;
	}
}
//if L is not empty, move previous. If cursor at front, do nothing
void movePrev(List L)
{
	if(L==NULL)
	{
		printf("List Error: movePrev() NULL List reference\n");
		exit(1);
	}

	if(L->cursor == NULL)
	{
		L->cursor = NULL;
		L->index = -1;
	
	}else if(L->cursor != NULL && L->cursor==L->front)
	{
		L->cursor = NULL;
		L->index =-1;
		
	}else if(L->cursor != NULL && L->cursor != L->front)
	{
		L->cursor = L->cursor->previous; //move to next node
		L->index--; 
	}
}
//if cursor is not at the back, move cursor one step toward back of L.
//if cursor is defined and 
void moveNext(List L)
{

	if(L==NULL)
	{
		printf("List Error: moveNext() NULL List reference\n");
		exit(1);
	}
	if(L->cursor == NULL)
	{
		L->cursor = NULL;
		L->index = -1;
	
	}else if(L->cursor != NULL && L->cursor==L->back)
	{
		L->cursor = NULL;
		L->index =-1;
		
	}else if(L->cursor != NULL && L->cursor != L->back)
	{
		L->cursor = L->cursor->next; //move to next node
		L->index++; 
	}
	
}
//insert before front element if L is not empty.
void prepend(List L, void* data)
{
	Node N = newNode(data);
	if(L==NULL)
	{
		printf("List Error: prepend() NULL List reference\n");
		exit(1);
	}
	if(length(L) == 0) 
	{
		L->front = L->back = N;
	}
	else
	{
		L->front->previous = N;
		N->next =L->front;
		L->front = N;
		//L->index++;
	}
	L->length++;
	if(index(L) != -1) L->index++;
}
//insert after back element if L is not empty.
void append(List L, void* data)
{
	Node N = newNode(data);
	if(L==NULL)
	{
		printf("List Error: prepend() NULL List reference\n");
		exit(1);
	}
	else if(length(L) == 0)
	{
		 L->front =L->back= N;
	 }
	else
	{
		L->back->next = N;
		N->previous =L->back;
		L->back = N;
		
	}
	L->length++;
}
//Insert new element before cursor
//length should be > 0 and index >= 0
void insertBefore(List L, void* data)
{
	if(L==NULL)
	{
		printf("List Error: insertBefore() NULL List reference\n");
		exit(1);
	}
	if(length(L) <= 0)
	{
		printf("4 List is empty\n");
		exit(1);
	}
	if(index(L) < 0)
	{
		printf("Undefined Cursor Position\n");
		exit(1);
	}

	
	if(L->cursor==L->front)
	{
		prepend(L,data);

	}else
	{
		Node temp = newNode(data);
		temp->next = L->cursor;
		temp->previous = L->cursor->previous;
		temp->next->previous = temp;
		temp->previous->next = temp;
		if(L->cursor) L->index++;
		L->length++;
		//~ L->cursor->previous->next = temp;
		//~ temp->previous = L->cursor->previous;
		//~ temp->next = L->cursor;
		//~ L->cursor->previous = temp;
		//~ L->length++;
	}
	
}

//Insert new element before cursor
//length should be > 0 and index >= 0
void insertAfter(List L, void* data)
{
	if(L==NULL)
	{
		printf("List Error: insertAfter() NULL List reference\n");
		exit(1);
	}
	if(length(L) == 0)
	{
		printf("5 List is empty\n");
		exit(1);
	}
	if(L->index < 0)
	{
		printf("Undefined Cursor Position\n");
		exit(1);
	}

	Node temp = newNode(data);
	if(L->cursor==L->back)
	{
		append(L,data);

	}else
	{
		L->cursor->next->previous = temp;
		temp->next = L->cursor->next;
		temp->previous = L->cursor;
		L->cursor->next = temp;
		L->length++;
	}
	
}
//delete the front element 
//length has to be > 0
void deleteFront(List L)
{
	if(L==NULL)
	{
		printf("List Error: insertAfter() NULL List reference\n");
		exit(1);
	}
	if(L->length <= 0)
	{
		printf("deleteFront() length is 0\n");
		exit(1);
	}	
	if(L->cursor == L->front)
	{
		L->cursor = L->cursor->next;
	}
	if(L->length==1)
	{
		L->front = L->back = L->cursor = NULL;
		L->length = 0;
		L->index = -1;
	}
	else
	{
		Node temp = L->front;
		L->front = L->front->next;
			freeNode(&temp);
		L->index--;
		L->length--;

	}
	
}
//delete the back element 
//length has to be > 0
void deleteBack(List L)
{	
	if(L==NULL)
	{
		printf("List Error: insertAfter() NULL List reference\n");
		exit(1);
	}
	if(length(L) <= 0)
	{
		printf("7 List is empty\n");
		exit(1);
	}	
	if(length(L) == 1)
	{
		Node temp = L->back;
		if(L->index ==0)
		{
			L->cursor = NULL;
			L->index = -1;
		}
		freeNode(&temp);
		L->front = L->back = NULL;
		L->length = 0;
	}
	else
	{
		if(L->cursor == L->back)
		{
			L->index =-1;
			L->cursor = NULL;
		}
		Node temp = L->back;
		L->back = L->back->previous;
		L->back->next = NULL;
		L->length--;
		freeNode(&temp);
	}
}
//dete cursor element, cursor is undefined
//length should be > 0 and index >= 0
void delete(List L)
{
	
	if(L==NULL)
	{
		printf("List Error: insertAfter() NULL List reference\n");
		exit(1);
	}
	if(length(L) <= 0)
	{
		printf("8 List is empty\n");
		exit(1);
	}
	if(L->index < 0)
	{
		printf("Undefined Cursor Position\n");
		exit(1);
	}
	Node A,B;
	if(L->index == 0)
	{
		deleteFront(L);
	}else if(L->index == length(L)-1)
	{
		deleteBack(L);
	} else 
	{
		//connect nodes
		A= L->cursor->previous;
		B = L->cursor->next;
		A->next = B;	
		B->previous = A;
		L->cursor = NULL;
		L->length--;
		L->index = -1;
	}
	
}


