//Ali Berkay Gorgulu | 22290421

#include <iostream>//Input ve output islemleri icin kullanildi
#include <fstream>//.txt dosyalariyla ilgili islemler icin kullanildi
#include <chrono>//okuKurallar fonksiyonunda yazdirma sirasinda beklenilmek istenen zaman icin kullanildi
#include <thread>//okuKurallar fonksiyonunda yazdirma sirasinda beklemenin yapilmasi icin kullanildi
#include <vector>//Vektor olusturmak icin kullanildi
#include <cstdlib>//rand ve srand fonksiyonlari icin kullanildi
#include <time.h>//srand fonksiyonu icerisinde zamani belirtmek icin kullanildi
#include <string>//string turunden degiskenler olusturmak icin ve stoi fonksiyonu kullanildi
#include "fonksiyonlar.h"//Fonksiyon tanimlarina erismek icin kullanildi
#include "siniflar.h"//Siniflarin tanimlarina erismek icin kullanildi

constexpr auto ESYA_SAYISI = 100;//Uygulamada bulunan esya sayisini belirtmek icin kullanildi
constexpr auto BOS_KONTEYNER_SAYISI = 5;//Uygulamada bulunan konteyner turunu belirtmek icin kullanildi
constexpr auto DOLU_KONTEYNER_SAYISI = 3;//Bir tur secildiginde kullanici icin rastgele yaratilan konteyner sayisi icin kullanildi
constexpr auto KONTEYNER_ESYA_SAYISI = 10;//Gosterilen konteynerlerde bulunmasi gereken esya sayisi. Bu sayi degistirilirse Konteyner sinifinda bulunan esyalar objesinin sayisi da degistirilmelidir
constexpr auto GOSTERILEN_ESYA_SAYISI = 3;//Konteynerlerin gosterilen esya sayisi

using namespace std;

void gizli_menu(Karakter karakter) {
	vector<Esya> esyalar = olusturEsyalar();//Fonksiyondan return edilen obje Esya sinifindan bir vektore aktarilir

	vector<Konteyner> bos_konteynerler = olusturBosKonteyner();//Fonksiyondan return edilen obje Konteyner sinifindn bir vektore aktarilir
	
	ana_menu(karakter, esyalar, bos_konteynerler);//ana_menu fonksiyonu cagrilir
}

void ana_menu(Karakter karakter, vector<Esya>& esyalar, vector<Konteyner>& bos_konteynerler) {
	char baslama_secim;//Alip almama secimi icin kullanilan degisken
	int konteyner_secim;//Konteyner numarasi icin degisken

	karakter.setIsim();//karakter objesinin isim degeri kullanicidan alinir

	do {
		karakter.gosterKarakterBilgi();

		cout << "|Konteynerlar|" << endl;
		cout << "1) " << bos_konteynerler[0].getIsim() << " \t | " << bos_konteynerler[0].getFiyat() << " TL" << endl;
		cout << "2) " << bos_konteynerler[1].getIsim() << " \t | " << bos_konteynerler[1].getFiyat() << " TL" << endl;
		cout << "3) " << bos_konteynerler[2].getIsim() << " \t | " << bos_konteynerler[2].getFiyat() << " TL" << endl;
		cout << "4) " << bos_konteynerler[3].getIsim() << " \t | " << bos_konteynerler[3].getFiyat() << " TL" << endl;
		cout << "5) " << bos_konteynerler[4].getIsim() << " \t | " << bos_konteynerler[4].getFiyat() << " TL" << endl;
		cout << "Konteyner almak icin a/A, cikis yapmak icin c/C karakterlerini giriniz:";
		cin >> baslama_secim;

		cout << endl;

		if (baslama_secim == 'a' || baslama_secim == 'A') {
			cout << "Bakmak istediginiz konteyner turunun numarasini giriniz:";
			cin >> konteyner_secim;

			cout << endl;

			if (konteyner_secim != 1 && konteyner_secim != 2 && konteyner_secim != 3 && konteyner_secim != 4 && konteyner_secim != 5) {
				cout << "Hatali bir girdi yaptiniz!" << endl << endl;
			}
			else {
				//karakterin butce degiskeninin secilen konteyner turunden buyuk ya da esit olup olmadigi kontrol edilir
				if (karakter.getButce() >= bos_konteynerler[konteyner_secim - 1].getFiyat()) {
					acKonteyner(karakter, esyalar, bos_konteynerler, konteyner_secim);
				}
				else {
					cout << "Butceniz bu turun konteynerlarini gormek icin yeterli degil" << endl << endl;
				}
			}
		}
		else if (baslama_secim == 'c' || baslama_secim == 'C') {
			yapCikis();
		}
		else {
			cout << "Hatali bir girdi yaptiniz!" << endl << endl;
		}
	} while (baslama_secim == 'a' || baslama_secim == 'A' || baslama_secim != 'c' && baslama_secim != 'C');//baslama_secim degiskeninin degeri 'c', 'C' veya yanlis degilse dongu devam eder
}

void okuKurallar() {
	ifstream kurallar("kurallar.txt");//kurallar.txt dosyasini parametre olarak alan obje

	//kurallar.txt dosyasinin var olup olmadigi kontrol edilir
	if (kurallar.is_open()) {
		char harf{};//kurallar.txt'nin harf harf okunmasini saglayan degisken
		while (kurallar.get(harf)) {
			this_thread::sleep_for(chrono::milliseconds(10));
			cout << harf;
		}

		kurallar.close();

		cout << endl << endl;
	}

	else {
		cout << "kurallar.txt adli dosya bulunamadi/acilamadi!" << endl << endl;
		sonlandirProgram();
	}
}

void yapCikis() {
	cout << "Gorusmek Uzere, Iyi Gunler!";
}

vector<Esya> olusturEsyalar() {
	vector<Esya> esyalar(ESYA_SAYISI);//Esya sinifindan olusturulan vector turunden obje

	ifstream isimler("esya_isimler.txt");//esya_isimler.txt dosyasini parametre olarak alan obje

	//esya_isimler.txt dosyasinin var olup olmadigi kontrol edilir
	if (isimler.is_open()) {
		//esya_isimler.txt dosyasinin her satirdaki isimler, indeksi satir numarasindan 1 eksik olan esyalar objesinin esya_isim degiskenine aktarilir
		for (int i = 0; i < ESYA_SAYISI; i++) {
			getline(isimler, esyalar[i].esya_isim);
		}
	}

	else {
		cout << "esya_isimler.txt adli dosya bulunamadi/acilamadi!" << endl << endl;
		sonlandirProgram();
	}

	isimler.close();

	ifstream fiyatlar("esya_fiyatlar.txt");//esya_fiyatlar.txt dosyasini parametre olarak alan obje

	string satir;//esya_fiyatlar.txt dosyasinin her satirini almaj icin kullanilan degisken

	if (fiyatlar.is_open()) {
		for (int i = 0; i < ESYA_SAYISI && getline(fiyatlar, satir); i++) {
			esyalar[i].esya_fiyat = stoi(satir);//Satirda bulunan string int turune cevrilir ve indeksi satir numarasindan 1 eksik olan esyalar objesinin esya_fiyat degiskenine aktarilir
		}
	}

	else {
		cout << "esya_fiyatlar.txt adli dosya bulunamadi/acilamadi!" << endl << endl;
		sonlandirProgram();
	}

	fiyatlar.close();

	//esyalar objesinin butun indekslerindeki tier degiskeni fiyatlarina gore belirlenir
	for (int i = 0; i < ESYA_SAYISI; i++) {
		if (esyalar[i].esya_fiyat < 500) {
			esyalar[i].tier = 1;
		}
		else if (esyalar[i].esya_fiyat < 1500) {
			esyalar[i].tier = 2;
		}
		else if (esyalar[i].esya_fiyat < 4000) {
			esyalar[i].tier = 3;
		}
		else if (esyalar[i].esya_fiyat < 8000) {
			esyalar[i].tier = 4;
		}
		else {
			esyalar[i].tier = 5;
		}
	}

	return esyalar;
}

vector<Konteyner> olusturBosKonteyner() {
	//Konteyner turunden olusturulan vector turunden obje
	//Bu obje konteyner isimlerinin ve fiyatlarinin gosterilmesi icin kullanilir
	vector<Konteyner> bos_konteynerler(BOS_KONTEYNER_SAYISI);

	//Isimler ve fiyatlar gelistirici tarafindan belirlenir
	bos_konteynerler[0].konteyner_isim = "Baslangic Seviye Konteyner";
	bos_konteynerler[0].konteyner_fiyat = 1750;

	bos_konteynerler[1].konteyner_isim = "Orta Seviye Konteyner";
	bos_konteynerler[1].konteyner_fiyat = 6000;

	bos_konteynerler[2].konteyner_isim = "Ileri Seviye Konteyner";
	bos_konteynerler[2].konteyner_fiyat = 15000;

	bos_konteynerler[3].konteyner_isim = "Usta Seviye Konteyner";
	bos_konteynerler[3].konteyner_fiyat = 45000;

	bos_konteynerler[4].konteyner_isim = "Efsane Seviye Konteyner";
	bos_konteynerler[4].konteyner_fiyat = 100000;

	return bos_konteynerler;
}

void acKonteyner(Karakter& karakter, vector<Esya>& esyalar, vector<Konteyner> bos_konteynerler, int numara) {
	srand(time(NULL));//Tam rastgelelik icin srand fonksiyonu
	
	//doluluk bir konteynerin dolup dolmadigini kontrol icin, i genel indeksler icin, konteyner_no dolu_konteyer objesinin indeksleri icin kullanildi
	//esya_sira konteyner icindeki esyanin indeksi icin, gosterilen_esya bir konteynerin ilk 3 esyasinin gosterilmesinde kullanildi
	int doluluk = 0, i, konteynor_no = 0, esya_sira = 0, gosterilen_esya = 0;

	//alim_secim gosterilen konteynerin alinmak istenip istenmedigini kullanicidan almak icin kullanildi
	char alim_secim;
	
	vector<Konteyner> dolu_konteyner(DOLU_KONTEYNER_SAYISI);//Kullaniciya gosterilecek konteynerler
	
	//Konteynerlerin olusturulmasi icin kullanilan algoritma
	while (konteynor_no < DOLU_KONTEYNER_SAYISI) {
		while (doluluk < KONTEYNER_ESYA_SAYISI) {
			i = rand() % ESYA_SAYISI;//Uygulamada bulunan esyalar arasindan biri icin rastgele bir indeks olusturulur, 0 ile ESYA_SAYISI arasinda
			if (esyalar[i].getTier() == numara) {//Secilen esya secilen konteyner turune ait mi diye kontrol edilir, eger sonuc true ise esya konteynere eklenir
				dolu_konteyner[konteynor_no].getEsyalar()[esya_sira] = esyalar[i];
				doluluk++;
				esya_sira++;
			}
		}
		konteynor_no++;//Sonraki konteynerin olup olmadiginin kontrolü icin konteyner_no bir arttirilir
		doluluk = 0;//Sonraki konteynerde bastan baslanmasi icin doluluk sifirlanir
		esya_sira = 0;//Sonraki konteynerde bastan baslanmasi icin esya_sira sifirlanir
	}

	konteynor_no = 0;//Acma dongusunde de kullanmak icin konteyner_no sifirlanir
	i = 0;//Acma dongusunde de kullanmak icin i sifirlanir

	//Konteynerlerin gosterilip kullanici istegine gore acilmasi icin kullanilan algoritma
	while (konteynor_no < DOLU_KONTEYNER_SAYISI) {
		karakter.gosterKarakterBilgi();//Her yeni konteyner gosterilmeden once karakter objesindeki degiskenler ekrana bastirilir

		cout << "|" << konteynor_no + 1 << ". Konteynerin Icerigi|" << endl;//Konteynerin icerigi icin bir baslik

		//Sirasiyla gosterilen konteynerdeki ilk uc esya gosterilir. Gosterilen esya sayisi GOSTERILEN_ESYA_SAYISI degiskenine baglidir
		while (gosterilen_esya < GOSTERILEN_ESYA_SAYISI) {
			cout << gosterilen_esya + 1 << ". Esya: " << dolu_konteyner[konteynor_no].getEsyalar()[i].getIsim() << " ";
			cout << dolu_konteyner[konteynor_no].getEsyalar()[i].getFiyat() << " TL" << endl;
			gosterilen_esya++;
			i++;
		}
		//Esyalar gosterildikten sonra kullaniciya gosterilen konteyneri almak isteyip istemedigi sorulur
		cout << "Bu Konteyneri almak ister misiniz? (" << bos_konteynerler[numara-1].getFiyat() << " TL)" << endl;//bos_konteynerler[numara-1].getFiyat() yapisi secilen konteyner turunun fiyati icindir
		cout << "Evet icin e/E, Hayir icin h/H karakterlerini giriniz:";
		cin >> alim_secim;
		cout << endl;

		if (alim_secim == 'e' || alim_secim == 'E') {
			if (karakter.getButce() >= bos_konteynerler[numara-1].getFiyat()) {//karakter objesinin butce degiskeni secilen konteyner turunun fiyatini karsilayip karsilamadigi kontrol edilir
				karakter.setButce() -= bos_konteynerler[numara - 1].getFiyat();//karakter objesindeki butce degiskeninin degeri secilen konteyner turunun fiyati kadar azaltilir

				char satim_secim;//Acilan konteynerdeki esyanin satilmak istenip istenmedigini kontrol etmek icin  kullanilir
				
				//Alinan konteynerdeki esyalarin isim ve fiyatlarinin tek tek gosterilmesini ve satilmasini veya saklanmasini saglayan algoritma
				for (int x = 0; x < KONTEYNER_ESYA_SAYISI; x++) {
					karakter.gosterKarakterBilgi();//Her esya gosterilmeden once karakter objesindeki degiskenler ekrana bastirilir

					//Esya gosterilir ve satmak istenip istenmedigi sorulur
					cout << x + 1 << ". Esya: " << dolu_konteyner[konteynor_no].getEsyalar()[x].getIsim() << " ";
					cout << dolu_konteyner[konteynor_no].getEsyalar()[x].getFiyat() << " TL" << endl;
					cout << "Bu esyayi satmak ister misiniz?" << endl;
					cout << "Evet icin e/E, Hayir icin h/H karakterlerini giriniz:";
					cin >> satim_secim;

					cout << endl;

					if (satim_secim == 'e' || satim_secim == 'E') {
						karakter.setButce() += dolu_konteyner[konteynor_no].getEsyalar()[x].getFiyat();//karakter objesinin butce degiskeni esya fiyati kadar arttirilir
						cout << "Esya Satildi";
					}
					else if (satim_secim == 'h' || satim_secim == 'H') {
						cout << "Esya saklandi";
					}
					else {
						cout << "Hatali bir girdi yaptiniz!";
						x--;
					}
					cout << endl << endl;
				}
			}
			else {
				cout << "Butceniz bu konteyneri almak icin yeterli degildir" << endl << endl;
			}

			if (konteynor_no + 1 < DOLU_KONTEYNER_SAYISI) {
				cout << "Siradaki Konteyner Gosteriliyor" << endl << endl;
			}
		}
		else if (alim_secim == 'h' || alim_secim == 'H') {
			if (konteynor_no + 1 < DOLU_KONTEYNER_SAYISI) {
				cout << "Siradaki Konteyner Gosteriliyor" << endl << endl;
			}
		}
		else {
			cout << "Hatali bir girdi yaptiniz!" << endl << endl;
			konteynor_no--;//Hatali girdi yapilirsa ayni konteynerin gosterilmesi icin konteyner_no bir azaltilir
		}

		i = 0;//Gosterilen esyalarin bastan baslamasi icin i sifirlanir
		gosterilen_esya = 0;//Gosterilen esyalarin bastan baslamasi icin gosterilen_esya sifirlanir
		konteynor_no++;//Siradaki konteynere gecilmesi icin konteyner_no bir arttirilir
	}
}

void sonlandirProgram() {
	return;
}