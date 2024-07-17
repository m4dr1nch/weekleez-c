#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "state.h"
#include "task.h"
#include "utils.h"

void add_task(struct State* state)
{
    printf("Add new node.\n");
    printf("Name: ");

    char* name = (char *) malloc(MAX_TASK_NAME_SIZE);
    fgets(name, MAX_TASK_NAME_SIZE, stdin);
    name[strcspn(name, "\n")] = 0;

    struct Task* task = create_task(name);
    append_task(task, &state->head, &state->tail);

    state->amount += 1;
}

void print_status(struct State* state)
{
    printf("Completed: %i/%i\n", state->completed, state->amount);
}

void print_tasks(struct State* state)
{
    if (state->head == NULL)
    {
        printf("There are no tasks.\n");
        return;
    }

    printf("Tasks:\n");
    struct Task *task = state->head;

    int i = 1;
    while (task != NULL)
    {
        print_task(task, i++);
        task = task->next;
    }
    print_status(state);
}

void remove_task(struct State* state)
{
    print_tasks(state);

    int index;
    printf("Select task: ");
    scanf("%i", &index);
    clear_stdin();

    if (index < 0 || index > state->amount)
    {
        printf("Index is out of range.\n");
        return;
    }

    struct Task* task = find_task(&state->head, index);

    delete_task(&state->head, task);

    printf("Task deleted\n");
}

void complete_task(struct State* state)
{
    print_tasks(state);

    int index;
    printf("Select task: ");
    scanf("%i", &index);
    clear_stdin();

    if (index < 0 || index > state->amount)
    {
        printf("Index is out of range.\n");
        return;
    }

    struct Task* task = find_task(&state->head, index);

    set_complete(task, true);

    printf("Task marked as completed\n");
}

void uncomplete_task(struct State* state)
{
    print_tasks(state);

    int index;
    printf("Select task: ");
    scanf("%i", &index);
    clear_stdin();

    if (index < 0 || index > state->amount)
    {
        printf("Index is out of range.\n");
        return;
    }

    struct Task* task = find_task(&state->head, index);

    set_complete(task, false);

    printf("Task marked as not completed\n");
}
