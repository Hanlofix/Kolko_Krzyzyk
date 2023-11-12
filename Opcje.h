#ifndef OPCJE_H
#define OPCJE_H
#include <string>
#include "Obsluga_gry.h"
using namespace std;

/**
 *\file Opcje.h
 * \brief Plik nagłówkowy modułu Opcje.
 */



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


#endif // OPCJE_H
