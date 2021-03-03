#include "telephone_Book.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
/*  Show the main menu  */
void telephone_Book::draw_Menu() {
    cout << "############################" << endl;
    cout << "#####     Main Menu   ######" << endl;
    cout << "###   1. Add Contact     ###" << endl;
    cout << "###   2. Delete Contact  ###" << endl;
    cout << "###   3. Show Contacts   ###" << endl;
    cout << "###   4. Search Contact  ###" << endl;
    cout << "###   5. Edit Contact    ###" << endl;
    cout << "###   0. Exit Program    ###" << endl;
    cout << "############################" << endl;
    cout << "_User_#  ";
}
/*  Show contacts by format */
void telephone_Book::display_Contact(int i) {
    cout << "Name: " << contacts[i].c_Name << "  ";
    if (contacts[i].c_Gender == 1) {
        cout << "Sex: Man" << "  ";
    } else
        cout << "Gender: Woman" << "  ";
    cout << "Age: " << contacts[i].c_Age << "  ";
    cout << "Phone number: " << contacts[i].c_Number << "  ";
    cout << "Address: " << contacts[i].c_Addr << endl;
}
/*  Add new contact */
void telephone_Book::add_Contact() {
    if (this->current_Size == max_Size) {
        cerr << "TelephoneBook is Full !" << endl;
    } else{
        string a_Name;
        while (true) {
            bool flag = false;
            cout << "New Contact's Name :" << endl;
            cin >> a_Name;
            for (int i = 0; i < this->current_Size; ++i) {
                if (contacts[i].c_Name == a_Name) {
                    cerr << "Contact_" << a_Name << " Exist, Try Another." << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            else {
                contacts[this->current_Size].c_Name = a_Name;
                break;
            }
        }

        cout << "New Contact's Gender :\n1 - Man ; 2 - Woman" << endl;
        while (true) {
            int sex = 0;
            cin >> sex;
            if (sex == 1 || sex == 2) {
                contacts[this->current_Size].c_Gender = sex;
                break;
            } else
                cerr << "Wrong! Enter Again." << endl;
        }
        cout << "New Contact's Age :" << endl;
        cin >> contacts[this->current_Size].c_Age;
        cout << "New Contact's Number :" << endl;
        cin >> contacts[this->current_Size].c_Number;
        cout << "New Contact's Address :" << endl;
        cin >> contacts[this->current_Size].c_Addr;
        this->current_Size++ ;
        cout << "Added Successfully!" << endl;
    }
}
/*  Delete existing contact  */
void telephone_Book::delete_Contact() {
    if (this->current_Size == 0) {
        cerr << "There is NO Contact Yet !" << endl;
    } else{
        cout << "You Want to Delete : ";
        string d_Name;
        bool flag = false;
        cin >> d_Name;
        for (int i = 0; i < this->current_Size; ++i) {
            if (contacts[i].c_Name == d_Name) {
                for (int j = i; j < this->current_Size - 1; ++j) {
                    contacts[j].c_Name = contacts[j + 1].c_Name;
                    contacts[j].c_Gender = contacts[j + 1].c_Gender;
                    contacts[j].c_Age = contacts[j + 1].c_Age;
                    contacts[j].c_Number = contacts[j + 1].c_Number;
                    contacts[j].c_Addr = contacts[j + 1].c_Addr;
                }
                flag = true;
                this->current_Size --;
            }
        }
        if (!flag) {
            cerr << "Contact_" << d_Name << "  Not Found!" << endl;
        } else
            cout << "Deleted Successfully!" << endl;
    }
}
/*  Show all existing contacts   */
void telephone_Book::show_Contacts() {
    if (this->current_Size == 0) {
        cerr << "There is NO Contact Yet !" << endl;
    } else {
        for (int i = 0; i < this->current_Size; ++i) {
            display_Contact(i);
        }
    }
}
/*  Search for specified contact by name   */
void telephone_Book::search_Contact() {
    if (this->current_Size == 0) {
        cerr << "There is NO Contact Yet !" << endl;
    } else {
        cout << "You Want to Find : ";
        string s_Name;
        bool flag = false;
        cin >> s_Name;
        for (int i = 0; i < this->current_Size; ++i) {
            if (contacts[i].c_Name == s_Name) {
                display_Contact(i);
                flag = true;
            }
        }
        if (!flag) {
            cerr << "Contact_" << s_Name << "  Not Found!" << endl;
        }
    }
}
/*  Edit specified contact's information   */
void telephone_Book::edit_Contact() {
    if (this->current_Size == 0) {
        cerr << "There is NO Contact Yet !" << endl;
    } else {
        cout << "You Want to Edit : ";
        string e_Name;
        cin >> e_Name;
        for (int i = 0; i < this->current_Size; ++i) {
            if (contacts[i].c_Name == e_Name) {
                int select = 9;
                while (true) {
                    cout << "1.Name 2.Gender 3.Age 4.Phone Number 5.Address 0.Exit" << "\nChoose to Begin: ";
                    cin >> select;
                    switch (select) {
                        case 0:
                        default:
                            return;
                        case 1:
                            cout << "Contact's New Name :" << endl;
                            cin >> contacts[i].c_Name;
                            break;
                        case 2:
                            cout << "Contact's New Gender :\n1 - Man ; 2 - Woman" << endl;
                            while (true) {
                                int sex = 0;
                                cin >> sex;
                                if (sex == 1 || sex == 2) {
                                    contacts[i].c_Gender = sex;
                                    break;
                                } else
                                    cerr << "Wrong! Enter Again." << endl;
                            }
                            break;
                        case 3:
                            cout << "Contact's New Age :" << endl;
                            cin >> contacts[i].c_Age;
                            break;
                        case 4:
                            cout << "Contact's New Number :" << endl;
                            cin >> contacts[i].c_Number;
                            break;
                        case 5:
                            cout << "Contact's New Address :" << endl;
                            cin >> contacts[i].c_Addr;
                            break;
                    }
                    cout << "Edited Successfully!" << endl;
                }
            }
        }
        cerr << "Contact_" << e_Name << "  Not Found!" << endl;
    }
}