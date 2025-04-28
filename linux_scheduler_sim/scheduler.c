#include "scheduler.h"
#include <stdio.h>

static struct task_struct runqueue[3];
static int current = 0;

void scheduler_tick() {
    struct task_struct* next = pick_next_task();
    context_switch(next);
}

struct task_struct* pick_next_task() {
    current = (current + 1) % 3;
    return &runqueue[current];
}

void context_switch(struct task_struct* next) {
    printf("Switching to PID %d (%s)\n", next->pid, next->name);
}

void init_runqueue() {
    runqueue[0] = (struct task_struct){ .pid = 1, .state = TASK_RUNNING, .name = "init" };
    runqueue[1] = (struct task_struct){ .pid = 2, .state = TASK_RUNNING, .name = "bash" };
    runqueue[2] = (struct task_struct){ .pid = 3, .state = TASK_RUNNING, .name = "nginx" };
}
