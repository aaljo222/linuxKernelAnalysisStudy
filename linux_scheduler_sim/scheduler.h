#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task_struct.h"

void scheduler_tick();
struct task_struct* pick_next_task();
void context_switch(struct task_struct* next);
void init_runqueue();

#endif
