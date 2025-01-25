#include <iostream>
using namespace std;

struct elementas { //node
    int data;
    elementas* next;
};

class TiesSar {  //LinkedList
private:
    elementas* tail;
public:
    TiesSar() {
        tail = NULL;
    }
    ~TiesSar() {
        
    }

    void pridetiElementaPab(int el) 
    { 
        elementas* temp = new elementas;
        if (isEmpty() == true)
        {
            temp->data = el;
            tail = temp;
            tail->next = tail;
            return;
        }

        temp->data = el;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
 
    }
    void pridetiElementaPradzioje(int el) 
    {
        elementas* temp = new elementas;
        if (isEmpty() == true)
        {
            temp->data = el;
            tail = temp;
            tail->next = tail;
            return;
        }

        temp->data = el;
        temp->next = tail->next;
        tail->next = temp;
    }
    void pridetiElementaPozicijoje(int pozicija, int el)
    {
        if (isEmpty() == true)
        {
            pridetiElementaPradzioje(el);
            return;
        }

        if (1 > pozicija)
        {
            cout<<"Pozicija blogai ivesta" << endl;
            return;
        }

        if (pozicija == 1)
        {
            pridetiElementaPradzioje(el);
            return;
        }
        

        elementas* temp = new elementas;
        temp->data = el;
        elementas* pre = tail->next;

        for (int i = 1;i < pozicija-1;i++)
        {
            pre = pre->next;
        }
        temp->next = pre->next;
        pre->next = temp;
    }

    void isimtiElementaPradzioje() 
    {
        if (isEmpty() == true)
        {
            cout<<"Negalima nieko trinti, nes sarasas yra TUSCIAS" << endl;
            return;
        }

        if (tail->next == tail)
        {
            delete tail;
            tail = NULL;
            return;
        }

        elementas* temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }
    void isimtiElementaPabaigoje() 
    {

        if (isEmpty() == true)
        {
            cout << "Negalima nieko trinti, nes sarasas yra TUSCIAS" << endl;
            return;
        }

        if (tail->next == tail)
        {
            delete tail;
            tail = NULL;
            return;
        }

        elementas* temp = tail->next;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
        
    }
    void isimtiElementaPozicijoje(int pozicija)
    {
        if (isEmpty() == true)
        {
            cout << "Negalima nieko trinti, nes sarasas yra TUSCIAS" << endl;
            return;
        }
        if (pozicija == 1)
        {
            isimtiElementaPradzioje();
            return;
        }
        elementas* temp = tail->next;
        elementas* pre = new elementas;
        pre = tail->next;
        
        for (int i = 1;i < pozicija - 1;i++)
        {
            if (pre->next == temp)
            {
                cout << "Pozicija yra per didele" << endl;
                return;
            }
            pre = pre->next;
        }

        elementas* cur = pre->next;
        if (cur == tail)
        {
            isimtiElementaPabaigoje();
        }
        else {
            pre->next = cur->next;
            delete cur;
        }
        
    }
    void display() 
    {   
        if (isEmpty() == true)
        {
            cout<<"Sarasas yra tuscias" << endl;
            return;
        }
        elementas* temp = tail;
        temp = temp->next;
        while (temp != tail)
        {
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout << temp->data << " ";
    }

    bool isEmpty() 
    {
        return (tail == NULL);
    }
    void clear() 
    {
        if (isEmpty() == true)
        {
            cout << "Sarasas yra jau ir taip tuscias" << endl;
            return;
        }
        while (tail!=tail->next)
        {
            isimtiElementaPradzioje();
        }
        isimtiElementaPradzioje();
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

        do {
            if (temp->data == el)
            {
                cout << "Pozicija: " << poz << endl;
                arYra = 1;
            }
            temp = temp->next;
            poz++;
        } while (temp != tail);

        if (arYra == 0)
            cout << "Tokio elemento sarase nera" << endl;
    }
    void reverse() 
    {
        
        if (isEmpty() == true)
        {
            cout << "Negalima apsukti nes sarasas tuscias" << endl;
            return;
        }
        elementas* cur = tail->next;
        elementas* pre = tail;
        elementas* nxt = NULL;
        elementas* newTail = tail->next;
        do
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        } while (cur != tail);
        
        tail->next = pre;
        tail = newTail;
    }

    int findtail()
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
            cout << TS.findtail() << endl;
            break;
        }
    }

    return 0;
}
