#include <iostream>
#include <string>
using namespace std;

struct maha
{
    string Nrp;
    string NamaMaha;
    string KelasMaha;
    string DepartMaha;
    string FakultasMaha;
    string AsalMaha;
    string AlamatMaha;
    string TelpMaha;
    string UsiaMaha;
    string IpMaha;
};

const int MAX_maha = 10;

void TampilkanData(const maha mhs[], int jumlahData)
{
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < jumlahData; i++)
    {
        cout << "Nrp: " << mhs[i].Nrp << endl;
        cout << "Nama: " << mhs[i].NamaMaha << endl;
        cout << "Kelas: " << mhs[i].KelasMaha << endl;
        cout << "Departemen: " << mhs[i].DepartMaha << endl;
        cout << "Fakultas: " << mhs[i].FakultasMaha << endl;
        cout << "Asal: " << mhs[i].AsalMaha << endl;
        cout << "Alamat: " << mhs[i].AlamatMaha << endl;
        cout << "Telepon: " << mhs[i].TelpMaha << endl;
        cout << "Usia: " << mhs[i].UsiaMaha << endl;
        cout << "IP: " << mhs[i].IpMaha << endl;
    }
}

	
int main()
{
    maha maha[MAX_maha];
    int jumlahData = 0;

    int menu;
    do
    {
        cout << "\nMenu: " << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data Baru" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1: //menampilkan data
            TampilkanData(maha, jumlahData);
            break;
        case 2: //menambahkan data 
            if (jumlahData < MAX_maha)
{
    cout << "Masukkan data baru:" << endl;
    cout << "Nrp: ";
    cin >> maha[jumlahData].Nrp;
    cin.ignore(); // Tambahkan ini untuk menghindari masalah newline (\n) yang tersisa di buffer input.

    cout << "Nama: ";
    cin.ignore();
    getline(cin, maha[jumlahData].NamaMaha);
    
    cout << "Kelas: ";
    cin >> maha[jumlahData].KelasMaha;
    
    cout << "Departemen: ";
    cin.ignore(); 
    getline(cin, maha[jumlahData].DepartMaha);

    cout << "Fakultas: ";
    getline(cin, maha[jumlahData].FakultasMaha);

    cout << "Asal: ";
    getline(cin, maha[jumlahData].AsalMaha);

    cout << "Alamat: ";
    getline(cin, maha[jumlahData].AlamatMaha);

    cout << "Telepon: ";
    cin >> maha[jumlahData].TelpMaha;

    cout << "Usia: ";
    cin >> maha[jumlahData].UsiaMaha;

    cout << "IP: ";
    cin >> maha[jumlahData].IpMaha;

    jumlahData++;
    cout << "Data berhasil ditambahkan." << endl;
            TampilkanData(maha, jumlahData); }
            else
            {
                cout << "Kapasitas data sudah penuh." << endl;
            }
            break;
        case 3: //menghapus data
            int indeksHapus;
            cout << "Masukkan indeks data yang ingin dihapus (1-" << jumlahData << "): ";
            cin >> indeksHapus;
            if (indeksHapus >= 1 && indeksHapus <= jumlahData)
            {
                for (int i = indeksHapus - 1; i < jumlahData - 1; i++)
                {
                    maha[i] = maha[i + 1];
                }
                jumlahData--;
                cout << "Data berhasil dihapus." << endl;
            }
            else
            {
                cout << "Indeks data tidak valid." << endl;
            }
            break;
        case 4: //mengubah data
            int indeksUbah;
            cout << "Masukkan indeks data yang ingin diubah (1-" << jumlahData << "): ";
            cin >> indeksUbah;
            if (indeksUbah >= 1 && indeksUbah <= jumlahData)
            {
                cout << "Masukkan data yang baru:" << endl;
                cout << "Nrp: ";
                cin >> maha[indeksUbah - 1].Nrp;
                cout << "Nama: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].NamaMaha);
                cout << "Kelas: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].KelasMaha);
                cout << "Departemen: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].DepartMaha);
                cout << "Fakultas: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].FakultasMaha);
                cout << "Asal: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].AsalMaha);
                cout << "Alamat: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].AlamatMaha);
                cout << "Telepon: ";
				cin.ignore();
				getline(cin, maha[indeksUbah - 1].TelpMaha);
                cout << "Usia: ";
                cin.ignore();
                getline(cin, maha[indeksUbah - 1].UsiaMaha);
                cout << "IP: ";
				cin.ignore();
				getline(cin, maha[indeksUbah - 1].IpMaha);

                cout << "Data berhasil diubah." << endl;
            }
            else
            {
                cout << "Indeks data tidak valid." << endl;
            }
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (menu != 5);

    return 0;
}

