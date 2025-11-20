#include "portofolio.h"

void createSaham(List_Saham &LS){

}

void createInvestor(List_Investor &LI){

}

void createList(){

}

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
