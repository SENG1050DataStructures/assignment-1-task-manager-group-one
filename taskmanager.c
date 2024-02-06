#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

#define KTaskMaxLength 101

struct Task {
	int TaskID;
	char Title[KTaskMaxLength];
	char Description[KTaskMaxLength];
	struct Task* NextTask;
};

/* Linked list function prototypes */
int CreateTaskID(int* TaskIDToAdd, struct Task* head);
struct Task CreateTask(int TaskIDToAdd);
struct Task* AddTask(struct Task taskToAdd);
struct Task* findTaskByIndex(struct Task*, int);
void printTasks(struct Task head);
void freeList(struct Task* head);

/* User input function prototypes */
void getNumber(const char[], int*);
void getString(const char[], char*);

int main(void) {

	/* Declare menu and user input variables */
	char userInput[KTaskMaxLength] = "";
	int command = 0;
	int loop = 1;

	/* Linked List variables */
	struct Task* head = NULL;
	struct Task* temp = NULL;
	struct Task* tail = NULL;
	int TaskIDToAdd = 0;

	while (loop == 1) {

		/* Display menu to user */
		printf("===MENU===\n");
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");

		getNumber("Your choice", &command) != 0);

		switch (command) {
		case 1:
			while(CreateTaskID(&TaskIDToAdd, head) != 0) {
				printf("--TaskID is duplicated--\n\n");
			}

			if (head == NULL) {
				head = AddTask(CreateTask(TaskIDToAdd));
				tail = head;
				temp = head;
			}
			else {
				tail = AddTask(CreateTask(TaskIDToAdd));
				temp->NextTask = tail;
				temp = tail;
			}
			break;
		case 2:
			//Delete Task & Free memory Aly will finish
			break;
		case 3:
			getNumber("Enter the index you want to display", &command);
			struct Task* temp2 = NULL;
			if ((temp2 = findTaskByIndex(head, command)) == NULL) {
				printf("--The Task at index %d cannot be found--", command);
				continue;
			}
			printf("-------------------------------------------\n");
			printf("Task ID: %d\nTitle: %s\nDescription: %s\n", temp2.TaskID, temp2.Title, temp2.Description);
			printf("-------------------------------------------\n\n");
			break;
		case 4:
			if (head == NULL) {
				printf("\n----------------------------------------------------------------------------\n");
				printf("There are currently no tasks defined. Please add some tasks before printing. \n");
				printf("----------------------------------------------------------------------------\n\n");
			}
			else {
				printTasks(*head);
			}
			break;
		case 5:
			freeList(head);
			loop = 0;
			break;
		default:
			printf("--Option %d does not exist--\n\n", command);
			break;
		}
	}
	return 0;
}

int CreateTaskID(int* TaskIDToAdd, struct Task* head) {
	
	getNumber("enter taskID?", TaskIDToAdd);

	while (head != NULL) {
		if (head->TaskID == *TaskIDToAdd) {
			return -1;
		}
		head = head->NextTask;
	}
	return 0;
}

struct Task CreateTask(int TaskIDToAdd) {

	struct Task task = { 0 };
	task.NextTask = NULL;
	task.TaskID = TaskIDToAdd;

	getString("enter Title?", task.Title);
	getString("enter Title?", task.Description);

	return task;
}

struct Task* AddTask(struct Task taskToAdd) {

	struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
	if (newTask == NULL) {
		printf("Add task is unsuccessful due to ran out of memory!");
		exit(EXIT_FAILURE);
	}

	newTask->TaskID = taskToAdd.TaskID;
	strcpy(newTask->Title, taskToAdd.Title);
	strcpy(newTask->Description, taskToAdd.Description);
	newTask->NextTask = NULL;

	return newTask;
}

struct Task* findTaskByIndex(struct Task* head, int index) {
	struct Task* temp = head;
	for (int i = 0; i < index; i++) {
		if (temp->NextTask == NULL) {
			return NULL;
		}
		temp = temp->NextTask;
	}
	return temp;
}

void printTasks(struct Task head) {
	struct Task current = head;
	while (current.NextTask != NULL) {
		printf("-------------------------------------------\n");
		printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskID, current.Title, current.Description);
		current = *(current.NextTask);
	}

	printf("-------------------------------------------\n");
	printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskID, current.Title, current.Description);
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

void getNumber(const char inputPrompt[], int* result) {
	char input[kMaxInputLength];
	while (1) {
		printf("%s >> ", inputPrompt);
		fgets(input, kMaxInputLength, stdin);
		if (sscanf(input, "%d", result) == 1) {
			break;
		}
		printf("\n--Input was not a valid integer--\n");
	}
}

void getString(const char inputPrompt[], char* result) {
	char input[kMaxInputLength];
	while (1) {
		printf("%s >> ", inputPrompt);
		fgets(input, kMaxInputLength, stdin);
		if (sscanf(input, "%s", result) == 1) {
			break;
		}
		printf("\n--Input was not a valid string--\n");
	}
}