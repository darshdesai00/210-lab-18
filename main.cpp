#include <iostream>
#include <string>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

int main() {
    cout << "Which linked list method should we use?\n";
    cout << "[1] New nodes are added at the head of the linked list\n";
    cout << "[2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    cin.ignore();

    //linked list logic next
    return 0;
}
