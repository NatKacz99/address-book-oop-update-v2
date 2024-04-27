#include "plikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return false;
    else
        return true;
}
string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}
