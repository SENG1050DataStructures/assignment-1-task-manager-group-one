# Assignment 1 : Console Based Task Manager

## What is it about?

> Build a console-based task management system using linked lists and structs with **dynamic memory allocation** in C.

## Requirements:

1. Define a structure named Task with the following members:

   - `TaskId` (integer): Represents the unique identifier of the task.
   - `Title` (string): Represents the title or name of the task.
   - `Description` (string): Represents a brief description of the task.
   - `NextTask` (pointer to Task): Represents the link to the next task in the list.

2. Linked List Management:

   Implement functions to manage the linked list of tasks:

   - `AddTask`: Adds a new task to the linked list.
   - `FindTaskByIndex`: Finds a task by its Index.
   - `DeleteTaskByTaskId`: Deletes a task from the linked list based on the TaskId.
   - `PrintTasks`: Prints the details of all tasks in the linked list.

3. Dynamic Memory Allocation:

   - Utilize dyanmic memory allocation using `malloc` to create new task nodes as needed.
   - `free` memory **appropriately** when deleting tasks or at the end of the program.

4. User Interaction:

   Implement a console based user interface for the application.

   - Display a menu with options such as
     - `Press 1 to Add Task`,
     - `Press 2 to Delete Task`,
     - `Press 3 to Find Task`,
     - `Press 4 to Print Tasks`
     - `Press 5 to Exit`

5. Validations:

   Add Validations as necessary and applicable.

6. Write Up:

   Do write up for your project. Each team member should do a write up about a functionality that they did not implement but one of the other team member implemented. Pick one such item and do a short write up.

---

PS:

> Your Submitted code should compile and build successfully without any errors.

> If you have 4 people in your group, split one menu item each and implement it.

> Submit your github classroom repository link in the assignment submission box.

> Do not add unnecessary code comments.

> Pick a coding stanadard and stick to it.
