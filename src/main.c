#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "state.h"

int main()
{
    banner();
 
    bool running = true;
    char option;

    struct State state;
    state.head = NULL;
    state.tail = NULL;
    state.amount = 0;
    state.completed = 0;

    while (running)
    {
        options();

        printf("Select option: ");
        scanf("%c", &option);
        clear_stdin();

        switch (option)
        {
            case '1':
                print_tasks(&state);
                break;
            case '2':
                add_task(&state);
                break;
            case '3':
                remove_task(&state);
                break;
            case '4':
                complete_task(&state);
                break;
            case '5':
                uncomplete_task(&state);
                break;
            case 'q':
                printf("Exiting\n");
                running = false;
                break;
            default:
                printf("Invalid option!!\n");
        }
    } 

    return 0;
}
