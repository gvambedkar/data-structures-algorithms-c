#include "list.c"

void options(); 
void insert_options(list);
void delete_options(list);
void search_options(list);
void order_options(list);
void util_options(list);

int main() {
    int size, item, loc;
    char option;
    list list;

    printf("Enter size of the list: ");
    scanf("%d", &size);
    
    list = List(size);
    printf("List with size %d created\n", size);

    options();

    while (1)
    {
        printf("\nChoose operation: ");
        scanf(" %c", &option);
        
        switch (option)
        {
            case 'h':
                options();
                break;

            case 'i':
                insert_options(list);
                break;

            case 'u':
                printf("Location: ");
                scanf("%d", loc);
                printf("New item: ");
                scanf("%d", &item);
                if(update(list, loc, item))
                    printf("Updated %d at location %d\n", item, loc);
                else
                    printf("Operation failed!\n");
                break;

            case 'd':
                delete_options(list);
                break;

            case 's':
                search_options(list);
                break;

            case 'o':
                order_options(list);
                break;

            case 't':
                util_options(list);
                break;

            case 'q':
                exit(0);
                break;

            default:
                // printf("\nChoose a valid option: ");
                break;
        }
    }
    
    return 0;
}

void options() {
    printf("h: help\n");
    printf("i: insert\n");
    printf("u: update\n");
    printf("d: delete\n");
    printf("s: search\n");
    printf("o: order\n");
    printf("t: utilities\n");
    printf("q: quit\n");
}

void insert_options(list list) {
    char option;
    int loc, item;

    while(1) {
        printf("a: insert\n");
        printf("b: append\n");
        printf("c: prepend\n");
        printf("x: back\n");

        printf(":");
        scanf(" %c", &option);

        switch (option)
        {
            case 'a':
                printf("Location: ");
                scanf("%d", &loc);
                printf("Item: ");
                scanf("%d", &item);
                if(insert(list, loc, item))
                    printf("Inserted %d at location %d\n", item, loc);
                else
                    printf("Operation failed!\n");
                break;

            case 'b':
                printf("Item: ");
                scanf("%d", &item);
                if(append(list, item))
                    printf("Appended %d\n", item);
                else
                    printf("Operation failed!\n");
                break;

            case 'c':
                printf("Item: ");
                scanf("%d", &item);
                if(prepend(list, item))
                    printf("Prepended %d\n", item);
                else
                    printf("Operation failed!\n");
                break;

            case 'p': 
                print(list);
                break;

            case 'x':
                return;
                break;

            default:
                break;
        }
    }
}

void delete_options(list list) {
    char option;
    int loc, item;

    while(1) {
        printf("a: delete at\n");
        printf("b: delete first\n");
        printf("c: delete last\n");
        printf("d: delete first occurance\n");
        printf("e: delete last occurance\n");
        printf("p: print\n");

        printf("x: back\n");

        printf(":");
        scanf(" %c", &option);

        switch (option)
        {
            case 'a':
                printf("Location: ");
                scanf("%d", loc);
                if(delete(list, loc))
                    printf("Deleted item at location %d\n", loc);
                else
                    printf("Operation failed!\n");
                break;

            case 'b':
                if(delete_first(list))
                    printf("Deleted first item\n");
                else
                    printf("Operation failed!\n");
                break;

            case 'c':
                if(delete_last(list))
                    printf("Deleted last item\n");
                else
                    printf("Operation failed!\n");
                break;

            case 'd':
                printf("Item: ");
                scanf("%d", &item);
                if(delete_first_occurance(list, item))
                    printf("Deleted first occurance of item %d\n", item);
                else
                    printf("Operation failed!\n");
                break;

            case 'e':
                printf("Item: ");
                scanf("%d", &item);
                if(delete_last_occurance(list, item))
                    printf("Deleted last occurance of item %d\n", item);
                else
                    printf("Operation failed!\n");
                break;
            
            case 'p': 
                print(list);
                break;

            case 'x':
                return;
                break;

            default:
                break;
        }
    }

}

void search_options(list list) {
    char option;
    int loc, item, times;

    while(1) {
        printf("a: find at at\n");
        printf("b: first index of\n");
        printf("c: last index of\n");
        printf("d: contains\n");
        printf("e: find times\n");
        printf("p: print\n");
        printf("x: back\n");

        printf(":");
        scanf(" %c", &option);

        switch (option)
        {
            case 'a':
                printf("Location: ");
                scanf("%d", loc);
                item = find_at(list, loc);
                if(item != INT_MIN)
                    printf("Item at location %d is %d\n", loc, item);
                else
                    printf("Item not found!\n");
                break;

            case 'b':
                printf("Item: ");
                scanf("%d", &item);
                loc = first_index_of(list, item);
                if(loc)
                    printf("First index of %d is %d\n", item, loc);
                else
                    printf("Item not found!\n");
                break;

            case 'c':
                printf("Item: ");
                scanf("%d", &item);
                loc = last_index_of(list, item);
                if(loc)
                    printf("Last index of %d is %d\n", item, loc);
                else
                    printf("Item not found!\n");
                break;

            case 'd':
                printf("Item: ");
                scanf("%d", &item);
                if(contains(list, item))
                    printf("List contains the item %d\n", item);
                else
                    printf("Item not found!\n");
                break;

            case 'e':
                printf("Item: ");
                scanf("%d", &item);
                times = find_times(list, item);
                if(times)
                    printf("%d is found %d times(s)\n", item, times);
                else
                    printf("Item not found!\n");
                break;

            case 'p': 
                print(list);
                break;

            case 'x':
                return;
                break;

            default:
                break;
        }
    }
}

void order_options(list list) {
    char option;
    int loc, item;

    while(1) {
        printf("a: sort ascending\n");
        printf("b: sort descending\n");
        printf("c: reverse\n");
        printf("p: print\n");
        printf("x: back\n");

        printf(":");
        scanf(" %c", &option);

        switch (option)
        {
            case 'a':
                sort(list, 'a');
                break;

            case 'b':
                sort(list, 'd');
                break;

            case 'c':
                reverse(list);
                break;

            case 'p': 
                print(list);
                break;

            case 'x':
                return;
                break;

            default:
                break;            
        }
    }
}

void util_options(list list) {
    char option;
    int loc, item;

    while(1) {
        printf("a: is empty?\n");
        printf("b: is full?\n");
        printf("c: size\n");
        printf("d: print\n");
        printf("x: back\n");

        printf(":");
        scanf(" %c", &option);

        switch (option)
        {
            case 'a':
                if(is_empty(list))
                    printf("List is empty\n");
                else
                    printf("List is not empty\n");
                break;

            case 'b':
                if(is_full(list))
                    printf("List is full\n");
                else
                    printf("List is not full\n");
                break;

            case 'c':
                printf("List size %d\n", get_size(list));
                break;

            case 'd':
                print(list);
                break;

            case 'x':
                return;
                break;

            default:
                break;
        }
    }
}