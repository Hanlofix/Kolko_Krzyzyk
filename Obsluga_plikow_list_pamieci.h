#ifndef OBSLUGA_PLIKOW_LIST_PAMIECI_H
#define OBSLUGA_PLIKOW_LIST_PAMIECI_H
#include <string>
#include "Obsluga_gry.h"
using namespace std;

/**
 *\file Oblsuga_plikow_list_pamieci.h
 * \brief Plik nagłówkowy modułu Oblsuga_plikow_list_pamieci.
 */


 //-----------------------OBSLUGA PLIKOW,LIST I PAMIECI-----------------------------------------


 //---------------------------------------------------------------------------------------------------
 /**
  * @brief zwolnij_pamiec ZWALNIA PAMIEC PO DYNAMICZNEJ ALOKACJI PAMIECI DLA PLANSZY
  * @param plansza ZMIENNA DYNAMICZNA W KTOREJ PO WPISANIU ROZMIARÓW PLANSZY ALKOWANA JEST WYNAMICZNE TABLICA DWUWYMIAROWA .
  * @param wysokosc ZMIENNA PRZECHOWUJACA WYSOKOSC PLANSZY DLA OPCJI 3.
  */
void zwolnij_pamiec(char**& plansza, int wysokosc);//LOGIKA//OPCJA 3
//---------------------------------------------------------------------------------------------------
/**
 * @brief pobierz FUNKCJA POBIERA DANE Z PLIKU
 * @param nazwa //ZMIENNA PRZECHOWUJACE NAZWE PLIKU Z KTOREGO POBIERANE SA DANE O AUTORZE
 */
bool pobierz(string nazwa);//LOGIKA//OPCJA 4
//---------------------------------------------------------------------------------------------------
/**
 * @brief historia ZAPIS HISTORI GIER DO PLIKU
 * @param nazwa ZMIENNA PRZECHOWUJACE NAZWE PLIKU DO KTOREGO ZAPISYWANE BEDA INFORMACJE O ROZGRYWCE
 * @param glowa PIERWSZY ELEMENT LISTY JEDNOKIERUNKOWEJ, KTORA BEDZIE UZYWANA DO PRZECHOWYWANIA POSZCZEGOLNYCH ROZGRYWEK.
 */
bool historia(string nazwa, Lista* glowa);//LOGIKA//OPCJA 6
//---------------------------------------------------------------------------------------------------
/**
 * @brief usun_lista_niestandardowa_plansza ZWALNIA PAMIEC PO LISCIE Z 3 OPCJI
 * @param poczatek PIERWSZY ELEMENT LISTY W KTOREJ BEDĄ PRZECHOWYWANE RUCHY Z OSTATNIEJ ROZGRYWKI Dla OPCJI 3.
 */
void usun_lista_niestandardowa_plansza(Niestandardowa*& poczatek);//LOGIKA OPCJA 3
//---------------------------------------------------------------------------------------------------
/**
 * @brief skasuj ZWALNIA PAMIEC PO LISCIE O NAZWIE LISTA
 * @param glowa PIERWSZY ELEMENT LISTY JEDNOKIERUNKOWEJ, KTORA BEDZIE UZYWANA DO PRZECHOWYWANIA POSZCZEGOLNYCH ROZGRYWEK.
 */
void skasuj(Lista*/*&*/glowa);
//---------------------------------------------------------------------------------------------------



#endif // OBSLUGA_PLIKOW_LIST_PAMIECI_H
