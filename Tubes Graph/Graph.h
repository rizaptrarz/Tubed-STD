#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef struct vertex* adrVertex;
typedef struct edge* adrEdge;

struct vertex {
    string namaGunung;
    int intensitas;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    string gunungTetangga;
    int scale;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex(string nama, adrVertex& v);
void initGraph(graph& G);
void addVertex(graph& G, string nama);
void buildGraph(graph& G);
void createEdge(string tujuan, int scale, adrEdge &e);
void addEdge(graph &G, string asal, string tujuan, int scale);
void showGraph(graph G);
adrVertex cariGunung(graph G, string namaGunung);
void printMenu();
void impact(graph G, string namaGunung);
void mostErupted(graph G);

#endif
