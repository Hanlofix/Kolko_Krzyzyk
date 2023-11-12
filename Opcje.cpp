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
//FUNKCJA ODPOWIEDZIALNA ZA WYKONYWANIE SIE OKRESLONYCH PODPROGRAMOW W ZALEZNOSCI OD TEGO CO WYBIERZE UZYTKOWNIK
void warunek(char& wybor, char& Gracz, Lista*& glowa, Niestandardowa*& poczatek, int& rozgrywka)//GUI
{
    Lista* pomocnicza = new Lista;//INICJALIZACJA POMOCNICZEJ LISTY, KTORA ODPOWIADA ZA AKTUALNA ROZGRYWKE


    do {
        if (wybor == '1') // GRACZ VS GRACZ NA PLANSZY 3x3
        {
            rozgrywka = 1;
            usun_lista_niestandardowa_plansza(poczatek);

            char** plansza = NULL;
            tworz(plansza, 3, 3);
            wypisz(plansza, 3, 3);
            pomocnicza->rodzaj = "Opcja 1-1vs1";
            //ZACZYNA KOLKO ZGODNIE Z NAZWA GRY
            int wynik = 0;
            while (true)
            {

                Ruch(Gracz, plansza, poczatek);
                if (wygrana(plansza, Gracz, 3, 3, glowa, pomocnicza, wynik, wybor))
                {
                    if (wynik == 1)
                    {
                        wypisz(plansza, 3, 3);
                        cout << "        TE PARTIE WYGRALO KOLKO" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRALO KOLKO";
                        pomocnicza->nast = glowa;//ZA PIERWSZYM RAZEM GLOWA==NULL WIEC NIE MA PROBLEMU
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");
                    }

                    else if (wynik == 2)
                    {
                        wypisz(plansza, 3, 3);
                        cout << "        TE PARTIE WYGRAL KRZYZYK" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRAL KRZYZYK";
                        pomocnicza->nast = glowa;
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");
                    }

                    else if (wynik == 3)
                    {
                        wypisz(plansza, 3, 3);
                        cout << "        PARTIA ZAKONCZYLA SIE REMISEM" << endl;
                        pomocnicza->wynik = "W TEJ PARTII WSZYSCY SA ZWYCIEZCAMI";
                        pomocnicza->nast = glowa;
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");
                    }




                    break;//JEZELI KTOS WYGRA TO WYCHODZIMY Z PETLI I WRACAMY DO MENU
                }
                Przelacz_Gracza(Gracz);
                wypisz(plansza, 3, 3);
            }
            zwolnij_pamiec(plansza, 7);
        }

        else if (wybor == '2')//GRACZ VS KOMPUTER NA PLANSZY 3x3
        {

            usun_lista_niestandardowa_plansza(poczatek);
            rozgrywka = 2;
            cout << "GRASZ Z DEEP BLUE 2  WIEC ZACZYNAJ!" << endl;

            char** plansza = NULL;
            tworz(plansza, 3, 3);
            wypisz(plansza, 3, 3);
            pomocnicza->rodzaj = "Opcja 2-CZLOWIEK KONTRA MASZYNA";
            int wynik = 0;
            while (true)
            {
                Ruch(Gracz, plansza, poczatek);
                if (wygrana(plansza, Gracz, 3, 3, glowa, pomocnicza, wynik, wybor))
                {
                    if (wynik == 1)
                    {
                        wypisz(plansza, 3, 3);
                        cout << "        TE PARTIE WYGRALO KOLKO" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRALO KOLKO";
                        pomocnicza->nast = glowa;//ZA PIERWSZYM RAZEM GLOWA==NULL WIEC NIE MA PROBLEMU
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");
                    }

                    else if (wynik == 4)
                    {
                        wypisz(plansza, 3, 3);
                        cout << "        TE PARTIE WYGRAL KOMPUTER" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRAL KOMPUTER";
                        pomocnicza->nast = glowa;
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");
                    }

                    else if (wynik == 3)
                    {
                        wypisz(plansza, 3, 3);
                        cout << "        PARTIA ZAKONCZYLA SIE REMISEM" << endl;
                        pomocnicza->wynik = "W TEJ PARTII WSZYSCY SA ZWYCIEZCAMI";
                        pomocnicza->nast = glowa;
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");
                    }



                    break;
                }
                Komputer('X', plansza, poczatek);
                Gracz = 'X';
                if (wygrana(plansza, Gracz, 3, 3, glowa, pomocnicza, wynik, wybor))
                {
                    if (Gracz == 'O')
                    {
                        wypisz(plansza, 3, 3);
                        cout << "TE PARTIE WYGRALO KOLKO" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRALO KOLKO";
                        pomocnicza->nast = glowa;//ZA PIERWSZYM RAZEM GLOWA==NULL WIEC NIE MA PROBLEMU
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");


                    }

                    else if (Gracz == 'X' && wybor == '2')//GRA Z KOMPUTEREM

                    {
                        wypisz(plansza, 3, 3);
                        cout << "TE PARTIE WYGRAL KOMPUTER" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRAL KOMPUTER";
                        pomocnicza->nast = glowa;
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                        system("cls");


                    }


                    break;
                }
                wypisz(plansza, 3, 3);
                Gracz = 'O';
            }
            zwolnij_pamiec(plansza, 7);
        }

        else if (wybor == '3') //GRACZ VS GRACZ NA PLANSZY DYNAMICZNEJ
        {

            usun_lista_niestandardowa_plansza(poczatek);
            rozgrywka = 3;
            pomocnicza->rodzaj = "Opcja 3-CZLOWIEK KONTRA CZLOWIEK NA NIESTANDARDOWEJ PLANSZY";

            cout << "WYBRALES GRE NA NIESTANDARDOWEJ PLANSZY!!! PODAJ JEJ WYMIARY!!!" << endl;

            int wysokosc, szerokosc;

            cout << "PODAJ WYSOKOSC I SZEROKOSC PLANSZY:"; //cin>>wysokosc;

            while ((!(cin >> wysokosc)) || wysokosc < 4)
            {
                cin.clear();
                cin.sync();
                system("cls");
                cout << "PODAJ WYSOKOSC I SZEROKOSC PLANSZY PONOWNIE(MUSI BYC WIEKSZA NIZ 3x3):";

            }
            szerokosc = wysokosc;


            // zarezerwujemy tablice duza typu char
            char** plansza = NULL;              // duza bedzie wskaznikiem do wskaznika
            tworz(plansza, wysokosc, szerokosc);                            // pierwszego elementu tablicy
            wypisz(plansza, wysokosc, szerokosc);

            int wiersz, kolumna;
            Gracz = 'X';
            system("cls");
            int wynik = 0;
            while (true)
            {
                Przelacz_Gracza(Gracz);
                wypisz(plansza, wysokosc, szerokosc);
                wspolrzedne(plansza, wysokosc, szerokosc, Gracz, wiersz, kolumna, poczatek);
                if (wygrana(plansza, Gracz, wysokosc, szerokosc, glowa, pomocnicza, wynik, wybor))
                {
                    if (wynik == 1)
                    {
                        system("cls");
                        wypisz(plansza, wysokosc, szerokosc);
                        cout << "TE PARTIE WYGRALO KOLKO" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRALO KOLKO";
                        pomocnicza->nast = glowa;//ZA PIERWSZYM RAZEM GLOWA==NULL WIEC NIE MA PROBLEMU
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';

                    }

                    else if (wynik == 2)
                    {
                        system("cls");
                        wypisz(plansza, wysokosc, szerokosc);
                        cout << "TE PARTIE WYGRAL KRZYZYK" << endl;
                        pomocnicza->wynik = "TE PARTIE WYGRAL KRZYZYK";
                        pomocnicza->nast = glowa;//ZA PIERWSZYM RAZEM GLOWA==NULL WIEC NIE MA PROBLEMU
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                    }

                    else if (wynik == 3)
                    {
                        system("cls");
                        wypisz(plansza, wysokosc, szerokosc);
                        cout << "PARTIA ZAKONCZYLA SIE REMISEM" << endl;
                        pomocnicza->wynik = "W TEJ PARTII WSZYSCY SA ZWYCIEZCAMI";
                        pomocnicza->nast = glowa;//ZA PIERWSZYM RAZEM GLOWA==NULL WIEC NIE MA PROBLEMU
                        glowa = pomocnicza;
                        Sleep(3000);
                        Gracz = 'O';
                    }

                    break;
                }
                system("cls");
            }
            zwolnij_pamiec(plansza, wysokosc + 4);
        }

        else if (wybor == '4')//POBIERA INFORMACJE O GRZE
        {
            if (pobierz("informacje.txt"))
            {
                cout << "WCISNIJ DOWOLNY PRZYCISK, ABY WROCIC DO MENU!!!";
                system("pause");
            }

            else
            {
                cout << "BLAD";
                exit(0);
            }
        }

        else if (wybor == '6')//POKAZUJE HISTORIE ROZGRYWEK W DANEJ SESJI
        {
            Lista* pomoc = glowa;//ZEBY NIE ZMIENIAC GLOWY BO NIE BEDZIE SIE DALO POZNIEJ ODTWORZYC LISTYS
            if (pomoc != NULL)
            {

                int licz = 1;
                while (pomoc != NULL)
                {
                    cout << licz << '.' << pomoc->rodzaj << "-->" << pomoc->wynik;
                    cout << endl;
                    pomoc = pomoc->nast;
                    licz++;
                }

            }
            else
            {
                cout << "NIE GRALES JESZCZE! LEC SIE ZABAWIC!" << endl;
            }
            delete pomoc;//USUWAMY ZMIENNA POMOCNICZA
            cout << endl;
            cout << "NACISNIJ DOWOLONY PRZYCISK, ABY KONTYNUOWAC" << endl;
            cout << _getch();
        }

        else if (wybor == '7')//POKAZUJE HISTORIE RUCHOW Z OSTATNIEJ ROZGRYWKI
        {

            if (poczatek != NULL)
            {

                int ile = 0;
                cout << "HISTORIA RUCHOW Z OSTATNIEJ ROZEGRANEJ GRY!" << endl << endl;
                historia_ruchow_niestandardowa_plansza(poczatek, ile, rozgrywka);

            }

            else
            {
                cout << "NIE GRALES NIE MA HISTORII! LEC SIE ZABAWIC!" << endl;
            }

            cout << endl;
            cout << "NACISNIJ DOWOLONY PRZYCISK, ABY KONTYNUOWAC" << endl;
            cout << _getch();


        }

    } while (wybor == '5');

}
//---------------------------------------------------------------------------------------------------
/* void Petla(char& wybor, char& Gracz, Lista*& glowa, Niestandardowa*& poczatek, int& rozgrywka)//FUNKCJA ZAPETLAJACA MENU GLOWNE//GUI
{
    while (true)
    {
        menu(wybor, glowa);//JEZELI CHCESZ WYJSC Z GRY TO PO PROSTU WCISNIJ OPCJE 5
        warunek(wybor, Gracz, glowa, poczatek, rozgrywka);
    }

}*/
