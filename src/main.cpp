#include "fungsi.cpp"
#include "24game.cpp"

int main(){
    float bil[4];
    vector<float> bilangan;
    list<string> hasil;
    list<string> kartu = {"a","A","2","3","4","5","6","7","8","9","10","j","J","q","Q","k","K"};
    string opp[64] = {"+++","++-","++*","++/","+-+","+--","+-*","+-/","+*+","+*-","+**","+*/","+/+","+/-","+/*","+//","-++","-+-","-+*","-+/","--+","---","--*","--/","-*+","-*-","-**","-*/","-/+","-/-","-/*","-//","*++","*+-","*+*","*+/","*-+","*--","*-*","*-/","**+","**-","***","**/","*/+","*/-","*/*","*//","/++","/+-","/+*","/+/","/-+","/--","/-*","/-/","/*+","/*-","/**","/*/","//+","//-","//*","///"};
    
    splashScreen();
    cout << "\n---------------------------------------------"<< endl;


    bilangan = mintaInput(bil, kartu);

    for (int i=0; i<4; i++){
        bil[i] = bilangan[i];
    }

    cout << "---------------------------------------------"<< endl;
    for (int i=0; i<4; i++){
        cout << bil[i] << " ";
    }
    cout << "\n---------------------------------------------"<< endl;


    time_t start, end;
    start = clock();
    hasil = solve24(hasil, opp, bil);
    end = clock();
    
    for (list<string>::iterator i=hasil.begin(); i!=hasil.end();i++){
        cout << *i << endl;
    }

    cout << "\n"<< hasil.size() << " solution found!\n" << endl;
    cout << "Waktu eksekusi: " << (end-start)/(double)(1e3) << " detik\n" << endl;
    cout << "---------------------------------------------"<< endl;


    tanyaSave(bil, hasil);

    cout << "---------------------------------------------"<< endl;
    cout << "Program selesai" << endl;

}