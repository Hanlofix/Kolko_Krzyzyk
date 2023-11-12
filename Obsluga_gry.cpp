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
//---------------------------------------------------------------------------------------------------
void Komputer(char krzyzyk, char**& plansza, Niestandardowa*& poczatek)//FUNKCJA LOSUJACA POLA DO GRY Z KOMPUTEREM//LOGIKA
{
    srand(time(NULL));
    Sleep(1000);
    int x, y;
    int ruch = 0;
    Niestandardowa* pom = new Niestandardowa;
    int pole;


    while (ruch == 0)
    {
        x = 2 + rand() % (4 - 2 + 1);
        y = 2 + rand() % (4 - 2 + 1);


        if (x == 2 && y == 2)
        {
            pole = 1;
        }
        else if (x == 2 && y == 3)
        {
            pole = 2;
        }
        else if (x == 2 && y == 4)
        {
            pole = 3;
        }
        else if (x == 3 && y == 2)
        {
            pole = 4;
        }
        else if (x == 3 && y == 3)
        {
            pole = 5;
        }
        else if (x == 3 && y == 4)
        {
            pole = 6;
        }
        else if (x == 4 && y == 2)
        {
            pole = 7;
        }
        else if (x == 4 && y == 3)
        {
            pole = 8;
        }
        else if (x == 4 && y == 4)
        {
            pole = 9;
        }



        if (plansza[x][y] == '_')
        {
            plansza[x][y] = krzyzyk;


            pom->ruch = pole;
            pom->gracz = 'X';
            pom->nastepny = poczatek;
            poczatek = pom;

            ruch = 1;
        }
    }

}
//---------------------------------------------------------------------------------------------------
void tworz(char**& plansza, int wysokosc, int szerokosc)//TWORZY PLANSZE NIESTANDARDOWA NxN//LOGIKA
{
    plansza = new char* [wysokosc + 4];     // rezerwujemy pamiec dla tablicy wysokosc wskazników
    // i adres pierwszego z nich zapamietujemy jako duza
    for (int i = 0; i < wysokosc + 4; i++) // przydzielamy pamiec na kolejne
        plansza[i] = new char[szerokosc + 4];    // tablice jednowym. o szerokosc elementach
    // (wiersze tablicy dwuwymiarowej)
    // a ich adresy wpisujemy
    // do kolejnych elementów duza[i]
    for (int i = 0; i < wysokosc + 4; i++)
    {
        for (int j = 0; j < szerokosc + 4; j++)
        {
            if (i == wysokosc + 3 || i == wysokosc + 2 || i == 0 || i == 1 || j == wysokosc + 3 || j == wysokosc + 2 || j == 0 || j == 1)
            {
                plansza[i][j] = ' ';
            }
            else { plansza[i][j] = '_'; }
            // wykonujemy zwyk³e dzia³ania na tablicy
        }
    }

}
//---------------------------------------------------------------------------------------------------
bool wygrana(char**& plansza, char Gracz, int wysokosc, int szerokosc, Lista*& glowa, Lista*& pomocnicza, int& wynik, char& wybor)//SPRAWDZA WYGRANIE DLA PLANSZY NxN//LOGIKA
{

    int tmp, ile;
    tmp = wysokosc * szerokosc;
    ile = 0;

    for (int i = 2;i < wysokosc + 2;i++)
    {
        for (int j = 2;j < szerokosc + 2;j++)
        { //za kazdym razem rozpatruje całą plansze i sprawdzam małe plansze 3x3 czy nie nastapiło zwyciestwo

            if ((plansza[i][j] == Gracz && plansza[i][j + 1] == Gracz && plansza[i][j + 2] == Gracz) ||//3 poziomo w prawo
                (plansza[i][j] == Gracz && plansza[i][j - 1] == Gracz && plansza[i][j - 2] == Gracz) ||//3 poziomo w lewo
                (plansza[i][j] == Gracz && plansza[i + 1][j] == Gracz && plansza[i + 2][j] == Gracz) ||//3 pionowo w doł
                (plansza[i][j] == Gracz && plansza[i - 1][j] == Gracz && plansza[i - 2][j] == Gracz) ||//3 pionowo w gore
                (plansza[i][j] == Gracz && plansza[i + 1][j + 1] == Gracz && plansza[i + 2][j + 2] == Gracz) ||//głowna przekatna w doł
                (plansza[i][j] == Gracz && plansza[i - 1][j - 1] == Gracz && plansza[i - 2][j - 2] == Gracz) ||//głowna przekatna w gore
                (plansza[i][j] == Gracz && plansza[i + 1][j - 1] == Gracz && plansza[i + 2][j - 2] == Gracz) ||//druga przekatna w dol
                (plansza[i][j] == Gracz && plansza[i - 1][j + 1] == Gracz && plansza[i - 2][j + 2] == Gracz) ||//druga przekatna w gore
                (plansza[i][j] == Gracz && plansza[i][j + 1] == Gracz && plansza[i][j - 1] == Gracz) ||//1 w lewo , 1 w prawo
                (plansza[i][j] == Gracz && plansza[i + 1][j] == Gracz && plansza[i - 1][j] == Gracz)/*|| //1 w gore, 1 w dol
                (plansza[i][i] == Gracz && plansza[i+1][j+1] == Gracz && plansza[i+1][j-1] == Gracz)*///druga przekatna , 1 w gore,1 w dol
                )



            {
                if (Gracz == 'O')
                {
                    wynik = 1;
                    return true;
                }

                else if (Gracz == 'X')
                {
                    wynik = 2;
                    return true;
                }

                else if (Gracz == 'X' && wybor == '2')//GRA Z KOMPUTEREM
                {
                    wynik = 4;
                }

                return true;

            }
            else if (plansza[i][j] != '_')
            {
                ile++;
            }

        }
    }

    if (ile == tmp)
    {
        wynik = 3;
        return true;
    }


    return false;


}
//---------------------------------------------------------------------------------------------------

