#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100

int ovqat[] = {10000, 25000, 30000, 20000, 25000, 25000, 20000, 5000};
char *ovqat_nomi[] = {"Somsa", "Lagmon", "Plov", "Shashlik", "Manti", "Shurva", "Chuchvara", "Non"};

int ichimlik[] = {5000, 10000, 10000, 10000, 10000, 15000, 5000, 20000};
char *ichimlik_nomi[] = {"Choy", "Kofe", "Pepsi", "Fanta", "Sprite", "Sovuq sharbat", "Gazlangan suv", "Energiya ichimligi"};

int salat[] = {20000, 10000, 15000};
char *salat_nomi[] = {"Olivye", "Tuzlangan sabzavotlar", "Pomidor va bodring salatasi"};

int shirinlik[] = {18000, 20000, 25000, 21000};
char *shirinlik_nomi[] = {"Sutli pirog", "Yogurtli muzqaymoq", "Shirin tort", "Biskvit"};

int ovqat_miqdor[MAX_ITEMS] = {0};
int ichimlik_miqdor[MAX_ITEMS] = {0};
int salat_miqdor[MAX_ITEMS] = {0};
int shirinlik_miqdor[MAX_ITEMS] = {0};

void menyu_chiqar(int menu[], char *nomlar[], int hajm) {
    for (int i = 0; i < hajm; i++) {
        printf("%d. %s - %d som\n", i + 1, nomlar[i], menu[i]);
    }
}

void hisobni_chiqarish(int ovqat_narxi, int ichimlik_narxi, int salat_narxi, int shirinlik_narxi,
                       int *ovqat_miqdor, int *ichimlik_miqdor, int *salat_miqdor, int *shirinlik_miqdor) {
    int umumiy_narx = 0;
    float xizmat_haqi = 0.0;
    int jami_narx = 0;
    printf("\nHisob:");

    if (ovqat_narxi > 0) {
        printf("\nOvqatlar:\n");
        for (int i = 0; i < sizeof(ovqat) / sizeof(ovqat[0]); i++) {
            if (ovqat_miqdor[i] > 0) {
                int mahsulot_narx = ovqat[i] * ovqat_miqdor[i];
                printf("%s: %d ta, Har bir donasi: %d som, Jami: %d som\n", ovqat_nomi[i], ovqat_miqdor[i], ovqat[i], mahsulot_narx);
                umumiy_narx += mahsulot_narx;
            }
        }
    }

    if (ichimlik_narxi > 0) {
        printf("\nIchimliklar:\n");
        for (int i = 0; i < sizeof(ichimlik) / sizeof(ichimlik[0]); i++) {
            if (ichimlik_miqdor[i] > 0) {
                int mahsulot_narx = ichimlik[i] * ichimlik_miqdor[i];
                printf("%s: %d ta, Har bir donasi: %d som, Jami: %d som\n", ichimlik_nomi[i], ichimlik_miqdor[i], ichimlik[i], mahsulot_narx);
                umumiy_narx += mahsulot_narx;
            }
        }
    }

    if (salat_narxi > 0) {
        printf("\nSalatlar:\n");
        for (int i = 0; i < sizeof(salat) / sizeof(salat[0]); i++) {
            if (salat_miqdor[i] > 0) {
                int mahsulot_narx = salat[i] * salat_miqdor[i];
                printf("%s: %d ta, Har bir donasi: %d som, Jami: %d som\n", salat_nomi[i], salat_miqdor[i], salat[i], mahsulot_narx);
                umumiy_narx += mahsulot_narx;
            }
        }
    }

    if (shirinlik_narxi > 0) {
        printf("\nShirinliklar:\n");
        for (int i = 0; i < sizeof(shirinlik) / sizeof(shirinlik[0]); i++) {
            if (shirinlik_miqdor[i] > 0) {
                int mahsulot_narx = shirinlik[i] * shirinlik_miqdor[i];
                printf("%s: %d ta, Har bir donasi: %d som, Jami: %d som\n", shirinlik_nomi[i], shirinlik_miqdor[i], shirinlik[i], mahsulot_narx);
                umumiy_narx += mahsulot_narx;
            }
        }
    }

    xizmat_haqi = umumiy_narx * 0.10;
    jami_narx = umumiy_narx + xizmat_haqi;

    if (ovqat_narxi > 0) printf("\nOvqatlar bo'limidan: %d som\n", ovqat_narxi);
    if (ichimlik_narxi > 0) printf("Ichimliklar bo'limidan: %d som\n", ichimlik_narxi);
    if (salat_narxi > 0) printf("Salatlar bo'limidan: %d som\n", salat_narxi);
    if (shirinlik_narxi > 0) printf("Shirinliklar bo'limidan: %d som\n", shirinlik_narxi);
    printf("buyurtma summasi: %d som \n ",ovqat_narxi+ichimlik_narxi+salat_narxi+shirinlik_narxi);
    printf("Xizmat haqi (10%%): %.2f som\n", xizmat_haqi);
    printf("\nUmumiy hisob: %d som\n", jami_narx);
}

void buyurtma_qabul_qilish(int menu[], char *nomlar[], int hajm, int *bolim_narx, int *miqdorlar, int *ovqat_narxi, int *ichimlik_narxi, int *salat_narxi, int *shirinlik_narxi) {
    int tanlov, miqdor;
    char belgi[10];

    while (1) {
        printf("\nMahsulot raqamini kiriting (1-%d) yoki ( * - bo'limlar menyusiga qaytish): ", hajm);
        if (scanf("%9s", belgi) != 1) {
            printf("\nNotog'ri kiritdingiz. Iltimos, qaytadan urinib ko'ring.");
            while (getchar() != '\n') continue;
            continue;
        }

        if (strlen(belgi) != 1 || !strchr("0123456789*", belgi[0])) {
            printf("\nNotog'ri kiritdingiz. Iltimos, faqat 0-%d raqamlarini yoki '*' belgilarini kiriting.", hajm);
            continue;
        }

        if (belgi[0] == '*') {
            return;
        } else if (belgi[0] == '0') {
            printf("\nNotog'ri kiritdingiz. Iltimos, qaytish uchun '*' ni bosing.");
            continue;
        }

        tanlov = belgi[0] - '0';
        if (tanlov < 1 || tanlov > hajm) {
            printf("\nNotog'ri mahsulot raqami. Iltimos, qaytadan urinib ko'ring.");
            continue;
        }

        printf("Miqdorini kiriting:\n ");
        if (scanf("%d", &miqdor) != 1 || miqdor <= 0) {
            printf("\nNotog'ri miqdor. Iltimos, ijobiy son kiriting.");
            while (getchar() != '\n') continue;
            continue;
        }

        miqdorlar[tanlov - 1] += miqdor;
        *bolim_narx += menu[tanlov - 1] * miqdor;

        menyu_chiqar(menu, nomlar, hajm);
    }
}

int main() {
    int ovqat_narxi = 0, ichimlik_narxi = 0, salat_narxi = 0, shirinlik_narxi = 0;

    while (1) {
        printf("\nOSHXONA MENYUSI");
        printf("\nBo'limni tanlang:\n");
        printf("1. Ovqatlar bo'limi\n");
        printf("2. Ichimliklar bo'limi\n");
        printf("3. Salatlar bo'limi\n");
        printf("4. Shirinliklar bo'limi\n");
        printf("0. Hisobni chiqarish\n");
        printf("Tanlovingizni kiriting: ");

        int tanlov;
        if (scanf("%d", &tanlov) != 1 || tanlov < 0 || tanlov > 4) {
            printf("\nNotog'ri tanlov. Iltimos, qaytadan urinib ko'ring.");
            while (getchar() != '\n') continue;
            continue;
        }

        switch (tanlov) {
            case 1:
                menyu_chiqar(ovqat, ovqat_nomi, sizeof(ovqat) / sizeof(ovqat[0]));
                buyurtma_qabul_qilish(ovqat, ovqat_nomi, sizeof(ovqat) / sizeof(ovqat[0]), &ovqat_narxi, ovqat_miqdor, &ovqat_narxi, &ichimlik_narxi, &salat_narxi, &shirinlik_narxi);
                break;
            case 2:
                menyu_chiqar(ichimlik, ichimlik_nomi, sizeof(ichimlik) / sizeof(ichimlik[0]));
                buyurtma_qabul_qilish(ichimlik, ichimlik_nomi, sizeof(ichimlik) / sizeof(ichimlik[0]), &ichimlik_narxi, ichimlik_miqdor, &ovqat_narxi, &ichimlik_narxi, &salat_narxi, &shirinlik_narxi);
                break;
            case 3:
                menyu_chiqar(salat, salat_nomi, sizeof(salat) / sizeof(salat[0]));
                buyurtma_qabul_qilish(salat, salat_nomi, sizeof(salat) / sizeof(salat[0]), &salat_narxi, salat_miqdor, &ovqat_narxi, &ichimlik_narxi, &salat_narxi, &shirinlik_narxi);
                break;
            case 4:
                menyu_chiqar(shirinlik, shirinlik_nomi, sizeof(shirinlik) / sizeof(shirinlik[0]));
                buyurtma_qabul_qilish(shirinlik, shirinlik_nomi, sizeof(shirinlik) / sizeof(shirinlik[0]), &shirinlik_narxi, shirinlik_miqdor, &ovqat_narxi, &ichimlik_narxi, &salat_narxi, &shirinlik_narxi);
                break;
            case 0:
                hisobni_chiqarish(ovqat_narxi, ichimlik_narxi, salat_narxi, shirinlik_narxi,
                                  ovqat_miqdor, ichimlik_miqdor, salat_miqdor, shirinlik_miqdor);
                printf("\nHisob chiqdi. Dastur yakunlandi.\n");
                return 0;
            default:
                printf("\nNotog'ri tanlov. Iltimos, qaytadan urinib ko'ring.");
                break;
        }
    }

    return 0;
}
