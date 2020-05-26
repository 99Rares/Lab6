#pragma once
#include "User.h"
#include "Admin.h"
#include "Valid.h"

class UI
{
private:

    Admin admin;
    User user;
public:
    UI(Admin, User);

    void main_menu();

    void admin_menu();

    void user_menu();

    void edit_menu(Film);

    void add_to_watch();

    void print_menu(int);

    void rate();
};

