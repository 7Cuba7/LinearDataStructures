#include <iostream>
#include <stack>
using namespace std;

struct elementas { //node
    int data;
    elementas* next;
    elementas* prev;
};

class TiesSar {  //LinkedList
private:
    elementas* tail;
    int kiekis = 0;
public:
    TiesSar() {
        tail = NULL;
    }
    ~TiesSar() {
    }

    void pridetiElementaPab(int el)
    {
        elementas* temp = new elementas;
        temp->data = el;
        if (isEmpty() == true)
        {
            tail = temp;
            tail->next = tail;
            tail->prev = tail;
            kiekis++;
            return;
        }
        temp->next = tail->next;
        tail->next->prev = temp;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        kiekis++;

    }
    void pridetiElementaPradzioje(int el)
    {
        elementas* temp = new elementas;
        temp->data = el;
        if (isEmpty() == true)
        {
            tail = temp;
            tail->next = tail;
            tail->prev = tail;
            kiekis++;
            return;
        }
        temp->next = tail->next;
        tail->next->prev = temp;
        tail->next = temp;
        temp->prev = tail;
        kiekis++;
    }
    void pridetiElementaPozicijoje(int pozicija, int el)
    {
        elementas* temp = new elementas;
        int poz2 = pozicija;
        if (isEmpty() == true)
        {
            pridetiElementaPradzioje(el);
            return;
        }
        if (pozicija < 1)
        {
            cout << "Pozicija yra per maza" << endl;
            return;
        }
        if (pozicija == 1)
        {
            pridetiElementaPradzioje(el);
            return;
        }
        if (pozicija == kiekis)
        {
            pridetiElementaPab(el);
            return;
        }

        pozicija = pozicija % kiekis;
        if (pozicija <= kiekis / 2)
        {
            elementas* pos = tail->next;
            temp->data = el;
            for (int i = 1;i < pozicija - 1;i++)
            {
                pos = pos->next;
            }
            temp->prev = pos;
            temp->next = pos->next;
            pos->next->prev = temp;
            pos->next = temp;
            kiekis++;
        }
        else {
            elementas* pos = tail;
            temp->data = el;
            for (int i = kiekis;i > pozicija;i--)
            {
                pos = pos->prev;
            }
            temp->next = pos;
            temp->prev = pos->prev;
            pos->prev->next = temp;
            pos->prev = temp;
        }
    }

    void isimtiElementaPradzioje()
    {
        if (isEmpty() == true)
        {
            cout << "Sarasas yra tuscias" << endl;
            return;
        }
        if (tail->next == tail)
        {
            delete tail;
            tail = NULL;
            kiekis = 0;
            return;
        }

        elementas* temp = tail->next;
        tail->next->next->prev = tail;
        tail->next = tail->next->next;
        delete temp;
        kiekis--;
    }
    void isimtiElementaPabaigoje()
    {
        if (isEmpty() == true)
        {
            cout << "Sarasas yra tuscias" << endl;
            return;
        }
        if (tail->next == tail)
        {
            delete tail;
            tail = NULL;
            kiekis = 0;
            return;
        }

        elementas* temp = tail;
        tail = tail->prev;
        tail->next = temp->next;
        temp->next->prev = tail;
        delete temp;
        kiekis--;
    }
    void isimtiElementaPozicijoje(int pozicija)
    {


    }
    void display()
    {

        if (isEmpty() == true)
        {
            cout << "Sarasas tuscias" << endl;
            return;
        }
        elementas* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);


    }

    bool isEmpty()
    {
        return (tail == NULL);
    }
    void clear()
    {
        if (isEmpty() == true)
        {
            cout << "Sarasas yra tuscias" << endl;
            return;
        }
        while (isEmpty() == false)
        {
            isimtiElementaPradzioje();
        }
    }

    void findPosition(int el)
    {
        if (isEmpty() == true)
        {
            cout << "Negalima surasti nes sarasas tuscias" << endl;
            return;
        }
        elementas* temp = tail->next;
        int poz = 1;
        int arYra = 0;
        do
        {
            if (temp->data == el)
            {
                cout << "Pozicija: " << poz << endl;
                arYra = 1;
            }
            temp = temp->next;
            poz++;
        } while (temp != tail->next);

        if (arYra == 0)
            cout << "Tokio elemento sarase nera" << endl;
    }
    void reverse()
    {
        if (isEmpty() == true)
        {
            cout << "Sarasas yra tuscias" << endl;
            return;
        }

        stack <int> stekas;
        elementas* temp = tail->next;

        do {
            stekas.push(temp->data);
            temp = temp->next;
        } while (temp != tail->next);
        clear();
        while (stekas.empty() == false)
        {
            pridetiElementaPab(stekas.top());
            stekas.pop();
        }


    }

    int grazinkTail()
    {
        return tail->data;
    }
};

int main()
{
    TiesSar TS;
    int p = 1000, r, poz;
    while (p != 0)
    {
        cout << "Pasirinkite ka norite daryti" << endl;
        cout << "0. Iseiti is programos\n";
        cout << "1. Prideti elementa i saraso pradzia\n";
        cout << "2. Prideti elementa i saraso pabaiga\n";
        cout << "3. Prideti elementa i pasirinkta saraso pozicija\n";
        cout << "4. Pasalinti elementa is saraso pradzios\n";
        cout << "5. Pasalinti elementa is saraso pabaigos\n";
        cout << "6. Pasalinti elementa is pasirinktos saraso pozicijos\n";
        cout << "7. Surasti elemento pozicijas sarase\n";
        cout << "8. Atspausdinti sarasa\n";
        cout << "9. Isvalyti sarasa\n";
        cout << "10. Apsukti sarasa, apsukant rodykles\n";
        cout << "11. Patikrinti ar sarasas tuscias\n";
        cout << "Jusu pasirinkimas: ";
        cin >> p;
        switch (p) {
        case 0:
            p = 0;
            break;
        case 1:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            TS.pridetiElementaPradzioje(r);
            break;
        case 2:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            TS.pridetiElementaPab(r);
            break;
        case 3:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            cout << "Iveskite pozicija ";
            cin >> poz;
            TS.pridetiElementaPozicijoje(poz, r);
            break;
        case 4:
            TS.isimtiElementaPradzioje();
            break;
        case 5:
            TS.isimtiElementaPabaigoje();
            break;
        case 6:
            cout << "Iveskite pozicija ";
            cin >> poz;
            TS.isimtiElementaPozicijoje(poz);
            break;
        case 7:
            cout << "Iveskite elemento, kurio pozicijas norite surasti ";
            cin >> r;
            TS.findPosition(r);
            break;
        case 8:
            TS.display();
            cout << " " << endl;
            break;
        case 9:
            TS.clear();
            break;
        case 10:
            TS.reverse();
            break;
        case 11:
            if (TS.isEmpty() == true)
                cout << "Sarasas yra tuscias" << endl;
            else {
                cout << "Sarasas nera tuscias" << endl;
            }
            break;
        case 12:
            cout << TS.grazinkTail() << endl;
        }
    }

    return 0;
}
