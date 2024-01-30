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
void freeList(struct Task* head);

int main(void)
{
	char userInput[KTaskMaxLength] = "";
	int command = 0;
	struct Task dataStructureProject = { 1, "Project", "Work in a group on some code", NULL };
	struct Task exampleFoot = { 2, "Title", "Description", NULL };
	struct Task* head = &dataStructureProject;
	dataStructureProject.NextTask = &exampleFoot;
	int quitProgram = 0;

	while (quitProgram == 0)
	{
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");
		printf("Your choice: ");

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
				if (head == NULL)
				{
					printf("\n----------------------------------------------------------------------------\n");
					printf("There are currently no tasks defined. Please add some tasks before printing. \n");
					printf("----------------------------------------------------------------------------\n\n");
				}
				else
				{
					printTasks(*head);
				}
				break;
			case 5:
				freeList(head);
				quitProgram = 1;
			}
		}
	}
	return 0;
}

void printTasks(struct Task head)
{
	struct Task current = head;
	while (current.NextTask != NULL)
	{
		printf("-------------------------------------------\n");
		printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskId, current.Title, current.Description);
		current = *(current.NextTask);
	}

	printf("-------------------------------------------\n");
	printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskId, current.Title, current.Description);
	printf("-------------------------------------------\n\n");
}

void freeList(struct Task* head)
{
	struct Task* current = head;
	struct Task* nextTask = NULL;

	while (current != NULL)
	{
		nextTask = current->NextTask;
		free(current);
		current = nextTask;
	}
}
