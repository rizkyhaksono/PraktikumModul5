#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variabel global untuk semua fungsi dan menyimpan data user
struct Mahasiswa {
    char nim[30];
    char nama[50];
    char kelas[20];
    char dosen[20];

    int display;
};

// untuk menyimpan semua data user dari nim, nama, kelas dan dosen
struct Mahasiswa User[100];

// untuk mengecek data sebelum nya
int extent = 0;

void createUser(void){
    char nim[30];
    char nama[50];
    char kelas[20];
    char dosen[20];

    // sebagai inputan sementara
    int repo = 0;
    int i;

    atasCreate:
    printf("\n=== Create Data ===\n");

    nimUlang:
    printf("\n[+] Input NIM Praktikan \t\t: IF2021-");
    scanf(" %[^\n]s", nim);

    while(strlen(nim) > 10 || strlen(nim) < 3){
        printf("\nNIM Tidak Boleh Lebih Dari Batas!\n");
        goto nimUlang;
    }

    printf("\n[+] Input Nama Praktikan \t\t: ");
    scanf(" %[^\n]s", nama);

    printf("\n[+] Input Kelas Pemrograman Dasar \t: ");
    scanf(" %[^\n]s", kelas);

    printf("\n[+] Input Nama Dosen Pengampu \t\t: ");
    scanf(" %[^\n]s", dosen);

    // cek data apakah data sudah ada
    for(i = 0; i < extent; i++){
        if(strcmp(User[i].nim, nim) == 0 && User[i].display == 1){
            repo = 1;
        }
    }

    // jika data tidak sama maka simpan
    if(repo == 0){
        strcpy(User[extent].nim, nim);
        strcpy(User[extent].nama, nama);
        strcpy(User[extent].kelas, kelas);
        strcpy(User[extent].dosen, dosen);

        User[extent].display = 1;
        ++extent;

        printf("\n------------------------------------------------------\n");
        printf("\n\t      Data Berhasil Di Tambahkan.\n");
        printf("\n------------------------------------------------------\n");
    }else{ // jika data sama dgn sebelumnya, maka masuk else
        printf("\nUser Sudah Ada!\n");
        repo = 0;
        goto atasCreate;
    }
}

void displayUser(void){
    int i;
    int no = 1;
    int repo = 0;

    // untuk mengecek semua data dari awal sampai akhir
    for(i = 0; i < extent; i++){
        if(User[i].display == 1){
            printf("\n\t=== [#] Daftar User %d ===\n", no);

            printf("\n==========================================\n");
            printf("\n[-] NIM \t\t: IF2021-%s\n", User[i].nim);
            printf("\n[-] Nama Lengkap \t: %s\n", User[i].nama);
            printf("\n[-] Kelas Pemrograman \t: %s\n", User[i].kelas);
            printf("\n[-] Dosen Pengampu \t: %s\n", User[i].dosen);
            printf("\n==========================================\n");
            ++no;
            repo = 1;
        }
    }

    // jika tidak ada maka masuk kesini
    if(extent == 0 || repo == 0){
        printf("\nData Belum Ada, Silahkan Membuat Terlebih Dahulu!\n");
    }

}

void searchUser(void){
    char nim[30];
    int i;
    int repo = 0;

    cari:
    printf("\n=== Search Data ===\n");

    printf("\nMasukkan NIM yang Ingin Di Cari : IF2021-");
    scanf("%s", nim);

    // jika data sudah ada maka masuk kesini, lalu cek nim satu per satu
    for(i = 0; i < extent; i++){
        if(strcmp(User[i].nim, nim) == 0){
            printf("\n==========================================\n");
            printf("\n[-] NIM \t\t: IF2021-%s\n", User[i].nim);
            printf("\n[-] Nama Lengkap \t: %s\n", User[i].nama);
            printf("\n[-] Kelas Pemrograman \t: %s\n", User[i].kelas);
            printf("\n[-] Dosen Pengampu \t: %s\n", User[i].dosen);
            printf("\n==========================================\n");
            repo = 1; // inputan jika data ada
        }
    }

    // jika data NIM tidak ada, maka masuk kesini
    if(extent == 0 || repo == 0){
        printf("\nData Belum Ada, Silahkan Membuat Terlebih Dahulu!\n");
    }

}

void updateUser(void){
    char nim[30];
    int repo = -1;
    int i;

    printf("\n=== Update Data ===\n");

    // masukkan nim user
    printf("\nMasukkan NIM yang Ingin Di Update : IF2021-");
    scanf("%s", nim);

    // lalu cek satu per satu data user
    for(i = 0; i < extent; i++){
        if(strcmp(User[i].nim, nim) == 0 && User[i].display == 1){
            repo = i; // untuk mengambil data dari index i dan masuk ke repo
        }
    }

    // jika repo sudah ada, maka masuk ke fungsi if
    if(repo != -1){
        printf("\n[+] Input Nama Praktikan \t\t: ");
        scanf(" %[^\n]s", User[repo].nama);

        printf("\n[+] Input Kelas Pemrograman Dasar \t: ");
        scanf(" %[^\n]s", User[repo].kelas);

        printf("\n[+] Input Nama Dosen Pengampu \t\t: ");
        scanf(" %[^\n]s", User[repo].dosen);

        printf("\n------------------------------------------------------\n");
        printf("\n\t      Data Berhasil Di Update!.\n");
        printf("\n------------------------------------------------------\n");
    }else{ // jika data tidak ada di dalam repo, maka masuk ke fungsi else
        printf("\nData Tidak Dapat Ditemukan!\n");
    }
}

void deleteUser(void){
    char nim[30];
    int repo = -1; // tidak ada batasan untuk hapus data user
    int i;

    printf("\n=== Delete User ===\n");

    printf("\nMasukkan NIM yang Ingin Di Hapus : IF2021-");
    scanf("%s", nim);

    // cek kembali jika data user sudah ada satu per satu
    for(i = 0; i < extent; i++){
        if(strcmp(User[i].nim, nim) == 0 && User[i].display == 1){
            repo = i;
        }
    }

    // jika data tidak sama dengan repo lokal, maka data berhasil dihapus
    if(repo != -1){
        User[repo].display = 0; // repo disini mengacu ke repo = i; (data masuk ke dalam repo)
        printf("\n------------------------------------------------------\n");
        printf("\n\t      Data Berhasil Di Hapus!.\n");
        printf("\n------------------------------------------------------\n");
    }else{
        printf("\nData Tidak Dapat Ditemukan!\n");
    }
}

int main(void){

    up:
    printf("[+] Tugas Modul 5\n");
    printf("\n|| ============================================ ||\n");
    printf("|| \t\t\t\t\t\t||");
    printf("\n||\t Nama \t: Muhammad Rizky Haksono \t||\n");
    printf("||\t NIM  \t: 325 \t\t\t \t||\n");
    printf("||\t Kelas \t: G \t\t\t \t||\n");
    printf("|| \t\t\t\t\t\t||");
    printf("\n|| ============================================ ||\n");

    printf("\n[#] Sistem Pendataan Akun I-Lab Infotech\n");

    printf("\n|| ============================================ ||\n");
    printf("|| \t\t\t\t\t\t||\n");
    printf("||\t\t[-] 1. Create \t\t\t||\n");
    printf("||\t\t[-] 2. Show \t\t\t||\n");
    printf("||\t\t[-] 3. Search \t\t\t||\n");
    printf("||\t\t[-] 4. Update \t\t\t||\n");
    printf("||\t\t[-] 5. Delete \t\t\t||\n");
    printf("||\t\t[-] 0. Exit \t\t\t||\n");
    printf("|| \t\t\t\t\t\t||");
    printf("\n|| ============================================ ||\n");

    int choice;
    again:
    printf("\n\n[+] Pilihan Menu : ");
    scanf("%d", &choice);

    switch(choice){
    case 1:
        createUser();
        break;
    case 2:
        displayUser();
        break;
    case 3:
        searchUser();
        break;
    case 4:
        updateUser();
        break;
    case 5:
        deleteUser();
        break;
    case 0:
        done:
        printf("\n|| ====================================================== ||\n");
        printf("|| \t\t\t\t\t\t\t  ");
        printf("|| \n");
        printf("||  [-] Terima Kasih Telah Menggunakan Pemrograman CRUD!  ||\n");
        printf("|| \t\t\t\t\t\t\t  ");
        printf("|| \n");
        printf("|| ====================================================== ||\n");
        exit(0);
        break;
    default:
        printf("\nInput Anda Salah!");
        goto again;
        break;
    }

    char konfirmasi;
    key:
    printf("\n[+] Apakah Ingin Melanjutkan Program? [y/n] : ");
    scanf("%s", &konfirmasi);

    switch(tolower(konfirmasi)){
    case 'y':
        system("cls");
        goto up;
        break;
    case 'n':
        system("cls");
        goto done;
        break;
    default:
        printf("\nInputan Anda Salah!\n");
        goto key;
        break;
    }
    return 0;

}
