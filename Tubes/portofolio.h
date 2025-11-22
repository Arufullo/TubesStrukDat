#ifndef PORTOFOLIO_H_INCLUDED
#define PORTOFOLIO_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct infotype_Saham {
    string kodeSaham;
    string namaPerusahaan;
    string sektor;
    double hargaSekarang;
};

struct infotype_Investor {
    string nama;
    string NIM;
    string jurusan;
    int angkatan;
};

struct infotype_Kepemilikan {
    int lot;
    double hargaBeliRata2;
};

typedef struct Elm_Saham       *address_Saham;
typedef struct Elm_Investor    *address_Investor;
typedef struct Elm_Kepemilikan *address_Kepemilikan;

struct Elm_Saham {
    infotype_Saham info;
    address_Saham next;
    address_Kepemilikan nextKepemilikan;  // head/first list relasi untuk saham ini
};

struct Elm_Investor {
    infotype_Investor info;
    address_Investor next;
    address_Investor prev;
};

struct Elm_Kepemilikan {
    infotype_Kepemilikan info;   // lot, harga beli rata rata
    address_Investor investor;   // pointer ke investor pemilik saham
    address_Kepemilikan next;    // relasi berikutnya pada saham yang sama
};

struct List_Saham {
    address_Saham first;
};

struct List_Investor {
    address_Investor first;
    address_Investor last;
};

//Inisiasi List
void createSaham(List_Saham &LS);
void createInvestor(List_Investor &LI);

//Alokasi Node
address_Saham alokasiSaham(infotype_Saham x);
address_Investor alokasiInvestor(infotype_Investor x);
address_Kepemilikan alokasiKepemilikan(address_Investor PInvestor, infotype_Kepemilikan x);

// insert node siap pakai
void insertSaham(List_Saham &LS, address_Saham P);
void insertInvestor(List_Investor &LI, address_Investor P);

// insert dengan data langsung
void insertSahamInfo(List_Saham &LS, infotype_Saham x);
void insertInvestorInfo(List_Investor &LI, infotype_Investor x);

// buat relasi, sambungkan saham dengan investor tertentu
void insertKepemilikan(List_Saham &LS, List_Investor &LI, string kodeSaham, string NIM, infotype_Kepemilikan x);

// Hapus List Parent
void deleteSaham(List_Saham &LS, string kodeSaham);

// hapus investor dan semua relasi yang menunjuk ke investor itu
void deleteInvestor(List_Saham &LS, List_Investor &LI, string NIM);

// hapus relasi antara saham tertentu dan investor tertentu
void deleteKepemilikan(List_Saham &LS, List_Investor &LI, string kodeSaham, string NIM);

// Find
address_Saham findSaham(List_Saham LS, string kodeSaham);
address_Investor findInvestor(List_Investor LI, string NIM);

// cari relasi tertentu pada satu saham
address_Kepemilikan findKepemilikan(address_Saham PSaham, address_Investor PInvestor);

// Print
void showSaham(List_Saham LS);
void showInvestor(List_Investor LI);

// tampilkan daftar investor yang memegang satu saham tertentu
void showInvestorSaham(List_Saham LS, string kodeSaham);

// tampilkan daftar saham yang dipegang satu investor tertentu
void showSahamDipegangInvestor(List_Saham LS, List_Investor LI, string NIM);

// tampilkan semua saham beserta seluruh investor pemiliknya
void showSemuaSahamDenganInvestor(List_Saham LS);

// tampilkan semua investor beserta seluruh saham yang ia pegang
void showSemuaInvestorDenganSaham(List_Saham LS, List_Investor LI);

// Hitung
int jumlahSaham(List_Saham LS);
int jumlahInvestor(List_Investor LI);

// jumlah investor yang tidak punya saham sama sekali
int jumlahInvestorTanpaSaham(List_Saham LS, List_Investor LI);

// edit data investor tertentu
void editInvestor(List_Investor &LI, string NIM);

// memindahkan kepemilikan saham dari investor lama ke investor baru
void editKepemilikanUbahInvestor(List_Saham &LS, List_Investor &LI, string kodeSaham, string NIMLama, string NIMBaru);

#endif // PORTOFOLIO_H_INCLUDED
