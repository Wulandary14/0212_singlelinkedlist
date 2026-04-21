#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START !=NULL || nim <= START->noMhs)
            {
                cout << "\nDuplikasi noMhs Tidak diijinkan\n";
                return;
            }

            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while (current !=NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs Tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, Node *&previous, Node *&current_exception)
    {
        previous = START;
        current = START;

        while (current !=NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current !=NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!search(nim, previous,current))
            return false;

            if(current == START)
                START = START->next;
            else
                previous->next = current->next;

            delete current;
            return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
        cout << "\nList Kososng\n";
        }
        else
        {
            cout << "\nData Didalam List adalah:\n";
            Node *currentNode = START;

            while (currentNode !=NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout <<endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambah Data Kedalam List" << endl;
        cout << "2. Menghapus Data dari Dalam List" << endl;
        cout << "3. Menampilkan Semua Data didalam List" << endl;
        cout << "4. Mencari Data dalam List" << endl;
        cout << "5. Keluar" << endl;

        cout << "\nMasukkan Pilihan (1-5): ";
        cin >> ch;

        
    }
    
}
