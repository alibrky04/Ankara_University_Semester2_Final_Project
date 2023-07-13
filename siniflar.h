//Ali Berkay Gorgulu | 22290421

#pragma once

#include <vector>//vector degisken turu icin kullanildi
#include <string>//string degisken turu icin kullanildi

//fonksiyonlar.h dosyasinda bulunan fonksiyon tanimlarina erismek icin kullanilan bir algoritma, dongu olusmamasi icin kullanildi
#ifndef FONKSIYONLAR_H
#define FONKSIYONLAR_H

using namespace std;

//Kullaniciyi simgeleyen bir sinif
class Karakter {
private:
	string karakter_isim;//Karakterin ismidir
	int butce = 3000;//Karakterin butcesidir
public:
	string getIsim();//Karakterin isim degiskeninin okunmasini saglar
	int getButce();//Karakterin butce degiskeninin okunmasini saglar
	void setIsim();//Karakterin isim degiskeninin degistirilmesini saglar
	int& setButce();//Karakterin butce degiskeninin degistirilmesini saglar
	void gosterKarakterBilgi();//Karakterin isim ve butce degiskenlerinin birlikte ekranda gosterilmesini saglar
};

//Konteynerlerde bulunan esyalar icin bir sinif
class Esya {
private:
	string esya_isim;//Esyanin ismidir
	int esya_fiyat;//Esyanin fiyatidir
	int tier;//Esyanin bulunabilecegi konteyner turudur
public:
	string getIsim();//Esyanin esya_isim degiskeninin okunmasini saglar
	int getFiyat();//Esyanin esya_fiyat degiskeninin okunmasini saglar
	int getTier();//Esyanin tier degiskeninin okunmasini saglar

	friend vector<Esya> olusturEsyalar();//olusturEsyalar fonksiyonunun private degiskenlere erismesine izin verir
};

//Konteynerler icin bir sinif
class Konteyner {
private:
	string konteyner_isim;//Konteynerin ismidir
	int konteyner_fiyat;//Konteynerin fiyatidir
	Esya esyalar[10];//Konteyner icinde bulunan esyalardir
public:
	string getIsim();//Konteynerin konteyner_isim degiskeninin okunmasini saglar
	int getFiyat();//Konteynerin konteyner_fiyat degiskeninin okunmasini saglar
	Esya* getEsyalar();//Konteynerin esyalar objesinin okunmasini saglar

	friend vector<Konteyner> olusturBosKonteyner();//olusturBosKonteyner fonksiyonunun private degiskenlere erismesine izin verir
};

#endif