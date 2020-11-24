#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string odwroc_i_dodaj_spacje( string & str )
{
     vector <int> spacje;

     char szukanyZnak = ' ';

    size_t znalezionaPozycja = str.find( szukanyZnak );

    do
    {
        spacje.push_back(znalezionaPozycja);
        znalezionaPozycja = str.find( szukanyZnak, znalezionaPozycja + 1 );
    } while( znalezionaPozycja != std::string::npos );

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    int n = str.length();

     for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    for( unsigned int i = 0; i < spacje.size(); i++ )
    {
        str.insert(spacje[ i ], " ");
    }

    return str;
}

int main()
{
    string tekst = "Ala ma kota";

    cout << odwroc_i_dodaj_spacje(tekst) << endl;


    return 0;
}
