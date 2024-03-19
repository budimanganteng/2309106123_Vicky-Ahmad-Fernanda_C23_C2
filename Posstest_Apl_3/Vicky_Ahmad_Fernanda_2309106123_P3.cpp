#include <iostream>
using namespace std;
#define max 10
string array[max];
int pos = 0;
void screen(){
    system("cls");
}
// Fungsi login
bool login() {
    string pilih_login;
    do
    {
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
        string Username1, Password1;
        cin.ignore();
        cout << "Masukkan Username Anda : ";
        getline(cin, Username1);
        cout << "Masukkan Password Anda : ";
        getline(cin, Password1);
        if (Username1 == username && Password1 == password) {
            cout << "Login Anda Berhasil!!!" << endl;
            return true;
        } else {
            cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
            coba++; // ketika salah akan memberikan 3x
        }
        // Memeriksa apakah sudah lebih dari 3x coba
        if (coba >= 3) {
            cout << "anda sudah 3x percobaan, akun anda telah di blokir" << endl;
            exit(0) ; // akun di blokir maka kembalikan 1
        }
    }
}else if (pilih_login == "2")
{
    exit(0);
}

}while (pilih_login != "2");
    return false;
}

// Fungsi Menu Utama
int lihat_menu(){
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
    string ulang;
    do
    {
        display();
        cout << "Masukkan index yang mau di ubah: ";
        cin >> x;
        cin.ignore();
        cout << "Masukkan Menu Batagor Baru : " ;
        getline(cin,  array[x-1]);//proses terjadinya update
        cout << "Apakah ingin Update menu lagi (Y/N)? : ";
        cin >> ulang;
    } while (ulang == "N" || ulang == "N");
    screen();
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
//Rekursif
void menu(){
    int pilih;
    string ulang;
    do{ 
        screen();
        pilih = lihat_menu();
        switch (pilih)
        {
        case 1:
            do{
                    display(); 
                    cout << "Kembali ke menu awal (y): ";
                    cin >> ulang;
                } while(ulang != "y" && ulang != "Y");
                menu();
                screen();
            break;
        case 2:
            create();
            menu();
            break;
        case 3:
            update(); 
            menu();
            break;
        case 4:
            hapus();
            menu();
            break;
        case 5:
            cout << "keluar dari program....."<<endl;
            exit(0);
            break;
        default:
            cout << "Pilihan Tidak Valid" << endl;
            break;
        }
    }while (pilih != 5);
        cout << "program berhenti...." << endl;
}

// Fungsi utama yaitu Crud di pilih
int main(){
    login();
    menu();
        return 0;
}