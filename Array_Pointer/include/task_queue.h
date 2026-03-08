
typedef struct TaskNode { 
    char task_description[50]; 
    struct TaskNode* next; 
} TaskNode_t; 

void queue_add_task(const char* description); 
TaskNode_t* queue_get_next_task(void); 
void print_task_queue(void); 