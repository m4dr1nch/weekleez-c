#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "task.h"

struct Task* create_task(char* name)
{
    // Alocate a task
    struct Task *task;
    task = malloc(sizeof(struct Task));

    // Set parameters
    task->name = name;
    task->complete = false;
    return task;
}

struct Task* find_task(struct Task** head, int index)
{
    if (index == 1)
        return *head;

    if ((*head)->next == NULL)
        return NULL;

    struct Task* task = (*head)->next;

    int i = 2;
    while (task != NULL)
    {
        if (i == index)
        {
            return task;
        }
        task = task->next;
    }
    
    return NULL;
}

void append_task(struct Task* task, struct Task** head, struct Task** tail)
{
    // Set next as NULL as this is an append
    task->next = NULL;

    // If first element (add normaly)
    if (*head == NULL && *tail == NULL)
    {
        *head = task;
        *tail = task;
        return;
    }

    task->prev = *tail;
    (*tail)->next = task;
    *tail = task;
    return;
}

void delete_task(struct Task** head, struct Task* task)
{
    if (*head == NULL || task == NULL)
        return;

    if (*head == task)
        *head = task->next;

    if (task->next != NULL)
        task->next->prev = NULL;

    if (task->prev != NULL)
        task->prev->next = task->next;

    free(task);
}

void print_task(struct Task* task, int index)
{
    printf("%i. Completed: %b | Name: %s\n", index, task->complete, task->name);
}

void set_complete(struct Task* task, bool complete)
{
    task->complete = complete;
}
