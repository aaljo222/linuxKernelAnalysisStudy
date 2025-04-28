#ifndef TASK_STRUCT_H
#define TASK_STRUCT_H

typedef enum {
    TASK_RUNNING,
    TASK_WAITING,
    TASK_STOPPED
} task_state_t;

struct task_struct {
    int pid;
    task_state_t state;
    char name[32];
};

#endif
