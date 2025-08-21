/*Napisite program koji trazi da kreirate dinamicki niz velicine koju korisnik odredi (od 1 do 50).


Nakon sto korisnik unese velicinu, rekurzivno unesite elemente u niz (koristite radn() funkciju).

Potom rekurzivnom funkcijom pronadite najveci broj u nizu, najmanji broj u nizu i ispisite prosjek niza

(mozete koristiti vise rekurzivnih funkcija).

ZABRANJENO JE KORISTITI UGLASTE ZAGRADE. OBAVEZNO KORISTITI ARITMETIKU POKAZIVACA. OBAVEZNO KORISTITI REKURZIVNE FUNKCIJE*/


#include <iostream>
using namespace std;

void PopuniNiz(int* niz, int velicinaNiza, int brojac = 0, int i = 0)
{
    if (velicinaNiza == brojac)
        return;
    int broj;
    
    do
    {
        broj = rand();
    } while (!(broj<=INT_MAX && broj>=INT_MIN));

    *(niz + i) = broj;
    PopuniNiz(niz, velicinaNiza, brojac + 1, i + 1);
}

void Ispis(int* niz, int velicinaNiza)
{
    for (int i = 0; i < velicinaNiza; i++)
    {
        cout << *(niz + i) << endl;
    }
}

int pronadjiNajveci(int* niz, int velicinaNiza, int brojac = 0, int i = 0,int najveci=INT_MIN)
{
    if (velicinaNiza == brojac)
        return najveci;
    if((*(niz+i))>najveci)
    {
        najveci = *(niz + i);
    }
    pronadjiNajveci(niz, velicinaNiza, brojac + 1, i + 1, najveci);
}

int pronadjiNajmanji(int* niz, int velicinaNiza, int brojac = 0, int i = 0, int najmanji = INT_MAX)
{
    if (velicinaNiza == brojac)
        return najmanji;
    if ((*(niz + i)) < najmanji)
    {
        najmanji = *(niz + i);
    }
    pronadjiNajmanji(niz, velicinaNiza, brojac + 1, i + 1, najmanji);
}

void IspisProsjeka(int* niz, int velicinaNiza, int brojac = 0, int i = 0, float suma=0)
{
    if (velicinaNiza == brojac)
    {
        cout << "Prosjek niza je: " << suma / brojac << endl;
        return;
    }
    suma += *(niz + i);
    IspisProsjeka(niz, velicinaNiza, brojac + 1, i + 1, suma);
}
int main()
{
    int velicinaNiza = 0;
    do
    {
        cout << "Unesite velicinu niza: " << endl;
        cin >> velicinaNiza;

    } while (!(velicinaNiza>=1 && velicinaNiza<=50));

    int* niz = new int[velicinaNiza] {};
    PopuniNiz(niz, velicinaNiza);
    Ispis(niz, velicinaNiza);
    cout << "Najveci element niza je: " << pronadjiNajveci(niz, velicinaNiza)<<endl;
    cout << "Najmanji element u nizu je: " << pronadjiNajmanji(niz, velicinaNiza)<<endl;
    IspisProsjeka(niz, velicinaNiza);
    system("Pause>0");
    return 0;
}

