#pragma once

#include "task.h"

struct State 
{
    struct Task *head;
    struct Task *tail;

    int amount;
    int completed;
};

void add_task (struct State*);
void remove_task (struct State*);
void print_status (struct State*);
void print_tasks (struct State*);
void complete_task (struct State*);
void uncomplete_task (struct State*);
