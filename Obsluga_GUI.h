#ifndef GUI_H
#define GUI_H
#include <string>
using namespace std;
#include "Obsluga_gry.h"

/**
 *\file Obsluga_GUI.h
 * \brief Plik nagłówkowy modułu Obsluga_GUI.
 */


 //---------------------------------------------------------------------------------------------------
 /**
  * @brief powitanie POWITANIE NA POCZATKU GRY I ZMIANA KOLORU TEKSTU.
  */
void powitanie();//GUI
//---------------------------------------------------------------------------------------------------
/**
 * @brief menu FUNKCJA POKAZUJACA MENU GLOWNE GRY
 * @param wybor TA ZMIENNA JEST ODPOWIEDZIALNA ZA WYBOR RODZAJU GRY!!
 * @param glowa PIERWSZY ELEMENT LISTY JEDNOKIERUNKOWEJ, KTORA BEDZIE UZYWANA DO PRZECHOWYWANIA POSZCZEGOLNYCH ROZGRYWEK.
 */
void menu(char& wybor, Lista*& glowa);//GUI
//---------------------------------------------------------------------------------------------------
/**
 * @brief Ruch FUNKCJA ODPOWIEDZIALNA ZA PODAWANIE POLA, WYKONYWANIE RUCHU I POSREDNIO ODPOWIEDZIALNA ZA ZAPIS DANYCH DO LISTY JEDNOKIERUNKOWEJ.
 * FUNKCJA, KTORA DOTYCZY OPCJI 1 I 2 Z MENU.
 * @param Gracz TA ZMIENNA PRZECHOWUJE ZNAK KOLKA BADZ KRZYZYKA W ZALEZNOSCI CZYJ JEST RUCH.
 * @param plansza ZMIENNA PRZECHOWUJACA TABLICE CHAROW NA KTOREJ ODBYWA SIE ROZGRYWKA DLA OPCJI 1 I 2.
 * @param pierwszy PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI DLA OPCJI 1 i 2.
 */
void Ruch(char Gracz, char**& plansza, Niestandardowa*& poczatek);//GUI//OPCJA 1 i 2
//---------------------------------------------------------------------------------------------------
/**
 * @brief Przelacz_Gracza FUNKCJA ODPOWIEDZIALNA ZA PRZELACZANIE GRACZY.
 * @param Gracz TA ZMIENNA PRZECHOWUJE ZNAK KOLKA BADZ KRZYZYKA W ZALEZNOSCI CZYJ JEST RUCH.
 */
void Przelacz_Gracza(char& Gracz);//GUI//OPCJA 1
//---------------------------------------------------------------------------------------------------
/**
 * @brief wypisz FUNKCJA ODPOWIEDZIALNA ZA ODSWIEZANIE I WYPISYWANIE STANU NA PLANSZY DLA OPCJI 3.
 * @param plansza ZMIENNA DYNAMICZNA W KTOREJ PO WPISANIU ROZMIARÓW PLANSZY ALKOWANA JEST WYNAMICZNE TABLICA DWUWYMIAROWA .
 * @param wysokosc ZMIENNA PRZECHOWUJACA WYSOKOSC PLANSZY DLA OPCJI 3.
 * @param szerokosc ZMIENNA PRZECHOWUJACA SZEROKOSC PLANSZY DLA OPCJI 3.
 */
void wypisz(char**& plansza, int wysokosc, int szerokosc);//GUI//OPCJA 3
//---------------------------------------------------------------------------------------------------
/**
 * @brief wspolrzedne ODPOWIADA ZA PRAWIDLOWE PODAWANIE WSPOLRZEDNYCH, WYKONYWANIE RUCHU I POSREDNIO ODPOWIEDZIALNA ZA ZAPIS DANYCH DO LISTY JEDNOKIERUNKOWEJ.
 * @param plansza ZMIENNA DYNAMICZNA W KTOREJ PO WPISANIU ROZMIARÓW PLANSZY ALKOWANA JEST WYNAMICZNE TABLICA DWUWYMIAROWA .
 * @param wysokosc ZMIENNA PRZECHOWUJACA WYSOKOSC PLANSZY DLA OPCJI 3.
 * @param szerokosc ZMIENNA PRZECHOWUJACA SZEROKOSC PLANSZY DLA OPCJI 3.
 * @param Gracz TA ZMIENNA PRZECHOWUJE ZNAK KOLKA BADZ KRZYZYKA W ZALEZNOSCI CZYJ JEST RUCH.
 * @param wiersz ZMIENNA PRZECHOWUJACA NUMER WIERSZA W KTORYM RUCH CHCE ZROBIC UZYTKOWNIK.
 * @param kolumna ZMIENNA PRZECHOWUJACA NUMER KOLUMNY W KTORYM RUCH CHCE ZROBIC UZYTKOWNIK
 * @param poczatek PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI Dla OPCJI 3.
 */
void wspolrzedne(char**& plansza, int wysokosc, int szerokosc, char& Gracz, int& wiersz, int& kolumna, Niestandardowa*& poczatek);//GUI//OPCJA 3
//---------------------------------------------------------------------------------------------------
/**
 * @brief historia_ruchow_niestandardowa_plansza FUNKCJA ODPOWIEDZIALNA ZA WYPISYWANIE HISTORII DLA OPCJA 3
 * @param poczatek  PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI Dla OPCJI 3.
 * @param ile ZMIENNA KTORA WYPISUJE TURE, W KTOREJ ZOSTAŁ ZROBIONY DANY RUCH.
 */
void  historia_ruchow_niestandardowa_plansza(Niestandardowa*& poczatek, int& ile, int& rozgrywka);//GUI//OPCJA 3
//---------------------------------------------------------------------------------------------------




//FUNKCJE GUI ODDZIELONE ZE WZGLEDU NA SWOJE ZNACZENIE I WAGE DLA ZWIEKSZENIA CZYTELNOSCI


//---------------------------------------------------------------------------------------------------
/**
 * @brief warunek FUNKCJA ODPOWIEDZIALNA ZA WYKONYWANIE SIE OKRESLONYCH PODPROGRAMOW W ZALEZNOSCI OD TEGO CO WYBIERZE UZYTKOWNIK.
 * @param wybor TA ZMIENNA JEST ODPOWIEDZIALNA ZA WYBOR RODZAJU GRY!!
 * @param Gracz TA ZMIENNA PRZECHOWUJE ZNAK KOLKA BADZ KRZYZYKA W ZALEZNOSCI CZYJ JEST RUCH.
 * @param glowa PIERWSZY ELEMENT LISTY JEDNOKIERUNKOWEJ, KTORA BEDZIE UZYWANA DO PRZECHOWYWANIA POSZCZEGOLNYCH ROZGRYWEK.
 * @param pierwszy PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI DLA OPCJI 1 i 2.
 * @param poczatek PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI Dla OPCJI 3.
 */
inline void warunek(char& wybor, char& Gracz, Lista*& glowa, Niestandardowa*& poczatek, int& rozgrywka);//GUI
//---------------------------------------------------------------------------------------------------
/**
 * @brief Petla FUNKCJA ZAPETLAJACA MENU GLOWNE
 * @param wybor TA ZMIENNA JEST ODPOWIEDZIALNA ZA WYBOR RODZAJU GRY!!
 * @param Gracz TA ZMIENNA PRZECHOWUJE ZNAK KOLKA BADZ KRZYZYKA W ZALEZNOSCI CZYJ JEST RUCH.
 * @param glowa PIERWSZY ELEMENT LISTY JEDNOKIERUNKOWEJ, KTORA BEDZIE UZYWANA DO PRZECHOWYWANIA POSZCZEGOLNYCH ROZGRYWEK.
 * @param pierwszy PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI DLA OPCJI 1 i 2.
 * @param poczatek PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI Dla OPCJI 3.
 */
 void Petla(char& wybor, char& Gracz, Lista*& glowa, Niestandardowa*& poczatek, int& rozgrywka);//GUI
//---------------------------------------------------------------------------------------------------

#endif // GUI_H


