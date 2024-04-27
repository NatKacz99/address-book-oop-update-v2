#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami :public PlikTekstowy
{
    int idOstatniegoAdresata;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    MetodyPomocnicze metodyPomocnicze;
public:
    void zwiekszIdOstatniegoAdresataOJedenPoZalogowaniuInnegoUzytkownika();
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata = 0;
        zwiekszIdOstatniegoAdresataOJedenPoZalogowaniuInnegoUzytkownika();
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    Adresat pobierzDaneAdresata(string daneJendegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void edytujDaneAdresataWPliku(Adresat adresat);
    void ustawNazwePliku(string nowaNazwa);
    void usunLinieZDanymiWybranegoAdresata(Adresat adresat);
};

#endif
