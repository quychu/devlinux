#include "user.h"
#include "../Utils/utils.h"

User g_User[MAX];
int g_User_count = 0;

void add_user(){
    if (g_User_count >= MAX) {
        printf(" Danh sach nguoi dung da day!\n");
        return;
    }

    User new_user;
    printf("\n--- THEM NGUOI DUNG ---\n");
    printf(" Nhap ID user: ");
    scanf("%d", &new_user.id);
    clear_buffer();

    printf(" Nhap ten user: ");
    scanf("%[^\n]", new_user.name);
    clear_buffer();

    for(int i = 0; i < 5; i++){
        new_user.book_borrowed[i] = -1; 
    }

    g_User[g_User_count] = new_user;
    g_User_count++;
    printf(" Them user thanh cong!\n");
}

void display_users(){
    printf("\n--- DANH SACH USER ---\n");
    printf(" %-10s | %-20s | %-15s\n", "ID", "Ten", "Sach dang muon");
    
    for(int i = 0 ; i < g_User_count; i++){
        int count = 0;
        for(int j = 0; j < 5; j++){
            if( g_User[i].book_borrowed[j] != -1){
                count++;
            }
        }
        printf(" %-10d | %-20s | %-15d cuon\n", 
                    g_User[i].id, g_User[i].name, count);
    }
}

int find_user_index_by_id(int id){
    for(int i = 0; i < g_User_count; i++){
        if(g_User[i].id == id){
            return i;
        }
    }
    return -1;
}

void edit_user(){
    int id_user;
    printf(" Nhap id user muon sua: ");
    scanf("%d", &id_user);
    clear_buffer();

    int user_index = find_user_index_by_id(id_user);
    if(user_index == -1){
        printf(" Khong tim thay user!\n");
        return;
    }
    printf(" Nhap ten moi: ");
    scanf("%[^\n]", g_User[user_index].name );
    clear_buffer();
    printf(" Cap nhat thanh cong!\n");
}

void delete_user(){
    int id_user;
    printf(" Nhap id user muon xoa: ");
    scanf("%d", &id_user);
    clear_buffer();
    int user_index = find_user_index_by_id(id_user);
    
    if(user_index == -1){
        printf(" Khong tim thay user!\n");
        return;
    }

    for( int i = user_index; i < g_User_count -1; i++){
        g_User[i] = g_User[i + 1];
    }
    g_User_count--;
    printf(" Xoa user thanh cong!\n");
}