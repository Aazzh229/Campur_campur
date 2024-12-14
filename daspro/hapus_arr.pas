program HapusArray;
uses crt;

var
    buah: array[0..3] of string[10]; // Array dengan panjang 4 elemen
    jumlahBuah, i, j, indexToDelete: Integer;

begin
    clrscr;

    // Inisialisasi array dengan beberapa buah
    buah[0] := 'apel';
    buah[1] := 'anggur';
    buah[2] := 'mangga';
    buah[3] := 'jeruk';

    jumlahBuah := 4; // Jumlah buah awal
    indexToDelete := 2; // Indeks yang ingin dihapus (indeks ke-2 adalah "mangga")

    // Menghapus elemen di indeks ke-2 (mangga)
    for i := indexToDelete to jumlahBuah - 2 do
        for j := 1 to Length(buah[i+1]) do
            buah[i][j] := buah[i+1][j]; // Geser karakter satu per satu
    jumlahBuah := jumlahBuah - 1; // Update jumlah buah

    // Tampilkan semua daftar buah
    Writeln('Semua Buah: ada', jumlahBuah, 'macam');
    for i := 0 to jumlahBuah - 1 do
        Writeln(buah[i]);

    readln;
end.
