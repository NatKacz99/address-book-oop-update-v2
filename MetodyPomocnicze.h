#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>


using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static char wczytajZnak();
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int konwersjaStringNaInt(string liczba);
    static int wczytajLiczbeCalkowita();
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
};

#endif
