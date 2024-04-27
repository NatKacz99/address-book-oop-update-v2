#include "PlikZUzytkownikami.h"

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(pobierzNazwePliku(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika << endl;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    fstream plikTekstowy;
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    plikTekstowy.open(pobierzNazwePliku(), ios::in);

    if (plikTekstowy.is_open() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
        plikTekstowy.close();
    }
    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    int pozycja;

    pozycja = daneJednegoUzytkownikaOddzielonePionowymiKreskami.find('|');
    uzytkownik.ustawId(stoi(daneJednegoUzytkownikaOddzielonePionowymiKreskami.substr(0, pozycja)));
    daneJednegoUzytkownikaOddzielonePionowymiKreskami = daneJednegoUzytkownikaOddzielonePionowymiKreskami.substr(pozycja + 1, daneJednegoUzytkownikaOddzielonePionowymiKreskami.length());

    pozycja = daneJednegoUzytkownikaOddzielonePionowymiKreskami.find('|');
    uzytkownik.ustawLogin(daneJednegoUzytkownikaOddzielonePionowymiKreskami.substr(0, pozycja));
    daneJednegoUzytkownikaOddzielonePionowymiKreskami = daneJednegoUzytkownikaOddzielonePionowymiKreskami.substr(pozycja + 1, daneJednegoUzytkownikaOddzielonePionowymiKreskami.length());

    pozycja = daneJednegoUzytkownikaOddzielonePionowymiKreskami.find('|');
    uzytkownik.ustawHaslo(daneJednegoUzytkownikaOddzielonePionowymiKreskami.substr(0, pozycja));
    daneJednegoUzytkownikaOddzielonePionowymiKreskami = daneJednegoUzytkownikaOddzielonePionowymiKreskami.substr(pozycja + 1, daneJednegoUzytkownikaOddzielonePionowymiKreskami.length());

    return uzytkownik;
}
