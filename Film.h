#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

class Film
{
private:
	string titel, genre, trailer;
	int jahr, like;
public:

	// Constructor
	Film(string, string, int, int, string);

	//Get-ers
	string get_titel()const;

	string get_genre()const;

	string get_trailer()const;

	int get_jahr()const;

	int get_like()const;

	//Set-ers
	void set_titel(string);

	void set_genre(string);

	void set_trailer(string);

	void set_jahr(int);

	void set_like(int);

	string prep_for_html();

	// operator overload

	friend std::ostream& operator << (std::ostream&, const Film&);



};

