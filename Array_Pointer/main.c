#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_queue.h"
#include "activity_log.h"

int main() {
    int choice;
    char taskDesc[100];
    while (1) {
        printf("\n===== HỆ THỐNG QUẢN LÝ TÁC VỤ =====\n");
        printf("1. Thêm tác vụ mới\n");
        printf("2. Thực hiện tác vụ tiếp theo\n");
        printf("3. Xem hàng đợi tác vụ\n");
        printf("4. Xem lịch sử hoạt động\n");
        printf("5. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Nhập mô tả tác vụ: ");
                fgets(taskDesc, sizeof(taskDesc), stdin);
                taskDesc[strcspn(taskDesc, "\n")] = 0; 
                queue_add_task(taskDesc);
                break;

            case 2:
                TaskNode_t* task = queue_get_next_task();
                if (task != NULL) {
                    printf("Đang thực hiện: %s\n", task->task_description);

                    char logMsg[150];
                    sprintf(logMsg, "Hoàn thành: %s", task->task_description);
                    history_log_activity(logMsg);
                    
                    free(task); 
                } else {
                    printf("Không còn tác vụ nào trong hàng đợi!\n");
                }
                break;

            case 3:
                print_task_queue();
                break;

            case 4:
                history_navigate();
                break;

            case 5:
                return 0;

            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    }
    return 0;
}