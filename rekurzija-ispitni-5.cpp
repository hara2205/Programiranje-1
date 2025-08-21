/*Napišite program koji od korisnika traži da unese broj u opsegu od 6 do 100 (uključujući granične
vrijednosti). Nakon što korisnik unese broj, program treba rekurzivno računati zbir svih njegovih
djelitelja (uključujući broj i 1).

Zbir djelitelja broja se računa sve dok ne dođemo do broja koji je djeljiv
sa 4. Nakon toga, ispišite rezultat

Primjer:

Djelitelji broja 17: 1, 17
Zbir: 1 + 17 = 18
Broj 18 nije djeljiv sa 4, pa računamo djelitelje broja 18.

Djelitelji broja 18: 1, 2, 3, 6, 9, 18
Zbir: 1 + 2 + 3 + 6 + 9 + 18 = 39
Broj 39 nije djeljiv sa 4, pa računamo djelitelje broja 39.
Djelitelji broja 39: 1, 3, 13, 39
Zbir: 1 + 3 + 13 + 39 = 56
Broj 56 je djeljiv sa 4, pa završavamo.


OBAVEZNO KORISTITI REKURZIVNE FUNKCIJE*/




#include <iostream>
using namespace std;

void IzracunajZbirDjeljitelja(int broj, int i = 1, int sumaDjeljitelja = 0)
{
    if (i > broj)
    {
        if (sumaDjeljitelja % 4 == 0) {
            cout << "Suma djeljitelja je: " << sumaDjeljitelja << endl;
            return;
        }
        else {
            return IzracunajZbirDjeljitelja(sumaDjeljitelja);
        }
    }
    if (broj % i == 0)
    {
        sumaDjeljitelja += i;
    }
    IzracunajZbirDjeljitelja(broj, i + 1, sumaDjeljitelja);
}

int main()
{

    int broj;
    do
    {
        cout << "Unesite broj: ";
        cin >> broj;

    } while (!(broj>=6 && broj<=100));
    
    IzracunajZbirDjeljitelja(broj);
    system("Pause>0");
    return 0;
}

