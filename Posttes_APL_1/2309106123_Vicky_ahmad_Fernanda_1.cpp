#include <iostream>
using namespace std;

// Fungsi Login menggunakan password default
int login() {
    string username = "Vicky Ahmad Fernanda";
    string password = "2309106123";
    int coba = 0; // nilai awal dari variable coba
    while (coba <= 3) {
        string x, y;
        cout << "Masukkan Username Anda : ";
        getline(cin, x);
        cout << "Masukkan Password Anda : ";
        getline(cin, y);

        if (x == username && y == password) {
            cout << "Login Anda Berhasil!!!" << endl;
            return 0;
        } else {
            cout << "Username Dan Password yang anda masukkan salah. silahkan coba lagi" << endl;
            coba++; // ketika salah akan memberikan 3x
            
        }
        // Memeriksa apakah sudah lebih dari 3x coba
        if (coba >= 3) {
            cout << "anda sudah 3x percobaan, akun anda telah di blokir" << endl;
            return 1; // akun di blokir maka kembalikan 1
        }
    }
    return 0;//mengembalikan fungsi
}

// fungsi konversi suhu
void celsius_ke_lain(){
    float celsius;
    cout << "Masukkan Suhu (Celsius): ";
    cin >> celsius;

    //rumusnya
    float reamur = (4.0 / 5.0)*celsius;
    float fahrenheit = (9.0 / 5.0)*celsius+32;
    float kelvin = celsius+273.15;
    
    //output
    cout << "============================"<<endl;
    cout << "Hasil konversi:" << endl;
    cout << "Reamur: " << reamur << endl;
    cout << "Fahrenheit: " << fahrenheit << endl;
    cout << "Kelvin: " << kelvin << endl;
    cout << "============================"<<endl;
}

void reamur_ke_lain() {
    float reamur;
    cout << "Masukkan suhu dalam Reamur: ";
    cin >> reamur;

    //rumusnya
    float celcius = (5.0 / 4.0) * reamur;
    float fahrenheit = (9.0 / 4.0) * reamur + 32;
    float kelvin = (5.0 / 4.0) * reamur + 273.15;

    //output
    cout << "============================"<<endl;
    cout << "Hasil konversi:" << endl;
    cout << "Celcius: " << celcius << endl;
    cout << "Fahrenheit: " << fahrenheit << endl;
    cout << "Kelvin: " << kelvin << endl;
    cout << "============================"<<endl;
}
void fahrenheit_ke_lain(){
    float fahrenheit;
    cout << "Masukkan suhu dalam Fahrenheit: ";
    cin >> fahrenheit;
    
    //rumusnya
    float celcius = (5.0 / 9.0) * (fahrenheit - 32);
    float reamur = (4.0 / 9.0) * (fahrenheit - 32);
    float kelvin = (5.0 / 9.0) * (fahrenheit - 32) + 273.15;
    
    //output
    cout << "============================"<<endl;
    cout << "Hasil konversi:" << endl;
    cout << "Celcius: " << celcius << endl;
    cout << "Reamur: " << reamur << endl;
    cout << "Kelvin: " << kelvin << endl;
    cout << "============================"<<endl;
}

void kelvin_ke_lain() {
    float kelvin;
    cout << "Masukkan suhu dalam Kelvin: ";
    cin >> kelvin;

    //rumusnya
    float celcius = kelvin - 273.15;
    float reamur = (4.0 / 5.0) * (kelvin - 273.15);
    float fahrenheit = (9.0 / 5.0) * (kelvin - 273.15) + 32;

    //output
    cout << "============================"<<endl;
    cout << "Hasil konversi:" << endl;
    cout << "Celcius: " << celcius << endl;
    cout << "Reamur: " << reamur << endl;
    cout << "Fahrenheit: " << fahrenheit << endl;
    cout << "============================"<<endl;
}


int menu() {
    cout << " MENU KONVERSI SUHU " << endl;
    cout << "====================" << endl;
    cout << "1. Konversi Celcius" << endl;
    cout << "2. Konversi Reamur" << endl;
    cout << "3. Konversi Farenheit" << endl;
    cout << "4. Konversi Kelvin" << endl;
    cout << "5. Keluar" << endl;
    cout << "====================" << endl;
}

//fungsi utama
int main() {
    //memanggil fungsi login
    if (!login()) {
    }else{
        return 1;
    }
    
    string pilih_menu;
    while (true){//untuk memanggil fungsi menu
        menu();
        cout << "Pilih menu (1-5): ";
        cin >> pilih_menu;
        
        if (pilih_menu == "1")
        {
            celsius_ke_lain();
            continue;
        }else if (pilih_menu == "2")
        {
            reamur_ke_lain();
            continue;
        }else if (pilih_menu == "3")
        {
            fahrenheit_ke_lain();
            continue;
        }else if (pilih_menu == "4")
        {
            kelvin_ke_lain();
            continue;
        }else if (pilih_menu == "5")
        {
            cout<< "Anda Telah keluar dari program"<<endl;
            break;
        }else
        {
            cout<<"pilihan anda invalid mohon pilih (1-5)"<<endl;
            continue;
        }
return 0;
}
}

