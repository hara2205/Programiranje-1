/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.* 
* 
Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., 
tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2. 

Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača*/

#include <iostream>
using namespace std;

void PopuniNiz(int* niz, int velicinaNiza, int i=0, int brojac=0, int vrijednost=1)
{
    if (brojac == velicinaNiza)
        return;

    vrijednost = vrijednost * 2;

    if (vrijednost > INT_MAX)
        return;
    if (vrijednost < 0)
        return;
    *(niz + i) = vrijednost;

    PopuniNiz(niz, velicinaNiza, i + 1, brojac + 1, vrijednost);
}

void IspisNiza(int* niz, int velicinaNIza)
{
    for (int i = 0; i < velicinaNIza; i++)
    {
        cout << *(niz + i) << endl;
    }
}

int main()
{
    int velicinaNiza = 0;

    do
    {

        cout << "Unesite velicinu niza: ";
        cin >> velicinaNiza;

    } while (velicinaNiza<=0);

    int* niz = new int[velicinaNiza] {};
    PopuniNiz(niz, velicinaNiza);
    IspisNiza(niz, velicinaNiza);
    


    system("Pause>0");
    return 0;
}

