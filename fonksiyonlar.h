//Ali Berkay Gorgulu | 22290421

#pragma once

#include <vector>//vector turunde fonksiyon ve parametrelerin tanimlanmasi icin kullanildi
#include "siniflar.h"//Siniflarin tanimlarina erismek icin kullanildi

using namespace std;

void gizli_menu(Karakter karakter);//Esya ve Konteyner siniflarindan bazi objeler olusturulmak ve ana_menu fonksiyonunu cagirmak icin kullanilir

void ana_menu(Karakter karakter, vector<Esya>& esyalar, vector<Konteyner>& bos_konteynerler);//Konteyner alinimi ve konteyner tur secimi islemleri yapilir, acKonteyner fonksiyonu cagrilir

void okuKurallar();//kurallar.txt dosyasinin okunmasini saglar

void yapCikis();//Programdan bir mesaj ile cikis yapilmasini saglar

vector<Esya> olusturEsyalar();//Esya sinifindan objelerin, konteyner esyalari, olusturulmasini saglar

vector<Konteyner> olusturBosKonteyner();//Konteyner sinifindan bos_konteyner objesinin olusturulmasini saglar

void acKonteyner(Karakter& karakter, vector<Esya>& esyalar, vector<Konteyner> bos_konteynerler, int numara);//Secilen turde konteynerlerin olusturulmasini ve bu konteynerlerin acilmasini saglar

void sonlandirProgram();//Programin kendini kapatmasini saglar