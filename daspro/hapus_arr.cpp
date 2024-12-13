#include <stdio.h>

int main() {
    // List nama-nama buah
    char buah[4][10] = {"apel", "anggur", "mangga", "Jeruk"};
    int jumlahBuah = 4; // Jumlah elemen dalam array
    int i, j;

    // Menghapus elemen di indeks ke-2 (mangga)
    for (i = 2; i < jumlahBuah - 1; i++) {
        for (j = 0; buah[i + 1][j] != '\0'; j++) {
            buah[i][j] = buah[i + 1][j];
        }
        buah[i][j] = '\0'; // Menambahkan karakter null di akhir string
    }
    jumlahBuah--; // Update jumlah buah

    // Tampilkan semua daftar buah
    printf("Semua Buah: ada %d macam\n", jumlahBuah);
    for (i = 0; i < jumlahBuah; i++) {
        printf("%s\n", buah[i]);
    }

    return 0;
}

