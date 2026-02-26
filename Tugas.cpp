//Masukkan Header atau Library yang diperlukan 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Buat fungsi compress untuk merubah array karakter yang ada menjadi bentuk baru 
int compress(vector<char>& chr) {
    int x = 0; //deklarasi sebelum masuk ke dalam while
    int y = 0; //deklarasi sebelum masuk ke dalam while
    int n = chr.size(); //Simpan panjang array ke dalam variabel n
    
    //Looping untuk melakukan operasi pada isi data array
    while (y < n) {
        char nc = chr[y]; //simpan karkater yang sedang diproses ke dalam variabel nc
        int count = 0; //Reset Counter tiap bertemu karakter baru pada array
        
        //Loop, Hitung karakter yang sama muncul berturut turut 
        //dengan syarat y masih kurang dari panjang array dan data pada y masih sama dengan nc
        while (y < n && chr[y] == nc) {
            y++; //Majuin Pointer y
            count++;
        }
        
        //Masukkan karakter asli ke dalam X++
        chr[x++] = nc;
        
        //Jika karakter terhitung lebih dari satu kali maka idganti dengan angka 
        if (count > 1) {
            string hitungStr = to_string(count); // Ubah angka count menjadi string 
            for (char c : hitungStr) { // Loop tip[ digit di string count 
                chr[x++] = c; // Tulis digit setelah perubahan ke dalam array kemudian majukan
            }
        }
    }
    
    return x; // Return panjang array setelah dikompres 
}

int main() {
    //Deklarasi dan inisialisasi array (nilai awal)
    vector<char> chars = {'a', 'a', 'b', 'b', 'c'};
    
    int newLine = compress(chars); //Memanggil fungsi compress, open array chars untuk dimasukkan ke dalam fungsi compress
    
    cout << "Panjang: " << newLine << endl; //Print panjang array setelah dikompres 
    cout << "Hasil: [";
    for (int i = 0; i < newLine; i++) { //Loop cuma sampai newline tidak lebih, sisanya array tidak terpakai
        cout << "\"" << chars[i] << "\"";
        if (i < newLine - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}