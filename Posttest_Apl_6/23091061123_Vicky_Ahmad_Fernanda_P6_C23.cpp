#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib> // For system("cls")
using namespace std;

const int MaxData = 10;

struct Batagor {
    string nama[MaxData];
    int harga[MaxData];
};

struct Menu {
    Batagor menu;
    int pos = 0;
};

bool login(Menu* menuArray);
void clearScreen() {
    system("cls");
}

void Bubbe_sort_Ascending(Menu* menuArray);
int displayMenu() {
    int pilihan_admin;
    cout << "===== Menu Admin Batagor Palembang =====" << endl;
    cout << "1. Tampilkan Menu Batagor Palembang" << endl;
    cout << "2. Tambahkan Menu Batagor Palembang" << endl;
    cout << "3. Perbarui Menu Batagor Palembang" << endl;
    cout << "4. Hapus Menu Batagor Palembang" << endl;
    cout << "5. Kembali dari menu utama " << endl;
    cout << "Pilih Menu (1-5): "; fflush(stdin);
    cin >> pilihan_admin;
    return pilihan_admin;
}

int displaymenuuser() {
    int pilihan_user_search;
    cout << "Tampilkan Menu Search User" << endl;
    cout << "1. Search data secara Ascending" << endl;
    cout << "2. Seach data secara Discending" << endl;
    cout << "3. Kembali ke menu Utama " << endl;
    cout << "Masukkan Pilihan Anda: ";
    cin >> pilihan_user_search;
    return pilihan_user_search;
}

void display(Menu* menuArray) {
    if (menuArray->pos > 0) {
        cout << "Tampilkan Menu yang terdaftar : " << endl;
        for (int i = 0; i < menuArray->pos; i++) {
            cout << i + 1 << ". " << menuArray->menu.nama[i] << " : ";
            cout << menuArray->menu.harga[i] << endl;
        }
    }
    else {
        cout << "{Array kosong}" << endl;
    }
}
void binarySearchDescending(Menu* menuArray, const string& keyword) {
    // Sorting menuArray terlebih dahulu agar dapat melakukan pencarian biner
    Bubbe_sort_Ascending(menuArray);

    int low = 0;
    int high = menuArray->pos - 1;
    int foundIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (menuArray->menu.nama[mid] == keyword) {
            foundIndex = mid;
            break;
        } else if (menuArray->menu.nama[mid] < keyword) { // Perbandingan dibalik untuk pencarian menurun
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (foundIndex != -1) {
        cout << "Menu " << keyword << " ditemukan di indeks " << foundIndex + 1 << endl;
        cout << "Harga: " << menuArray->menu.harga[foundIndex] << endl;
    } else {
        cout << "Menu dengan kata kunci '" << keyword << "' tidak ditemukan." << endl;
    }
}

void Sequentia(Menu* menuArray, const string& keyword) {
    bool found = false;
    for (int i = 0; i < menuArray->pos; ++i) {
        if (menuArray->menu.nama[i].find(keyword) != string::npos) {
            cout << "Menu " << menuArray->menu.nama[i] << " ditemukan di indeks " << i + 1 << endl;
            cout << "Harga: " << menuArray->menu.harga[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Menu dengan kata kunci '" << keyword << "' tidak ditemukan." << endl;
    }
}

void insertion_sort(Menu* menuArray) {
    for (int i = 1; i < menuArray->pos; ++i) {
        string key_nama = menuArray->menu.nama[i];
        int key_harga = menuArray->menu.harga[i];
        int j = i - 1;
    
        // Pindahkan elemen yang lebih besar dari key ke posisi setelahnya
        while (j >= 0 && menuArray->menu.nama[j] > key_nama) {
            menuArray->menu.nama[j + 1] = menuArray->menu.nama[j];
            menuArray->menu.harga[j + 1] = menuArray->menu.harga[j];
            j = j - 1;
        }

        // Masukkan key ke posisi yang benar
        menuArray->menu.nama[j + 1] = key_nama;
        menuArray->menu.harga[j + 1] = key_harga;
    }
}

void Bubbe_sort_Ascending(Menu* menuArray) {
    for (int i = 0; i < menuArray->pos - 1; ++i) {
        for (int j = menuArray->pos - 1; j > i; --j) {
            if (menuArray->menu.harga[j] < menuArray->menu.harga[j - 1]) {
                // Swap harga and nama if prices are not in ascending order
                swap(menuArray->menu.harga[j], menuArray->menu.harga[j - 1]);
            }
        }
    }
}


void Seection_sort_discending(Menu* menuArray) {
    for (int i = 0; i < menuArray->pos - 1; ++i) {
        // Find the index of the maximum element in the unsorted portion (based on ASCII order)
        int maxIdx = i;
        for (int j = i + 1; j < menuArray->pos; ++j) {
            if (menuArray->menu.nama[j][0] > menuArray->menu.nama[maxIdx][0]) { // Compare first characters
                maxIdx = j;
            }
            else if (menuArray->menu.nama[j][0] == menuArray->menu.nama[maxIdx][0]) {
                // If first characters are equal, compare subsequent characters
                int k = 1;
                while (menuArray->menu.nama[j][k] == menuArray->menu.nama[maxIdx][k] && k < menuArray->menu.nama[j].length() && k < menuArray->menu.nama[maxIdx].length()) {
                    ++k;
                }
                if (menuArray->menu.nama[j][k] > menuArray->menu.nama[maxIdx][k]) {
                    maxIdx = j;
                }
            }
        }

        // Swap the maximum element with the first element of the unsorted portion
        swap(menuArray->menu.nama[i], menuArray->menu.nama[maxIdx]);
    }
}


void create(Menu* menuArray) {
    string ulang;
    int harga;
    do {
        if (menuArray->pos < MaxData) {
            cout << "Masukkan Menu Batagor yang ingin ditambahkan : "; fflush(stdin);
            getline(cin, menuArray->menu.nama[menuArray->pos]);
            cout << "Masukkan Harga Batagor ini : ";
            cin >> menuArray->menu.harga[menuArray->pos];
            menuArray->pos++;
            cout << "Menu Batagor Berhasil ditambahkan " << endl;
        }
        else {
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
    string baru_nama;
    int baru_harga;

    do {
        display(menuArray);
        cout << "Masukkan indeks menu yang ingin diubah: ";
        cin >> index;

        if (index >= 1 && index <= menuArray->pos) {
            cout << "Masukkan nama baru untuk menu: ";
            fflush(stdin);
            getline(cin, baru_nama);

            cout << "Masukkan harga baru untuk menu: ";
            cin >> baru_harga;

            // Update both nama and harga variables
            menuArray->menu.nama[index - 1] = baru_nama;
            menuArray->menu.harga[index - 1] = baru_harga;

            cout << "Menu berhasil diperbarui." << endl;
        }
        else {
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
            menuArray->menu.harga[i] = menuArray->menu.harga[i + 1];
        }
        menuArray->pos--;
        cout << "Menu berhasil dihapus." << endl;
    }
    else {
        cout << "Indeks tidak valid." << endl;
    }
}

void menu1(Menu* menuArray) {
    int pilihan_admin;
    do {
        clearScreen();
        pilihan_admin = displayMenu();
        switch (pilihan_admin) {
        case 1: {
            int pilih_menu_sort;
            if (pilihan_admin == 1)
            {
                cout << "Menu Sorting secara ascending " << endl;
                cout << "1. Sorting Insertion " << endl;
                cout << "2. Sorting Bubble (Harga)" << endl;
                cout << "3. Sorting Selection (Nama)" << endl;
                cout << "Masukkan Pilihan Anda: ";
                cin >> pilih_menu_sort;
                if (pilih_menu_sort == 1)
                {
                    clearScreen();
                    insertion_sort(menuArray);
                    display(menuArray);
                }
                else if (pilih_menu_sort == 2)
                {
                    clearScreen();
                    Bubbe_sort_Ascending(menuArray);
                    display(menuArray);
                }
                else if (pilih_menu_sort == 3)
                {
                    clearScreen();
                    Seection_sort_discending(menuArray);
                    display(menuArray);
                }
            }
            break; };
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
        case 5: {
            clearScreen();
            login(menuArray);
            break;
        }
        default:
            cout << "Pilihan Tidak Valid" << endl;
            break;
        }
        system("pause");
    } while (pilihan_admin != 5);

    cout << "Program berhenti...." << endl;
}
void menu2(Menu* menuArray) {
    int pilihan_user;
    do {
        pilihan_user = displaymenuuser();
        switch (pilihan_user) {
        case 1: {
            string keyword;
            cout << "Tampilkan Menu Search User" << endl;
            cout << "Masukkan kata kunci pencarian: ";
            cin.ignore(); // ignore previous newline character
            getline(cin, keyword);
            Sequentia(menuArray, keyword);
            break;
        }
        case 2: {
             string keyword;
            cout << "Tampilkan Menu Search User secara descending" << endl;
            cout << "Masukkan kata kunci pencarian: ";
            cin.ignore(); // ignore previous newline character
            getline(cin, keyword);
            binarySearchDescending(menuArray, keyword); // Panggil fungsi binarySearchDescending
            break;
        }
        default:
            cout << "Pilihan User tidak Valid" << endl;
            break;
        }
    } while (pilihan_user != 2);
    cout << "Program Berhenti....." << endl;
}

bool login(Menu* menuArray) {
    string pilih_login;
    do {
        cout << "|==========================================|\n";
        cout << "| < < Selamat Datang di Program ini! > >   |\n";
        cout << "|==========================================|\n";
        cout << "|    Silahkan login terlebih dahulu...     |\n";
        cout << "|==========================================|\n\n";
        cout << "1. Login Sebagai Admin\n";
        cout << "2. Login Sebagai User\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan anda: ";
        cin >> pilih_login;
        if (pilih_login == "1") {
            string username = "Vicky Ahmad Fernanda";//nick name admin
            string password = "2309106123";// pw admin
            int coba = 0;
            while (coba <= 3) {
                string Username1, Password1;
                cout << "Masukkan Username Anda : "; fflush(stdin);
                getline(cin, Username1);
                cout << "Masukkan Password Anda : "; fflush(stdin);
                getline(cin, Password1);
                if (Username1 == username && Password1 == password) {
                    cout << "Login Anda sebagai admin berhasil!!!" << endl;
                    menu1(menuArray);
                    return true;
                }
                else {
                    cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
                    coba++;
                }
                if (coba >= 3) {
                    cout << "Anda sudah 3x percobaan, akun anda telah di blokir" << endl;
                    exit(0);
                }
            }
        }
        else if (pilih_login == "2") {
            string username_user = "User";
            string password_user = "User";
            int coba = 0;
            while (coba <= 3) {
                string Username2, Password2;
                cout << "Masukkan Username Anda : "; fflush(stdin);
                getline(cin, Username2);
                cout << "Masukkan Password Anda : "; fflush(stdin);
                getline(cin, Password2);
                if (Username2 == username_user && Password2 == password_user) {
                    cout << "Login Anda sebagai pengguna berhasil!!!" << endl;
                    menu2(menuArray); // Menampilkan menu
                    return true;
                }
                else {
                    cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
                    coba++;
                }
                if (coba >= 3) {
                    cout << "Anda sudah 3x percobaan, akun anda telah di blokir" << endl;
                    exit(0);
                }
            }
        }
        else if (pilih_login == "3") {
            exit(0);
        }
    } while (pilih_login != "3");
    return false;
}

int main() {
    Menu menuArray;
    login(&menuArray);
    return 0;
}
