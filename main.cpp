#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

OrderProcessor::OrderProcessor() : nextOrderNumber(1) {
    menu.push_back({ "오리지널버거", 6000});
    menu.push_back({ "치즈버거", 7000});
    menu.push_back({ "더블치즈버거", 8000});
    menu.push_back({ "감자튀김", 2000 });
    menu.push_back({ "콜라", 2000 });
}

void OrderProcessor::addOrder(const string& name, int quantity) {
    double price = findPrice(name) * quantity;
    orders.push_back({ nextOrderNumber, name, quantity, price, false, false });
    orderStatus[nextOrderNumber] = "주문 완료";
    nextOrderNumber++;
}

double OrderProcessor::findPrice(const string& name) {
    // 메뉴에서 주어진 음식의 가격을 찾는 코드
    for (const auto& item : menu) {
        if (item.name == name) {
            return item.price;
        }
    }
    return 0.0; // 메뉴에 없는 음식인 경우
}

void OrderProcessor::printOrder() {
    double total = 0.0;
    cout << "주문 내역:" << endl;
    for (const auto& order : orders) {
        cout << "#" << order.orderNumber << " - " << order.name << " x " << order.quantity << " = $" << order.price;
        if (order.isPaid)
            cout << " (결제 완료)";
        if (order.isCompleted)
            cout << " (주문 완료)";
        cout << endl;
        total += order.price;
    }
    cout << "총 가격: $" << total << endl;
}

void OrderProcessor::payOrder(int orderNumber) {
    for (auto& order : orders) {
        if (order.orderNumber == orderNumber) {
            order.isPaid = true;
            orderStatus[orderNumber] = "결제 완료";
            break;
        }
    }
}

void OrderProcessor::trackOrder(int orderNumber) {
    if (orderStatus.find(orderNumber) != orderStatus.end()) {
        cout << "주문 #" << orderNumber << " 상태: " << orderStatus[orderNumber] << endl;
    }
    else {
        cout << "해당 주문번호의 주문이 없습니다." << endl;
    }
}

void OrderProcessor::addMenuItem(const string& name, double price) {
    menu.push_back({ name, price });
}

void OrderProcessor::manageMenu() {
    cout << "==== 메뉴 관리 ====" << endl;
    cout << "1. 메뉴 추가" << endl;
    cout << "2. 현재 메뉴 보기" << endl;
    cout << "3. 뒤로 가기" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "추가할 메뉴 이름: ";
        string name;
        cin.ignore();
        getline(cin, name);

        cout << "추가할 메뉴 가격: ";
        double price;
        cin >> price;

        addMenuItem(name, price);
        cout << "메뉴가 추가되었습니다." << endl;
        break;
    }
    case 2:
        cout << "=== 현재 메뉴 ===" << endl;
        for (const auto& item : menu) {
            cout << item.name << " - $" << item.price << endl;
        }
        break;
    case 3:
        return;
    default:
        cout << "잘못된 선택입니다." << endl;
        break;
    }
}

void OrderProcessor::processOrder() {
    while (true) {
        cout << "==== 키오스크 ====" << endl;
        cout << "1. 주문 추가" << endl;
        cout << "2. 주문 상태 추적" << endl;
        cout << "3. 결제" << endl;
        cout << "4. 주문 내역 보기" << endl;
        cout << "5. 메뉴 관리" << endl;
        cout << "6. 종료" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "메뉴 이름: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "수량: ";
            int quantity;
            cin >> quantity;

            addOrder(name, quantity);
            cout << "주문이 추가되었습니다." << endl;
            break; }
        case 2: {
            cout << "추적할 주문번호: ";
            int orderNumber;
            cin >> orderNumber;

            trackOrder(orderNumber);
            break; }
        case 3: {
            cout << "결제할 주문번호: ";
            int paymentOrderNumber;
            cin >> paymentOrderNumber;

            payOrder(paymentOrderNumber);
            cout << "결제가 완료되었습니다." << endl;
            break; }
        case 4: {
            printOrder();
            break; }
        case 5: {
            manageMenu();
            break; }
        case 6: {
            cout << "키오스크를 종료합니다." << endl;
            return; }
        default: {
            cout << "잘못된 선택입니다." << endl;
            break; }
        }
    }
}

int main() {
    OrderProcessor orderProcessor;
    orderProcessor.processOrder();
    return 0;
}
