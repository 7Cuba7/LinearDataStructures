#include <iostream>
using namespace std;
int const N = 11;
class Stekas {
private:
    int mas[N];
    int top;

public:
    //konstruktorius
    Stekas() {
        top = -1;
    }

    void push(int el) {

        if (top < N - 1)
        {
            top++;
            mas[top] = el;
        }
        else {
            std::cout << "Stekas yra jau pilnas ";
        }

    }

    int pop() {
        if (top >= 0)
        {
            int elementas = top;
            top--;
            return mas[elementas];
        }
        else {
            return -100;
        }


    }

    //metodas, kuri isspausdina virsutini steko elementa
    int topEl() {
        if (isEmpty() == true)
            return -100;
        return mas[top];
    }

    //patikrinti, ar stekas tuscias
    bool isEmpty() {
        if (top == -1)
            return true;
        else {
            return false;
        }
    }

    //patikrinti, stekas pilnas
    bool isFull() {
        if (top == N - 1)
            return true;
        else {
            return false;
        }
    }

    //metodas parodyti visus steko elementus
    void display() {
        int elementas = top;
        while (top >= 0) {
            std::cout << mas[top] << " ";
            top--;
        }
        top = elementas;
    }

    void clear()
    {
        if (top >= 0)
        {
            top = -1;
        }
    }
};

int main()
{
    Stekas stekas;
    int p = 10000, r;
    while (p != 0) {
        cout << "Pasirinkite ka norite daryti\n";
        cout << "0. Iseiti is programos\n";
        cout << "1. Padeti elementa i steka\n";
        cout << "2. Isimti elementa is steko\n";
        cout << "3. Paziureti virsutini steko elementa\n";
        cout << "4. Patikrinti, ar stekas tuscias\n";
        cout << "5. Patikrinti, ar stekas pilnas\n";
        cout << "6. Parodyti visus steko elementus\n";
        cout << "Jusu pasirinkimas: ";
        cin >> p;
        switch (p) {
        case 1:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            stekas.push(r);
            break;
        case 2: {
            int laik = stekas.pop();
            if (laik == -100)
                cout << "Nera elementu kuriuos galima butu salinti" << endl;
            else {
                cout << "Pasalintas elementas " << laik << " sekmingai\n";
            }
        }
            break;
        case 3:
            cout << "Virsutinis steko elementas " << stekas.topEl() << endl;
            break;
        case 4:
            if (stekas.isEmpty() == true) {
                cout << "Stekas tuscias\n";
            }
            else {
                cout << "Stekas turi elementu\n";
            }
            break;
        case 5:
            if (stekas.isFull() == true) {
                cout << "Stekas pilnas\n";
            }
            else {
                cout << "Stekas dar turi laisvos vietos\n";
            }
            break;
        case 6:
            cout << "Steko elementai: ";
            stekas.display();
            break;
        case 7:
            cout<<"Stekas isvalytas" << endl;
            stekas.clear();
            break;
        default:
            cout << "Neteisingas pasirinkimas" << endl;
            break;
        }
    }

    return 0;
}
