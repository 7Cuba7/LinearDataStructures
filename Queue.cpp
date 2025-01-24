#include <iostream>
#include <stack>
using namespace std;

int const N = 11;
class Eile {
private:
    int mas[N];
    int front, back;

public:
    Eile() {
        front = -1;
        back = -1;
    }

    void enqueue(int el)
    {   
        if (isFull())
        {
            cout << "Negalima prideti elemento" << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            back = 0;
            mas[back] = el;
        }
        else {
            back = (back + 1) % N;
            mas[back] = el;
        }
        
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout<<"Negalima pasalinti, kadangi tuscia eile" << endl;
            return -1;
        }
        
        int temp = mas[front];

        if (front == back) {
            front = -1;
            back = -1;
        }
        else {
            front = (front + 1) % N;
        }

        return temp;
            
    }

    int peek() //blogai
    {
        if (isEmpty() == true)
        {
            cout<<"Eile tuscia" << endl;
            return -100;
        }
        return mas[front];
    }

    bool isEmpty()
    {
        return (front == -1 && back == -1);
    }

    bool isFull()
    {
        return (front == (back + 1) % N);
    }

    void display()
    {   
        if (isEmpty()) {
            cout << "Eile tuscia!" << endl;
            return;
        }

        int i = front;
        while (i != back) {
            cout << mas[i] << " ";
            i = (i + 1) % N;
        }
        cout << mas[back] << endl;
    }
    void reverse(Eile& eil)
    {
        stack <int> stekas;
        while (eil.isEmpty() == false)
        {
            stekas.push(eil.dequeue());
        }
        while (stekas.empty() == false)
        {
            eil.enqueue(stekas.top());
            stekas.pop();
        }

    }

    void clear()
    {
        front = -1;
        back = -1;
    }
};
int main()
{
    Eile eile;
    int p = 1000, r;
    while (p != 0)
    {
        cout << "Pasirinkite ka norite daryti\n";
        cout << "0. Iseiti is programos\n";
        cout << "1. Prideti elementa i eile\n";
        cout << "2. Istrinti elementa is eiles\n";
        cout << "3. Pasiziureti pirma elementa\n";
        cout << "4. Patikrinti ar eile tuscia\n";
        cout << "5. Patikrinti ar eile pilna\n";
        cout << "6. Parodyti eile\n";
        cout << "7. Reverse\n";
        cout << "8. Isvalyti eile\n";
        cout << "Jusu pasirinkimas: ";
        cin >> p;
        switch (p){
        case 0:
            p = 0;
            break;
        case 1:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            eile.enqueue(r);
            break;
        case 2:
            eile.dequeue();
            break;
        case 3:
            if (eile.peek() == -1)
                cout<<"Eile tuscia" << endl;
            else {
                cout<< eile.peek() <<endl;
            }
            break;
        case 4:
            if (eile.isEmpty() == true)
                cout<<"Eile tuscia" << endl;
            else {
                cout<<"Eile netuscia" << endl;
            }
            break;
        case 5:
            if(eile.isFull()==true)
                cout << "Eile pilna" << endl;
            else {
                cout << "Eile nepilna" << endl;
            }
            break;
        case 6:
            cout << "Eiles elementai: ";
            eile.display();
            break;
        case 7:
            eile.reverse(eile);
            break;
        case 8:
            eile.clear();
            cout<<"Eile isvalyta" << endl;
            break;

        }
    }
}
