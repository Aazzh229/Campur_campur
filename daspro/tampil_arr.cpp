#include <stdio.h>

int main() {
    // List nama-nama buah (menggunakan array karakter 2D)
    char buah[4][10] = {"apel", "anggur", "mangga", "Jeruk"};
    int jumlahBuah = 4;  // Jumlah elemen dalam array

    // Ambil "mangga" dari indeks ke-2
    printf("Menampilkan salah satu isi array\n");
    printf("\nIsi buah indeks ke-2 adalah: %s\n", buah[2]);

    // Tampilkan semua daftar buah
    printf("\nMenampilkan semua isi array:\n");
    printf("\nSemua Buah: ada %d macam\n", jumlahBuah);
    for (int i = 0; i < jumlahBuah; i++) {
        printf("%s\n", buah[i]);
    }

    return 0;
}

