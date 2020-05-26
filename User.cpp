#include "User.h"
#include <iostream>
#include <vector>
#include <exception>
#include <fstream>
#include "Exception.h"
#include <sstream> 

//constructor
User::User(FilmRepo &repo) {
    this->repo = repo;
}


//get-er repo
FilmRepo User::get_repo() {
    return this->repo;
}
//get-er watchlist
vector<Film> User::get_watch()const {
    return WatchList;
}
//setter watchlist
void User::set_watch(vector<Film> watch) {
    WatchList = watch;
}
//adauga la watchlist
void User::add_to_watch(Film film) {
		//daca e gasit returneaza ca filmul deja exista in lista
	try {
		if (_find(film)) {
			//cout << "Das Film " << film.get_titel() << " ist schon in der liste\n";
			throw _Exception("Das Film " + film.get_titel() + " ist schon in der liste\n");
		}
	}
	catch (_Exception& e) {
		cout << e.error_message();
		return;}
	WatchList.push_back(film);
}

//adauga like uri la film
void User::add_like(Film film) {
	repo.edit_like(film, film.get_like() + 1);
}
//elimina din watchlist
void User::remove_from_watch(Film film) {
	try {
		for (vector<Film>::iterator i = WatchList.begin(); i < WatchList.end(); i++)
			//daca nu e gasit nu se sterge si se afiseaza error 404 film (cout)
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				WatchList.erase(i);
				cout << "WatchList Film " << film.get_titel() << " removed." << '\n';
				return;}
		throw _Exception("WatchList Error 404: Film " + film.get_titel() + '\n');

	}
	catch (_Exception& e) {
		cout << e.error_message();
	}
}

//printeaza watchlist-ul
std::string User::print_watch() {
	std::stringstream out;
	for (int i = 0; i < WatchList.size(); i++) 
		out <<WatchList[i]<<'\n';
	string out2 = out.str();
	return out2;
}

//cauta filmul
Film User::find_film(Film film) {
	try {
		for (vector<Film>::iterator i = WatchList.begin(); i < WatchList.end(); i++)    // verifiva daca filmul exista deja in watchlist
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr())
				return *i;
		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');

	}
	catch (_Exception& e) {
		cout << e.error_message();
		return Film("", "", 0, 0, "");
	}
}

bool User::_find(Film film) {
	for (vector<Film>::iterator i = WatchList.begin(); i < WatchList.end(); i++)    // verifiva daca filmul exista deja in watchlist
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr())
			return true;
	return false;

}

void User::Read_Data(string file) {
	string title, genre, trailer, Jahr, Likes; // vor contine datele din fisier
	int jahr, likes;
	std::ifstream fin(file);
	while (!fin.eof())//cat timp exista date in fisier
	{
		//citire din fisier
		getline(fin, title, ',');
		getline(fin, genre, ',');
		getline(fin, Jahr, ',');
		getline(fin, Likes, ',');
		getline(fin, trailer, ',');
		fin.get();
		//conversie in int
		jahr = stoi(Jahr);
		likes = stoi(Likes);

		Film new_film(title, genre, jahr, likes, trailer);
		if (title != "")
			add_to_watch(new_film); // adauga in repo
	}
	fin.close();
}

void User::Write_Data(string file) {
	std::ofstream fout;
	fout.open(file, std::ofstream::out | std::ofstream::trunc);
	// scrie date in fisier
	for (int i = 0; i < WatchList.size(); i++)
		fout << WatchList[i].get_titel() << "," << WatchList[i].get_genre() << "," << WatchList[i].get_jahr() << "," << WatchList[i].get_like() << "," << WatchList[i].get_trailer() << ',' << "\n";

	fout.close();
}
void User::save_to_csv(string file) {
	std::fstream save;
	// scrie date in fisier csv
	save.open(file, std::fstream::out | std::fstream::trunc);
	for (int i = 0; i < WatchList.size(); i++)
		save << WatchList[i].get_titel() << ",\t" << WatchList[i].get_genre() << ",\t" << WatchList[i].get_jahr() << ",\t" << WatchList[i].get_like() << ",\t" << WatchList[i].get_trailer()<< "\n";

	save.close();
}
void User::save_to_html(string file) {
	string head = "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table border=\"1\">\n<tr>\n<td>Title</td>\n<td>Genre</td>\n<td>Jahr</td>\n<td>Likes</td>\n<td>Trailer Link</td>\n</tr>";
	string tail = "</table>\n</body>\n</html>";
	string body;
	std::fstream save;
	// scrie date in fisier html
	save.open(file, std::fstream::out | std::fstream::trunc);
	save << head;
	for (int i = 0; i < WatchList.size(); i++) {
		body = WatchList[i].prep_for_html();
		save << body;
	}
		
	save << tail;
	save.close();


}