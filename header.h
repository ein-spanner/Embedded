#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// ���� �ֹ� ������ �����ϴ� ����ü
struct Order {
    int orderNumber;
    string name;
    int quantity;
    double price;
    bool isPaid;
    bool isCompleted;
};

// �޴� ������ �����ϴ� ����ü
struct MenuItem {
    string name;
    double price;
};

// ���� �ֹ��� ó���ϴ� Ŭ����
class OrderProcessor {
private:
    vector<MenuItem> menu;
    vector<Order> orders;
    int nextOrderNumber;
    map<int, string> orderStatus;

public:
    OrderProcessor();

    // �ֹ��� �߰��ϴ� �Լ�
    void addOrder(const string& name, int quantity);

    // �ֹ� ������ ã�� �Լ�
    double findPrice(const string& name);

    // �ֹ� ������ ����ϴ� �Լ�
    void printOrder();

    // ���� ���
    void payOrder(int orderNumber);

    // �ֹ� ���� ���� ���
    void trackOrder(int orderNumber);

    // �޴� �߰� ���
    void addMenuItem(const string& name, double price);

    // �޴� ���� ���
    void manageMenu();

    // �ֹ� ó�� �Լ�
    void processOrder();
};

#endif // HEADER_H
