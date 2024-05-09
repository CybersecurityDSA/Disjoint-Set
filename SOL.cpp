#include <iostream>

const int MAX_SIZE = 100;

int list[MAX_SIZE];
int count[MAX_SIZE];
int size = 0;

using namespace std;

bool isEmpty() {
    return size == 0;
}

bool isFull() {
    return size == MAX_SIZE;
}

void makeEmpty() {
    size = 0;
}

int getSize() {
    return size;
}

void insert(int val) {
    if (isFull()) {
        cout << "Error: List full!" << endl;
        return;
    }
    list[size] = val;
    count[size] = 0;
    size++;
}

void remove(int pos) {
    pos--;
    if (pos < 0 || pos >= size) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        list[i] = list[i + 1];
        count[i] = count[i + 1];
    }
    size--;
}

bool search(int x) {
    bool searchResult = false;
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (list[i] == x) {
            searchResult = true;
            pos = i;
            break;
        }
    }
    if (searchResult) {
        count[pos]++;
        int c = count[pos];
        for (int i = 0; i < pos; i++) {
            if (count[pos] > count[i]) {
                for (int j = pos; j > i; j--) {
                    list[j] = list[j - 1];
                    count[j] = count[j - 1];
                }
                list[i] = x;
                count[i] = c;
                break;
            }
        }
    }
    return searchResult;
}

void printList() {
    cout << "List = ";
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
    cout << "\nCount = ";
    for (int i = 0; i < size; i++)
        cout << count[i] << " ";
    cout << endl;
}

int main() {
    char ch;
    do {
        cout << "Please Choose one of the Operations:" << endl;
        cout << "1. To insert Data in the Self Organizing List." << endl;
        cout << "2. To delete Data from the Self Organizing List." << endl;
        cout << "3. To search/find Data in the Self Organizing List." << endl;
        cout << "4. To Check List is empty or not." << endl;
        cout << "5. To Check List is full or not." << endl;
        cout << "6. To Get the size of the Self Organizing List." << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer element to insert" << endl;
                int val;
                cin >> val;
                insert(val);
                break;
            case 2:
                cout << "Enter position to delete" << endl;
                int pos;
                cin >> pos;
                remove(pos);
                break;
            case 3:
                cout << "Enter integer element to search" << endl;
                int x;
                cin >> x;
                cout << "Search Result: " << (search(x) ? "true" : "false") << endl;
                break;
            case 4:
                cout << "Empty status = " << (isEmpty() ? "true" : "false") << endl;
                break;
            case 5:
                cout << "Full status = " << (isFull() ? "true" : "false") << endl;
                break;
            case 6:
                cout << "Size = " << getSize() << endl;
                break;
            default:
                cout << "Please enter a valid option from the menu to proceed further." << endl;
                break;
        }

        printList();

        cout << "Do you want to continue (Type y or n)" << endl;
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
