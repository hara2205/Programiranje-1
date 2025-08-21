/*Napisite program koji trazi da unesete broj koji je u opsegu od 100 do 100 000 (ukljucujuci i granicne vrijednosti).
* 
Nakon sto korisnik unese broj, rekurzivno sabirete znamenke broja. Ako dobiveni

rezultat zbira znamenki broja je veci od broj 10 (npr. Broj 546 = 5 + 4 + 6 = 15),

nastavite sabirati znamenke novog broja (15 = 1 + 5 = 6), sve dok ne dobijete rezultat koji je manji od 10.*/

#include <iostream>
using namespace std;

int saberiCifre(int broj, int sumaCifara = 0)
{
    if (broj == 0) {
        if (sumaCifara <= 10) {
            return sumaCifara;
        }
        else
        {
            return saberiCifre(sumaCifara);
        }
    }
    int cifra = broj % 10;
    sumaCifara += cifra;

    saberiCifre(broj / 10, sumaCifara);
}

int main()
{
    int broj;
    do
    {
        cout << "Unesite broj izmedju 100 i 100 000: ";
        cin >> broj;
    } while (!(broj>=100 && broj<=100000));

    cout << "Suma cifara unesenog broja je: " << saberiCifre(broj);
    system("Pause>0");
    return 0;
}

