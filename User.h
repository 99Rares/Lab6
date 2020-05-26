#pragma once
#include "FilmRepo.h"
class User:public FileRepo
{
private:
	FilmRepo repo;
	vector<Film>WatchList;
public:
	User(){}
	User(FilmRepo&);

	void Read_Data(string);
	void Write_Data(string);

	void save_to_csv(string);

	void save_to_html(string);

	FilmRepo get_repo();
	vector<Film>get_watch()const;
	void set_watch(vector<Film>);

	void add_to_watch(Film);

	void remove_from_watch(Film);

	void add_like(Film);

	std::string print_watch();

	Film find_film(Film);

	bool _find(Film);
};

