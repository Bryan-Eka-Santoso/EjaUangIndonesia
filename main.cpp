#include <iostream>
#include <string>

using namespace std;

// Procedure Untuk Mengeja Angka 3 Digit
void eja1sd999(int n){
    int s, p, r;
    string ejaDigit[10] = {"","Satu ", "Dua ", "Tiga ", "Empat ", "Lima ", "Enam ", "Tujuh ", "Delapan ", "Sembilan "};
//    Array Untuk Angka Belasan
    string ejaDigitBelas[10] = {"","Sebelas ", "Dua Belas ", "Tiga Belas ", "Empat Belas ", "Lima Belas ", "Enam Belas ", "Tujuh Belas ", "Delapan Belas ", "Sembilan Belas "};

    s = n % 10;
    p = n / 10 % 10;
    r = n / 100 % 10;

//    Cek Anggka Seratus
    if(r > 1){
        cout << ejaDigit[r] << "Ratus ";
    } else if (r == 1) {
        cout << "Seratus ";
    }

//    Cek Angka Belasan Dan Juga Sepuluh
    if(p == 1 && s > 0){
        cout << ejaDigitBelas[s];
    } else if (p > 0){
        if(p > 1){
            cout << ejaDigit[p] << "Puluh ";
        } else {
            cout << "Sepuluh ";
        }
        if (s > 0) cout << ejaDigit[s];
    } else if (s > 0){
       cout << ejaDigit[s];
    }
}

void eja(int n)
{
    int a, b, c;

    a = n / 1000000;
    b = n / 1000 % 1000;
    c = n % 1000;

//    Cek Besaran Angka Dan Juga Cek Untuk Angka Seribuan
    if (n > 999999){
        eja1sd999(a);
        cout << "Juta ";
        eja1sd999(b);
        cout << "Ribu ";
        eja1sd999(c);
        cout << "Rupiah ";
    } else if (n > 999) {
        if (b == 1){
            cout << "Seribu ";
        } else {
            eja1sd999(b);
            cout << "Ribu ";
        }
        eja1sd999(c);
        cout << "Rupiah ";
    } else {
        eja1sd999(c);
        cout << "Rupiah ";
    }
}
int main()
{
    double n;

    do {
        cout << "Jumlah Uang: ";
        cin >> n;
    } while (n < 1 || n > 999999999);

    eja(n);
    cout << endl;
    return 0;
}
