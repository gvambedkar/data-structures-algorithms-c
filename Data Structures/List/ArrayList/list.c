#include<stdio.h>
#include<stdlib.h>


/*
* This List is implemented using array. So, Items are stored in array.
* Memory allocation is static in C and size of the array need to be specified 
* at the time of declaration. 
*/
#define MAX_SIZE 100


/*
* List has properties
* 1. Items - an array to store items, iths case the list if of numbers, so int array.
* 2. Capacity - The capacity of the list. the list can grow up to this number.
* 3. size - The current size of the list, iniially set to zero.
* Created a user defined data type using 'struct' with these three properties to represent a list.
*/
struct list {
    int items[MAX_SIZE];
    int capacity;
    int size;
};

/* Set 'list' as alternative name for 'struct list*' */
typedef struct list* list;

/*
* Operations implementted the this 'Array List'
* Factory:
*   1. List - Ctreates a list
* Core Operations: 
*   2. Insert 
        2a. insert - inserts an item at the given position
*       2b. append - inserts at the end of the list
*       2c. prepend - inserts at the beginning of the list
*   3. Update - replaces item at the given position
*   4. Delete
*       4a. delete - deletes an item at the given position
*       4b. delete_first - deletes the first item
*       4c. delete_last - deletes the last item
*       4d. delete_first_occurance - deletes the first occurance of the given item
*       4e. delete_last_occurance - deletes the last occurance of the given item
*   5. Search
*       5a. find_at - finds the element at the given position
*       5b. first_index_of - finds the index of first occurance of the given item
*       5c. last_index_of - finds the index of last occurance of the given item
*       5d. contains - finds whether the given item is in the list
*       5e. find_times - finds no of times the given item found in the list
*   6. Order 
*       6a. sort - Sorts the list either ascending or descending
*       6b. reverse - reverses the order of items in the list
*   7. Utilities
*       7a. is_empty - tells whether the list is empty or not
*       7b. is_full - tells whether the list is full or not
*       7c. size - gets the size of the list
*       7d. print - prints the list
*/

/*
* Function: list 
* Parameters: capacity
* Returns: list
* Description: Creates a list with the given capacity and returns that list. 
* This is of like a factory function to create list
*/
list List(int capacity) {
    list new_list = (list) malloc(sizeof(struct list));
    new_list->capacity = capacity;
    new_list->size = 0;

    return new_list;
}

/*
* Function: insert 
* Parameters: list - which list, position - where in, what - item
* Returns: 1 if item inserted otherwise 0
* Description: Inserts the given item at the specified position in the given list
*/
int insert(list list, int position, int item) {
    // Check if the position is invalid. 
    // A position is called invalid if it is less than 0 or greater than capacity of the list.
    if (list->size == list->capacity) {
        printf("WARN: List is full\n");
        return 0;
    }
 
    // Check if the position is out of range
    // A position is called out of range if it is not continous with the existing items' positions.
    if (position > list->size + 1) {
        printf("WARN: Index out of range\n");
        return 0;
    }
 
    // Check if it needs to move items to the right to accommodate new item
    // Move all the items starting from item at 'size' to the item at the given position.
    // Nothing need to be moved, if the given position is the immediate next of 'size'.
    for( int i = list->size; i >= position; i--) {
        list->items[i] = list->items[i-1];
    }
    
    // Assign given items in the specified position
    list->items[position-1] = item;

    // Increase size by 1
    list->size++;

    return 1;
}

/*
* Function: append 
* Parameters: list - which list, what - item
* Returns: 1 if item inserted otherwise 0
* Description: Inserts the given item at the last position in the given list
*/
int append(list list, int item) {
    // check if list is full
    if( list->size == list->capacity ) {
        printf("WARN: List is full\n");
        return 0;
    }

    // assign value at last position
    list->items[list->size] = item;

    // Increase size by 1
    list->size++;

    return 1;
}

/*
* Function: prepend 
* Parameters: list - which list, what - item
* Returns: 1 if item inserted otherwise 0
* Description: Inserts the given item at the first position in the given list
*/
int prepend(list list, int item) {
    // check if list is full
    if( list->size == list->capacity ) {
        printf("WARN: List is full\n");
        return 0;
    }

    // Check if it needs to move items to the right to accommodate new item
    // Move all the items starting from item at 'size' to the item at the given position.
    // Nothing need to be moved, if the given position is the immediate next of 'size'.
    for( int i = list->size; i >= 1; i--) {
        list->items[i] = list->items[i-1];
    }

    // assign value at last position
    list->items[0] = item;

    // Increase size by 1
    list->size++;

    return 1;
}

/*
* Function: update 
* Parameters: list - which list, position - where in, what with - new item
* Returns: 1 if item updated otherwise 0
* Description: Updates the given item at the specified position in the given list
*/
int update(list list, int position, int item) {
    // Check if the position is out of range
    // Item can be deleted only if it is there in the list
    if (position > list->size) {
        printf("WARN: Index out of bounds\n");
        return 0;
    }

    // Assign given items in the specified position
    list->items[position-1] = item;

    return 1;
}

/*
* Function: delete 
* Parameters: list - which list, position - where in
* Returns: 1 if item deleted otherwise 0
* Description: deletes the item at the specified position in the given list
*/
int delete(list list, int position) {
    // Check if list is empty
    // Item can be deleted only if it is there in the list
    if (list->size == 0) {
        printf("WARN: List is empty\n");
        return 0;
    }

    // Check if the position is out of range
    // Item can be updated only if it is there in the list
    if (position > list->size) {
        printf("WARN: Index out of bounds\n");
        return 0;
    }

    // Check if it needs to move items to the left to fill the deleted item's position.
    // Move all the items starting from item at 'position' to the last item.
    // Nothing need to be moved, if the given position is the last item.
    for( int i = position; i <= list->size; i++) {
        list->items[i-1] = list->items[i];
    }

    // decrease size eby 1
    list->size--;

    return 1;
}

/*
* Function: delete_first 
* Parameters: list - which list
* Returns: 1 if item deleted otherwise 0
* Description: deletes the item at the first position in the given list
*/
int delete_first(list list) {
    // Check if list is empty
    // Item can be deleted only if it is there in the list
    if (list->size == 0) {
        printf("WARN: List is empty\n");
        return 0;
    }

    // Check if it needs to move items to the left to fill the deleted item's position.
    // Move all the items starting from item at 'position' to the last item.
    // Nothing need to be moved, if the given position is the last item.
    for( int i = 1; i <= list->size; i++) {
        list->items[i-1] = list->items[i];
    }

    // decrease size eby 1
    list->size--;

    return 1;
}

/*
* Function: delete_last 
* Parameters: list - which list
* Returns: 1 if item deleted otherwise 0
* Description: deletes the item at the first position in the given list
*/
int delete_last(list list) {
    // Check if list is empty
    // Item can be deleted only if it is there in the list
    if (list->size == 0) {
        printf("WARN: List is empty\n");
        return 0;
    }

    // decrease size eby 1
    list->size--;

    return 1;
}

/*
* Function: delete_first_occurance 
* Parameters: list - which list, which item
* Returns: 1 if item deleted otherwise 0
* Description: deletes the first occurance of the item in the given list
*/

int delete_first_occurance(list list, int item) {
    int found_at = -1;

    // get index of first occurance of the given item
    for(int i = 0; i < list->size; i++) {
        if(list->items[i] == item) {
            found_at = i+1;
            break;
        }
    }

    // return if not found
    if(found_at == -1) {
        printf("WARN: Item not found\n");
        return 0;
    }

    // Check if it needs to move items to the left to fill the deleted item's position.
    // Move all the items starting from item at 'position' to the last item.
    // Nothing need to be moved, if the given position is the last item.
    for( int i = found_at; i <= list->size; i++) {
        list->items[i-1] = list->items[i];
    }

    // decrease size eby 1
    list->size--;

    return 1;
}

/*
* Function: delete_last_occurance 
* Parameters: list - which list, which item
* Returns: 1 if item deleted otherwise 0
* Description: deletes the last occurance of the item in the given list
*/

int delete_last_occurance(list list, int item) {
    int found_at = -1;

    // get index of first occurance of the given item
    for(int i = list->size; i > 0; i--) {
        if(list->items[i-1] == item) {
            found_at = i;
            break;
        }
    }

    // return if not found
    if(found_at == -1) {
        printf("WARN: Item not found\n");
        return 0;
    }

    // Check if it needs to move items to the left to fill the deleted item's position.
    // Move all the items starting from item at 'position' to the last item.
    // Nothing need to be moved, if the given position is the last item.
    for( int i = found_at; i <= list->size; i++) {
        list->items[i-1] = list->items[i];
    }

    // decrease size eby 1
    list->size--;

    return 1;
}


/*
* Function: find_at 
* Parameters: list - which list, which location
* Returns: item at the given position
* Description: gives the item at the given position in the list.
*/
int find_at(list list, int position) {
    if (position > list->size) {
        printf("WARN: Index out of bounds\n");
        return INT_MIN;
    }

    return list->items[position-1];
}


/*
* Function: first_index_of
* Parameters: list - which list, which item
* Returns: the index of the first occurance of the given item
* Description: gives the index of first occurance of the given item in the list
*/
int first_index_of(list list, int item) {
    // get index of first occurance of the given item
    for(int i = 0; i < list->size; i++) {
        if(list->items[i] == item) {
            return i+1;
        }
    }

    return 0;
}


/*
* Function: last_index_of
* Parameters: list - which list, which item
* Returns: the index of the last occurance of the given item
* Description: gives the index of last occurance of the given item in the list
*/
int last_index_of(list list, int item) {
    // get index of last occurance of the given item
    for(int i = list->size; i > 0; i--) {
        if(list->items[i-1] == item) {
            return i;
        }
    }
    
    return 0;
}


/*
* Function: contains
* Parameters: list - which list, which item
* Returns: 1 if item found in the list otherwise 0
* Description: finds if the list contains the given item
*/
int contains(list list, int item) {
    // traverse through all items
    for(int i = 0; i < list->size; i++) {
        if(list->items[i] == item) {
            return  1;
        }
    }

    return 0;
}


/*
* Function: find_times
* Parameters: list - which list, which item
* Returns: no of times the item foumd in the list
* Description: gives the frequency of the given item in the list
*/
int find_times(list list, int item) {
    int times =0;

    // traverse through all items
    for(int i = 0; i < list->size; i++) {
        if(list->items[i] == item) {
            times++;
        }
    }

    return times;
}

/*
* Function: sort 
* Parameters: list - which list
* Returns: nothing
* Description: sorts the given list in the specified order
*/
void sort(list list, char order) {
    int temp;
    if( !(order == 'a' || order == 'd') ) {
        printf("ERROR: Invalid order\n");
        return;
    }
    for (int i = 0; i < list->size; ++i) 
    {
        for (int j = i + 1; j < list->size; ++j)
        {
            if( order == 'a') {
                if (list->items[i] > list->items[j]) 
                {
                    temp =  list->items[i];
                    list->items[i] = list->items[j];
                    list->items[j] = temp;
                }
            } else {
                if (list->items[i] < list->items[j]) 
                {
                    temp =  list->items[i];
                    list->items[i] = list->items[j];
                    list->items[j] = temp;
                }
            }
        }
    }    
}

/*
* Function: reverse 
* Parameters: list - which list
* Returns: nothing
* Description: reverses the given list in the specified order
*/
void reverse(list list) {
    int temp;

    for (int i = 0; i < list->size / 2; i++)
    {
        temp = list->items[list->size - 1 - i];
        list->items[list->size - 1 -i] = list->items[i];
        list->items[i] = temp;
    }
    
}

/*
* Function: is_empty 
* Parameters: list - which list
* Returns: 1 if empty otherwise 0
* Description: finds whether list is empty or not
*/
int is_empty(list list) {
    return !list->size;
}


/*
* Function: is_full
* Parameters: list - which list
* Returns: 1 if full otherwise 0
* Description: finds whether list is full or not
*/
int is_full(list list) {
    return list->size == list->capacity;
}


/*
* Function: get_size 
* Parameters: list - which list
* Returns: current size
* Description: gives the current size of the list
*/
int get_size(list list) {
    return list->size;
}

/*
* Function: print 
* Parameters: list - which list
* Returns: nothing
* Description: prints the given list
*/
void print(list list) {
    printf("list [ ");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d", list->items[i]);
        if( i != list->size-1) printf(", ");
    }
    printf(" ]\n");    
}
