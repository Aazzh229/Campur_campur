#include <stdio.h>
#include <string.h>

int main() {
    // List nama-nama buah
    char buah[4][10] = {"apel", "anggur", "mangga", "Jeruk"};
    int jumlahBuah = 4;  // Jumlah elemen dalam array

    // Mengubah nilai indeks ke-2 menjadi "Kelapa"
    snprintf(buah[2], sizeof(buah[2]), "Kelapa");

    // Tampilkan semua daftar buah
    printf("Semua Buah: ada %d macam\n", jumlahBuah);
    for (int i = 0; i < jumlahBuah; i++) {
        printf("%s\n", buah[i]);
    }

    return 0;
}

