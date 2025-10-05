#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

// Add node at head
void addToHead(Node*& head, double rating, string comment) {
    Node* temp = new Node;
    temp->rating = rating;
    temp->comment = comment;
    temp->next = head;
    head = temp;
}

// Add node at tail
void addToTail(Node*& head, double rating, string comment) {
    Node* temp = new Node;
    temp->rating = rating;
    temp->comment = comment;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}

int main() {
    cout << "Which linked list method should we use?\n";
    cout << "[1] New nodes are added at the head of the linked list\n";
    cout << "[2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Node* head = nullptr;
    char again;

    // collect user reviews
    do {
        double rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1)
            addToHead(head, rating, comment);
        else
            addToTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (again == 'Y' || again == 'y');

    cout << "\nOutputting all reviews:\n";
    Node* current = head;
    int count = 1;
    while (current != nullptr) {
        cout << "> Review #" << count << ": " << current->rating
             << ": " << current->comment << endl;
        current = current->next;
        count++;
    }

    cout << "\nReviews displayed successfully!\n";
    return 0;
}
