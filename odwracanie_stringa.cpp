#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void szukajZnaku( string & tekst, char szukanyZnak, vector <int> &spacje_ )
{
    size_t znalezionaPozycja = tekst.find( szukanyZnak );

    do
    {
        spacje_.push_back(znalezionaPozycja);
        znalezionaPozycja = tekst.find( szukanyZnak, znalezionaPozycja + 1 );
    } while( znalezionaPozycja != std::string::npos );

}

int main()
{
    string str = "Ala ma kota";

    vector <int> spacje;

    szukajZnaku(str, ' ', spacje);

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    int n = str.length();

     for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    for( unsigned int i = 0; i < spacje.size(); i++ )
    {
        str.insert(spacje[ i ], " ");
    }

    //str1.insert(6, str2);

        cout << str << endl;

    return 0;
}
