#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

void saveFile(string filename,int bil[4], list<string> kartu){
    //kartu nanti dihapus diganti sama hasil
    
    // buat file
    ofstream File("..//test//" + filename + ".txt");
    // tulis input
    for (int i = 0; i < 4; i++){
        if(bil[i] == 1){
            File << "A ";
        }else if(bil[i] == 11){
            File << "J ";
        }else if(bil[i] == 12){
            File << "Q ";
        }else if(bil[i] == 13){
            File << "K ";
        }else{
            File << bil[i] << " ";
        }
    }
    File << endl;

    // tulis jumlah hasil
    int total = kartu.size();
    File << total << " Solution Found" << endl;

    // tulis hasil
    for (int i=0; i<4; i++){
        // nanti diganti sama hasil
        File << bil[i] << endl;
    }
    File.close();
}


int main(){
    string input[4];
    int bil[4];
    int bilOri[4];
    list<string> kartu = {"a","A","2","3","4","5","6","7","8","9","10","j","J","q","Q","k","K"};
    string opp[64] = {"+++","++-","++*","++/","+-+","+--","+-*","+-/","+*+","+*-","+**","+*/","+/+","+/-","+/*","+//","-++","-+-","-+*","-+/","--+","---","--*","--/","-*+","-*-","-**","-*/","-/+","-/-","-/*","-//","*++","*+-","*+*","*+/","*-+","*--","*-*","*-/","**+","**-","***","**/","*/+","*/-","*/*","*//","/++","/+-","/+*","/+/","/-+","/--","/-*","/-/","/*+","/*-","/**","/*/","//+","//-","//*","///"};
    
    cout << "Input sendiri?? (y/n)" << endl;
    char inputSendiri;
    cin >> inputSendiri;
    while(inputSendiri != 'y' && inputSendiri != 'Y' && inputSendiri != 'n' && inputSendiri != 'N'){
        cout << "Masukan tidak sesuai" << endl;
        cin >> inputSendiri;
    }

    if(inputSendiri == 'y' || inputSendiri == 'Y'){
        cout << "Masukkan 4 kartu: " << endl;

        for (int i=0; i<4; i++){
            // minta input sekalian validasi
            do{
                cin >> input[i];
                if(find(kartu.begin(), kartu.end(), input[i]) == kartu.end()){
                    cout << "Masukan tidak sesuai" << endl;
                }
            }while(find(kartu.begin(), kartu.end(), input[i]) == kartu.end());
        }
        for (int i=0; i<4; i++){
        // konversi string ke integer
            if(input[i] == "a" || input[i] == "A"){
                bil[i] = 1;
            }else if(input[i] == "j" || input[i] == "J"){
                bil[i] = 11;
            }else if(input[i] == "q" || input[i] == "Q"){
                bil[i] = 12;
            }else if(input[i] == "k" || input[i] == "K"){
                bil[i] = 13;
            }else{
                bil[i] = stoi(input[i]);
            }

            // else if(input[i] == "1" || input[i] == "2" || input[i] == "3" || input[i] == "4" || input[i] == "5" || input[i] == "6" || input[i] == "7" || input[i] == "8" || input[i] == "9" || input[i] == "10"){
            //     bil[i] = stoi(input[i]);
            // }
        }
    }else{
        // generate random
        srand(time(0));
        for (int i=0; i<4; i++){
            bil[i] = 1 + (rand() % 13);
        }
    }
    
    for(int i=0; i<4; i++){
        bilOri[i] = bil[i];
    }
    

    cout << "----------------------"<< endl;
    for (int i=0; i<4; i++){
        cout << bil[i] << endl;
    }
    cout << "----------------------"<< endl;

    int temp[4];

    for(int i=0; i<24 ;i++){ // iterasi buat 4 angka
        for(int j=0; j<64; j++){ // iterasi buat 4 operator
            for(int k=0; k<3; k++){ // iterasi isi operator
                // if(opp[j][k] == '+'){
                //     temp[i] = bil[i] + bil[i+1];
                // }else if(opp[j][i] == '-'){
                //     temp[i] = bil[i] - bil[i+1];
                // }else if(opp[j][i] == '*'){
                //     temp[i] = bil[i] * bil[i+1];
                // }else if(opp[j][i] == '/'){
                //     temp[i] = bil[i] / bil[i+1];
                // }
            }
        }
    }










    // save file
    cout << "Apakah ingin menyimpan solusi?? (y/n)" << endl;
    char save;
    cin >> save;
    while(save != 'y' && save != 'Y' && save != 'n' && save != 'N'){
        cout << "Masukan tidak sesuai" << endl;
        cin >> save;
    }

    if(save == 'y' || save == 'Y'){
        string filename;
        cout << "Masukkan nama file: ";
        cin >> filename;
        saveFile(filename, bilOri, kartu);
    }

    cout << "----------------------"<< endl;
    cout << "Program selesai" << endl;

}