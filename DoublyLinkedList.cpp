#include <iostream>
using namespace std;

struct elementas { //node
    int data;
    elementas* next;
    elementas* prev;
};

class TiesSar {  //LinkedList
private:
    elementas* head;
    elementas* tail;
    int kiekis = 0;
public:
    TiesSar() {
        head = NULL;
        tail = NULL;
    }
    ~TiesSar() {
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

    void pridetiElementaPab(int el) { //DONE
       

        elementas* temp = new elementas;
        temp->data = el;
        temp->next = NULL;
        if (head==NULL)
        {   
            temp->prev = NULL;
            head = temp;
            tail = temp;
        }
        else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        kiekis++;

    }
    void pridetiElementaPradzioje(int el) //DONE
    {
        elementas* temp = new elementas;
        temp->data = el;
        temp->next = head;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else {
            head->prev = temp;
            head = temp;
        }
        kiekis++;
    }
    void pridetiElementaPozicijoje(int pozicija, int el)
    {
        elementas* temp = new elementas;
        if (pozicija <= kiekis / 2)
        {
            elementas* pre = head;
            temp->data = el;
            if (pozicija < 1)
            {
                cout<<"Pozicija yra per maza" << endl;
                return;
            }
            if (pozicija == 1)
            {
                temp->next = head;
                head->prev = temp;
                temp->prev = NULL;
                head = temp;
                kiekis++;
            }
            else {
                for (int i = 1;i < pozicija - 1;i++)
                {
                    pre = pre->next;
                }
                temp->prev = pre;
                temp->next = pre->next;
                pre->next = temp;
                temp->next->prev = temp;
                kiekis++;
            }
            

            if (temp->next == NULL)
            {
                tail = temp;
            }

        }
        else {
            elementas* pre = tail;
            temp->data = el;
            if (kiekis == 1 && pozicija == 1)
            {
                pridetiElementaPradzioje(el);
                return;
            }

            if (pozicija > kiekis)
            {   
                cout<<"Pozicija yra per didele todel elementa pridesime i GALA" << endl;
                pridetiElementaPab(el);
                return;
            }
            else {
                for (int i = kiekis;i > pozicija;i--)
                {
                    pre = pre->prev;
                }
                temp->next = pre;
                temp->prev = pre->prev;
                pre->prev = temp;
                temp->prev->next = temp;
                kiekis++;
            }

        }
    }

    void isimtiElementaPradzioje() //DONE
    {
       
        if (isEmpty() == true)
        {
            cout << "Elemento negalima isimti, nes sarasas yra TUSCIAS" << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
            kiekis = 0;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            kiekis--;
        }
        
    }
    void isimtiElementaPabaigoje() //DONE
    {
        
        if (isEmpty() == true)
        {
            cout << "Elemento negalima isimti, nes sarasas yra TUSCIAS" << endl;
            return;
        }
        if (tail->prev == NULL)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            kiekis = 0;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            kiekis--;
        }

    }
    void isimtiElementaPozicijoje(int pozicija)
    {   
        if (isEmpty())
        {
            cout << "Elemento negalima isimti, nes sarasas yra TUSCIAS" << endl;
            return;
        }
        if (pozicija > kiekis || pozicija<=0)
        {
            cout<<"Pozicija yra per didele arba per maza " << endl;
            return;
        }
        if (pozicija <= kiekis / 2)
        {
            elementas* temp = head;
            if (pozicija == 1)
            {
                isimtiElementaPradzioje();
                return;
            }
            for (int i = 1;i < pozicija;i++)
            {
                temp=temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            kiekis--;
        }
        else {
            if (pozicija == 1 && kiekis == 1)
            {
                isimtiElementaPradzioje();
                return;
            }
            if (pozicija == kiekis)
            {
                isimtiElementaPabaigoje();
                return;
            }
            elementas* temp = tail;
            for (int i = kiekis;i > pozicija;i--)
            {
                temp=temp->prev;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            kiekis--;
        }
    }
    void display() //DONE
    {
        elementas* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool isEmpty() //DONE
    {
        return (head == NULL && tail == NULL);
    }
    void clear() //done
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

    void findPosition(int el) //DONE
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
                cout << "Pozicija: " << poz << endl;
                arYra = 1;
            }
            temp = temp->next;
            poz++;
        }
        if (arYra == 0)
            cout << "Tokio elemento sarase nera" << endl;
    }
    void reverse() //DONE
    {
        if (isEmpty() == true)
        {
            cout << "Negalima apsukti nes sarasas tuscias" << endl;
            return;
        }

        elementas* current = head;
        elementas* temp = NULL;

        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;

        }

        temp = head;
        head = tail;
        tail = temp;
 
    }

    int grazinkKieki()
    {
        return kiekis;
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
            cout<<TS.grazinkKieki()<<endl;
        }
    }

    return 0;
}
