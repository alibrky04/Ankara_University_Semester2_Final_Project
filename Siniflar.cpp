//Ali Berkay Gorgulu | 22290421

#include <iostream>//Input ve output islemleri icin kullanildi
#include <string>//string degisken turu icin kullanildi
#include "siniflar.h"//Siniflarin tanimlarina erismek icin kullanildi

using namespace std;

string Karakter::getIsim() {
	return karakter_isim;
}

int Karakter::getButce() {
	return butce;
}

void Karakter::setIsim() {
	do {
		cout << "Isminiz: ";
		cin >> karakter_isim;

		if (karakter_isim.size() < 3 || karakter_isim.size() > 15) {
			cout << endl << "Lutfen 3-15 karakter araliginda bir isim giriniz" << endl << endl;
		}
	} while (karakter_isim.size() < 3 || karakter_isim.size() > 15);

	cout << endl;
}

int& Karakter::setButce() {
	return butce;
}

void Karakter::gosterKarakterBilgi() {
	cout << "|Karakter Bilgileri|" << endl;
	cout << "Ad: " << karakter_isim << endl;
	cout << "Butce: " << butce << " TL" << endl << endl;
}

string Esya::getIsim() {
	return esya_isim;
}

int Esya::getFiyat() {
	return esya_fiyat;
}

int Esya::getTier() {
	return tier;
}

string Konteyner::getIsim() {
	return konteyner_isim;
}

int Konteyner::getFiyat() {
	return konteyner_fiyat;
}

Esya* Konteyner::getEsyalar() {
	return esyalar;
}