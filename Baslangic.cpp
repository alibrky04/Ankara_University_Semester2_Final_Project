//Ali Berkay Gorgulu | 22290421

#include <iostream> //Input ve output islemleri icin kullanildi
#include "siniflar.h"//Siniflarin tanimlarina erismek icin kullanildi
#include "fonksiyonlar.h"//Fonksiyon tanimlarina erismek icin kullanildi

using namespace std;

int main() {

    char login_secim{};//Giriste yapilan secim icin bir degisken

    cout << "\t\t\t  Lucky Container'a Hos Geldiniz!" << endl << endl;

    do {
        cout << "\t\t\t\tBaslamak icin b/B" << endl;
        cout << "\t\t\t     Kurallari gormek icin k/K" << endl;
        cout << "\t\t\t      Cikis yapmak icin c/C" << endl;
        cout << "\t\t\t\t  Tercihiniz:";
        cin >> login_secim;

        cout << endl;

        //Girilen karaktere gore ilgili fonksiyon cagrilir
        if (login_secim == 'b' || login_secim == 'B') {
            Karakter karakter;
            gizli_menu(karakter);
        }

        else if (login_secim == 'k' || login_secim == 'K') {
            okuKurallar();
        }

        else if (login_secim == 'c' || login_secim == 'C') {
            yapCikis();
        }

        else {
            cout << "\t\t\t     Hatali bir girdi yaptiniz!" << endl << endl;
        }
    } while (login_secim != 'b' && login_secim != 'B' && login_secim != 'c' && login_secim != 'C');//Girilen karakter 'k', 'K' veya yanlis ise dongu devam eder 

    return 0;
}