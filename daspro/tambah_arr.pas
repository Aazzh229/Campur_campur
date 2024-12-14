program TambahArray;
uses crt;
var
    buah: array[0..5] of string[10]; // Array dengan panjang 6 elemen
    jumlahBuah, i: Integer;
begin
    clrscr;
    // Inisialisasi array dengan beberapa buah
    buah[0] := 'apel';
    buah[1] := 'anggur';
    buah[2] := 'mangga';
    buah[3] := 'Jeruk';

    jumlahBuah := 4; // Jumlah buah awal

    // Menambah buah array
    if jumlahBuah < 6 then
    begin
        for i := jumlahBuah downto 2 do
            buah[i] := buah[i-1]; // Geser elemen ke kanan
        buah[2] := 'durian'; // Menambahkan "durian" di indeks 2
        jumlahBuah := jumlahBuah + 1; // Update jumlah buah
    end;

    // Tampilkan semua daftar buah
    writeln('Semua Buah: ada ', jumlahBuah, ' macam');
    for i := 0 to jumlahBuah - 1 do
        writeln(buah[i]);
    readln;
end.
