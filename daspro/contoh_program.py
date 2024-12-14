# Membuat list kosong untuk menampung tugas
tugas = []
stop=False
i = 1

#Mengisi tugas
while not stop:
    tugas_baru = input ("Inputkan Judul Video Favorite yang ke-1): ".format(i))
    tugas.append(tugas_baru)

    #Increment i
    i += 1

    tanya=input ("Mau isi lagi? (y/t): ")
    if tanya == "t":
        stop = True

#Cetak Semua Tugas
print ("=" *10)
print ("Kamu memiliki {} Judul Video Favorite.".format (len(tugas)))
for t in tugas:
    print("- {}".format(t))
