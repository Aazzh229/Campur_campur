program DataMahasiswa;

uses crt;

var
data_mahasiswa: array [1..3, 1..3] of string[50];
i: integer;

begin
clrscr;

// Data mahasiswa

data_mahasiswa[1, 1] := '001'; data_mahasiswa[1, 2] := 'Alice'; data_mahasiswa[1,3] :='Teknik Informatika' ;
data_mahasiswa[2, 1] := '002'; data_mahasiswa[2, 2] := 'Bob'; data_mahasiswa[2, 3] := 'Sistem Informasi';
data_mahasiswa[3, 1] := '003'; data_mahasiswa[3, 2] := 'Charlie'; data_mahasiswa[3, 3] := 'Manajement';

//Menampilkan pilkan salah satu data
writeln (data_mahasiswa[3, 2]);

// Menampilkan seluruh data
writeln('ID          Nama                Jurusan');
writeln('-----------------------------');
for i :=1 to 3 do
begin

writeln(data_mahasiswa[i,1]:6, '   ', data_mahasiswa[i, 2]:10, '            ' , data_mahasiswa[i, 3]);
end;

readln;
end.
