#include <iostream>
#include <stack>
using namespace std;

int const N = 11;
class Dekas {
private:
    int mas[N];
    int front, rear;

public:
    Dekas() {
        front = -1;
        rear = -1;
    }

    void pushBack(int el)
    {   
        if (isFull())
        {
            cout<<"Negalima prideti elemento, nes dekas PILNAS" << endl;
        }
        else if (rear == -1 && front == -1)
        {
            rear = 0; //
            front = 0;
            mas[rear] = el;
        }
        else {
            rear = (rear + 1) % N;
            mas[rear] = el;
        }
        
    }
    void pushFront(int el)
    {
        if (isFull())
        {
            cout << "Negalima prideti elemento, nes dekas PILNAS" << endl;
        }
        else if (rear == -1 && front == -1)
        {
            rear = 0; 
            front = 0; //
            mas[front] = el;
        }
        else {
            front = (front - 1 + N) % N;
            mas[front] = el;
        }
    }
    int popFront()
    {   
        int temp = mas[front];
        if (isEmpty())
        {
            cout << "Negalima istrinti elemento, nes dekas TUSCIAS" << endl;
            return -1;
        }
        else if(front==rear){
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % N;
        }

        return temp;
    }
    int popBack()
    {
        int temp = mas[rear];
        if (isEmpty())
        {
            cout << "Negalima istrinti elemento, nes dekas TUSCIAS" << endl;
            return -1;
        }
        else if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            rear = (rear - 1 + N) % N;
        }

        return temp;
    }
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (front == (rear + 1) % N);
    }
    int Front()
    {
        if (front == -1)
        {
            return front;
        }
        else {
            return mas[front];
        }
    }
    int Back()
    {
        if (rear == -1)
        {
            return rear;
        }
        else {
            return mas[rear];
        }
    }
    void display()
    {
        if (isEmpty()) {
            cout << "Eile tuscia!" << endl;
            return;
        }

        int i = front;
        while (i != rear) {
            cout << mas[i] << " ";
            i = (i + 1) % N;
        }
        cout << mas[rear] << endl;
    }
    void reverse(Dekas& dek)
    {
        stack <int> stekas;
        while (!dek.isEmpty())
        {
            int el = dek.popFront();
            stekas.push(el);
        }

        dek.clear();

        while (!stekas.empty())
        {
            dek.pushBack(stekas.top());
            stekas.pop();
        }
    }

    void clear()
    {
        front = -1;
        rear = -1;
    }
    
};
int main()
{
    Dekas dekas;
    int p = 1000, r;
    while (p != 0)
    {
        cout << "Pasirinkite ka norite daryti\n";
        cout << "0. Iseiti is programos\n";
        cout << "1. Prideti elementa i deko gala\n";
        cout << "2. Prideti elementa i deko pradzia\n";
        cout << "3. Pasalinti elementa is deko pradzio\n";
        cout << "4. Pasalinti elementa is deko galo\n";
        cout << "5. Perziureti pirma elementa\n";
        cout << "6. Perziureti galini elementa\n";
        cout << "7. Patikrinti ar dekas tuscias\n";
        cout << "8. Patikrinti ar dekas yra pilnas\n";
        cout << "9. Isvesti deko elementus i ekrana\n";
        cout << "10. Apsukti deka\n";
        cout << "11. Isvalyti deka\n";
        cout << "Jusu pasirinkimas: ";
        cin >> p;
        switch (p) {
        case 0:
            p = 0;
            break;
        case 1:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            dekas.pushBack(r);
            break;
        case 2:
            cout << "Iveskite elemento reiksme ";
            cin >> r;
            dekas.pushFront(r);
            break;
        case 3:
            dekas.popFront();
            break;
        case 4:
            dekas.popBack();
            break;
        case 5:
            if (dekas.Front() == -1)
                cout << "Dekas tuscias" << endl;
            else {
                cout << dekas.Front() << endl;
            }
            break;
        case 6:
            if (dekas.Back() == -1)
                cout << "Dekas tuscias" << endl;
            else {
                cout << dekas.Back() << endl;
            }
            break;
        case 7:
            if (dekas.isEmpty() == true)
                cout << "Dekas tuscias" << endl;
            else {
                cout << "Dekas netuscias" << endl;
            }
            break;
        case 8:
            if (dekas.isFull() == true)
                cout << "Dekas pilna" << endl;
            else {
                cout << "Dekas nepilna" << endl;
            }
            break;
        case 9:
            dekas.display();
            break;
        case 10:
            dekas.reverse(dekas);
            break;
        case 11:
            dekas.clear();
        }
        

        

    }
}
