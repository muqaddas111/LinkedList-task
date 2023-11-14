#include <iostream>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class represents a linked list and provides various operations
class LinkedList {
private:
    Node* head;

public:
    // Constructor initializes an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtStart(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at a specific position in the list
    void insertAtPoint(int position, int data) {
        if (position == 0) {
            insertAtStart(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* current = head;

        for (int i = 0; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            cout << "Position out of bounds." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to delete the first node in the list
    void deleteFromStart() {
        if (!head) {
            cout << "List is empty. Cannot delete from beginning." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete the last node in the list
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty. Cannot delete from end." << endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // Function to delete a node at a specific position in the list
    void deleteAtPoint(int position) {
        if (!head) {
            cout << "List is empty. Cannot delete from position." << endl;
            return;
        }

        if (position == 0) {
            deleteFromStart();
            return;
        }

        Node* current = head;

        for (int i = 0; i < position - 1 && current && current->next; ++i) {
            current = current->next;
        }

        if (!current || !current->next) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to search for a node with a specific value and update its data
    void searchAndUpdate(int searchData, int newData) {
        Node* current = head;

        while (current) {
            if (current->data == searchData) {
                current->data = newData;
                cout << "Data updated successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Data not found." << endl;
    }

    // Function to search for a node with a specific value
    void search(int searchData) {
        Node* current = head;

        while (current) {
            if (current->data == searchData) {
                cout << "Data found in the list." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Data not found in the list." << endl;
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

// Main function where the linked list operations are demonstrated
int main() {
    int choice, n1, n2, n3, n5, n6, n7, n8;
    LinkedList List;

    // Initial elements in the linked list
    List.insertAtStart(50);
    List.insertAtStart(60);
    List.insertAtStart(80);
    List.insertAtStart(90);
    List.insertAtStart(20);

    cout << "Original LinkList: ";
    List.display();

    do {
        cout << "1. for Insert, 2. for Delete, 3. for Search and Update, 4. for Search, 5. for Display, 6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insertion operations
                cout << "Enter Position to insert data: ";
                cin >> n1;
                cout << "Enter data to insert at position: ";
                cin >> n2;
                List.insertAtPoint(n1, n2);
                cout << "List after insert at position: ";
                List.display();
                cout << "Enter data to insert at start: ";
                cin >> n3;
                List.insertAtStart(n3);
                List.display();
                break;

            case 2:
                // Deletion operations
                List.deleteFromStart();
                cout << "List after deleting from beginning: ";
                List.display();

                List.deleteFromEnd();
                cout << "List after deleting from end: ";
                List.display();

                cout << "Enter Position to Delete data: ";
                cin >> n5;
                List.deleteAtPoint(n5);
                cout << "List after deleting from position: ";
                List.display();
                break;

            case 3:
                // Search and Update operation
                cout << "Enter number to search: ";
                cin >> n6;
                cout << "Enter number to update: ";
                cin >> n7;
                List.searchAndUpdate(n6, n7);
                cout << "List after searching and updating: ";
                List.display();
                break;

            case 4:
                // Search operation
                cout << "Enter number to search: ";
                cin >> n8;
                List.search(n8);
                break;

            case 5:
                // Display the final linked list
                cout << "Final linked list:" << endl;
                List.display();
                break;
        }
    } while (choice != 6);

    cout << "Exit (.-.)" << endl;
    return 0;
}