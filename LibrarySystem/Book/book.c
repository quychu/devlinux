#include "book.h"
#include "../Utils/utils.h"

Book g_Book_library[MAX];
int g_Book_count = 0;

void add_book(){
    Book new_book;
    printf(" Them sach moi \n");
    printf(" Nhap id sach: ");
    scanf("%d", &new_book.id);
    clear_buffer();
    
    printf(" Nhap ten sach: ");
    scanf(" %[^\n]", new_book.title );
    clear_buffer();
    
    printf(" Nhap ten tac gia: ");
    scanf(" %[^\n]", new_book.author );
    clear_buffer();
    
    new_book.status = AVAILABLE;
    g_Book_library[g_Book_count] = new_book;
    g_Book_count++;
}

void display_book(){
    printf("\n--- DANH SACH SACH ---\n");
    for(int i = 0 ; i < g_Book_count; i++){
        printf(" Vi tri [%-5d] | ID: %-5d | Sach: %-30s | Tac gia: %-20s  | Trang thai: %-15s\n", 
            i, g_Book_library[i].id, g_Book_library[i].title, g_Book_library[i].author ,
             (g_Book_library[i].status == AVAILABLE) ? " San sang ": "Da Het" );
    }
}

int find_book_index_by_id(int id){
    for( int i = 0 ; i < g_Book_count; i++){
        if( g_Book_library[i].id == id){
            return i;
        }
    }
    return -1;
}

void delete_book(){
    int id;
    printf(" Nhap id sach muon xoa: ");
    scanf("%d", &id);
    clear_buffer();

    int index = find_book_index_by_id(id);
    if (index == -1) {
        printf(" Khong tim thay ID sach!\n");
        return;
    }

    for( int i = index; i < g_Book_count - 1; i++){
        g_Book_library[i] = g_Book_library[i+1];
    }
    g_Book_count--;
    printf(" Xoa sach thanh cong!\n");
}

void edit_book(){
    int id_book;
    printf(" Nhap id sach muon sua: ");
    scanf("%d", &id_book);
    clear_buffer();
    
    int book_index = find_book_index_by_id(id_book);
    if(book_index == -1) {
        printf(" Khong tim thay sach!\n");
        return;
    }

    int choice;
    do{
        printf(" 1. Sua ten sach\n");
        printf(" 2. Sua ten tac gia\n");
        printf(" 0. Thoat\n");
        scanf("%d", &choice);
        clear_buffer();

        switch(choice){
            case 1:{
                printf(" Nhap ten sach moi: \n");
                scanf("%[^\n]", g_Book_library[book_index].title );
                clear_buffer(); 
                break;
            }
            case 2:{
                printf(" Nhap ten tac gia moi: \n");
                scanf("%[^\n]", g_Book_library[book_index].author);
                clear_buffer();
                break;
            }
            case 0: break;
            default: printf(" Lua chon khong hop le!\n");
        }
    } while( choice != 0 );
    printf(" Cap nhat thanh cong!\n");
}

void search_book_by_title_or_author(){
    int found_count = 0;
    char keyword[MAX];

    printf(" Nhap ten sach or tac gia: ");
    scanf("%[^\n]", keyword);
    clear_buffer();

    printf("\n Ket qua tim kiem cho '%s':\n", keyword);
    printf(" %-5s | %-5s | %-30s | %-20s | %-15s\n", "Pos", "ID", "Ten Sach", "Tac Gia", "Trang Thai");
    printf(" --------------------------------------------------------------------------------------\n");

    for(int i = 0; i < g_Book_count; i ++){
        int is_author = ( strstr( g_Book_library[i].author, keyword) != NULL);
        int is_title = ( strstr( g_Book_library[i].title, keyword) != NULL);
        if( is_author || is_title){
             printf(" %-5d | %-5d | %-30s | %-20s | %-15d\n",
                     i, g_Book_library[i].id, g_Book_library[i].title, g_Book_library[i].author, g_Book_library[i].status);
             found_count++;
        }
    }
    if (found_count == 0) {
        printf(" -> Khong tim thay sach nao phu hop!\n");
    }
}