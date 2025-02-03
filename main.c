#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void writefile(char filename[]);
void readfile(char filename[]);
void listfile();
void deletefile(char filename[]);
void appendfile(char filename[]);
void updatefile(char filename[]);
int metinguncelle(char filename[]);

int main() {
    char filename[100];
    int secim;
    printf("Dosya adini giriniz(ornek.txt): ");
    scanf("%s", filename);
    getchar();
    while (1) {
        printf("1.Dosya yaz\n2.Dosya oku\n3.Dosyalarimi listele\n4.Dosya sil\n5.Dosya ekle-Var olan dosyaya metin ekle\n6.Cikis\nSeciminizi girin:");
        scanf("%d", &secim);
        getchar();

        switch (secim) {
            case 1:
                printf("Dosya adini giriniz:");
            scanf("%s", filename);
            getchar();
                writefile(filename);
            break;
            case 2:
                printf("Dosya adini giriniz:");
            scanf("%s", filename);
            getchar();
                readfile(filename);
            break;
            case 3:
                listfile();
            break;
            case 4:
                printf("Silmek istediginiz dosya adini giriniz(ornek.txt):");
            scanf("%s", filename);
            getchar();
                deletefile(filename);
            break;
            case 5:
                printf("Ekleme yapmak istediginiz dosya adini giriniz(ornek.txt):");
            scanf("%s", filename);
            getchar();
            if (metinguncelle(filename)) {
                appendfile(filename);
            }
            break;
            case 6:
                printf("Programdan cikiliyor...\n");
                exit(0);
            break;
            default:
                printf("Gecersiz secim yaptiniz,tekrar deneyiniz.\n");
        }
    }
    return 0;
}
int metinguncelle(char filename[]) {
if (strlen(filename) == 0) {
    printf("Dosya adi bos olamaz!\n");
    return 0;
}
    if (strchr(filename,'/') != NULL || strchr(filename,'\\') != NULL) {
        printf("Dosya adi gecersiz karakterler iceriyor!\n");
        return 0;
    }
    return 1;
}

void writefile(char filename[]) {
    FILE *file;
    char input[1000];
    file=fopen(filename, "w");
    if (file == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    printf("|Dosya yazman icin metin  girin ve bittiginde 'exit' yazin.|\n");
while(1) {
    fgets(input,sizeof(input),stdin);
    if (strcmp(input,"exit\n")==0){
        break;
    }
    fprintf(file, "%s", input);
    fflush(file);
}
    fclose(file);
    printf("Metin dosyaya kaydedildi.\n");
}

void readfile(char filename[]) {
    FILE *file;
    char input[1000];
    file=fopen(filename, "r");
    if (file==NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    printf("\nDosyadaki metin:\n");
    while (fgets(input,sizeof(input),file)!=NULL) {
        printf("%s", input);
    }
    fclose(file);
}

void listfile() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        printf("\nMevcut dosyalar:\n");

        while ((dir = readdir(d)) != NULL) {
printf("|%s|\n",dir->d_name);
        }
        closedir(d);
    }
    else {
        printf("Dizin acilmadi.\n");
    }
}

void deletefile(char filename[]) {
    if (remove(filename) == 0) {
        printf("Dosya basariyla silindi.\n");
    }
    else {
        printf("Dosya silinemedi.\n");
    }
}

void appendfile(char filename[]) {
    FILE *file;
    char input[1000];
    file=fopen(filename, "a");
    if (file==NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    printf("|Dosya yazman icin metin  girin ve bittiginde 'exit' yazin.|\n");
    while (1) {
        fgets(input,sizeof(input),stdin);
        if (strcmp(input,"exit\n")==0) {
            break;
        }
        fprintf(file,"%s", input);
        fflush(file);
    }
    fclose(file);
    printf("Metin dosyaya eklendi.\n");
}