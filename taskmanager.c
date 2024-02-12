/*
* Filename:		taskmanager.c
* Project:		Assignment 1
* By:			Alysse Palmer, Curtis Wentzlaff, Yiu Cho Yuen
* Date:			February 10th, 2024
* Description:	This project utilises a console based user interface to allow users to input
*				Task structs into a linked list, as well as provides the option to delete, search for,
*				and print specific or all structs in the linked list. 
*/

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

int createTaskID(int* TaskIDToAdd, struct Task* head);
struct Task createTask(int TaskIDToAdd);
void addTask(struct Task taskToAdd, struct Task** head);
struct Task* deleteTaskByTaskId(struct Task* head, int iD);
struct Task* findTaskByIndex(struct Task*, int);
void printTasks(struct Task head);
void freeList(struct Task* head);
void getNumber(const char[], int*);
void getString(const char[], char*);

int main(void) {
	int userInput = 0;
	int loop = 1;

	struct Task* head = NULL;
	struct Task* tempNode = NULL;
	int TaskIDToAdd = 0;

	while (loop == 1) {
		printf("\n===MENU===\n");
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");

		getNumber("\nYour choice", &userInput);

		switch (userInput) {
		case 1: /*---------------------ADD TASK---------------------*/
			while (createTaskID(&TaskIDToAdd, head) != 0) {
				printf("--TaskID is duplicated--\n\n");
			}
			addTask(createTask(TaskIDToAdd), &head);
			break;
		case 2: /*---------------------DELETE TASK BY ID---------------------*/
			if (head == NULL) {
				printf("\n--There are currently no Tasks in the list--\n");
				continue;
			}

			getNumber("\nEnter the Task ID of the task you want to delete.", &userInput);
			head = deleteTaskByTaskId(head, userInput);
			break;
		case 3: /*---------------------FIND TASK BY INDEX---------------------*/
			if (head == NULL) {
				printf("\n--There are currently no Tasks--\n");
				continue;
			}

			getNumber("\nEnter the index you want to display", &userInput);

			if ((tempNode = findTaskByIndex(head, userInput)) == NULL) {
				printf("\n--The Task at index %d cannot be found--\n", userInput);
			}
			else {
				printf("\n-------------------------------------------\n");
				printf("Task ID: %d\nTitle: %s\nDescription: %s\n", temp->TaskID, temp->Title, temp->Description);
				printf("-------------------------------------------\n");
			};

			break;
		case 4: /*---------------------PRINT ALL TASKS---------------------*/
			if (head == NULL) {
				printf("\n--There are currently no tasks defined. Please add some tasks before printing.--\n");
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

	printf("\n------------------------------------------------------\n");
	printf("Closing Program! Thank you for using the task manager.\n");
	printf("------------------------------------------------------\n");
	return 0;
}

int createTaskID(int* TaskIDToAdd, struct Task* head) {
	getNumber("\nEnter Task ID", TaskIDToAdd);

	while (head != NULL) {
		if (head->TaskID == *TaskIDToAdd) {
			return -1;
		}
		head = head->NextTask;
	}
	return 0;
}

struct Task createTask(int TaskIDToAdd) {
	struct Task task = { 0 };
	task.NextTask = NULL;
	task.TaskID = TaskIDToAdd;

	getString("Enter Title", task.Title);
	getString("Enter Description", task.Description);

	return task;
}

void addTask(struct Task taskToAdd, struct Task** head) {
	struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));

	struct Task* current = *head;

	if (newTask == NULL) {
		printf("\n--Add task is unsuccessful due to ran out of memory!--\n");
		exit(EXIT_FAILURE);
	}

	newTask->TaskID = taskToAdd.TaskID;
	strcpy(newTask->Title, taskToAdd.Title);
	strcpy(newTask->Description, taskToAdd.Description);
	newTask->NextTask = NULL;

	if (*head == NULL) {
		*head = newTask;
	}

	else {
		while (current->NextTask != NULL) {
			current = current->NextTask;
		}
		current->NextTask = newTask;
	}

	printf("\n-------------------------------------------\n");
	printf("Task [%s] has been successfully added.\n", newTask->Title);
	printf("-------------------------------------------\n");
}

struct Task* deleteTaskByTaskId(struct Task* head, int iD) {
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

	printf("\n--------------------------------------------\n");
	printf("Task ID [%d] has been successfully deleted.\n", iD);
	printf("--------------------------------------------\n");

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
	printf("\n-------------------------------------------\n");
	while (current.NextTask != NULL) {
		printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskID, current.Title, current.Description);
		printf("-------------------------------------------\n");
		current = *(current.NextTask);
	}

	printf("Task ID: %d\nTitle: %s\nDescription: %s\n", current.TaskID, current.Title, current.Description);
	printf("-------------------------------------------\n");
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