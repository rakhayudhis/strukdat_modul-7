#include <iostream>
using namespace std;

struct Node
{
    string nama;
    string NIM;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(string nama, string NIM)
    {
        Node *temp = new Node();
        temp->nama = nama;
        temp->NIM = NIM;
        temp->next = nullptr;

        if (isEmpty())
        {
            front = temp;
            back = temp;
        }
        else
        {
            back->next = temp;
            back = temp;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr)
            {
                back = nullptr;
            }
        }
    }

    int countQueue()
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void viewQueue()
    {
        cout << "Data antrian mahasiswa:" << endl;
        Node *current = front;
        int index = 1;
        while (current != nullptr)
        {
            cout << index << ". Nama: " << current->nama << ", NIM: " << current->NIM << endl;
            current = current->next;
            index++;
        }
        if (isEmpty())
        {
            cout << "(kosong)" << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice;
    string nama, NIM;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah ke antrian \n";
        cout << "2. Hapus dari antrian \n";
        cout << "3. Lihat antrian\n";
        cout << "4. Hitung antrian\n";
        cout << "5. Bersihkan antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa: ";
            cin >> NIM;
            q.enqueue(nama, NIM);
            cout << "Berhasil ditambahkan!" << endl;
            break;
        case 2:
            q.dequeue();
            cout << "Berhasil dihapus!" << endl;
            break;
        case 3:
            q.viewQueue();
            break;
        case 4:
            cout << "Jumlah antrian = " << q.countQueue() << endl;
            break;
        case 5:
            q.clearQueue();
            cout << "Berhasil dihapus!" << endl;
            break;
        case 0:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}