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

struct Task* AddTask(struct Task* tail, struct Task taskToAdd);
struct Task CreateTask();
struct Task* findTaskByIndex(struct Task*, int);
void printTasks(struct Task head);
void freeList(struct Task* head);

/* User Input function prototypes */
int getNumber(const char[], int*);
int getString(const char[], char*);

int main(void) {
	/* Declare User Input variables */
	char userInput[KTaskMaxLength] = "";
	int command = 0;

	/* Linked List variables */
	struct Task dataStructureProject = { 1, "Project", "Work in a group on some code", NULL };
	struct Task exampleFoot = { 2, "Title", "Description", NULL };
	//struct Task* head = &dataStructureProject;(joe:I changed to below)
	struct Task* head = NULL;
	struct Task* current = NULL;
	struct Task* tail = NULL;
	int checker = 0;
	dataStructureProject.NextTask = &exampleFoot;

	while (command != 5) {
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");

		while (getNumber("Your choice", &command) != 0) {
			printf("--Input was not a valid integer--\n\n");
		}

		switch (command)
		{
		case 1:
			if (0 == checker)
			{
				head = AddTask(tail, CreateTask());
				current = head;
				checker++;
			}
			else
			{
				tail = AddTask(tail, CreateTask());
				current->NextTask = tail;
				current = tail;
			}
			break;
		case 2:
			//Delete Task & Free memory Aly will finish
			break;
		case 3:
			while (getNumber("Enter the index you want to display", &command) != 0) {
				printf("--Input was not a valid integer--\n\n");
			}
			if ((current = findTaskByIndex(head, command)) == NULL) {
				printf("--The Task at index %d cannot be found--", command);
				continue;
			}
			// print task info to display
			break;
		case 4:
			if (head == NULL) {
				printf("\n----------------------------------------------------------------------------\n");
				printf("There are currently no tasks defined. Please add some tasks before printing. \n");
				printf("----------------------------------------------------------------------------\n\n");
			}
			else{
				printTasks(*head);
			}
			break;
		case 5:
			freeList(head);
			break;
		default:
			printf("--Option %d does not exist--\n\n", command);
			break;
		}
	}
	return 0;
}

struct Task CreateTask() {
	struct Task task;
	char userInput[KTaskMaxLength] = "";

	while (getNumber("enter taskId?>>>", &(task.TaskId)) != 0) {
		printf("--Input was not a valid integer--\n\n");
	}

	while (getString("enter Title?>>>", &(task.Title)) != 0) {
		printf("--Input was not a valid integer--\n\n");
	}

	while (getString("enter Title?>>>", &(task.Description)) != 0) {
		printf("--Input was not a valid integer--\n\n");
	}

	return task;
}

struct Task* AddTask(struct Task* tail, struct Task taskToAdd)
{
	char userInput[KTaskMaxLength] = "";

	struct Task* current = tail;

	struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
	if (newTask == NULL) {
		printf("Add task is unsuccessful due to ran out of memory!");
		exit(EXIT_FAILURE);
	}

	newTask->TaskId = taskToAdd.TaskId;
	strcpy(newTask->Title, taskToAdd.Title);
	strcpy(newTask->Description, taskToAdd.Description);
	newTask->NextTask = NULL;

	return newTask;
}


struct Task* findTaskByIndex(struct Task* head, int index) {
	Task* current = head;
	for (int i = 0; i > index; i++) {
		if (current->NextTask == NULL) {
			return NULL;
		}
		current = current->NextTask;
	}
	return current;
}

void printTasks(struct Task head) {
	struct Task current = head;
	while (current.NextTask != NULL) {
		printf("-------------------------------------------\n");
		printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskId, current.Title, current.Description);
		current = *(current.NextTask);
	}

	printf("-------------------------------------------\n");
	printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskId, current.Title, current.Description);
	printf("-------------------------------------------\n\n");
}

void freeList(struct Task* head) {
	struct Task* current = head;
	struct Task* nextTask = NULL;

	while (current != NULL) {
		nextTask = current->NextTask;
		free(current);
		current = nextTask;
	}
}


int getNumber(const char inputPrompt[], int* result) {
	char input[KTaskMaxLength];
	printf("%s >> ", inputPrompt);
	fgets(input, KTaskMaxLength, stdin);
	if (sscanf(input, "%d", result) != 1) {
		/* printf("<ADD ERROR MESSAGE HERE>\n"); */
		return -1;
	}
	return 0;
}


int getString(const char message[], char* result) {
	char input[KTaskMaxLength];
	printf("%s >> ", message);
	fgets(input, KTaskMaxLength, stdin);
	if (sscanf(input, "%s", result) != 1) {
		/* printf("<ADD ERROR MESSAGE HERE>\n"); */
		return -1;
	}
	return 0;
}