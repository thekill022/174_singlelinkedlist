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

    //kondisi jika STAR == NULL atau nim lebih kecil sama dengan START->noMhs
    if (START == NULL || nim <= START->noMhs) {
        if (START != NULL && nim == START->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }

        nodeBaru->next = START;
        START = nodeBaru;
        return;
    }
    //set nilai previous dan current menjadi START
    Node* previous = START;
    Node* current = START;

};

int main()
{
   
}

