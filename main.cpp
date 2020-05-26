#include "FilmRepo.h"
#include "UI.h"
#include "Test.h"
#include <iostream>
#include <time.h>

using std::cout;

void waitFor(unsigned int sec) {
	unsigned int retTime = time(0) + sec;

	cout << "\n\n\tAsteptam " << sec << " secunde...\n\n ";

	while (time(0) < retTime);
}

int main() {

	Test test;
	test.test();
	waitFor(5);
	system("cls");
	cout << "Teste reusite! \n\n";
	FilmRepo list;
	list.Read_Data("Input.txt");
	User user = User(list);
	Admin admin = Admin(list);
	user.Read_Data("User_In.txt");
	UI ui(admin, user);
	ui.main_menu();
}