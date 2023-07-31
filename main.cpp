#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

OrderProcessor::OrderProcessor() : nextOrderNumber(1) {
    menu.push_back({ "�������ι���", 6000});
    menu.push_back({ "ġ�����", 7000});
    menu.push_back({ "����ġ�����", 8000});
    menu.push_back({ "����Ƣ��", 2000 });
    menu.push_back({ "�ݶ�", 2000 });
}

void OrderProcessor::addOrder(const string& name, int quantity) {
    double price = findPrice(name) * quantity;
    orders.push_back({ nextOrderNumber, name, quantity, price, false, false });
    orderStatus[nextOrderNumber] = "�ֹ� �Ϸ�";
    nextOrderNumber++;
}

double OrderProcessor::findPrice(const string& name) {
    // �޴����� �־��� ������ ������ ã�� �ڵ�
    for (const auto& item : menu) {
        if (item.name == name) {
            return item.price;
        }
    }
    return 0.0; // �޴��� ���� ������ ���
}

void OrderProcessor::printOrder() {
    double total = 0.0;
    cout << "�ֹ� ����:" << endl;
    for (const auto& order : orders) {
        cout << "#" << order.orderNumber << " - " << order.name << " x " << order.quantity << " = $" << order.price;
        if (order.isPaid)
            cout << " (���� �Ϸ�)";
        if (order.isCompleted)
            cout << " (�ֹ� �Ϸ�)";
        cout << endl;
        total += order.price;
    }
    cout << "�� ����: $" << total << endl;
}

void OrderProcessor::payOrder(int orderNumber) {
    for (auto& order : orders) {
        if (order.orderNumber == orderNumber) {
            order.isPaid = true;
            orderStatus[orderNumber] = "���� �Ϸ�";
            break;
        }
    }
}

void OrderProcessor::trackOrder(int orderNumber) {
    if (orderStatus.find(orderNumber) != orderStatus.end()) {
        cout << "�ֹ� #" << orderNumber << " ����: " << orderStatus[orderNumber] << endl;
    }
    else {
        cout << "�ش� �ֹ���ȣ�� �ֹ��� �����ϴ�." << endl;
    }
}

void OrderProcessor::addMenuItem(const string& name, double price) {
    menu.push_back({ name, price });
}

void OrderProcessor::manageMenu() {
    cout << "==== �޴� ���� ====" << endl;
    cout << "1. �޴� �߰�" << endl;
    cout << "2. ���� �޴� ����" << endl;
    cout << "3. �ڷ� ����" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "�߰��� �޴� �̸�: ";
        string name;
        cin.ignore();
        getline(cin, name);

        cout << "�߰��� �޴� ����: ";
        double price;
        cin >> price;

        addMenuItem(name, price);
        cout << "�޴��� �߰��Ǿ����ϴ�." << endl;
        break;
    }
    case 2:
        cout << "=== ���� �޴� ===" << endl;
        for (const auto& item : menu) {
            cout << item.name << " - $" << item.price << endl;
        }
        break;
    case 3:
        return;
    default:
        cout << "�߸��� �����Դϴ�." << endl;
        break;
    }
}

void OrderProcessor::processOrder() {
    while (true) {
        cout << "==== Ű����ũ ====" << endl;
        cout << "1. �ֹ� �߰�" << endl;
        cout << "2. �ֹ� ���� ����" << endl;
        cout << "3. ����" << endl;
        cout << "4. �ֹ� ���� ����" << endl;
        cout << "5. �޴� ����" << endl;
        cout << "6. ����" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "�޴� �̸�: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "����: ";
            int quantity;
            cin >> quantity;

            addOrder(name, quantity);
            cout << "�ֹ��� �߰��Ǿ����ϴ�." << endl;
            break; }
        case 2: {
            cout << "������ �ֹ���ȣ: ";
            int orderNumber;
            cin >> orderNumber;

            trackOrder(orderNumber);
            break; }
        case 3: {
            cout << "������ �ֹ���ȣ: ";
            int paymentOrderNumber;
            cin >> paymentOrderNumber;

            payOrder(paymentOrderNumber);
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
            break; }
        case 4: {
            printOrder();
            break; }
        case 5: {
            manageMenu();
            break; }
        case 6: {
            cout << "Ű����ũ�� �����մϴ�." << endl;
            return; }
        default: {
            cout << "�߸��� �����Դϴ�." << endl;
            break; }
        }
    }
}

int main() {
    OrderProcessor orderProcessor;
    orderProcessor.processOrder();
    return 0;
}
