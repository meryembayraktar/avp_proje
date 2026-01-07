#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

// Fonksiyon prototipleri
void menuYazdir();
void serbestDusmeDeneyi(double*, char**, int);
void yukariAtisDeneyi(double*, char**, int);
void agirlikDeneyi(double*, char**, int);
void potansiyelEnerjiDeneyi(double*, char**, int);
void hidrostatikBasincDeneyi(double*, char**, int);
void arsimetDeneyi(double*, char**, int);
void basitSarkacDeneyi(double*, char**, int);
void ipGerilmesiDeneyi(double*, char**, int);
void asansorDeneyi(double*, char**, int);

int main() {
    char bilimInsaniAdi[50];
    int deneySecimi;

    // Gezegenlerlerin gunese yakinligina gore siralanmasi
    char *gezegenIsimleri[] = {
        "Merkur", "Venus", "Dunya", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptun"
    };

    double yercekimiIvmeleri[] = {
        3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15
    };

    int gezegenSayisi = 8;

    // Bilim insani adi girisi
    printf("Bilim insaninin adini giriniz: ");
    scanf(" %49[^\n]", bilimInsaniAdi);

    printf("\nHos geldiniz %s!\n", bilimInsaniAdi);

    while (1) {
        menuYazdir();
        printf("Seciminiz: ");
        scanf("%d", &deneySecimi);

        //cikis icin kontrol
        if (deneySecimi == -1) {
            printf("\nProgram sonlandirildi.\n");
            break;
        }

        switch (deneySecimi) {
            case 1: serbestDusmeDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 2: yukariAtisDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 3: agirlikDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 4: potansiyelEnerjiDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 5: hidrostatikBasincDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 6: arsimetDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 7: basitSarkacDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 8: ipGerilmesiDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            case 9: asansorDeneyi(yercekimiIvmeleri, gezegenIsimleri, gezegenSayisi); break;
            default:
                printf("Hatali secim! Lutfen 1-9 arasi veya -1 giriniz.\n");
        }
    }

    return 0;
}

void menuYazdir() {
    printf("\n--- DENEY MENUSU ---\n");
    printf("1 - Serbest Dusme Deneyi\n");
    printf("2 - Yukari Atis Deneyi\n");
    printf("3 - Agirlik Deneyi\n");
    printf("4 - Potansiyel Enerji Deneyi\n");
    printf("5 - Hidrostatik Basinc Deneyi\n");
    printf("6 - Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7 - Basit Sarkac Deneyi\n");
    printf("8 - Sabit Ip Gerilmesi Deneyi\n");
    printf("9 - Asansor Deneyi\n");
    printf("-1 - Cikis\n");
}

/* 1-Serbest dusme deneyi */
void serbestDusmeDeneyi(double *g, char **isim, int n) {
    double t;
    printf("\nKullanilan formul: h = 1/2 * g * t^2\n");
    printf("Sure (saniye): ");
    scanf("%lf", &t);
    t = (t < 0) ? -t : t; // Ternary operatör kullanimi

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde alinan yol: %.2f metre\n",
               *(isim + i), 0.5 * *(g + i) * t * t);   // Pointer aritmetigi
}

/* 2-Yukari atis deneyi */
void yukariAtisDeneyi(double *g, char **isim, int n) {
    double v;
    printf("\nKullanilan formul: h_max = v^2 / (2 * g)\n");
    printf("Ilk hiz (m/s): ");
    scanf("%lf", &v);
    v = (v < 0) ? -v : v;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde maksimum yukseklik: %.2f metre\n",
               *(isim + i), (v * v) / (2 * *(g + i)));
}

/* 3-Agirlik deneyi */
void agirlikDeneyi(double *g, char **isim, int n) {
    double m;
    printf("\nKullanilan formul: G = m * g\n");
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? -m : m;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde agirlik: %.2f Newton\n",
               *(isim + i), m * *(g + i));
}

/* 4-Potansiyel enerji deneyi */
void potansiyelEnerjiDeneyi(double *g, char **isim, int n) {
    double m, h;
    printf("\nKullanilan formul: Ep = m * g * h\n");
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Yukseklik (m): ");
    scanf("%lf", &h);
    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde potansiyel enerji: %.2f Joule\n",
               *(isim + i), m * *(g + i) * h);
}

/* 5-Hidrostatik basinc deneyi */
void hidrostatikBasincDeneyi(double *g, char **isim, int n) {
    double rho, h;
    printf("\nKullanilan formul: P = rho * g * h\n");
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Derinlik (m): ");
    scanf("%lf", &h);
    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde hidrostatik basinc: %.2f Pascal\n",
               *(isim + i), rho * *(g + i) * h);
}

/* 6-Arsimet deneyi */
void arsimetDeneyi(double *g, char **isim, int n) {
    double rho, V;
    printf("\nKullanilan formul: F = rho * g * V\n");
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Batan hacim (m^3): ");
    scanf("%lf", &V);
    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde kaldirma kuvveti: %.2f Newton\n",
               *(isim + i), rho * *(g + i) * V);
}

/* 7-Basit sarkac deneyi */
void basitSarkacDeneyi(double *g, char **isim, int n) {
    double L;
    printf("\nKullanilan formul: T = 2pi * sqrt(L / g)\n");
    printf("Ip uzunlugu (m): ");
    scanf("%lf", &L);
    L = (L < 0) ? -L : L;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde periyot: %.2f saniye\n",
               *(isim + i), 2 * PI * sqrt(L / *(g + i)));
}

/* 8-Sabit Ip gerilmesi deneyi */
void ipGerilmesiDeneyi(double *g, char **isim, int n) {
    double m;
    printf("\nKullanilan formul: T = m * g\n");
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? -m : m;

    for (int i = 0; i < n; i++)
        printf("%s gezegeninde ip gerilmesi: %.2f Newton\n",
               *(isim + i), m * *(g + i));
}

/* 9-Asansor deneyi */
void asansorDeneyi(double *g, char **isim, int n) {
    double m, a;
    int yon;

    printf("\nKullanilan formuller:\n");
    printf("Yukari ivme: N = m * (g + a)\n");
    printf("Asagi ivme : N = m * (g - a)\n");

    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Asansor ivmesi (m/s^2): ");
    scanf("%lf", &a);
    printf("Yukari Hizlanma/Asagi Yavaslama = 1, Asagi Hizlanma/Yukari Yavaslama = 0: ");
    scanf("%d", &yon);

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    if (yon != 0 && yon != 1) {
        printf("Hatali yon girdiniz!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        double yercekimi = *(g + i);
        if (yon == 1)
            printf("%s gezegeninde hissedilen agirlik: %.2f Newton\n",
                   *(isim + i), m * (yercekimi + a));
        else
            printf("%s gezegeninde hissedilen agirlik: %.2f Newton\n",
                   *(isim + i), (yercekimi - a >= 0) ? m * (yercekimi - a) : 0);
    }
}
