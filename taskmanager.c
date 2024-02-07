#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

#define kMaxStringLength 101

struct Task {
	int TaskID;
	char Title[kMaxStringLength];
	char Description[kMaxStringLength];
	struct Task* NextTask;
};

/* Linked list function prototypes */
int CreateTaskID(int* TaskIDToAdd, struct Task* head);
struct Task CreateTask(int TaskIDToAdd);
struct Task* AddTask(struct Task taskToAdd);
struct Task* DeleteTaskByTaskId(struct Task* head, int iD);
struct Task* findTaskByIndex(struct Task*, int);
void printTasks(struct Task head);
void freeList(struct Task* head);

/* User input function prototypes */
void getNumber(const char[], int*);
void getString(const char[], char*);

int main(void) {

	int userInput = 0;
	int loop = 1;

	/* Linked List variables */
	struct Task* head = NULL;
	struct Task* temp = NULL;
	struct Task* temp2 = NULL;
	struct Task* tail = NULL;
	int TaskIDToAdd = 0;

	while (loop == 1) {

		/* Display menu to user */
		printf("\n===MENU===\n");
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");

		getNumber("\nYour choice", &userInput);

		switch (userInput) {
		case 1: /*---------------------ADD TASK---------------------*/
			while (CreateTaskID(&TaskIDToAdd, head) != 0) {
				printf("\n--TaskID is duplicated--\n");
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
		case 2: /*---------------------DELETE TASK BY ID---------------------*/
			if (head == NULL) {
				printf("\n--There are currently no Tasks in the list--\n");
				continue;
			}

			getNumber("\nEnter the Task ID of the task you want to delete.", &userInput);
			head = DeleteTaskByTaskId(head, userInput);

			break;
		case 3: /*---------------------FIND TASK BY INDEX---------------------*/
			if (head == NULL) {
				printf("\n--There are currently no Tasks--\n");
				continue;
			}

			getNumber("\nEnter the index you want to display", &userInput);

			if ((temp2 = findTaskByIndex(head, userInput)) == NULL) {
				printf("\n--The Task at index %d cannot be found--\n", userInput);
			}
			else {
				printf("-------------------------------------------\n");
				printf("Task ID: %d\nTitle: %s\nDescription: %s\n", temp2->TaskID, temp2->Title, temp2->Description);
				printf("-------------------------------------------\n\n");
			};

			break;
		case 4: /*---------------------PRINT ALL TASKS---------------------*/
			if (head == NULL) {
				printf("\n----------------------------------------------------------------------------\n");
				printf("There are currently no tasks defined. Please add some tasks before printing. \n");
				printf("----------------------------------------------------------------------------\n\n");
			}
			else {
				printTasks(*head);
			}
			break;
		case 5: /*---------------------EXIT PROGRAM---------------------*/
			freeList(head);
			loop = 0;
			break;
		default: /*---------------------INVALID INPUT---------------------*/
			printf("\n--Option %d does not exist--\n", userInput);
			break;
		}
	}
	return 0;
}

int CreateTaskID(int* TaskIDToAdd, struct Task* head) {

	getNumber("\nEnter taskID", TaskIDToAdd);

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

	getString("Enter Title", task.Title);
	getString("Enter Description", task.Description);

	return task;
}

struct Task* AddTask(struct Task taskToAdd) {

	struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
	if (newTask == NULL) {
		printf("\n--Add task is unsuccessful due to ran out of memory!--\n");
		exit(EXIT_FAILURE);
	}

	newTask->TaskID = taskToAdd.TaskID;
	strcpy(newTask->Title, taskToAdd.Title);
	strcpy(newTask->Description, taskToAdd.Description);
	newTask->NextTask = NULL;

	return newTask;
}

struct Task* DeleteTaskByTaskId(struct Task* head, int iD) {
	struct Task* current = head;
	struct Task* temp = NULL;

	if (current->TaskID == iD) {
		temp = head;
		head = current->NextTask;
	}
	else {
		while (current->NextTask != NULL) {
			if (current->NextTask->TaskID == iD) {
				temp = current->NextTask;
				current->NextTask = temp->NextTask;
				break;
			}
			current = current->NextTask;
		}
	}

	if (temp == NULL) {
		printf("\n--No Task found with ID: %d--\n", iD);
	}

	free(temp);
	return head;
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
	char input[kMaxStringLength];
	while (1) {
		printf("%s >> ", inputPrompt);
		fgets(input, kMaxStringLength, stdin);
		if (sscanf(input, "%d", result) == 1) {
			break;
		}
		printf("\n--Input was not a valid integer--\n");
	}
}

void getString(const char inputPrompt[], char* result) {
	char input[kMaxStringLength];
	while (1) {
		printf("%s >> ", inputPrompt);
		fgets(input, kMaxStringLength, stdin);
		if (sscanf(input, "%s", result) == 1) {
			break;
		}
		printf("\n--Input was not a valid string--\n");
	}
}
