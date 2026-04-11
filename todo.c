#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 200

typedef struct 
{
    char description[MAX_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void displayMenu() 
{
    printf("\n===== TO-DO LIST MANAGER =====\n");
    printf("1. Add a task\n");
    printf("2. View all tasks\n");
    printf("3. Mark task as completed\n");
    printf("4. Delete a task\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
}

void addTask() 
{
    if (taskCount >= MAX_TASKS) 
    {
        printf("\nTask list is full!\n");
        return;
    }
    
    printf("\nEnter task description: ");
    getchar();
    fgets(tasks[taskCount].description, MAX_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0; 
    tasks[taskCount].completed = 0;
    taskCount++;
    
    printf("Task added successfully!\n");
}

void viewTasks() 
{
    if (taskCount == 0) 
    {
        printf("\nNo tasks in your to-do list!\n");
        return;
    }
    
    printf("\n===== YOUR TASKS =====\n");
    for (int i = 0; i < taskCount; i++) 
    {
        printf("%d. [%s] %s\n", i + 1, 
               tasks[i].completed ? "X" : " ", 
               tasks[i].description);
    }
    printf("======================\n");
}

void markCompleted() 
{
    if (taskCount == 0) 
    {
        printf("\nNo tasks to mark as completed!\n");
        return;
    }
    
    viewTasks();
    printf("\nEnter task number to mark as completed: ");
    int taskNum;
    scanf("%d", &taskNum);
    
    if (taskNum < 1 || taskNum > taskCount) 
    {
        printf("Invalid task number!\n");
        return;
    }
    
    tasks[taskNum - 1].completed = 1;
    printf("Task marked as completed!\n");
}

void deleteTask() 
{
    if (taskCount == 0) 
    {
        printf("\nNo tasks to delete!\n");
        return;
    }
    
    viewTasks();
    printf("\nEnter task number to delete: ");
    int taskNum;
    scanf("%d", &taskNum);
    
    if (taskNum < 1 || taskNum > taskCount) 
    {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = taskNum - 1; i < taskCount - 1; i++) 
    {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    
    printf("Task deleted successfully!\n");
}

int main() 
{
    int choice;
    
    printf("Welcome to To-Do List Manager!\n");
    
    while (1) 
    {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("\nThank you for using To-Do List Manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
