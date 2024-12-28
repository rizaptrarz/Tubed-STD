#include "graph.h"

void createVertex(string nama, int intensitas, adrVertex& v) {
    v = new vertex();
    v->namaGunung = nama;
    v->intensitas = intensitas;
    v->firstEdge = nullptr;
    v->nextVertex = nullptr;
}

void initGraph(graph& G) {
    G.firstVertex = nullptr;
}

void addVertex(graph& G, string nama, int intensitas) {
    adrVertex v, p;
    createVertex(nama, intensitas, v);

    if (G.firstVertex == nullptr) {
        G.firstVertex = v;
    } else {
        p = G.firstVertex;
        while (p->nextVertex != nullptr) {
            p = p->nextVertex;
        }
        p->nextVertex = v;
    }
}

void buildGraph(graph& G) {
    string nama;
    int intensitas;

    cout << "Masukkan nama Gunung: ";
    cin >> nama;
    cout << "Masukkan intensitas meletus: ";
    cin >> intensitas;

    while (nama != "-" && intensitas >= 0) {
        addVertex(G, nama, intensitas);
        cout << "Masukkan nama Gunung: ";
        cin >> nama;
        cout << "Masukkan intensitas meletus: ";
        cin >> intensitas;
        cout << "Data berhasil dibuat.\n" << endl;
    }
    if(intensitas < 0){
        cout << "[ERROR] Intensitas gunung tidak bisa negatif." << endl;
    }
}

void createEdge(string tujuan, int scale, adrEdge &e) {
    e = new edge();
    e->gunungTetangga = tujuan;
    e->scale = scale;
    e->nextEdge = nullptr;
};

void addEdge(graph &G, string asal, string tujuan, int scale) {
    adrVertex v = G.firstVertex;
    while (v != nullptr && v->namaGunung != asal) {
        v = v->nextVertex;
    }
    if (v != nullptr) {
        adrEdge e;
        createEdge(tujuan, scale, e);
        if (v->firstEdge == nullptr) {
            v->firstEdge = e;
        } else {
            adrEdge temp = v->firstEdge;
            while (temp->nextEdge != nullptr) {
                temp = temp->nextEdge;
            }
            temp->nextEdge = e;
        }
    }
}

void showGraph(graph G) {
    adrVertex p = G.firstVertex;

    cout << "Data Gunung Aktif: " << endl;
    while (p != nullptr) {
        cout << "Gunung " << p->namaGunung << endl;
        adrEdge e = p->firstEdge;
        while (e != nullptr) {
            cout << "\t(skala VEI antar gunung " << e->gunungTetangga << ", adalah: " << e->scale << " VEI (Volcanic Explosivity Index))" << endl;
            e = e->nextEdge;
        }
        cout << endl;
        p = p->nextVertex;
    }
}

adrVertex cariGunung(graph G, string namaGunung) {
    adrVertex current = G.firstVertex;
    while (current != nullptr && current->namaGunung != namaGunung) {
        current = current->nextVertex;
    }
    return current;
}

void printMenu(){
    cout << "======================Daftar Menu=====================" << endl;
    cout << "1. Membuat data gunung" << endl;
    cout << "2. Memasukkan data gunung" << endl;
    cout << "3. Menampilkan data gunung" << endl;
    cout << "4. Mencari data gunung tertentu" << endl;
    cout << "5. Informasi seputar dampak letusan gunung tertentu" << endl;
    cout << "6. Data gunung paling sering meletus" << endl;
    cout << "0. Keluar" << endl;
    cout << "======================================================" << endl;
    cout << ">> Pilih menu : ";
}

void impact(graph G, string namaGunung){
    adrVertex gunung = cariGunung(G, namaGunung);

    if(gunung != nullptr){
        cout << "Jika gunung " << gunung->namaGunung << " meletus, maka:" << endl;
        adrEdge e = gunung->firstEdge;
        while (e != nullptr) {
            cout << ">> Daerah lintasan antara gunung " << e->gunungTetangga << " akan mengalami ";
            if(e->scale < 3){
                cout << "gempa bumi & longsoran material vulkanik" << endl;
            } else if(e->scale == 3 || e->scale == 4){
                cout << "gempa bumi, longsoran vulkanik, & hujan lahar" << endl;
            } else if(e->scale == 5 || e->scale == 6){
                cout << "gempa bumi, longsoran vulkanik, hujan lahar, & banjir bandang" << endl;
            } else if(e->scale == 7 || e->scale == 8){
                cout << "gempa bumi, longsoran vulkanik, hujan lahar, & tsunami" << endl;
            }
            e = e->nextEdge;
        }
    } else {
        cout << "[ERROR] Data gunung tidak ditemukan." << endl;
    }
}

void mostErupted(graph G){
    adrVertex v, max;

    max = G.firstVertex;
    v = max->nextVertex;

    while(v != nullptr){
        if(v->intensitas > max->intensitas){
            max = v;
        }
        v = v->nextVertex;
    }

    cout << "Gunung yang paling sering meletus adalah: " << max->namaGunung << endl;
    cout << "Dengan intensitas meletus sebanyak " << max->intensitas << " kali." << endl;
}
