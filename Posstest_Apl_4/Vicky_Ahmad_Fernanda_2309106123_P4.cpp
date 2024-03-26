#include <iostream>
using namespace std;

void screen(){
    system("cls");
}

struct Batagor {
    string nama;
} ;

struct Menu{
    Batagor menu;
    int pos;
}; 
struct Menu Array[10];
// array of struct Menu

// Fungsi Menu Utama
int lihat_menu(int index) {
    int pilih;
    cout << "===== Menu Admin Batagor Palembang =====" << endl;
    cout << "1. Tampilkan Menu Batagor Palembang" << endl;
    cout << "2. Tambahkan Menu " << endl;
    cout << "3. Perbarui Menu" << endl;
    cout << "4. Hapus Menu" << endl;
    cout << "5. Keluar dari menu utama " <<endl;
    cout <<"Pilih Menu (1-5): ";
    cin >> pilih; 
    return pilih; 
}

// Fungsi Untuk menampilkan menu batagor
void display() {
    Menu menu;
    if (Array[0].pos > 0) {
        cout << "Tampilkan Menu yang terdaftar : " << endl;
        for (int i = 0; i < Array[0].pos; i++) {
            cout << i+1 << ". " << Array[i].menu.nama<< endl;
        }
    } else {
        cout << "{Array kosong}" << endl;
    }
}

// Fungsi Menambahkan menu Batagor
void create() {
    Menu menu;
    string ulang;
    do {
        if (Array[0].pos< 10) {
            cout << "Masukkan Menu Batagor yang ingin ditambahkan : ";fflush(stdin);
            getline(cin, Array[Array[0].pos].menu.nama);
            Array[0].pos++;
            cout << "Menu Batagor Berhasil ditambahkan " << endl;
        } else {
            cout << " Database sudah penuh " << endl;
            break;
        }
        cout << "Apakah ingin memasukkan menu lagi? (Y/N): ";
        cin >> ulang;
    } while (ulang == "Y" || ulang == "y");
}

// Fungsi Untuk Memperbarui menu Batagor
void update() {
    Menu menu;
    int index_lama;
    string ulang;
    do {
        display();
        cout << "Masukkan index yang mau di ubah: ";
        cin >> index_lama;
        cout << "Masukkan Menu Batagor Baru : " ; fflush(stdin);
        getline(cin, Array[index_lama-1].menu.nama);
        cout << "Apakah ingin Update menu lagi (Y/N)? : ";
        cin >> ulang;
    } while (ulang == "Y" || ulang == "y");
    screen();
}

// fungsi untuk menghapus menu batagor
void hapus() {
    Batagor menu;
    if (Array[0].pos == 0) {
        cout << "Tidak ada menu yang tersedia untuk dihapus." << endl;
        return;
    }
    display();
    int index;
    cout << "Masukkan indeks menu yang ingin dihapus: "; fflush(stdin);
    cin >> index;

    if (index < 1 || index > Array[0].pos) {
        cout << "Indeks tidak valid." << endl;
        return;
    }
    for (int i = index - 1; i < Array[0].pos - 1; ++i) {
        Array[i] = Array[i + 1];
    }
    Array[0].pos--;
    cout << "Menu berhasil dihapus." << endl;
}

void menu1() {
    int index = 0; 
    int pilih;
    string ulang;
    do { 
        screen();
        pilih = lihat_menu(index);
        switch (pilih) {
            case 1:
                do {
                    display(); 
                    cout << "Kembali ke menu awal (y): ";
                    cin >> ulang;
                } while(ulang != "y" && ulang != "Y");
                screen();
                break;
            case 2:
                create();
                break;
            case 3:
                update(); 
                break;
            case 4:
                hapus();
                break;
            case 5:
                cout << "keluar dari program....."<<endl;
                exit(0);
                break;
            default:
                cout << "Pilihan Tidak Valid" << endl;
                break;
        }
    } while (pilih != 5);
    cout << "program berhenti...." << endl;
}

bool login() {
    string pilih_login;
    do {
        cout << "|==========================================|\n";
        cout << "|  < < Selamat Datang di Program ini! > >  |\n";
        cout << "|==========================================|\n";
        cout << "|    Silahkan login terlebih dahulu...     |\n";
        cout << "|==========================================|\n\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Masukkan pilihan anda: "; 
        cin >> pilih_login;
        if (pilih_login == "1") {
            string username = "Vicky Ahmad Fernanda";
            string password = "2309106123";
            int coba = 0;
            while (coba <= 3) {
                string Username1, Password1;
                cout << "Masukkan Username Anda : ";fflush(stdin);
                getline(cin, Username1);
                cout << "Masukkan Password Anda : "; fflush(stdin);
                getline(cin, Password1);
                if (Username1 == username && Password1 == password) {
                    cout << "Login Anda Berhasil!!!" << endl;
                    menu1(); // Panggil menu1 setelah login berhasil
                    return true;
                } else {
                    cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
                    coba++;
                }
                // Memeriksa apakah sudah lebih dari 3x coba
                if (coba >= 3) {
                    cout << "anda sudah 3x percobaan, akun anda telah di blokir" << endl;
                    exit(0) ;
                }
            }
        } else if (pilih_login == "2") {
            exit(0);
        }
    } while (pilih_login != "2");
    return false;
}

// Fungsi utama yait
int main(){
    login();
    menu1();
    return 0;
}