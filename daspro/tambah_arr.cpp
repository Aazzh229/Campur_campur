#include <stdio.h>
#include <string.h>

int main() {
    // Daftar nama-nama buah
    char buah[6][10] = {"apel", "anggur", "mangga", "Jeruk"};
    int jumlahBuah = 4;  // Jumlah elemen awal dalam array

    // Menambahkan buah
    if (jumlahBuah < 6) {
        // Geser elemen ke kanan
        for (int i = jumlahBuah; i > 2; i--) {
            for (int j = 0; j < 10; j++) {
                buah[i][j] = buah[i - 1][j];
            }
        }

        // Menambahkan "duren" di indeks ke-2
        for (int i = 0; i < 10; i++) {
            buah[2][i] = "duren"[i];
        }
        jumlahBuah++;  // Update jumlah buah
    }

    // Tampilkan semua daftar buah
    printf("Semua Buah: ada %d macam\n", jumlahBuah);
    for (int i = 0; i < jumlahBuah; i++) {
        printf("%s\n", buah[i]);
    }

    return 0;
}

