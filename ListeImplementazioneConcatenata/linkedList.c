#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) 
{
    if(first == NULL)
    {
        first = (LLElement*)malloc(sizeof(LLElement));
        if(first != NULL)
        {
            first->key = key;
            first->next = NULL;
        }
    }
    else
    {
        LLElement *element = (LLElement*)malloc(sizeof(LLElement));
        if(element != NULL)
        {
            element->key = key;
            element->next = first;
            first = element;
        }
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) 
{
    if(first == NULL)
    {
        first = (LLElement*)malloc(sizeof(LLElement));
        if(first != NULL)
        {
            first->key = key;
            first->next = NULL;
        }
    }
    else
    {
        LLElement *element = (LLElement*)malloc(sizeof(LLElement)), **temporary = &first;
        if(element != NULL)
        {
            element->key = key;
            element->next = NULL;
            while(*temporary != NULL)
                temporary = &((*temporary)->next);
            *temporary = element;
        }
    }
    return first;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position)
{
    if(first == NULL)
    {
        first = (LLElement*)malloc(sizeof(LLElement));
        if(first != NULL)
        {
            first->key = key;
            first->next = NULL;
        }
    }
    else
    {
        LLElement *element = (LLElement*)malloc(sizeof(LLElement)), **temporary;
        if(element != NULL)
        {
            int counter;
            temporary = &first;
            for(counter = 0; counter < position; counter++)
                temporary = &((*temporary)->next);
            element->next = *temporary;
            element->key = key;
            *temporary = element;
        }
    }
    return first;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first)
{
    int size = 0;
    for(size = 0; first != NULL; size++)
        first = first->next;
    return size;
}

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position)
{
    int counter;
    for(counter = 0; counter < position; counter++)
        first = first->next;
    return first->key;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition)
{
    int counter, position = -1;
    for(counter = 0; counter < startPosition; counter++)
        first = first->next;
    for(; first != NULL && position == -1; counter++)
    {
        if(first->key == key)
            position = counter;
        first = first->next;
    }
    return position;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first)
{
    if(first != NULL)
    {
        LLElement *elementToDelete = first;
        first = first->next;
        free(elementToDelete);
    }
    return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first)
{
    if(first != NULL)
    {
        LLElement **elementToDelete = &first;
        while((*elementToDelete)->next != NULL)
            elementToDelete = &((*elementToDelete)->next);
        *elementToDelete = NULL;
        free(*elementToDelete);
    }
    return first;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position)
{
    if(first != NULL)
    {
        int counter;
        LLElement *elementToDelete, **temporary = &first;
        for(counter = 0; counter < position; counter++)
            temporary = &((*temporary)->next);
        elementToDelete = *temporary;
        if((*temporary)->next != NULL)
            *temporary = (*temporary)->next;
        free(elementToDelete);
    }
    return first;
}

/* Empties the list */
LLElement * LLEmptyList(LLElement *first)
{
    LLElement *elementToDelete;
    while(first != NULL)
    {
        elementToDelete = first;
        first = first->next;
        free(elementToDelete);
    }
    return NULL;
}
