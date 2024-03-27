/*
  1. 부모 클래스
  class Product : id, price, producer

  2. 자식 클래스
  class Book : ISBN, author, title // 978-89-001-0001-1
  class Handphone : model, RAM
  class Computer : model, cpu, RAM

  3. 객체포인터 배열 사용 : product[100]

  4. string 클래스 사용가능

  5. 메인화면
  ------상품관리 프로그램------
  1) 상품추가 2) 상품출력 3) 상품검색 0) 종료 >

  6. 1) 또는 2) 또는 3)을 선택한 경우,
    1) 책 2) 핸드폰 3) 컴퓨터 선택목록을 띄워 해당 상품을 선택한 후에 추가, 출력, 또는 검색 실행된다.

  7. 파일분할(나중에 해도 됨)
*/

/*
 File : ProductManager.c
 Created : 2024-03-06
 Author : 김현지
*/
#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string id;
    double price;
    string producer;

public:
    Product(string id, double price, string producer)
        : id(id), price(price), producer(producer) {}

    virtual void printDetails() = 0;
};

class Book : public Product {
private:
    string ISBN;
    string author;
    string title;

public:
    Book(string id, double price, string producer, string ISBN, string author, string title)
        : Product(id, price, producer), ISBN(ISBN), author(author), title(title) {}

    void printDetails() {
        cout << "Book Details:" << endl;
        cout << "ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Producer: " << producer << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
    }
};

class Handphone : public Product {
private:
    string model;
    int RAM;

public:
    Handphone(string id, double price, string producer, string model, int RAM)
        : Product(id, price, producer), model(model), RAM(RAM) {}

    void printDetails() {
        cout << "Handphone Details:" << endl;
        cout << "ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Producer: " << producer << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << RAM << endl;
    }
};

class Computer : public Product {
private:
    string model;
    string cpu;
    int RAM;

public:
    Computer(string id, double price, string producer, string model, string cpu, int RAM)
        : Product(id, price, producer), model(model), cpu(cpu), RAM(RAM) {}

    void printDetails() {
        cout << "Computer Details:" << endl;
        cout << "ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Producer: " << producer << endl;
        cout << "Model: " << model << endl;
        cout << "CPU: " << cpu << endl;
        cout << "RAM: " << RAM << "GB" << endl;
    }
};

void main() {
    Product* products[100];
    int productCount = 0;

    while (true) {
        cout << "상품관리 프로그램" << endl;
        cout << "1. 상품추가 2. 상품출력 3. 상품검색 0. 종료" << endl;

        int choice;
        cin >> choice;

        if (choice == 0)
            break;
        else if (choice == 1) {
            int subChoice;
            cout << "1. 책 2. 핸드폰 3. 컴퓨터" << endl;
            cin >> subChoice;

            if (subChoice == 1) {
                string id, ISBN, author, title, producer;
                double price;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Producer: ";
                cin >> producer;
                cout << "Enter ISBN: ";
                cin >> ISBN;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Title: ";
                cin >> title;
                products[productCount] = new Book(id, price, producer, ISBN, author, title);
            }
            else if (subChoice == 2) {
                string id, model, producer;
                int RAM;
                double price;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Producer: ";
                cin >> producer;
                cout << "Enter Model: ";
                cin >> model;
                cout << "Enter RAM (in GB): ";
                cin >> RAM;
                products[productCount] = new Handphone(id, price, producer, model, RAM);
            }
            else if (subChoice == 3) {
                string id, model, cpu, producer;
                int RAM;
                double price;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Producer: ";
                cin >> producer;
                cout << "Enter Model: ";
                cin >> model;
                cout << "Enter CPU: ";
                cin >> cpu;
                cout << "Enter RAM (in GB): ";
                cin >> RAM;
                products[productCount] = new Computer(id, price, producer, model, cpu, RAM);
            }
            productCount++;
        }
        else if (choice == 2) {
            cout << "등록된 상품 목록:" << endl;
            for (int i = 0; i < productCount; i++) {
                products[i]->printDetails();
                cout << endl;
            }
        }
        else {
            cout << "잘못된 선택입니다. 다시 선택하세요." << endl;
        }
    }

    for (int i = 0; i < productCount; i++) {
        delete products[i];
    }
}
