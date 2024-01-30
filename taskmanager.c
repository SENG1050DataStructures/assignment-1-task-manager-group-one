#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

#define KTitleLen 101
#define KDescriptionLen 101

struct Task {
    int TaskId;
    char Title[KTitleLen];
    char Description[KDescriptionLen];
    struct Task* NextTask;
};

int main(void)
{
	char userInput[KTitleLen] = "";
	int commend = 0;
	struct Task* head = NULL;

	while (1)
	{
		printf("Press 1 to Add Task\n");
		printf("Press 2 to Delete Task\n");
		printf("Press 3 to Find Task\n");
		printf("Press 4 to Print Tasks\n");
		printf("Press 5 to Exit\n");

		fgets(userInput, sizeof userInput, stdin);
		
		if ((sscanf(userInput, "%d", &commend) != 1) || (commend > 5) || (commend < 1))
		{
			printf("please enter vaild input\n\n");
			continue;
		}

		else
		{
			switch (commend) 
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
				//Delete Print Tasks
				break;
			case 5:
				//Free memory
				return 0;
			}
		}
	}
}