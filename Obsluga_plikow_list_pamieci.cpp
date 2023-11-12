#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include "Opcje.h"
#include "Obsluga_GUI.h"
#include "Obsluga_gry.h"
#include "Obsluga_plikow_list_pamieci.h"

using namespace std;


//-----------------------OBSLUGA PLIKOW,LIST I PAMIECI-----------------------------------------

void zwolnij_pamiec(char**& plansza, int wysokosc)//ZWALNIA PAMIEC PO DYNAMICZNEJ ALOKACJI PAMIECI DLA PLANSZY//LOGIKA
{
    for (int i = 0; i < wysokosc; i++) // zwalniamy pamiec po kazdej
    {
        delete[] plansza[i];
    } // z tablic jednowymiarowych
    delete[] plansza; // zwalniamy pamiec po tablicy wskazników


}
//---------------------------------------------------------------------------------------------------
bool pobierz(string nazwa)//FUNKCJA POBIERA DANE Z PLIKU I WYPISUJE INFORMACJE O AUTORZE//GUI
{
    ifstream plik(nazwa.c_str());

    if (plik.good() == 0)
    {
        return false;
    }

    string wiersz;

    while (!plik.eof())
    {
        getline(plik, wiersz);
        cout << wiersz << endl;
    }
    cout << endl;

    plik.close();
    return true;
}
//---------------------------------------------------------------------------------------------------
bool historia(string nazwa, Lista* glowa)//ZAPIS HISTORI GIER DO PLIKU//LOGIKA
{
    ofstream plik1(nazwa.c_str());

    if (plik1.good() == 0)
    {
        return false;
    }

    plik1 << "HISTORIA ROZGRYWEK PODCZAS URUCHOMIENIA GRY KOLKO I KRZYZYK";
    plik1 << endl << endl;
    Lista* pomoc = glowa;//ZEBY NIE ZMIENIAC GLOWY BO NIE BEDZIE SIE DALO POZNIEJ ODTWORZYC LISTYS
    if (pomoc != NULL)//JEST CALY CZAS JAKIS PROBLEM, BO JAK NIE MA ZADNYCH ROZGRYWEK TO KONSOLA KONCZY DZIALANIE
    {

        int licz = 1;
        while (pomoc != NULL)
        {
            plik1 << licz << '.' << pomoc->rodzaj << "-->" << pomoc->wynik;
            plik1 << endl;
            pomoc = pomoc->nast;
            licz++;
        }
        plik1 << endl;
        plik1 << "ZOSTALO ROZEGRANYCH " << licz - 1 << " ROZGRYWEK!!!";
    }
    else
    {
        plik1 << "NIE GRALES JESZCZE! LEC SIE ZABAWIC!" << endl;
    }
    delete pomoc;//USUWAMY ZMIENNA POMOCNICZA

    plik1.close();
    return true;

}
//---------------------------------------------------------------------------------------------------
void usun_lista_niestandardowa_plansza(Niestandardowa*& poczatek)//ZWALNIA PAMIEC PO LISCIE Z 3 OPCJI//LOGIKA
{
    while (poczatek != 0)
    {
        Niestandardowa* pom = poczatek;
        poczatek = poczatek->nastepny;
        delete pom;
    }


}
//---------------------------------------------------------------------------------------------------
void skasuj(Lista*/*&*/glowa)//ZWALNIA PAMIEC PO LISCIE O NAZWIE LISTA//LOGIKA
{
    while (glowa != 0)
    {
        Lista* pom = glowa;
        glowa = glowa->nast;
        delete pom;
    }
}
//---------------------------------------------------------------------------------------------------

