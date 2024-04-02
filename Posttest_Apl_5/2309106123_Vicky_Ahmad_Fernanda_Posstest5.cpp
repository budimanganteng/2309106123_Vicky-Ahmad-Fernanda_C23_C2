#include <iostream>
using namespace std;

const int MaxData = 10;

struct Batagor {
    string nama[MaxData]; //Deklarasi penyimpanan array yang sebelumnya Variable Array menjadi Variable nama
};

struct Menu {
    Batagor menu;
    int pos = 0; 
};

void clearScreen() {
    system("cls");
}

int displayMenu() {
    int pilih;
    cout << "===== Menu Admin Batagor Palembang =====" << endl;
    cout << "1. Tampilkan Menu Batagor Palembang" << endl;
    cout << "2. Tambahkan Menu Batagor Palembang" << endl;
    cout << "3. Perbarui Menu Batagor Palembang" << endl;
    cout << "4. Hapus Menu Batagor Palembang" << endl;
    cout << "5. Keluar dari menu utama " << endl;
    cout <<"Pilih Menu (1-5): "; fflush(stdin);
    cin >> pilih; 
    return pilih; 
}

void display(Menu* menuArray) {
    if (menuArray->pos > 0) {
        cout << "Tampilkan Menu yang terdaftar : " << endl;
        for (int i = 0; i < menuArray->pos; i++) {
            cout << i+1 << ". " << menuArray->menu.nama[i] << endl;
        }
    } else {
        cout << "{Array kosong}" << endl;
    }
}

void create(Menu* menuArray) {
    string ulang;
    do {
        if (menuArray->pos < MaxData) {
            cout << "Masukkan Menu Batagor yang ingin ditambahkan : "; fflush(stdin);
            getline(cin, menuArray->menu.nama[menuArray->pos]);
            menuArray->pos++;
            cout << "Menu Batagor Berhasil ditambahkan " << endl;
        } else {
            cout << "Database sudah penuh " << endl;
            break;
        }
        cout << "Apakah ingin memasukkan menu lagi? (Y/N): "; fflush(stdin);
        cin >> ulang;
    } while (ulang == "Y" || ulang == "y");
}

void update(Menu* menuArray) {
    int index;
    string ulang;
    do {
        display(menuArray);
        cout << "Masukkan index yang mau diubah: "; fflush(stdin);
        cin >> index;
        if (index >= 1 && index <= menuArray->pos) {
            cout << "Masukkan Menu Batagor Baru : "; fflush(stdin);
            getline(cin, menuArray->menu.nama[index - 1]);
            cout << "Menu berhasil diperbarui." << endl;
        } else {
            cout << "Indeks tidak valid." << endl;
        }
        cout << "Apakah ingin Update menu lagi (Y/N)? : ";
        cin >> ulang;
    } while (ulang == "Y" || ulang == "y");
    clearScreen();
}

void Hapus(Menu* menuArray) {
    int index;
    display(menuArray);
    cout << "Masukkan indeks menu yang ingin dihapus: "; fflush(stdin);
    cin >> index;
    if (index >= 1 && index <= menuArray->pos) {
        for (int i = index - 1; i < menuArray->pos - 1; ++i) {
            menuArray->menu.nama[i] = menuArray->menu.nama[i + 1];
        }
        menuArray->pos--;
        cout << "Menu berhasil dihapus." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

void menu1(Menu* menuArray) {
    int pilih;
    do { 
        clearScreen();
        pilih = displayMenu();
        switch (pilih) {
            case 1:
                clearScreen();
                display(menuArray);
                break;
            case 2:
                clearScreen();
                create(menuArray);
                break;
            case 3:
                clearScreen();
                update(menuArray); 
                break;
            case 4:
                clearScreen();
                Hapus(menuArray);
                break;
            case 5:
                cout << "Keluar dari program....." << endl;
                break;
            default:
                cout << "Pilihan Tidak Valid" << endl;
                break;
        }
        system("pause");
    } while (pilih != 5);

    cout << "Program berhenti...." << endl;
}

bool login(Menu* menuArray) {
    string pilih_login;
    do {
        cout << "|==========================================|\n";
        cout << "| < < Selamat Datang di Program ini! > > |\n";
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
                cout << "Masukkan Username Anda : "; fflush(stdin);
                getline(cin, Username1);
                cout << "Masukkan Password Anda : "; fflush(stdin);
                getline(cin, Password1);
                if (Username1 == username && Password1 == password) {
                    cout << "Login Anda Berhasil!!!" << endl;
                    menu1(menuArray);
                    return true;
                } else {
                    cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
                    coba++;
                }
                if (coba >= 3) {
                    cout << "Anda sudah 3x percobaan, akun anda telah di blokir" << endl;
                    exit(0);
                }
            }
        } else if (pilih_login == "2") {
            exit(0);
        }
    } while (pilih_login != "2");
    return false;
}

int main() {
    Menu menuArray; 
    login(&menuArray); 
    return 0;
}
