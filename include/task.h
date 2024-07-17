#pragma once

#include <stdbool.h>

#define MAX_TASK_NAME_SIZE 64

struct Task 
{
    char* name;
    bool complete;

    struct Task *next;
    struct Task *prev;
};

struct Task* create_task (char* name);
struct Task* find_task (struct Task**, int);
void append_task (struct Task*, struct Task**, struct Task** tail);
void delete_task (struct Task**, struct Task*);
void print_task (struct Task*, int);
void set_complete(struct Task*, bool);
