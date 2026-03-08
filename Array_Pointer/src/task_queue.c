#include"task_queue.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

TaskNode_t *taskQueueHead = NULL;
TaskNode_t *taskQueueTail = NULL;

void queue_add_task(const char* description){
    TaskNode_t *newNode = (TaskNode_t *)malloc(sizeof(TaskNode_t));
    if(newNode == NULL){
        return;
    }

    strncpy(newNode->task_description,description,sizeof(newNode->task_description)-1);
    newNode->task_description[sizeof(newNode->task_description)-1] = '\0';
    newNode->next = NULL;

    if(taskQueueHead == NULL){
        taskQueueHead = newNode;
        taskQueueTail = newNode;
    }else{
        taskQueueTail->next = newNode;
        taskQueueTail = newNode ;
    }

}

TaskNode_t* queue_get_next_task(void){
    if(taskQueueHead == NULL){
        return NULL;
    }
    TaskNode_t *taskHeadTemp = taskQueueHead;
    taskQueueHead = taskHeadTemp->next;

    if(taskQueueHead == NULL){
        taskQueueTail = NULL;
    }

    return taskHeadTemp;
}

void print_task_queue(void){
    TaskNode_t *current = taskQueueHead;
    while(current != NULL){
        printf(" - %s\n",current->task_description);
        current = current->next;
    }
}
