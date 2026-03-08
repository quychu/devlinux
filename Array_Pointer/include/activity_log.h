
typedef struct HistoryNode {
    char log_entry[50];
    struct HistoryNode* next;
    struct HistoryNode* prev; 
} HistoryNode_t;

void history_log_activity(const char* entry);
void history_navigate(void);
