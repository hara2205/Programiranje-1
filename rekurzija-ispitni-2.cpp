/*Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog dinamičkog niza integer vrijednosti (n > 2).
*
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva 1, 3, 3, 9, 27, ..., tako da je svaki slijedeći broj jednak umnosku dva
prethodna broja (Prva dva elementa su 1 i 3.) Rekurzija se prekida kad se popuni cijeli niz ili kad se desi overflow na integer varijabli.

Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza (Voditi računa o tipu podataka zbog veličine broja).

U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača*/

#include <iostream>
using namespace std;


void PopuniNiz(int* niz, int n, int brojac = 2, int i = 2)
{
    *(niz + 0) = 1;
    *(niz + 1) = 3;

    if (brojac == n)
        return;


    int vrijednost1 = *(niz + (i - 1));

    int vrijednost2 = *(niz + (i - 2));


    int broj = vrijednost1 * vrijednost2;

    if (broj > INT_MAX)
        return;
    if (broj < 0)
        return;


    *(niz + i) = broj;


    PopuniNiz(niz, n, brojac + 1, i + 1);

}
void Ispis(int* niz, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(niz + i) << endl;
    }
}

void IzracunajZbir(int* niz, int n, int brojac = 0, int i = 0, int sumaNiza = 0)
{
    if (brojac == n)
    {
        cout << "Suma niza je: " << sumaNiza << endl;
        return;
    }
    sumaNiza += *(niz + i);

    IzracunajZbir(niz, n, brojac + 1, i + 1, sumaNiza);
}
int main()
{
    int n;
    do
    {

        cout << "Unesite velicinu niza: ";
        cin >> n;

    } while (n <= 2);

    int* niz = new int[n] {};
    PopuniNiz(niz, n);
    Ispis(niz, n);
    IzracunajZbir(niz, n);

    system("Pause>0");
    return 0;
}

