#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf

// Fungsi untuk menghitung harga tiket berdasarkan jenis KBT dan status hari libur
int hitungHargaTiket(int jenisKBT, int isLiburNasional) {
    int harga = 0;

    // Logika penentuan harga
    if (jenisKBT == 1) { // KBT Ekonomi
        if (isLiburNasional == 1) {
            harga = 125000; // Harga saat Libur Nasional
        } else {
            harga = 110000; // Harga saat Weekday
        }
    } else if (jenisKBT == 2) { // KBT Eksekutif
        if (isLiburNasional == 1) {
            harga = 150000; // Harga saat Libur Nasional
        } else {
            harga = 140000; // Harga saat Weekday
        }
    }
    // Jika jenisKBT tidak valid (bukan 1 atau 2), harga akan tetap 0

    return harga;
}

int main() {
    int pilihanKBT;
    int pilihanLibur;
    int hargaTiket = 0;

    printf("===========================================================\n");
    printf("       Selamat Datang di Sistem Ticketing Koperasi       \n");
    printf("                  Bintang Tapanuli (KBT)                 \n");
    printf("===========================================================\n");
    printf("Rute Umum: Medan -> Siborong-borong/Bandara Silangit\n\n");

    // Menerima input jenis KBT dari pengguna
    printf("Pilih jenis KBT yang Anda inginkan:\n");
    printf("1. Ekonomi (Weekday: Rp110.000, Libur Nasional: Rp125.000)\n");
    printf("2. Eksekutif (Weekday: Rp140.000, Libur Nasional: Rp150.000)\n");
    printf("Masukkan pilihan Anda (1 atau 2): ");
    scanf("%d", &pilihanKBT);

    // Validasi input jenis KBT
    if (pilihanKBT < 1 || pilihanKBT > 2) {
        printf("Pilihan jenis KBT tidak valid. Harap masukkan 1 atau 2.\n");
        return 1; // Keluar dari program dengan kode error
    }

    // Menerima input status hari libur dari pengguna
    printf("\nApakah tanggal keberangkatan Anda adalah Hari Libur Nasional?\n");
    printf("1. Ya\n");
    printf("0. Tidak\n");
    printf("Masukkan pilihan Anda (0 atau 1): ");
    scanf("%d", &pilihanLibur);

    // Validasi input status hari libur
    if (pilihanLibur < 0 || pilihanLibur > 1) {
        printf("Pilihan status hari libur tidak valid. Harap masukkan 0 atau 1.\n");
        return 1; // Keluar dari program dengan kode error
    }

    // Memanggil fungsi untuk menghitung harga tiket
    hargaTiket = hitungHargaTiket(pilihanKBT, pilihanLibur);

    // Menampilkan hasil kepada pengguna
    printf("\n-----------------------------------------------------------\n");
    printf("Detail Tiket Anda:\n");
    printf("Jenis KBT   : %s\n", (pilihanKBT == 1) ? "Ekonomi" : "Eksekutif");
    printf("Status Hari : %s\n", (pilihanLibur == 1) ? "Libur Nasional" : "Weekday Biasa");
    printf("Harga Tiket : Rp%d\n", hargaTiket);
    printf("-----------------------------------------------------------\n");
    printf("Terima kasih telah menggunakan layanan KBT!\n");

    return 0; // Program berakhir dengan sukses
}
