#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct list {
    int data[MAX_SIZE];
    int size;
    int current_size;
};
typedef struct list list;

list create_list(int size) {
    list new_list;
    new_list.size = size;
    new_list.current_size = 0;

    return new_list;
}

int insert(list* list, int loc, int item) {
    if (list->current_size == list->size) {
        printf("WARN: List is full\n");
        return 0;
    }
 
    if (loc > list->current_size + 1) {
        printf("WARN: Index out of bounds\n");
        return 0;
    }
 
    for( int i = list->current_size; i >= loc; i--) {
        list->data[i] = list->data[i-1];
    }
    list->data[loc-1] = item;
    list->current_size++;
    return 1;
}

int update(list* list, int loc, int item) {
    if (loc > list->current_size) {
        printf("WARN: Index out of bounds\n");
        return 0;
    }
    list->data[loc-1] = item;
    return 1;
}

int delete(list* list, int loc) {
    if (loc > list->current_size) {
        printf("WARN: Index out of bounds\n");
        return 0;
    }

    for( int i = loc; i <= list->current_size; i++) {
        list->data[i-1] = list->data[i];
    }
    list->current_size--;
    return 1;
}

int get(list list, int loc) {
    if (loc > list.current_size) {
        printf("WARN: Index out of bounds\n");
        return INT_MIN;
    }

    return list.data[loc-1];
}

void print(list list) {
    printf("list [ ");
    for (int i = 0; i < list.current_size; i++)
    {
        printf("%d", list.data[i]);
        if( i != list.current_size-1) printf(", ");
    }
    printf(" ]\n");    
}

int is_empty(list list) {
    return !list.current_size;
}

int is_full(list list) {
    return list.current_size == list.size;
}

int get_size(list list) {
    return list.current_size;
}