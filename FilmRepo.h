#pragma once
#include "Film.h"
#include <vector>
#include "FileRepo.h"
using std::vector;
class FilmRepo
{
private:
	vector <Film> filme;
public:
	FilmRepo();
	void Read_Data(string);
	void Write_Data(string);
	
	vector<Film> get_filme() const;

	void add(Film);

	void remove(Film);

	void edit_titel(Film, string);

	void edit_genre(Film, string);

	void edit_jahr(Film, int);

	void edit_like(Film, int);

	void edit_trailer(Film, string);

	string print_filme();

	Film find_film(Film);

	vector<Film> sort_genre(string);

	int find_likes(Film);

	~FilmRepo() {}
};

