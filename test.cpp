#include "Test.h"
#include "UI.h"
#include <cassert>
#include <sstream> 

Film a("The Dark Knight", "Action", 2008, 98, "https://youtu.be/EXeTwQWrcwY");
Film b("Spidermann", "Action", 2019, 56, "https://youtu.be/Nt9L1jCKGnE");
Film c("Star Wars", "Sci-Fi", 2015, 81, "https://youtu.be/sGbxmsDFVnE");
Film d("The Dictator", "Comedy", 2012, 82, "https://youtu.be/cYplvwBvGA4");
Film e("The Lord of the Rings", "Fantasy", 2003, 9, "https://youtu.be/r5X-hFf6Bwo");
Film f("Thor", "Action", 2017, 28, "https://youtu.be/ue80QwXMRHg");
Film g("Joker", "Drama", 2019, 9, "https://youtu.be/rgXplohCw5o");
Film h("Avengers: Endgame", "Action", 2019, 55, "https://youtu.be/TcMBFSGVi1c");
Film i("Justice League", "", 2017, 42, "https://youtu.be/3cxixDgHUYw");
Film j("Mission: Impossible", "Action", 2018, 69, "https://youtu.be/wb49-oV0F78");

void Test::test() {

	FilmRepo r;
	cout << "Test Add\n";
	r.add(a);
	r.add(b);
	r.add(c);
	r.add(a);
	assert(r.get_filme().size() == 3);

	cout << "Test Remove\n";
	r.remove(a);
	r.remove(b);
	r.remove(c);
	r.remove(a);
	assert(r.get_filme().size() == 0);

	cout << "Test Edit\n";
	r.add(a);
	
	assert(r.find_likes(a) == 98);
	Film az = Film("gg", "gg", 0, 0, "gg");
	assert(r.find_likes(az) == 0);
	r.edit_titel(a, "aaa");
	a.set_titel("aaa");
	r.edit_genre(a, "aaa");
	a.set_genre("aaa");
	r.edit_jahr(a, 1);
	a.set_jahr(1);
	r.edit_like(a, 1);
	a.set_like(1);
	r.edit_trailer(a, "aaa");
	a.set_trailer("aaa");

	assert(r.find_film(a).get_titel() == a.get_titel());
	r.remove(a);
	assert(r.get_filme().size() == 0);

	Valid val;
	assert(val.read_nr(INT_MIN) == INT_MIN);
	assert(val.read_string("test_123") == "test_123");
	//assert(val.read_range(INT_MIN, 5) == 0);
	r.add(c);

	User vali = User(r);
	vali.add_to_watch(c);
	vali.add_to_watch(c);
	assert(vali.get_watch().size() == 1);
	vali.add_like(c);
	std::stringstream out;
	out << c<<'\n';
	assert(vali.print_watch() == out.str());
	assert(r.print_filme() == out.str());
	vector<Film>a = vali.get_watch();
	assert(vali.find_film(c).get_titel() == c.get_titel());
	assert(a[0].get_titel() == c.get_titel());
	assert(vali._find(c) == true);
	vali.remove_from_watch(c);
	vali.remove_from_watch(c);
	assert(vali.get_watch().size() == 0);
	r = vali.get_repo();

	Admin Vali = Admin(r);
	Vali.add(b);
	r = Vali.get_repo();
	assert(r.find_film(c).get_like() == 82);
	assert(r.find_likes(b) == 56);
	assert(r.get_filme().size() == 2);
	Vali.remove(b);
	Vali.edit_genre(c, "aaa");
	Vali.edit_like(c, 5);
	Vali.edit_trailer(c, "aaa");
	Vali.edit_jahr(c, 2);
	Vali.edit_titel(c, "aaa");
	Vali.save("test.txt");
	Vali.edit_genre(az, "aaa");
	Vali.edit_like(az, 5);
	Vali.edit_trailer(az, "aaa");
	Vali.edit_jahr(az, 2);
	Vali.edit_titel(az, "aaa");
	Vali.save("test.txt");
	vali.Write_Data("test2.txt");
	string s = Vali.print_filme();
	r = Vali.get_repo();
	a=r.get_filme();
	assert(a[0].get_trailer() == "aaa");
	assert(a[0].get_like() == 5);
	assert(a[0].get_genre() == "aaa");
	assert(r.get_filme().size() == 1);
	r.sort_genre("");
	assert(r.get_filme().size() == 1);
	vali.set_watch(a);
	vali.find_film(az);


}