#include <stdio.h>
#include "Book/book.h"
#include "User/user.h"
#include "Utils/utils.h"
#include "Management/management.h"

int main(void){
   int choice;
    do {
        choice = show_menu(); 

        switch(choice){
            case 1: add_book(); break;
            case 2: display_book(); break;
            case 3: delete_book(); break;
            case 4: add_user(); break;
            case 5: display_users(); break;
            case 6: borrow_book(); break;
            case 7: return_book(); break; 
            case 8: edit_book(); break;
            case 9: search_book_by_title_or_author(); break;
            case 0: printf(" Tam biet!\n"); break;
            default: printf(" Lua chon khong hop le!\n");
        }
    } while(choice != 0);
   
    return 0;
}