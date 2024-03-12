#include <iostream>
using namespace std;
#define max 10
string array[max];
int pos = 0;
void screen(){
    system("cls");
}
// Fungsi login
void login() {
    string pilih_login; 
    cout << "|==========================================|\n";
    cout << "|  < < Selamat Datang di Program ini! > >  |\n";
    cout << "|==========================================|\n";
    cout << "|    Silahkan login terlebih dahulu...     |\n";
    cout << "|==========================================|\n\n";
    cout << "1. Login\n";
    cout << "2. Keluar\n";
    cout << "Masukkan pilihan anda: "; 
    cin >> pilih_login;
    if (pilih_login == "1"){
    
    string username = "Vicky Ahmad Fernanda";
    string password = "2309106123";
    int coba = 0; // nilai awal dari variable coba
    while (coba <= 3) {
        string x, y;
        cin.ignore();
        cout << "Masukkan Username Anda : ";
        getline(cin, x);
        cout << "Masukkan Password Anda : ";
        getline(cin, y);

        if (x == username && y == password) {
            cout << "Login Anda Berhasil!!!" << endl;
            return ;
        } else {
            cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
            coba++; // ketika salah akan memberikan 3x
            
        }
        // Memeriksa apakah sudah lebih dari 3x coba
        if (coba >= 3) {
            cout << "anda sudah 3x percobaan, akun anda telah di blokir" << endl;
            return ; // akun di blokir maka kembalikan 1
        }
    }
    return ;//mengembalikan fungsi
}}

// Fungsi Untuk menampilkan menu batagor
void display(){
    if (pos > 0)
    {
    cout << "Tampilkan Menu yang terdaftar : " << endl;
    for (int i = 0; i < pos; i++){//proses terjadinya perulangan untuk menampilkan
        cout << i+1 << ". " << array[i] << endl;
        }
    }else {
        cout << "{Array kosong}" << endl;
    }
    
    }
// Fungsi Menambahkan menu Batagor
void create(){
    string ulang;
    do{
        if (pos < max){
            cin.ignore();
            cout << "Masukkan Menu Batagor yang ingin di tambahkan : " ;
            getline(cin, array[pos]);
            pos++;//untuk menambahkan menu batagor
            cout << " Menu Batagor Berhasil di tambahkan " << endl;
        }else {
            cout << " Database sudah penuh " << endl;
            break;
        }
        cout << "Apakah ingin memasukkan menu lagi? (Y/N): ";
        cin >> ulang;
    } while (ulang == "Y" || ulang == "y"); // Periksa baik huruf besar maupun huruf kecil
}
// Fungsi Untuk Memperbarui menu Batagor
void update(){
    int x;
    display();
    cout << "Masukkan index yang mau di ubah: ";
    cin >> x;
    cin.ignore();
    cout << "Masukkan Menu Batagor Baru : " ;
    getline(cin,  array[x-1]);//proses terjadinya update
}
// fungsi untuk menghapus menu batagor
void hapus(){
    if (pos == 0) {//kondisi ketika pos = 0
        cout << "Tidak ada menu yang tersedia untuk dihapus." << endl;
        return;
    }
    display();
    int index;
    cout << "Masukkan indeks menu yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > pos) {//kondisi ketika index tidak di temukan
        cout << "Indeks tidak valid." << endl;
        return;
    }
    for (int i = index - 1; i < pos - 1; ++i) {
        array[i] = array[i + 1];
    }//terjadinya perulangan untuk menghapus menu
    pos--;
    cout << "Menu berhasil dihapus." << endl;
}

// Fungsi utama yaitu Crud di pilih
int main(){
    login();
    int pilih;
    string ulang;
    do{ 
        screen();
        cout << "===== Menu Admin Batagor Palembang =====" << endl;
        cout << "1. Tampilkan Menu Batagor Palembang" << endl;
        cout << "2. Tambahkan Menu " << endl;
        cout << "3. Perbarui Menu" << endl;
        cout << "4. Hapus Menu" << endl;
        cout << "5. Keluar dari menu utama " <<endl;
        cout <<"Pilih Menu (1-5): ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            do{
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
            do{
                    update(); 
                    cout << "Kembali ke menu awal (y): ";
                    cin >> ulang;
                } while(ulang != "y" && ulang != "Y");
                screen();
        case 4:
            hapus();
            break;
        case 5:
            cout << "Kembali ke menu utama....."<<endl;
            login();
            return 1;
            break;
        default:
            cout << "Pilihan Tidak Valid" << endl;
            break;
        }
    }while (pilih != 5);
        cout << "program berhenti...." << endl;
        return 0;
}