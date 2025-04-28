#include "scheduler.h"

int main() {
    init_runqueue();

    for (int i = 0; i < 5; ++i) {
        scheduler_tick();
    }

    return 0;
}
