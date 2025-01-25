#include <iostream>
using namespace std;

struct elementas { //node
    int data;
    elementas* next;
};

class TiesSar {  //LinkedList
private:
    elementas* head;
    elementas* tail;
public:
    TiesSar() {
        head = NULL;
        tail = NULL;
    }
    ~TiesSar()
    {
        elementas* temp = head;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        head = NULL;
        tail = NULL;
    }
    void pridetiElementaPab(int el) {
        elementas* temp = new elementas;
        temp->data = el;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void pridetiElementaPradzioje(int el)
    {
        elementas* temp = new elementas;
        temp->data = el;
        temp->next = head;  //next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else {
            head = temp;
        }
    }
    void pridetiElementaPozicijoje(int pozicija, int el)
    {
        elementas* temp = new elementas;
        temp->data = el;

        elementas* pre;
        pre = head;

        for (int i = 1;i < pozicija - 1;i++)
        {
            if (pre->next == NULL)
            {
                pridetiElementaPab(el);
                return;
            }
            else {
                pre = pre->next;
            }
        }

        temp->next = pre->next;
        pre->next = temp;

        if (temp->next == NULL) {
            tail = temp;
        }
    }

    void isimtiElementaPradzioje()
    {
        elementas* temp = head;
        if (isEmpty() == true)
        {
            cout << "Elemento negalima isimti, nes sarasas yra TUSCIAS" << endl;
            return;
        }
        else {
            head = head->next;
            delete temp;
        }

        if (head == NULL) {
            tail = NULL;    //jeigu sarasas tampa tuscias nustatau tail i NULL
        }

    }
    void isimtiElementaPabaigoje()
    {
        elementas* temp = new elementas;
        temp = head;
        
        if (head == tail) // Jeigu vienas elementas sarase
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        if (isEmpty())
        {
            cout << "Elemento negalima isimti, nes sarasas yra TUSCIAS" << endl;
            return;
        }
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        temp->next = NULL;

        
    }
    void isimtiElementaPozicijoje(int pozicija)
    {   
        int k = 1;
        elementas* pre = head;

        if (isEmpty() == true)
        {
            cout << "Elemento negalima isimti, nes sarasas yra TUSCIAS" << endl;
            return;
        }

        if (pozicija <= 0)
        {
            cout<<"Neteisinga pozicija" << endl;
            return;
        }

        if (pozicija == 1) 
        {
            head = head->next;
            delete pre; 
            return;
        }

        for (int i = 1;i < pozicija-1;i++)
        {
            if (pre->next == NULL)
            {
                cout<<"Pasirinkta pozicija yra per didele" << endl;
                return;
            }
            pre = pre->next;
        }

        elementas* cur = pre->next;

        if (cur == NULL)
        {
            cout << "Pasirinkta pozicija yra per didele" << endl;
            return;
        }

        pre->next = cur->next;
        delete cur;
    }
    void display()
    {
        elementas* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool isEmpty()
    {
        return (head == NULL && tail == NULL);
    }
    void clear()
    {
        if (isEmpty() == true)
        {
            cout << "Sarasas yra jau ir taip tuscias" << endl;
            return;
        }
        while (head != tail)
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
        elementas* temp = head;
        int poz = 1;
        int arYra = 0;
        while (temp != NULL)
        {
            if (temp->data == el)
            {
                cout <<"Pozicija: " << poz << endl;
                arYra = 1;
            }      
            temp = temp->next;
            poz++;
        }
        if (arYra == 0)
            cout<<"Tokio elemento sarase nera" << endl;
    }
    void reverse()
    {
        if (isEmpty() == true)
        {
            cout << "Negalima apsukti nes sarasas tuscias" << endl;
            return;
        }
        elementas* cur = head;
        elementas* pre = NULL;
        elementas* nxt = NULL;
        tail = head;
        while (cur!=NULL)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head = pre;
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
            cout<<" " << endl;
            break;
        case 9:
            TS.clear();
            break;
        case 10:
            TS.reverse();
            break;
        case 11:
            if (TS.isEmpty() == true)
                cout<<"Sarasas yra tuscias" << endl;
            else {
                cout<<"Sarasas nera tuscias" << endl;
            }
            break;
        }
    }
     
    return 0;
}
