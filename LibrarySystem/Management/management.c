#include "management.h"
#include "../Utils/utils.h"

void borrow_book(){
    int id_book, id_user;
    printf(" Nhap ID nguoi dung: ");
    scanf("%d", &id_user);
    clear_buffer();
    
    int index_user = find_user_index_by_id(id_user);
    if( index_user == -1 ){
        printf(" Ko tim thay nguoi dung!\n");
        return;
    }

    printf(" Nhap ID sach: ");
    scanf("%d", &id_book);
    clear_buffer();
    
    int index_book = find_book_index_by_id(id_book);
    if( index_book == -1 ){
        printf(" Ko tim thay sach!\n");
        return;
    }

    if( g_Book_library[index_book].status == BORROWED ){
        printf(" Sach da bi muon!\n");
        return; 
    }
    
    int empty_slot = -1;
    for(int i = 0; i < 5; i++){
        if( g_User[index_user].book_borrowed[i] == -1 ){
            empty_slot = i;
            break;
        }
    }

    if (empty_slot == -1) {
        printf(" LOI: Nguoi dung nay da muon toi da 5 cuon!\n");
        return;
    }

    g_Book_library[index_book].status = BORROWED;
    g_User[index_user].book_borrowed[empty_slot] = id_book;
    printf(" THANH CONG: %s da muon sach %s\n", g_User[index_user].name, g_Book_library[index_book].title);
}

void return_book(){
    int id_user, id_book;
    
    printf(" Nhap ID user: ");
    scanf("%d", &id_user); 
    clear_buffer();
    
    int user_index = find_user_index_by_id(id_user);
    if (user_index == -1) {
        printf(" Khong tim thay User!\n");
        return;
    }

    printf(" Nhap ID sach: ");
    scanf("%d", &id_book);
    clear_buffer();
    
    int book_index = find_book_index_by_id(id_book);
    if (book_index == -1) {
        printf(" Khong tim thay sach trong thu vien!\n"); 
    }

    int found_slot = -1;
    
    for(int i = 0 ; i < 5; i++){
        if( g_User[user_index].book_borrowed[i] == id_book){
            found_slot = i;
            break;
        }
    }

    if(found_slot == -1){
        printf(" LOI: User nay khong muon cuon sach co ID %d!\n", id_book);
        return;
    }
    
    // Trả sách
    if(book_index != -1){
        g_Book_library[book_index].status = AVAILABLE; // Đã fix: Phép gán (=) chứ không phải so sánh (==)
    }
    
    g_User[user_index].book_borrowed[found_slot] = -1;
    printf(" Tra sach thanh cong!\n");
}
