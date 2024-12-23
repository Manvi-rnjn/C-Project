#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

const int bar_length = 50;

typedef struct {
    int id;
    int progress;
    int step;
} Task;

void print_bar(Task task);
void clear_screen();
 
int main() {
    
    int max_tasks;
    printf("Enter number of tasks:\n");
    scanf("%d",&max_tasks);

    Task tasks[max_tasks];
    srand(time(NULL));

    for (int i = 0; i < max_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 3;
    }  

    int tasks_incomplete = 1;
    while (tasks_incomplete) {
        tasks_incomplete = 0;
        clear_screen();
        for (int i = 0; i < max_tasks; i++) {
            tasks[i].progress += tasks[i].step;
            if (tasks[i].progress > 100) {
                tasks[i].progress = 100;
            }
            if (tasks[i].progress < 100) {
                tasks_incomplete = 1;
            }
            print_bar(tasks[i]);
        }
        sleep(1); // Sleep for 1 second.
    }  
    printf("All tasks completed!\n");
    return 0;
}

void clear_screen() {
    // ANSI escape code to move the cursor to the top-left corner
    printf("\033[H\033[J");  // This moves the cursor to the top and clears the screen
}

void print_bar(Task task) {
    int bars_to_show = (task.progress * bar_length) / 100;
    printf("Task %d: [", task.id);
    for (int i = 0; i < bar_length; i++) {
        if (i < bars_to_show) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", task.progress);
}