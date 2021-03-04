/*  telephone_Book.h   */
#include <iostream>
#include <string>
#include <cstdio>
//define PAUSE to realize "Press Enter to Continue..."
#define PAUSE getchar();getchar();
#define max_Size 50

using std::string;

/*  Each contact has name,gender,age,phone-number,address  */
struct Contact {
    string c_Name;
    int c_Gender;
    int c_Age;
    string c_Number;
    string c_Addr;
};

class telephone_Book {
    private:
        int current_Size = 0; //record current size
        Contact contacts[max_Size];
        void display_Contact(int);
    public:
        static void draw_Menu();
        void add_Contact();
        void delete_Contact();
        void show_Contacts();
        void search_Contact();
        void edit_Contact();
};