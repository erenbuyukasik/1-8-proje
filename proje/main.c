#include <stdio.h>    // Standart giriş/çıkış işlemleri için kütüphane


#define MAX_PERSONEL 50    // Personel sayısının en fazla 50 olacağına dair sabit tanımlama
#define MAX_NAME 50        // Personel adı uzunluğunun en fazla 50 karakter olacağına dair sabit tanımlama

// Personel bilgilerini tutacak yapı (struct) tanımlaması
typedef struct {
    int sicil;            // Personel sicil numarası
    char ad[MAX_NAME];    // Personel adı
    int satis;            // Personelin yaptığı satış miktarı
} Personel;

int main() {
    FILE *f_in, *f_out;               // Dosya işaretçileri
    Personel personeller[MAX_PERSONEL]; // Personel verilerini tutacak dizi
    int n = 0, i, maxSatis = 0;       // Personel sayısı (n), en yüksek satış miktarı (maxSatis)

    // "yillik.dat" dosyasını açmak için dosya işaretçisi f_in
    if ((f_in = fopen("C:\\Users\\erenb\\CLionProjects\\proje\\yillik.dat", "r")) == NULL) {
        printf("Dosya acilamadi.\n");  // Dosya açılamazsa hata mesajı ver
        return 1;                       // Hata durumunda programdan çık
    }

    // Dosyadan personel verilerini okuma
    while (fscanf(f_in, "%d %s %d", &personeller[n].sicil, personeller[n].ad, &personeller[n].satis) != EOF) {
        if (personeller[n].satis > maxSatis) {
            maxSatis = personeller[n].satis;  // En yüksek satış miktarını bul
        }
        n++;  // Okunan personel sayısını artır
    }
    fclose(f_in);  // Dosyayı kapat

    // "satislar.dat" dosyasını yazmak için açmak
    if ((f_out = fopen("C:\\Users\\erenb\\CLionProjects\\proje\\satislar.dat", "w")) == NULL) {
        printf("Dosya yazmak icin acilamadi.\n");  // Dosya yazılamazsa hata mesajı ver
        return 1;  // Hata durumunda programdan çık
    }

    // Her personel için satış farkını hesapla ve dosyaya yaz
    for (i = 0; i < n; i++) {
        int fark = maxSatis - personeller[i].satis; // En yüksek satıştan mevcut satış miktarını çıkar
        fprintf(f_out, "%d %s %d\n", personeller[i].sicil, personeller[i].ad, fark); // Sonuçları dosyaya yaz
    }
    fclose(f_out);  // Dosyayı kapat

    printf("satislar.dat dosyasina yazildi.\n");  // İşlem tamamlandığında mesaj yaz
    return 0;  // Programı başarıyla sonlandır
}
