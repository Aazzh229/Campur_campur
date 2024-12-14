program DaftarBuah;
uses crt;
var
    buah: array[1..4] of string[10];
    i: integer;
begin
    clrscr;
    // List nama-nama buah
    buah[1] := 'apel';
    buah[2] := 'anggur';
    buah[3] := 'mangga';
    buah[4] := 'Jeruk';

    // Ambil "mangga" dari indeks ke-3
    writeln('Menampilkan salah satu isi array');
    writeln('Isi buah index ke-3 adalah: ', buah[3]);
    writeln;

    // Tampilkan semua daftar buah
    writeln('Menampilkan semua isi array:');
    writeln('Semua Buah: ada ', 4, ' macam');
    for i := 1 to 4 do
    begin
        writeln(buah[i]);
    end;
    readln;
end.
