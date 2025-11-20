#ifndef PORTOFOLIO_H_INCLUDED
#define PORTOFOLIO_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct infotype_Saham{
    string kodeSaham;
    string namaPerusahaan;
    string sektor;
    double hargaSekarang;
};

struct infotype_Investor{
    string nama;
    string NIM;
    string jurusan;
    int angkatan;
    int lot;
};

typedef struct Elm_Saham *address_Saham;
typedef struct Elm_Investor *address_Investor;
typedef struct Elm_Kepemilikan *address_Kepemilikan;

struct Elm_Saham{
    infotype_Saham info;
    address_Saham next;
    address_Kepemilikan nextKepemilikan;
};

struct Elm_Investor{
    infotype_Investor info;
    address_Investor next;
    address_Investor prev;
};

struct List_Saham{
    address_Saham first;
};

struct List_Investor{
    address_Investor first;
    address_Investor last;
};

struct Elm_Kepemilikan{
    address_Investor nextInvestor;
    address_Kepemilikan next;
};

void createSaham(List_Saham &LS);
void createInvestor(List_Investor &LI);
void createList();
void insertSaham(List_Saham &LS, address_Saham p);
void insertInvestor(List_Investor &LI, address_Investor p);
void insertKepemilikan(List_Saham LS, List_Investor LI);
void deleteSaham(List_Saham &LS, address_Saham &p);
void deleteInvestor(List_Investor &LI, address_Investor &p);
void deleteKepemilikan(List_Saham LS, List_Investor LI, &p);
address_Saham findSaham(List_Saham LS, infotype_Saham x);
address_Investor findInvestor(List_Investor LI, infotype_Investor x);
address_Kepemilikan findKepemilikan();
void showSaham(List_Saham LS);
void showInvestor(List_Investor LI);
void showInvestorSaham(List_Saham LS, List_Investor LI);
void showSahamDipegangInvestor(List_Saham LS, List_Investor LI);
void showSahamInvestorTertentu(List_Saham LS, List_Investor LI)
int jumlahSaham(List_Saham LS);
int jumlahInvestor(List_Investor LI);
int jumlahInvestorTanpaSaham();
void editInvestor();
#endif // PORTOFOLIO_H_INCLUDED
