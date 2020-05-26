#pragma once
#include "FilmRepo.h"
class Admin
{private:
	FilmRepo repo;
public:
	// Constructor
	Admin(){}
	Admin(FilmRepo);

	FilmRepo get_repo();

	void add(Film);
	void save(string);
	void edit_titel(Film, string);
	void edit_genre(Film, string);
	void edit_trailer(Film, string);
	void edit_jahr(Film, int);
	void edit_like(Film, int);

	void remove(Film);

	string print_filme();
};

