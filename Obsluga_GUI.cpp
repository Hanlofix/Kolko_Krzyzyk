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


void powitanie()//POWITANIE //GUI
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "WITAJ W MOJEJ APLIKACJI!!! PORA ZAGRAC W KOLKO I KRZYZYK!!!" << endl << endl;
}
//---------------------------------------------------------------------------------------------------
void menu(char& wybor, Lista*& glowa) //MENU GLOWNE (NA KONCU FUNKCJI SYSTEM(CLS))//GUI
{
    do
    {
        HANDLE hOut;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "MENU GLOWNE" << endl;
        cout << "----------------" << endl;
        cout << "1. GRA 1vs1 NA ZWYKLEJ PLANSZY(3x3)" << endl;
        cout << "2. GRA Z KOMPUTEREM (plansza 3x3)" << endl;
        cout << "3. GRA NA PLANSZY O DOWOLNYCH WYMIARACH(plansza NxN)" << endl;
        cout << "4. INFORMACJE O GRZE I JEJ TWORCACH" << endl;
        cout << "5. WYJSCIE Z GRY" << endl;
        cout << "6. HISTORIA ROZGRYWEK" << endl;
        cout << "7. PRZEBIEG OSTATNIEJ GRY" << endl;

        cout << endl;
        cout << "WYBIERZ OPCJE: ";
        wybor = _getch();  //pobiera pierwszy znak z konsoli bez sprawdzania czy jest to int czy nie
        cout << wybor;
        cout << endl;

        switch (wybor)
        {
        case '1':
            cout << "WYBRALES GRE NA ZWYKLEJ PLANSZY!!! Powodzenia!!!" << endl;

            break;

        case '2':
            cout << "Wybrales GRE Z KOMPUTEREM!!!" << endl;
            break;

        case '3':
            cout << "WYBRALES GRE NA PLANSZY O DOWOLNYCH WYMIARACH. WYBIERZ WYMIARY!!!" << endl;
            break;

        case'4':
            cout << "NACISNIJ ENTER, ABY DOWIEDZIEC SIE WIECEJ O GRZE!!!" << endl;
            break;

        case '5':
            if (historia("Historia.txt", glowa))
            {
            }
            else
            {
                cout << "BLAD";
                exit(0);
            }
            skasuj(glowa);
            system("cls");
            cout << " ________________$$$$$$$$_____" << endl;
            cout << " _______________$$$$$$$$$$____" << endl;
            cout << " ____$$$$$$____$$$$$$$$$$$$___" << endl;
            cout << " ___$$$$$$$$__$$$$$$$$$$$$$___" << endl;
            cout << " __$$$$$$$$$__$$$$$$$$$$$$$___" << endl;
            cout << " __$$$$$$$$$__$$$$$$$$$$$$$___" << endl;
            cout << " __$$$$$$$$___$$$$$$$$$$$$____" << endl;
            cout << " __$$$$$$$$___$$$$$$$$$$$_____" << endl;
            cout << " __$$$$$$$_____$$$$$$$$$______" << endl;
            cout << " ___$$$$$_______$$$$$$$_______" << endl;
            cout << " _$___________________________" << endl;
            cout << " _$$__________________________" << endl;
            cout << " _$$$______________________$$_" << endl;
            cout << " __$$$u_________________$$$$__" << endl;
            cout << " ___$$$$$$___________$$$$$$___" << endl;
            cout << " _____$$$$$$$$$$$$$$$$$$$$____" << endl;
            cout << " _______$$$$$$$$$$$$$$$_______" << endl;
            cout << " ___________$$$$$$____________" << endl;
            cout << endl;
            cout << "________WROC SZYBKO!!!_________" << endl;


            exit(0);


        case '6':
            cout << "-_-_-HISTORIA ROZGRYWEK W GRZE KOLKO I KRZYZYK-_-_-" << endl;
            break;

        case '7':
            cout << "-_-_-NACISNIJ ENTER, ABY ZOBACZYC HISTORIE RUCHOW!!!-_-_-" << endl;
            break;


        }

    } while (wybor <= 48 || wybor >= 56);




    system("pause");
    system("cls");
}
//---------------------------------------------------------------------------------------------------
void Ruch(char Gracz, char**& plansza, Niestandardowa*& poczatek)//FUNKCJA ODPOWIEDZIALNA ZA WYKONYWANIE RUCHU(NA KONCU JEST "SYSTEM(CLS)")//GUI
{
    int cofanie_ruchu = 1;//DOMYSLNA WARTOSC, KTORA OZNACZA DALSZA ROZGRYWKE BEZ COFANIA RUCHU
    Niestandardowa* pom = new Niestandardowa;
    int pole;
    cout << "        PODAJ NUMER POLA(1-9):";

    while (!(cin >> pole))
    {
        cin.clear();
        cin.sync();
        system("cls");
        wypisz(plansza, 3, 3);
        cout << "        ZlE POLE" << endl;
        cout << "        PODAJ NUMER POLA:";

    }

    switch (pole)
    {
    case 1:
        if (plansza[2][2] == '_' && !((plansza[2][3] == Gracz && plansza[2][4] == Gracz) || (plansza[3][2] == Gracz && plansza[3][4] == Gracz)
            || (plansza[3][3] == Gracz && plansza[4][4] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[2][2] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[2][2] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[2][2] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLAD WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[2][2] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 2:
        if (plansza[2][3] == '_' && !((plansza[2][2] == Gracz && plansza[2][4] == Gracz) || (plansza[3][3] == Gracz && plansza[4][3] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[2][3] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[2][3] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[2][3] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[2][3] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 3:
        if (plansza[2][4] == '_' && !((plansza[2][2] == Gracz && plansza[2][3] == Gracz) || (plansza[3][4] == Gracz && plansza[4][4] == Gracz)
            || (plansza[4][2] == Gracz && plansza[3][3] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[2][4] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[2][4] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[2][4] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[2][4] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 4:
        if (plansza[3][2] == '_' && !((plansza[2][2] == Gracz && plansza[4][2] == Gracz) || (plansza[3][3] == Gracz && plansza[3][4] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[3][2] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[3][2] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[3][2] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[3][2] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 5:
        if (plansza[3][3] == '_' && !((plansza[2][2] == Gracz && plansza[4][4] == Gracz) || (plansza[4][2] == Gracz && plansza[2][4] == Gracz)
            || (plansza[3][2] == Gracz && plansza[3][4] == Gracz) || (plansza[2][3] == Gracz && plansza[4][3] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[3][3] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[3][3] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[3][3] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[3][3] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 6:
        if (plansza[3][4] == '_' && !((plansza[2][4] == Gracz && plansza[4][4] == Gracz) || (plansza[3][2] == Gracz && plansza[3][3] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[3][4] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[3][4] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[3][4] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[3][4] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 7:
        if (plansza[4][2] == '_' && !((plansza[2][2] == Gracz && plansza[3][2] == Gracz) || (plansza[4][3] == Gracz && plansza[4][4] == Gracz)
            || (plansza[3][3] == Gracz && plansza[2][4] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[4][2] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[4][2] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[4][2] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[4][2] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 8:
        if (plansza[4][3] == '_' && !((plansza[4][2] == Gracz && plansza[4][4] == Gracz) || (plansza[2][3] == Gracz && plansza[3][3] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[4][3] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[4][3] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[4][3] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[4][3] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    case 9:
        if (plansza[4][4] == '_' && !((plansza[4][2] == Gracz && plansza[4][3] == Gracz) || (plansza[2][2] == Gracz && plansza[3][3] == Gracz)
            || (plansza[3][4] == Gracz && plansza[2][4] == Gracz)))//JEZELI KTOS WYGRA TO NIE PYTAMY JUZ O COFANIE RUCHU
        {
            plansza[4][4] = Gracz;
            system("cls");
            wypisz(plansza, 3, 3);
            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                wypisz(plansza, 3, 3);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
            if (cofanie_ruchu == 2)//COFNIJ RUCH
            {
                plansza[4][4] = '_';
                system("cls");
                wypisz(plansza, 3, 3);
                Ruch(Gracz, plansza, poczatek);
            }

            else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
            {
                pom->ruch = pole;
                pom->gracz = Gracz;
                pom->nastepny = poczatek;
                poczatek = pom;
            }

        }
        else if (plansza[4][4] == '_')//KTOS WYGRAL(BO ZOSTALO WCZESNIEJ SPRAWDZONE, ZE JEST UKLADY WYGRYWAJACY I NIE WESZLO W POPRZEDNIEGO IFA)
        {
            plansza[4][4] = Gracz;
            pom->ruch = pole;
            pom->gracz = Gracz;
            pom->nastepny = poczatek;
            poczatek = pom;
        }
        else
        {
            cout << "        TO POLE JEST ZAJETE" << endl;
            Sleep(1000);
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, 3, 3);
            Ruch(Gracz, plansza, poczatek);
        }
        break;

    default:
        cout << "        ZLE POLE" << endl;
        Sleep(1000);
        system("cls");
        if (Gracz == 'O')
        {
            cout << "KOLEJ GRACZA KOLKO" << endl;
        }
        else
        {
            cout << "KOLEJ GRACZA KRZYZYK" << endl;
        }
        wypisz(plansza, 3, 3);
        Ruch(Gracz, plansza, poczatek);
    }
    system("cls");
}
//---------------------------------------------------------------------------------------------------
void Przelacz_Gracza(char& Gracz) //FUNKCJA ODPOWIEDZIALNA ZA PRZELACZANIE GRACZY//GUI
{
    switch (Gracz)
    {
    case'X':
    {
        cout << "KOLEJ GRACZA KOLKO" << endl;
        Gracz = 'O';
    }
    break;
    case 'O':
    {
        cout << "KOLEJ GRACZA KRZYZYK" << endl;
        Gracz = 'X';
    }
    break;
    }
}
//---------------------------------------------------------------------------------------------------
void wypisz(char**& plansza, int wysokosc, int szerokosc)//FUNKCJA ODPOWIEDZIALNA ZA ODSWIEZANIE I WYPISYWANIE STANU NA PLANSZY DLA OPCJI 3//GUI
{
    if (wysokosc > 3) {

        cout << "   ";
        for (int j = 0;j < szerokosc + 4;j++)
        {
            if (j != 0 && j != 1 && j != wysokosc + 3 && j != wysokosc + 2)
                cout << fixed << setprecision(1) << setw(5) << j - 1;
        }
        for (int i = 0;i < wysokosc + 4;i++)
        {
            if (i != 0 && i != 1 && i != wysokosc + 3 && i != wysokosc + 2)
                cout << i - 1;
            for (int j = 0;j < szerokosc + 4;j++)
            {

                if (i == wysokosc + 3 || i == wysokosc + 2 || i == 0 || i == 1 || j == wysokosc + 3 || j == wysokosc + 2 || j == 0 || j == 1)
                {
                    cout << plansza[i][j];
                }
                else { cout << fixed << setprecision(1) << setw(5) << plansza[i][j]; }
            }
            cout << endl;
        }


    }

    else if (wysokosc <= 3) {

        for (int i = 0;i <= wysokosc + 3;i = i + wysokosc + 3) {
            for (int j = 0;j <= szerokosc + 3;j++) {
                plansza[i][j] = '#';
            }
        }

        for (int j = 0;j <= szerokosc + 3;j = j + szerokosc + 3) {
            for (int i = 0;i <= wysokosc + 3;i++) {
                plansza[i][j] = '#';

            }
        }
        HANDLE hOut;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        for (int i = 0;i < wysokosc + 4;i++)
        {
            for (int j = 0;j < szerokosc + 4;j++)
            {
                if (i == wysokosc + 3 || i == wysokosc + 2 || i == 0 || i == 1 || j == wysokosc + 3 || j == wysokosc + 2 || j == 0 || j == 1)
                {
                    cout << fixed << setprecision(1) << setw(5) << plansza[i][j];
                }
                else { cout << fixed << setprecision(1) << setw(5) << plansza[i][j]; }
            }
            cout << endl;
        }




    }




}
//---------------------------------------------------------------------------------------------------
void wspolrzedne(char**& plansza, int wysokosc, int szerokosc, char& Gracz, int& wiersz, int& kolumna, Niestandardowa*& poczatek)//ODPOWIADA ZA PRAWIDLOWE PODAWANIE WSPOLRZEDNYCH//GUI
{
    Niestandardowa* pom = new Niestandardowa;
    int cofanie_ruchu = 1;
    cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
    cout << "PODAJ WIERSZ:";
    while (!(cin >> wiersz))
    {
        cin.clear();
        cin.sync();
        system("cls");
        if (Gracz == 'O')
        {
            cout << "KOLEJ GRACZA KOLKO" << endl;
        }
        else
        {
            cout << "KOLEJ GRACZA KRZYZYK" << endl;
        }
        wypisz(plansza, wysokosc, szerokosc);

        cout << "NIE MOZESZ PODAWAC INNYCH ZNAKOW NIZ CYFRY!" << endl;
        cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
        cout << "PODAJ WIERSZ:";
    }

    cout << "PODAJ KOLUMNE:";
    while (!(cin >> kolumna))
    {
        cin.clear();
        cin.sync();
        system("cls");
        if (Gracz == 'O')
        {
            cout << "KOLEJ GRACZA KOLKO" << endl;
        }
        else
        {
            cout << "KOLEJ GRACZA KRZYZYK" << endl;
        }
        wypisz(plansza, wysokosc, szerokosc);

        cout << "NIE MOZESZ PODAWAC INNYCH ZNAKOW NIZ CYFRY!" << endl;
        cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
        cout << "PODAJ WIERSZ:" << wiersz << endl;
        cout << "PODAJ KOLUMNE:";
    }


    wiersz = wiersz + 1;
    kolumna = kolumna + 1;
    while (wiersz > wysokosc + 1 || kolumna > szerokosc + 1 || plansza[wiersz][kolumna] != '_')
    {
        system("cls");
        if (Gracz == 'O')
        {
            cout << "KOLEJ GRACZA KOLKO" << endl;
        }
        else
        {
            cout << "KOLEJ GRACZA KRZYZYK" << endl;
        }
        wypisz(plansza, wysokosc, szerokosc);

        cout << "NIE MOZESZ TU STANAC!" << endl;

        cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
        cout << "PODAJ WIERSZ:";
        while (!(cin >> wiersz))
        {
            cin.clear();
            cin.sync();
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, wysokosc, szerokosc);

            cout << "NIE MOZESZ PODAWAC INNYCH ZNAKOW NIZ CYFRY!" << endl;
            cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
            cout << "PODAJ WIERSZ:";
        }

        cout << "PODAJ KOLUMNE:";
        while (!(cin >> kolumna))
        {
            cin.clear();
            cin.sync();
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, wysokosc, szerokosc);

            cout << "NIE MOZESZ PODAWAC INNYCH ZNAKOW NIZ CYFRY!" << endl;
            cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
            cout << "PODAJ WIERSZ:" << wiersz << endl;
            cout << "PODAJ KOLUMNE:";
        }





        wiersz = wiersz + 1;
        kolumna = kolumna + 1;
    }

    if (plansza[wiersz][kolumna] == '_')
    {
        plansza[wiersz][kolumna] = Gracz;

        if (!((plansza[wiersz][kolumna] == Gracz && plansza[wiersz][kolumna + 1] == Gracz && plansza[wiersz][kolumna + 2] == Gracz) ||//3 poziomo w prawo
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz][kolumna - 1] == Gracz && plansza[wiersz][kolumna - 2] == Gracz) ||//3 poziomo w lewo
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna] == Gracz && plansza[wiersz + 2][kolumna] == Gracz) ||//3 pionowo w doł
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz - 1][kolumna] == Gracz && plansza[wiersz - 2][kolumna] == Gracz) ||//3 pionowo w gore
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna + 1] == Gracz && plansza[wiersz + 2][kolumna + 2] == Gracz) ||//głowna przekatna w doł
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz - 1][kolumna - 1] == Gracz && plansza[wiersz - 2][kolumna - 2] == Gracz) ||//głowna przekatna w gore
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna - 1] == Gracz && plansza[wiersz + 2][kolumna - 2] == Gracz) ||//druga przekatna w dol
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz - 1][kolumna + 1] == Gracz && plansza[wiersz - 2][kolumna + 2] == Gracz) ||//druga przekatna w gore
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz][kolumna + 1] == Gracz && plansza[wiersz][kolumna - 1] == Gracz) ||//1 w lewo , 1 w prawo
            (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna] == Gracz && plansza[wiersz - 1][kolumna] == Gracz)))//druga przekatna , 1 w gore,1 w dol

        {
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, wysokosc, szerokosc);

            cout << "CZY CHCESZ COFNAC RUCH?" << endl;
            cout << "1.GRAMY DALEJ" << endl;
            cout << "2.COFNIJ RUCH" << endl;
            cout << "WYBIERZ OPCJE:";
            while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
            {
                cin.clear();
                cin.sync();
                system("cls");
                if (Gracz == 'O')
                {
                    cout << "KOLEJ GRACZA KOLKO" << endl;
                }
                else
                {
                    cout << "KOLEJ GRACZA KRZYZYK" << endl;
                }
                wypisz(plansza, wysokosc, szerokosc);
                cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                cout << "1.GRAMY DALEJ" << endl;
                cout << "2.COFNIJ RUCH" << endl;
                cout << "WYBIERZ OPCJE:";
            }
        }

        if (cofanie_ruchu == 2)//COFNIJ RUCH
        {
            plansza[wiersz][kolumna] = '_';
            goto cofanie;
        }

        else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
        {
            pom->gracz = Gracz;
            pom->x = wiersz - 1;
            pom->y = kolumna - 1;
            pom->nastepny = poczatek;
            poczatek = pom;
        }

    }
    else
    {
        while (plansza[wiersz][kolumna] == 'O' || plansza[wiersz][kolumna] == 'X' || plansza[wiersz][kolumna] != '_' || cofanie_ruchu == 2)
        {
        cofanie://DO TEJ PETLI SIE WCHODZI JEZELI CHCEMY COFNAC RUCH
            cofanie_ruchu = 1;
            system("cls");
            if (Gracz == 'O')
            {
                cout << "KOLEJ GRACZA KOLKO" << endl;
            }
            else
            {
                cout << "KOLEJ GRACZA KRZYZYK" << endl;
            }
            wypisz(plansza, wysokosc, szerokosc);

            if (cofanie_ruchu == 2)
            {
                cout << "POWTORZ SWOJ RUCH" << endl;
            }
            else
            {
                cout << "NIE MOZESZ TU STANAC!" << endl;
            }

            cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
            cout << "PODAJ WIERSZ:";
            while (!(cin >> wiersz))
            {
                cin.clear();
                cin.sync();
                system("cls");
                if (Gracz == 'O')
                {
                    cout << "KOLEJ GRACZA KOLKO" << endl;
                }
                else
                {
                    cout << "KOLEJ GRACZA KRZYZYK" << endl;
                }
                wypisz(plansza, wysokosc, szerokosc);

                cout << "NIE MOZESZ PODAWAC INNYCH ZNAKOW NIZ CYFRY!" << endl;
                cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
                cout << "PODAJ WIERSZ:";
            }

            cout << "PODAJ KOLUMNE:";
            while (!(cin >> kolumna))
            {
                cin.clear();
                cin.sync();
                system("cls");
                if (Gracz == 'O')
                {
                    cout << "KOLEJ GRACZA KOLKO" << endl;
                }
                else
                {
                    cout << "KOLEJ GRACZA KRZYZYK" << endl;
                }
                wypisz(plansza, wysokosc, szerokosc);

                cout << "NIE MOZESZ PODAWAC INNYCH ZNAKOW NIZ CYFRY!" << endl;
                cout << "PODAJ WSPOLRZEDNE RUCHU!" << endl;
                cout << "PODAJ WIERSZ:" << wiersz << endl;
                cout << "PODAJ KOLUMNE:";
            }

            wiersz = wiersz + 1;
            kolumna = kolumna + 1;

            if (plansza[wiersz][kolumna] == '_')
            {
                plansza[wiersz][kolumna] = Gracz;

                if (!((plansza[wiersz][kolumna] == Gracz && plansza[wiersz][kolumna + 1] == Gracz && plansza[wiersz][kolumna + 2] == Gracz) ||//3 poziomo w prawo
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz][kolumna - 1] == Gracz && plansza[wiersz][kolumna - 2] == Gracz) ||//3 poziomo w lewo
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna] == Gracz && plansza[wiersz + 2][kolumna] == Gracz) ||//3 pionowo w doł
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz - 1][kolumna] == Gracz && plansza[wiersz - 2][kolumna] == Gracz) ||//3 pionowo w gore
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna + 1] == Gracz && plansza[wiersz + 2][kolumna + 2] == Gracz) ||//głowna przekatna w doł
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz - 1][kolumna - 1] == Gracz && plansza[wiersz - 2][kolumna - 2] == Gracz) ||//głowna przekatna w gore
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna - 1] == Gracz && plansza[wiersz + 2][kolumna - 2] == Gracz) ||//druga przekatna w dol
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz - 1][kolumna + 1] == Gracz && plansza[wiersz - 2][kolumna + 2] == Gracz) ||//druga przekatna w gore
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz][kolumna + 1] == Gracz && plansza[wiersz][kolumna - 1] == Gracz) ||//1 w lewo , 1 w prawo
                    (plansza[wiersz][kolumna] == Gracz && plansza[wiersz + 1][kolumna] == Gracz && plansza[wiersz - 1][kolumna] == Gracz)))//druga przekatna , 1 w gore,1 w dol
                {
                    system("cls");
                    if (Gracz == 'O')
                    {
                        cout << "KOLEJ GRACZA KOLKO" << endl;
                    }
                    else
                    {
                        cout << "KOLEJ GRACZA KRZYZYK" << endl;
                    }
                    wypisz(plansza, wysokosc, szerokosc);

                    cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                    cout << "1.GRAMY DALEJ" << endl;
                    cout << "2.COFNIJ RUCH" << endl;
                    cout << "WYBIERZ OPCJE:";
                    while (!(cin >> cofanie_ruchu) || cofanie_ruchu < 1 || cofanie_ruchu>2)
                    {
                        cin.clear();
                        cin.sync();
                        system("cls");
                        if (Gracz == 'O')
                        {
                            cout << "KOLEJ GRACZA KOLKO" << endl;
                        }
                        else
                        {
                            cout << "KOLEJ GRACZA KRZYZYK" << endl;
                        }
                        wypisz(plansza, wysokosc, szerokosc);
                        cout << "CZY CHCESZ COFNAC RUCH?" << endl;
                        cout << "1.GRAMY DALEJ" << endl;
                        cout << "2.COFNIJ RUCH" << endl;
                        cout << "WYBIERZ OPCJE:";
                    }
                }


                if (cofanie_ruchu == 2)//COFNIJ RUCH
                {
                    plansza[wiersz][kolumna] = '_';
                    goto cofanie;
                }

                else if (cofanie_ruchu == 1)//GRAMY DALEJ (JEST USTAWIONE AUTOMATYCZNIE)
                {
                    pom->gracz = Gracz;
                    pom->x = wiersz - 1;
                    pom->y = kolumna - 1;
                    pom->nastepny = poczatek;
                    poczatek = pom;
                    break;
                }

            }

        }//klamra od while

    }
}
//---------------------------------------------------------------------------------------------------
void  historia_ruchow_niestandardowa_plansza(Niestandardowa*& poczatek, int& ile, int& rozgrywka)//GUI//FUNKCJA ODPOWIEDZIALNA ZA WYPISYWANIE HISTORII DLA OPCJA 3
{
    if (rozgrywka == 3)

    {
        if (poczatek != NULL)
        {
            historia_ruchow_niestandardowa_plansza(poczatek->nastepny, ile, rozgrywka);
            ile++;
            cout << ile << ".TURA --> Wspolrzedne: (" << poczatek->x << "," << poczatek->y << ")" << "-->RUCH WYKONAL:" << poczatek->gracz;
            cout << endl;
        }

    }

    else if (rozgrywka == 1 || rozgrywka == 2)
    {
        if (poczatek != NULL)
        {
            historia_ruchow_niestandardowa_plansza(poczatek->nastepny, ile, rozgrywka);
            ile++;
            cout << ile << ".TURA --> POLE:" << poczatek->ruch << "-->RUCH WYKONAL:" << poczatek->gracz;
            cout << endl;
        }


    }


}
//---------------------------------------------------------------------------------------------------


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
void Petla(char& wybor, char& Gracz, Lista*& glowa, Niestandardowa*& poczatek, int& rozgrywka)//FUNKCJA ZAPETLAJACA MENU GLOWNE//GUI
{
    while (true)
    {
        menu(wybor, glowa);//JEZELI CHCESZ WYJSC Z GRY TO PO PROSTU WCISNIJ OPCJE 5
        warunek(wybor, Gracz, glowa, poczatek, rozgrywka);
    }

}
