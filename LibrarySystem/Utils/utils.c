#include "utils.h"

void clear_buffer(){
    int c;
    while( (c = getchar()) != '\n' && c != EOF );
}

int show_menu(){
    int choice;
    printf("\n================================\n");
    printf("   HE THONG QUAN LY THU VIEN    \n");
    printf("================================\n");
    printf(" 1. Them sach moi\n");
    printf(" 2. Hien thi danh sach sach\n");
    printf(" 3. Xoa sach\n");
    printf(" 4. Them nguoi dung\n");
    printf(" 5. Hien thi danh sach User\n");
    printf(" 6. MUON SACH\n");
    printf(" 7. TRA SACH\n"); 
    printf(" 8. SUA SACH\n");
    printf(" 9. Tim sach or ten tac gia\n");
    printf(" 0. Thoat\n");
    printf(" Lua chon cua ban: ");
    scanf("%d", &choice);
    clear_buffer();
    return choice;
}