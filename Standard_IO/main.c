#include "logger.h"

int main() {
    printf("--- Khoi tao Logger (Level: INFO) ---\n");
    loggerInit(LOG_INFO, "system.log");

    log_message(LOG_INFO, "Ung dung da bat dau thanh cong.");
    log_message(LOG_WARNING, "Canh bao: Bo nho sap day (%d%%).", 85);
    log_message(LOG_ERROR, "Loi nghiem trong: %s", "Khong the ket noi database.");
    log_message(LOG_DEBUG, "Day la thong tin debug chi tiet."); 

    printf("Thay doi level sang DEBUG");
    loggerSetLevel(LOG_DEBUG);
    log_message(LOG_DEBUG, "Bay gio thong tin DEBUG da hien thi!");
    log_message(LOG_CRITICAL, "HE THONG DANG GAP NGUY HIEM!");
    loggerClose();

    return 0;
}