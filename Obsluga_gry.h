#ifndef LOGIKA_H
#define LOGIKA_H
#include <string>
using namespace std;

/**
 *\file Obsluga_gry.h
 * \brief Plik nagłówkowy modułu Obsluga_gry.
 */


 //---------------------------------------------------------------------------------------------------
 /**
  * @brief The Lista struct
  * DEKLARACJA LISTY KTORA ZAWIERA WYNIKI POSZCZEGOLNYCH ROZGRYWEK I WYBRANYCH RODZAJI GRY
  */
struct Lista
{
    ///ZAPISUJE WYNIK DANEJ ROZGRYWKI W POSTACI TEKSTU.
    string wynik;
    ///ZAPISUJE RODZAJ ROZGRYWKI W KTORA GRAŁ UZYTKOWNIK
    string rodzaj;
    ///WSKAZNIK NA KOLEJNY ELEMENT LISTY
    Lista* nast;
};
//---------------------------------------------------------------------------------------------------
/**
 * @brief The Niestandardowa struct
 * DEKLARACJA LISTY KTORA ZAWIERA HISTORIE RUCHOW Z OPCJI 1 I 2
 */
struct Niestandardowa
{
    ///ZAPISUJE NUMER POLA NA KTORYM GRACZ POSTAWIL ZNAK W SWOJEJ TURZE
    int ruch;
    ///zapisuje wspolrzedna x z 3 opcji
    int x;
    ///zapisuje wspolrzedna y z 3 opcji
    int  y;
    ///ZAPISUJE CZYJA BYLA KOLEJ W DANEJ TURZE Z 3 ROZGRYWKI
    char gracz;
    ///WSKAZNIK NA KOLEJNY ELEMENT LISTY
    Niestandardowa* nastepny;
};
//---------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------
/**
 * @brief Komputer FUNKCJA LOSUJACA POLA DO GRY Z KOMPUTEREM
 * @param krzyzyk ZMIENNA PRZECHOWUJACA ZNAK KRZYZYKA.
 * @param plansza ZMIENNA PRZECHOWUJACA TABLICE CHAROW NA KTOREJ ODBYWA SIE ROZGRYWKA DLA OPCJI 1 I 2.
 * @param pierwszy PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI DLA OPCJI 1 i 2.
 */
void Komputer(char krzyzyk, char**& plansza, Niestandardowa*& poczatek);//LOGIKA//OPCJA 2
//---------------------------------------------------------------------------------------------------
/**
 * @brief tworz TWORZY PLANSZE NIESTANDARDOWA NxN.
 * @param plansza ZMIENNA PRZECHOWUJACA TABLICE CHAROW NA KTOREJ ODBYWA SIE ROZGRYWKA DLA OPCJI 1 I 2.
 * @param wysokosc ZMIENNA PRZECHOWUJACA WYSOKOSC PLANSZY DLA OPCJI 3.
 * @param szerokosc ZMIENNA PRZECHOWUJACA SZEROKOSC PLANSZY DLA OPCJI 3.
 */
void tworz(char**& plansza, int wysokosc, int szerokosc);//LOGIKA//OPCJA 3
//---------------------------------------------------------------------------------------------------
/**
 * @brief wygrana SPRAWDZA WYGRANIE DLA PLANSZY NxN
 * @param plansza ZMIENNA DYNAMICZNA W KTOREJ PO WPISANIU ROZMIARÓW PLANSZY ALKOWANA JEST WYNAMICZNE TABLICA DWUWYMIAROWA .
 * @param Gracz TA ZMIENNA PRZECHOWUJE ZNAK KOLKA BADZ KRZYZYKA W ZALEZNOSCI CZYJ JEST RUCH.
 * @param wysokosc ZMIENNA PRZECHOWUJACA WYSOKOSC PLANSZY DLA OPCJI 3.
 * @param szerokosc ZMIENNA PRZECHOWUJACA SZEROKOSC PLANSZY DLA OPCJI 3.
 * @param glowa PIERWSZY ELEMENT LISTY JEDNOKIERUNKOWEJ, KTORA BEDZIE UZYWANA DO PRZECHOWYWANIA POSZCZEGOLNYCH ROZGRYWEK.
 * @param pomocnicza PIERWSZY ELEMENT LISTY, KTORA ODPOWIADA ZA AKTUALNA ROZGRYWKE. DOTYCZY LISTY O NAZWIE LISTA.
 * @param wynik ZMIENNA, KTÓRA PRZYJMUJE ROZNE WARTOSCI W ZALEZNOSCI CZY WYGRAŁO KOŁKO, KRZYZYK CZY MOZE BYŁ REMIS.
 * @return ZWRACA INFORMACJE O TYM CZY PO WYKONANIU OSTATNIEGO RUCHU NASTĄPIŁA WYGRANA CZY NIE.
 */
bool wygrana(char**& plansza, char Gracz, int wysokosc, int szerokosc, Lista*& glowa, Lista*& pomocnicza, int& wynik, char& wybor);//LOGIKA//OPCJA 3
//---------------------------------------------------------------------------------------------------



#endif // LOGIKA_H
