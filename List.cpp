#include "List.hpp"
using namespace std;

// Node constructor definitions
List::Node::Node(int value) : value(value), prev(nullptr), next(nullptr) {}
List::Node::Node(int value, Node* previous) : value(value), prev(previous), next(nullptr) {}

// Overload << operator for Node
ostream& operator<<(ostream& stream, const List::Node* node) {
    stream << node->value;
    return stream;
}

// List constructor and destructor
List::List() : head(nullptr), tail(nullptr), counter(0) {}

List::~List() {
    purge();
}

// Push elements to the back of the list
void List::push_back(int value) {
    if (!head) {
        head = new Node(value);
        tail = head;
    } else {
        tail->next = new Node(value, tail);
        tail = tail->next;
    }
    ++counter;
}

// Push elements to the front of the list
void List::push_front(int value) {
    if (!head) {
        head = new Node(value);
        tail = head;
    } else {
        Node* temp = head;
        head = new Node(value);
        head->next = temp;
        temp->prev = head;
    }
    ++counter;
}

// Insert element at specific index
void List::insert_at(int value, int index) {
    if (index < 0) {
        cerr << "Index cannot be negative\n";
        return;
    }

    if (index == 0) {
        push_front(value);
    } else if (index == counter) {
        push_back(value);
    } else if (index > counter) {
        cerr << "Index out of bounds: " << index << '\n';
    } else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        ++counter;
    }
}

// Remove the first element in the list
void List::remove_first() {
    if (!head) {
        cerr << "List is empty, cannot remove first element\n";
        return;
    }

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    --counter;
}

// Remove the last element in the list
void List::remove_last() {
    if (!tail) {
        cerr << "List is empty, cannot remove last element\n";
        return;
    }

    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    --counter;
}

// Remove element at specific index
void List::remove_at(int index) {
    if (index < 0 || index >= counter) {
        cerr << "Index out of bounds: " << index << '\n';
        return;
    }

    if (index == 0) {
        remove_first();
    } else if (index == counter - 1) {
        remove_last();
    } else {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        --counter;
    }
}

// Purge the entire list
void List::purge() {
    while (head) {
        remove_first();
    }
}

// Display the list in forward order
void List::display() const {
    cout << *this << '\n';
}

// Display the list in reverse order
void List::display_reversed() const {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }

    Node* current = tail;
    while (current) {
        cout << current << (current->prev ? ", " : "\n");
        current = current->prev;
    }
}

// Display the next element of the list given an index
void List::display_next(int index) const {
    if (index < 0 || index >= counter - 1) {
        cerr << "Index out of bounds or there is no next element\n";
        return;
    }

    cout << (*this)[index + 1] << '\n';
}

// Display the previous element of the list given an index
void List::display_previous(int index) const {
    if (index <= 0 || index >= counter) {
        cerr << "Index out of bounds or there is no previous element\n";
        return;
    }

    cout << (*this)[index - 1] << '\n';
}

// Overload [] operator to access element at index
const int& List::operator[](int index) const {
    if (index < 0 || index >= counter) {
        cerr << "Index out of bounds\n";
        exit(1);
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->value;
}

// Overload << operator to display list
ostream& operator<<(ostream& stream, const List& list) {
    if (!list.head) {
        stream << "List is empty";
    } else {
        List::Node* current = list.head;
        while (current) {
            stream << current;
            if (current->next) stream << ", ";
            current = current->next;
        }
    }
    return stream;
}
