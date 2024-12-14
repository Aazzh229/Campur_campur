program DaftarBuah;
uses crt;
var
buah: array[1..4] of string[10]; // Array string dengan panjang maksimal 10 karakter
i: integer;
begin
clrscr;
// List nama-nama buah
buah[1] := 'apel';
buah[2] := 'anggur' ;
buah[3] := 'Mangga';
buah[4] := 'Jeruk';
// Mengubah nilai indeks ke-3 menjadi "Kelapa"
buah[3] := 'Kelapa';
// Tampilkan semua daftar buah
writeln('Semua Buah: ada ', 4,'macam');
 for i := 1 to 4 do
begin
writeln(buah[i]);
end;
readln;
end.
