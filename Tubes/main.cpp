#include <limits>       // untuk numeric_limits
#include "portofolio.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // numeric_limits<streamsize>::max() dipakai supaya cin.ignore bisa membuang SEMUA sisa input di baris itu, jadi input berikutnya aman.
}

void menu() {
    cout << "=============================================\n";
    cout << " PENGOLAHAN DATA TERKAIT PORTOFOLIO SAHAM MAHASISWA\n";
    cout << "=============================================\n";
    cout << "1.  Tambah data saham\n";
    cout << "2.  Tambah data investor\n";
    cout << "3.  Tambah kepemilikan saham (relasi)\n";
    cout << "4.  Hapus data saham\n";
    cout << "5.  Hapus data investor\n";
    cout << "6.  Hapus kepemilikan saham (relasi)\n";
    cout << "7.  Tampilkan semua saham\n";
    cout << "8.  Tampilkan semua investor\n";
    cout << "9.  Tampilkan investor yang memegang suatu saham\n";
    cout << "10. Tampilkan saham yang dipegang investor tertentu\n";
    cout << "11. Tampilkan semua saham beserta semua investornya\n";
    cout << "12. Tampilkan semua investor beserta semua saham yang ia pegang\n";
    cout << "13. Tampilkan jumlah saham, jumlah investor, dan jumlah investor tanpa saham\n";
    cout << "14. Edit data investor\n";
    cout << "15. Edit kepemilikan (pindahkan ke investor lain)\n";
    cout << "0.  Keluar\n";
    cout << "=============================================\n";
    cout << "Pilih menu: ";
}

int main() {
    List_Saham LS;
    List_Investor LI;

    createSaham(LS);
    createInvestor(LI);

    int pilihan;

    do {
        menu();
        cin >> pilihan;
        clearInput(); // buang newline setelah input angka

        switch (pilihan) {

        case 1: {
            // Tambah data saham
            infotype_Saham s;
            cout << "\n=== Tambah Data Saham ===\n";
            cout << "Kode saham        : ";
            getline(cin, s.kodeSaham);
            cout << "Nama perusahaan   : ";
            getline(cin, s.namaPerusahaan);
            cout << "Sektor            : ";
            getline(cin, s.sektor);
            cout << "Harga sekarang    : ";
            cin >> s.hargaSekarang;
            clearInput();

            insertSahamInfo(LS, s);
            cout << "Data saham berhasil ditambahkan.\n\n";
            break;
        }

        case 2: {
            // Tambah data investor
            infotype_Investor inv;
            cout << "\n=== Tambah Data Investor ===\n";
            cout << "NIM        : ";
            getline(cin, inv.NIM);
            cout << "Nama       : ";
            getline(cin, inv.nama);
            cout << "Jurusan    : ";
            getline(cin, inv.jurusan);
            cout << "Angkatan   : ";
            cin >> inv.angkatan;
            clearInput();

            insertInvestorInfo(LI, inv);
            cout << "Data investor berhasil ditambahkan.\n\n";
            break;
        }

        case 3: {
            // Tambah kepemilikan saham
            string kode, nim;
            infotype_Kepemilikan kep;
            cout << "\n=== Tambah Kepemilikan Saham ===\n";
            cout << "Kode saham        : ";
            getline(cin, kode);
            cout << "NIM investor      : ";
            getline(cin, nim);
            cout << "Jumlah lot        : ";
            cin >> kep.lot;
            cout << "Harga beli rata2  : ";
            cin >> kep.hargaBeliRata2;
            clearInput();

            address_Saham ps = findSaham(LS, kode);
            address_Investor pi = findInvestor(LI, nim);

            if (ps == NULL) {
                cout << "Saham dengan kode tersebut tidak ditemukan.\n\n";
            } else if (pi == NULL) {
                cout << "Investor dengan NIM tersebut tidak ditemukan.\n\n";
            } else {
                insertKepemilikan(LS, LI, kode, nim, kep);
                cout << "Relasi kepemilikan berhasil ditambahkan.\n\n";
            }
            break;
        }

        case 4: {
            // Hapus data saham
            string kode;
            cout << "\n=== Hapus Data Saham ===\n";
            cout << "Kode saham yang akan dihapus: ";
            getline(cin, kode);

            deleteSaham(LS, kode);
            cout << "Proses penghapusan saham selesai.\n\n";
            break;
        }

        case 5: {
            // Hapus data investor
            string nim;
            cout << "\n=== Hapus Data Investor ===\n";
            cout << "NIM investor yang akan dihapus: ";
            getline(cin, nim);

            deleteInvestor(LS, LI, nim);
            cout << "Proses penghapusan investor selesai.\n\n";
            break;
        }

        case 6: {
            // Hapus kepemilikan saham
            string kode, nim;
            cout << "\n=== Hapus Kepemilikan Saham ===\n";
            cout << "Kode saham   : ";
            getline(cin, kode);
            cout << "NIM investor : ";
            getline(cin, nim);

            deleteKepemilikan(LS, LI, kode, nim);
            cout << "Proses penghapusan relasi selesai.\n\n";
            break;
        }

        case 7: {
            // Tampilkan semua saham
            cout << "\n=== Daftar Semua Saham ===\n";
            showSaham(LS);
            cout << "\n";
            break;
        }

        case 8: {
            // Tampilkan semua investor
            cout << "\n=== Daftar Semua Investor ===\n";
            showInvestor(LI);
            cout << "\n";
            break;
        }

        case 9: {
            // Tampilkan investor yang memegang suatu saham
            string kode;
            cout << "\n=== Investor yang Memegang Suatu Saham ===\n";
            cout << "Kode saham: ";
            getline(cin, kode);

            showInvestorSaham(LS, kode);
            cout << "\n";
            break;
        }

        case 10: {
            // Tampilkan saham yang dipegang investor tertentu
            string nim;
            cout << "\n=== Saham yang Dipegang Investor Tertentu ===\n";
            cout << "NIM investor: ";
            getline(cin, nim);

            showSahamDipegangInvestor(LS, LI, nim);
            cout << "\n";
            break;
        }

        case 11: {
            // Tampilkan semua saham + semua investornya
            cout << "\n=== Semua Saham beserta Investornya ===\n";
            showSemuaSahamDenganInvestor(LS);
            cout << "\n";
            break;
        }

        case 12: {
            // Tampilkan semua investor + semua saham yang ia pegang
            cout << "\n=== Semua Investor beserta Saham yang Dipegang ===\n";
            showSemuaInvestorDenganSaham(LS, LI);
            cout << "\n";
            break;
        }

        case 13: {
            // Tampilkan jumlah data
            cout << "\n=== Informasi Jumlah Data ===\n";
            int js = jumlahSaham(LS);
            int ji = jumlahInvestor(LI);
            int jTanpa = jumlahInvestorTanpaSaham(LS, LI);

            cout << "Jumlah saham                : " << js << endl;
            cout << "Jumlah investor             : " << ji << endl;
            cout << "Jumlah investor tanpa saham : " << jTanpa << endl;
            cout << "\n";
            break;
        }

        case 14: {
            // Edit data investor
            string nim;
            cout << "\n=== Edit Data Investor ===\n";
            cout << "Masukkan NIM investor yang akan diedit: ";
            getline(cin, nim);

            editInvestor(LI, nim);
            cout << "Proses edit data investor selesai (cek implementasi editInvestor).\n\n";
            break;
        }

        case 15: {
            // Edit kepemilikan: pindahkan ke investor lain
            string kode, nimLama, nimBaru;
            cout << "\n=== Edit Kepemilikan (Pindahkan ke Investor Lain) ===\n";
            cout << "Kode saham         : ";
            getline(cin, kode);
            cout << "NIM investor lama  : ";
            getline(cin, nimLama);
            cout << "NIM investor baru  : ";
            getline(cin, nimBaru);

            editKepemilikanUbahInvestor(LS, LI, kode, nimLama, nimBaru);
            cout << "Proses edit kepemilikan selesai (cek implementasi editKepemilikanUbahInvestor).\n\n";
            break;
        }

        case 0:
            cout << "\nKeluar dari program. Terima kasih.\n";
            break;

        default:
            cout << "\nPilihan tidak valid, silakan coba lagi.\n\n";
            break;
        }

    } while (pilihan != 0);

    return 0;
}
