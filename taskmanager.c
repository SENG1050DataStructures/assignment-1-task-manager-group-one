#include <stdio.h>

#include KTitleLen 101
#include KDescriptionLen 201

struct Task {
    int TaskId;
    char Title[KTitleLen];
    char Description[KDescriptionLen];
    struct Task* NextTask;
};

int main(void)
{
    
}