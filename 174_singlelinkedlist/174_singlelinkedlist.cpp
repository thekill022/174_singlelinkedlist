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
    //perulangan jika kondisi current tidak = NULL dan nim lebih dari sama dengan current->noMhs
    while ((current != NULL) && (nim >= current->noMhs))
    {
        if (nim == current->noMhs)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    //set nilai nodeBaru->next = current
    nodeBaru->next = current;
    //set nilai previous->next = nodeBaru
    previous->next = nodeBaru;
};

//membuat method serachNode dengan parameter
bool serachNode(int nim, Node* current, Node* previous) {
    previous = START;
    current = START;
    while (current != NULL && nim > current->noMhs)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return false;
    }
    else if (current->noMhs == nim)
    {
        return true;
    }
    else
    {
        return false;
    }
};

//membuat method deleteNode() dengan parameter
bool deleteNode(int nim) {
    Node* current = START;
    Node* previous = START;
    if (serachNode(nim, previous, current) == false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}

//membuat method listEmpty()
bool listEmpty() {
    if (START == NULL)
        return true;
    else
        return false;

}

//membuat prosedur traverse()
void traverse() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

//membuat prosedur searchData()
void searchData() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        int nim;
        cout << "Masukkan NIM: ";
        cin >> nim;
        Node* currentNode = START;
        while (currentNode != NULL) {
            if (currentNode->noMhs == nim) {
                cout << "NIM: " << currentNode->noMhs << ",Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}


int main()
{
    //deklarasi variabel pilihan untuk menangkap input pengguna
    int pilihan;

    do
    {
        //membungkus program dengan try catch untuk mendeteksi kesalahan

        try
        {
            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Cari Data" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            //membuat kondisi switch dari pilihan yang dimasukkan pengguna
            switch (pilihan)
            {
            case 1:
                addNode();
                cout << "Data Berhasil Ditambahkan" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                if (listEmpty())
                {
                    cout << "List Kosong" << endl;
                    system("pause");
                    system("cls");
                    break;
                }

                int nim;
                cout << "Masukkan NIM: ";
                cin >> nim;
                if (deleteNode(nim)) {
                    cout << "nim: " << nim << " berhasil dihapus" << endl;
                    system("pause");
                    system("cls");
                }
                else
                    cout << "Data tidak ditemukan" << endl;
                break;
            case 3:
                traverse();
                break;
            case 4:
                searchData();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
            }
        }

        catch (exception e)
        {
            //pesan kesalahan
            cout << "Terjadi Kesalahan" << endl;
        }

    } while (true);

}

