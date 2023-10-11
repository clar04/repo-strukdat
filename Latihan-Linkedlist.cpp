#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
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
    Mahasiswa* next;
};

void TampilkanData(Mahasiswa* head)
{
    cout << "Data Mahasiswa" << endl;
    int index = 1;
    Mahasiswa* current = head;
    while (current != nullptr)
    {
        cout << "Index: " << index << endl;
        cout << "Nrp: " << current->Nrp << endl;
        cout << "Nama: " << current->NamaMaha << endl;
        cout << "Kelas: " << current->KelasMaha << endl;
        cout << "Departemen: " << current->DepartMaha << endl;
        cout << "Fakultas: " << current->FakultasMaha << endl;
        cout << "Asal: " << current->AsalMaha << endl;
        cout << "Alamat: " << current->AlamatMaha << endl;
        cout << "Telepon: " << current->TelpMaha << endl;
        cout << "Usia: " << current->UsiaMaha << endl;
        cout << "IP: " << current->IpMaha << endl;
        current = current->next;
        index++;
    }
}

Mahasiswa* TambahData(Mahasiswa* head, const Mahasiswa& mahasiswa)
{
    Mahasiswa* newNode = new Mahasiswa(mahasiswa);
    newNode->next = head;
    return newNode;
}

Mahasiswa* HapusData(Mahasiswa* head, int index)
{
    if (index < 1)
    {
        cout << "Indeks data tidak valid." << endl;
        return head;
    }

    if (index == 1)
    {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus." << endl;
        return head;
    }

    Mahasiswa* current = head;
    int currentIndex = 1;
    while (currentIndex < index - 1 && current != nullptr)
    {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr || current->next == nullptr)
    {
        cout << "Indeks data tidak valid." << endl;
        return head;
    }

    Mahasiswa* temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "Data berhasil dihapus." << endl;
    return head;
}

int main()
{
    Mahasiswa* head = nullptr;
    Mahasiswa mahasiswa;

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
        case 1:
            TampilkanData(head);
            break;
        case 2:
            cout << "Masukkan data baru:" << endl;
            // Membaca data mahasiswa dari input ke variabel mahasiswa
            cout << "NRP : ";
            cin >> mahasiswa.Nrp;
            cin.ignore(); 
            cout << "Nama: ";
            getline(cin, mahasiswa.NamaMaha);
            cout << "Kelas: ";
            cin >> mahasiswa.KelasMaha;
            cout << "Departemen: ";
            cin.ignore(); 
            getline(cin, mahasiswa.DepartMaha);
            cout << "Fakultas: ";
            getline(cin, mahasiswa.FakultasMaha);
            cout << "Asal: ";
            getline(cin, mahasiswa.AsalMaha);
            cout << "Alamat: ";
            getline(cin, mahasiswa.AlamatMaha);
            cout << "Telepon: ";
            cin >> mahasiswa.TelpMaha;
            cout << "Usia: ";
            cin >> mahasiswa.UsiaMaha;
            cout << "IP: ";
            cin >> mahasiswa.IpMaha;
            head = TambahData(head, mahasiswa);
            break;
        case 3:
            int indeksHapus;
            cout << "Masukkan indeks data yang ingin dihapus: ";
            cin >> indeksHapus;
            head = HapusData(head, indeksHapus);
            break;
        case 4:
    int indeksUbah;
    cout << "Masukkan indeks data yang ingin diubah: ";
    cin >> indeksUbah;

    if (indeksUbah >= 1)
    {
        Mahasiswa* current = head;
        int currentIndex = 1;
        while (currentIndex < indeksUbah && current != nullptr)
        {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr)
        {
            cout << "Masukkan data yang baru:" << endl;
            cin.ignore();
            cout << "Nrp: ";
            getline(cin, current->Nrp);
            cout << "Nama: ";
            getline(cin, current->NamaMaha);
            cout << "Kelas: ";
            getline(cin, current->KelasMaha);
            cout << "Departemen: ";
            getline(cin, current->DepartMaha);
            cout << "Fakultas: ";
            getline(cin, current->FakultasMaha);
            cout << "Asal: ";
            getline(cin, current->AsalMaha);
            cout << "Alamat: ";
            getline(cin, current->AlamatMaha);
            cout << "Telepon: ";
            getline(cin, current->TelpMaha);
            cout << "Usia: ";
            getline(cin, current->UsiaMaha);
            cout << "IP: ";
            getline(cin, current->IpMaha);
            cout << "Data berhasil diubah." << endl;
        }
        else
        {
            cout << "Indeks data tidak valid." << endl;
        }
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

 
    while (head != nullptr)
    {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}



