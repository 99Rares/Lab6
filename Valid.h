#pragma once
#include "UI.h"
#include "Exception.h"
class Valid
{
public:
    //se valideaza input-ul pentru a fi numar
	int read_nr(int x) {
        if(x!=INT_MIN)
            cin >> x;
        while (true)
        {
            try {
                if (!cin)
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    //cout << "Invalid input\n";
                    //cout << "Zahl eingeben "; cin >> x;
                    throw _Exception(" Invalid input \nZahl eingeben: " + '\n');
                }
                else break;
            }
            catch (_Exception& e) {
                cout << e.error_message();
                cin >> x;
            }
        }
        
        return x;
	}
    // se valideaza pentru a fi numar dar dintre numerele disponibile in meniu
    int read_range(int x, int n){  
        if (x != INT_MIN)
        cin >> x;
        while (true) {

            try {
                if (!cin || x > n || x < 0)
                {

                    cin.clear();
                    if (x != INT_MIN)
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    //cout << "Invalid input\n";
                    //cout << "Zahl eingeben <= als: " << n << '\n'; 
                    throw _Exception("Invalid input\nZahl eingeben <= als: " + std::to_string(n) + '\n');
                    
                }
                else break;
            }
            catch (_Exception& e) {
                cout << e.error_message();
                cin >> x;
            }

        }
        return x;
    }
    //se valideaza input-ul pentru a fi string
    string read_string(string arg) {
        //Filme mit Zahlen als Titel: 2012
        if (arg != "test_123") {
            cin.ignore();
            getline(cin, arg);
        }
        return arg;
    }

};

