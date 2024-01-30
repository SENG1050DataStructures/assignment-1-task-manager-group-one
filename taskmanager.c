#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

#define KTaskMaxLength 101

struct Task {
    int TaskId;
    char Title[KTaskMaxLength];
    char Description[KTaskMaxLength];
    struct Task* NextTask;	
};

void printTasks(struct Task head);

int main(void)
{
	char userInput[KTaskMaxLength] = "";
	int command = 0;
	struct Task* head = NULL;

	while (1)
	{
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");

		fgets(userInput, sizeof userInput, stdin);
		
		if ((sscanf(userInput, "%d", &command) != 1) || (command > 5) || (command < 1))
		{
			printf("Please enter valid input.\n\n");
			continue;
		}

		else
		{
			switch (command) 
			{
			case 1:
				//add Task
				break;
			case 2:
				//Delete Task & Free memory
				break;
			case 3:
				//Delete Find Task
				break;
			case 4:
				printTasks(head);
				break;
			case 5:
				//Free memory
				return 0;
			}
		}
	}
}

void printTasks(struct Task head)
{
	struct Task current = head;
	while (current.NextTask != NULL)
	{
		printf("Task ID: %d\n Title: %s\n Description: %s\n", current.TaskId, current.Title, current.Description);
		printf("-------------------------------------------");
		current = *(current.NextTask);
	}

	printf("Task ID: %d\n Title: %s\n Description: %s\n", current.TaskId, current.Title, current.Description);
	printf("-------------------------------------------/n/n");
}
