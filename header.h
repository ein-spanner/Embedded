#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 음식 주문 정보를 저장하는 구조체
struct Order {
    int orderNumber;
    string name;
    int quantity;
    double price;
    bool isPaid;
    bool isCompleted;
};

// 메뉴 정보를 저장하는 구조체
struct MenuItem {
    string name;
    double price;
};

// 음식 주문을 처리하는 클래스
class OrderProcessor {
private:
    vector<MenuItem> menu;
    vector<Order> orders;
    int nextOrderNumber;
    map<int, string> orderStatus;

public:
    OrderProcessor();

    // 주문을 추가하는 함수
    void addOrder(const string& name, int quantity);

    // 주문 가격을 찾는 함수
    double findPrice(const string& name);

    // 주문 내역을 출력하는 함수
    void printOrder();

    // 결제 기능
    void payOrder(int orderNumber);

    // 주문 상태 추적 기능
    void trackOrder(int orderNumber);

    // 메뉴 추가 기능
    void addMenuItem(const string& name, double price);

    // 메뉴 관리 기능
    void manageMenu();

    // 주문 처리 함수
    void processOrder();
};

#endif // HEADER_H
