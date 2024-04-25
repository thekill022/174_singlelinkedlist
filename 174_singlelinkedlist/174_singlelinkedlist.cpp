#include <iostream>
using namespace std;

//membuat sturct node
struct Node {
    int noMhs;
    string name;
    Node* next;
};

//set value START = NULLL
Node* START = NULL;

//membuat prosedur addNode()
void addNode() {
    int nim;
    string nama;
    Node* nodeBaru = new Node();
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    nodeBaru->noMhs = nim;
    nodeBaru->name = nama;
};

int main()
{
   
}

