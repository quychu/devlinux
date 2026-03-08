#include"activity_log.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

HistoryNode_t *history_head = NULL;

void history_log_activity(const char* entry){
    HistoryNode_t *newNode = (HistoryNode_t*)malloc(sizeof(HistoryNode_t));
    if(newNode == NULL){
        return;
    }

    strcpy(newNode->log_entry,entry);
    newNode->next = history_head;
    newNode->prev = NULL;

    if(history_head != NULL){
        history_head->prev = newNode;
    }
    history_head = newNode;

}

void history_navigate(void){
    if(history_head == NULL){
        return;
    }

    HistoryNode_t *current = history_head;
    char choice;
    while(1){
        printf("\n--- Nhật ký hoạt động ---\n");
        printf("Nội dung: %s\n", current->log_entry);
        printf("[n] Tiếp theo (Cũ hơn) | [p] Quay lại (Mới hơn) | [q] Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf(" %c", &choice);

        if(choice == 'n'){
            if(current->next != NULL){
                current = current->next;
            }else{
                printf("end");
            }
        }
        else if(choice == 'p'){
            if(current->prev != NULL){
                current = current->prev;
            }else{
                 printf("end");
            }
        }
        else if(choice == 'q'){
            break;
        }
    }
}