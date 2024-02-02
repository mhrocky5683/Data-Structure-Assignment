#include <iostream>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* nextNode;

    ListNode(int val) : value(val), nextNode(nullptr) {}
};

class LinkedList {
private:
    ListNode* rootNode;

public:
    LinkedList() : rootNode(nullptr) {}

    void addNodeAtStart(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->nextNode = rootNode;
        rootNode = newNode;
    }

    void addNodeAtEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (rootNode == nullptr) {
            rootNode = newNode;
            return;
        }

        ListNode* current = rootNode;
        while (current->nextNode != nullptr) {
            current = current->nextNode;
        }
        current->nextNode = newNode;
    }

    void addNodeAtPosition(int val, int pos) {
        if (pos == 1) {
            addNodeAtStart(val);
            return;
        }

        ListNode* newNode = new ListNode(val);
        ListNode* current = rootNode;

        for (int i = 0; i < pos - 2; i++) {
            if (current == nullptr) {
                cout << "Position beyond current list size." << endl;
                return;
            }
            current = current->nextNode;
        }

        if (current == nullptr) {
            cout << "Position beyond current list size." << endl;
            return;
        }

        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    void displayList() {
        ListNode* current = rootNode;
        cout << "Current List: ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->nextNode;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    int count, num, position;

    cout << "Enter the number of elements: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> num;
        myList.addNodeAtEnd(num);
    }

    cout << "Specify the position for the new element: ";
    cin >> position;
    cout << "Enter the value of the new element: ";
    cin >> num;

    myList.addNodeAtPosition(num, position);
    myList.displayList();

    return 0;
}
