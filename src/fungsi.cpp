
#include "namaFungsi.hpp"

void saveFile(string filename,float bil[], list<string> hasil){

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
    int total = hasil.size();
    File << total << " Solution Found" << endl;

    // tulis hasil ke file
    for (list<string>::iterator i = hasil.begin();i != hasil.end();i++){
        File << *i << endl;
    }
    File.close();
}

void tanyaSave(float bil[], list<string> hasil){
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
        saveFile(filename, bil, hasil);
    }

}


vector<float> mintaInput(float bil[], list<string> kartu){
    string input[4];
    cout << "Input sendiri?? (y/n)" << endl;
    char inputSendiri;
    cin >> inputSendiri;
    while(inputSendiri != 'y' && inputSendiri != 'Y' && inputSendiri != 'n' && inputSendiri != 'N'){
        cout << "Masukan tidak sesuai" << endl;
        cin >> inputSendiri;
    }

    if(inputSendiri == 'y' || inputSendiri == 'Y'){
        cout << "\nMasukkan 4 kartu: " << endl;

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
        // konversi string ke float
            if(input[i] == "a" || input[i] == "A"){
                bil[i] = 1;
            }else if(input[i] == "j" || input[i] == "J"){
                bil[i] = 11;
            }else if(input[i] == "q" || input[i] == "Q"){
                bil[i] = 12;
            }else if(input[i] == "k" || input[i] == "K"){
                bil[i] = 13;
            }else{
                bil[i] = stof(input[i]);
            }
        }
    }else{
        // generate random
        srand(time(0));
        for (int i=0; i<4; i++){
            bil[i] = 1 + (rand() % 13);
        }
    }
    vector<float> bill;

    for (int i=0; i<4; i++){
        bill.push_back(bil[i]);
    }

    return bill;
}

void splashScreen(){
    cout <<  " ___  _  _      _____          __  __ ______\n|__ \\| || |    / ____|   /\\   |  \\/  |  ____|\n   ) | || |_  | |  __   /  \\  | \\  / | |__\n  / /|__   _| | | |_ | / /\\ \\ | |\\/| |  __|\n / /_   | |   | |__| |/ ____ \\| |  | | |____\n|____|  |_|    \\_____/_/    \\_\\_|  |_|______|" << endl;                                             
}

vector<string> floatToString(vector<float> bil){
    vector<string> bilangan;
    for (int i=0; i<4; i++){
        if(bil[i] == 1){
            bilangan.push_back("A");
        }else if(bil[i] == 11){
            bilangan.push_back("J");
        }else if(bil[i] == 12){
            bilangan.push_back("Q");
        }else if(bil[i] == 13){
            bilangan.push_back("K");
        }else{
            bilangan.push_back(to_string((int)bil[i]));
        }
    }
    return bilangan;
}