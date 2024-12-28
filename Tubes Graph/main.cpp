#include "graph.h"

int main() {
    graph G;
    bool stop = false;
    string asal, tujuan, nama;
    int scale, intensitas;
    adrVertex gunung;

    initGraph(G);

    while(!stop){
        int input;
        printMenu();
        cin >> input;

        if(input == 1){
            buildGraph(G);
            cout << endl;

        } else if(input == 2){
            cout << "Masukkan koneksi geologis (asal gunung, tujuan gunung, skala VEI antar gunung, ketik '-' dan 0 untuk berhenti)" << endl;
            cin >> asal >> tujuan >> scale;
            while (asal != "-" && tujuan != "-" && scale != 0) {
                addEdge(G, asal, tujuan, scale);
                cin >> asal >> tujuan >> scale;
            }
            cout << "Data behasil dimasukkan." << endl;
            cout << endl;

        } else if(input == 3){
            showGraph(G);
            cout << endl;

        } else if(input == 4){
            cout << "Masukkan nama gunung: ";
            cin >> nama;
            gunung = cariGunung(G, nama);
            if(gunung != nullptr){
                cout << "Data: " << endl;
                cout << "Gunung " << gunung->namaGunung << endl;
                adrEdge e = gunung->firstEdge;
                while (e != nullptr) {
                    cout << "\t(skala VEI antar gunung " << e->gunungTetangga << ", adalah " << e->scale << " VEI (Volcanic Explosivity Index))" << endl;
                    e = e->nextEdge;
                }
                cout << endl;
            } else {
                cout << "[Error] Data gunung tidak ditemukan." << endl;
                cout << endl;
            }

        } else if(input == 5){
            cout << "Masukkan nama gunung: ";
            cin >> nama;
            impact(G, nama);
            cout << endl;

        } else if(input == 6){
            mostErupted(G);
            cout << endl;

        } else if(input == 0){
            cout << "~~Program selesai~~" << endl;
            stop = true;

        } else {
            cout << "[ERROR] Masukkan input menu yang benar." << endl;
        }
    }

    return 0;
}
