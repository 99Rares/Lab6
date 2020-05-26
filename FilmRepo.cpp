#include "FilmRepo.h"
#include "Exception.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream> 

using namespace std;
using std::cout;

FilmRepo::FilmRepo(){
}
void FilmRepo::Read_Data(string file) {
	string title, genre, trailer, Jahr, Likes; // vor contine datele din fisier
	int jahr, likes; 
	ifstream fin(file);
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
		if(title!="")
		add(new_film); // adauga in repo
	}
	fin.close();
}

void FilmRepo::Write_Data(string file) {
	fstream fout;
	fout.open(file, ofstream::out | ofstream::trunc);
	// scrie date in fisier
	for (int i = 0; i < filme.size(); i++)
		fout << filme[i].get_titel() << "," << filme[i].get_genre() << "," << filme[i].get_jahr() << "," << filme[i].get_like() << "," << filme[i].get_trailer() <<','<< "\n";

	fout.close();
}

vector<Film> FilmRepo::get_filme() const {
	return filme;
}
//adauga film 
void FilmRepo::add(Film film) {

	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++) {
		//daca il gaseste atunci nu il mai adauga
		try {
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				//cout << "Das Film " << film.get_titel() << " ist schon in der liste\n";
				throw _Exception("Das Film " + film.get_titel() + " ist schon in der liste\n");
			}

		}

		catch (_Exception& e) {
			cout << e.error_message();
			return;
		}
	}
		filme.push_back(film);
}
//editarea numelui filmului
void FilmRepo::edit_titel(Film film, string titel) {
try {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			i->set_titel(titel);
			return;
		}
	throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
}
catch (_Exception& e) {
	cout << e.error_message();
}
	//cout << "Repo Error 404: Film " << film.get_titel() << '\n';
	
}
//editeaza genul filmului
void FilmRepo::edit_genre(Film film, string genre) {
	try {
		for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
			//il editeaza daca il gaseste dupa titlu si an
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				i->set_genre(genre);
				return;
			}
		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
	}
	catch (_Exception& e) {
		cout << e.error_message();
	}
	//cout << "Repo Error 404: Film " << film.get_titel() << '\n';
}
//editeaza trailerul
void FilmRepo::edit_trailer(Film film, string trailer) {
	try {
		for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
			//il editeaza daca il gaseste dupa titlu si an
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				i->set_trailer(trailer);
				return;
			}
		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
	}
	catch (_Exception& e) {
		cout << e.error_message();
		return;
	}
	//cout << "Repo Error 404: Film " << film.get_titel() << '\n';
}
//schimba anul filmului
void FilmRepo::edit_jahr(Film film, int jahr) {
	try {
		for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
			//il editeaza daca il gaseste dupa titlu si an
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				i->set_jahr(jahr);
				return;
			}
		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
	}
	//cout << "Repo Error 404: Film " << film.get_titel() << '\n';
	catch (_Exception& e) {
		cout << e.error_message();
		return;
	}
}

//schimba nr de likeuri
void FilmRepo::edit_like(Film film, int like) {
	try {
		for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
			//il editeaza daca il gaseste
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				i->set_like(like);
				return;
			}
		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
	}
	//cout << "Repo Error 404: Film " << film.get_titel()<<'\n';
	catch (_Exception& e) {
		cout << e.error_message();
		return;
	}
}

//sterge
void FilmRepo::remove(Film film) {
	try {
		for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
			//il sterge daca il gaseste dupa titlu si an
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
				filme.erase(i);
				cout << "Film " << film.get_titel() << " removed." << '\n';
				return;
			}
		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
	}
	catch (_Exception& e) {
		cout << e.error_message();
		return;
	}
	//cout << "Repo Error 404: Film " << film.get_titel()<<'\n';
}
// afiseaza filmele
string FilmRepo::print_filme() {
	std::stringstream out;
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		out << *i<<'\n';
	string out2 = out.str();
	return out2;
}

//cauta filmul
Film FilmRepo::find_film(Film film) {
	try {
		for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)   // cauta filmul in lista si returneaza daca e gasit
			if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr())
				return *i;

		throw _Exception("Repo Error 404: Film " + film.get_titel() + '\n');
	}
	catch(_Exception& e) {
		cout << e.error_message();
		
	}
}

int FilmRepo::find_likes(Film film) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)   //cauta filmul in lista si returneaza nr de like uri
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr())
			return film.get_like();
	return 0;
}

vector<Film> FilmRepo::sort_genre(string g) {
	std::vector <Film> aux;
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++) {   // cauta filmul specific unui gen in lista si il adauga intr o lista noua
		if (i->get_genre() == g)
			aux.push_back(*i);
	}
	return aux;
}
