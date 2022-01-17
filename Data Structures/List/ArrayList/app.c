#include "list.c"

void options(); 

int main() {
    int size, item, loc;
    char option;
    list list;

    printf("Enter size of the list: ");
    scanf("%d", &size);
    
    list = create_list(size);
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
                printf("Location: ");
                scanf("%d", &loc);
                printf("Item: ");
                scanf("%d", &item);
                if(insert(&list, loc, item))
                    printf("Inserted %d at location %d\n", item, loc);
                else
                    printf("Operation failed!\n");
                break;
            case 'u':
                printf("Location: ");
                scanf("%d", &loc);
                printf("New item: ");
                scanf("%d", &item);
                if(update(&list, loc, item))
                    printf("Updated %d at location %d\n", item, loc);
                else
                    printf("Operation failed!\n");
                break;
            case 'd':
                printf("Location: ");
                scanf("%d", &loc);
                if(delete(&list, loc))
                    printf("Deleted item at location %d\n", loc);
                else
                    printf("Operation failed!\n");
                break;
            case 'g':
                printf("Location: ");
                scanf("%d", &loc);
                item = get(list, loc);
                if(item != INT_MIN)
                    printf("Item %d is at location %d\n", item, loc);
                else
                    printf("Operation failed!\n");
                break;
            case 'p':
                print(list);
                break;
            case 's':
                printf("Size is %d\n", get_size(list));
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
    printf("g: get\n");
    printf("p: print\n");
    printf("s: size\n");
    printf("q: quit\n");
}