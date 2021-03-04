#include "telephone_Book.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[]) {
    int func_Select = 9;
    telephone_Book telephoneBook;
    while(true) {
        system("clear");
        telephone_Book::draw_Menu();
        //User choose the function
        cin >> func_Select;
        if (func_Select >= 0 && func_Select <= 5) {
            switch (func_Select) {
                case 1:
                    telephoneBook.add_Contact();
                    break;
                case 2:
                    telephoneBook.delete_Contact();
                    break;
                case 3:
                    telephoneBook.show_Contacts();
                    break;
                case 4:
                    telephoneBook.search_Contact();
                    break;
                case 5:
                    telephoneBook.edit_Contact();
                    break;
                case 0:
                default:
                    cout << "See You Next Time !" << endl;
                    return 0;
            }
        } else
            cerr << "WRONG! Enter Again." << endl;
        cout << "Press Enter to Continue..." << endl;
        PAUSE
    }

}