#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

/// @brief Klasa reprezentująca dwukierunkową listę powiązaną.
class List {
    /// @brief Struktura reprezentująca węzeł w liście.
    struct Node {
        int value;      ///< Wartość przechowywana w węźle.
        Node* prev;     ///< Wskaźnik na poprzedni węzeł.
        Node* next;     ///< Wskaźnik na następny węzeł.

        /// @brief Konstruktor do tworzenia węzła z podaną wartością.
        /// @param val Wartość do przechowywania w węźle.
        Node(int val = 0);

        /// @brief Konstruktor do tworzenia węzła z podaną wartością i wskaźnikiem na inny węzeł.
        /// @param val Wartość do przechowywania w węźle.
        /// @param previous Wskaźnik na poprzedni węzeł.
        Node(int val, Node* previous);

        /// @brief Przeciążenie operatora << do wyświetlania węzła.
        /// @param stream Strumień wyjściowy.
        /// @param node Wskaźnik na węzeł do wyświetlenia.
        /// @return Referencja do strumienia wyjściowego.
        friend ostream& operator<<(ostream& stream, const List::Node* node);
    };

private:
    Node* head;      ///< Wskaźnik na pierwszy węzeł listy.
    Node* tail;      ///< Wskaźnik na ostatni węzeł listy.
    int count;       ///< Licznik elementów na liście.

public:
    /// @brief Konstruktor domyślny klasy List.
    List();

    /// @brief Destruktor klasy List.
    ~List();

    /// @brief Dodaje nowy element na końcu listy.
    /// @param value Wartość do dodania.
    void push_back(int value);

    /// @brief Dodaje nowy element na początku listy.
    /// @param value Wartość do dodania.
    void push_front(int value);

    /// @brief Wstawia nowy element na określonym indeksie.
    /// @param value Wartość do wstawienia.
    /// @param index Indeks, na którym ma być wstawiony nowy element.
    void insert_at(int value, int index);

    /// @brief Usuwa pierwszy element z listy.
    void remove_first();

    /// @brief Usuwa ostatni element z listy.
    void remove_last();

    /// @brief Usuwa element na określonym indeksie.
    /// @param index Indeks elementu do usunięcia.
    void remove_at(int index);

    /// @brief Usuwa wszystkie elementy z listy.
    void purge();

    /// @brief Wyświetla zawartość listy.
    void display() const;

    /// @brief Wyświetla zawartość listy w odwrotnej kolejności.
    void display_reversed() const;

    /// @brief Wyświetla następny element, zaczynając od danego indeksu.
    /// @param index Indeks początkowy do wyświetlenia.
    void display_next(int index) const;

    /// @brief Wyświetla poprzedni element, zaczynając od danego indeksu.
    /// @param index Indeks początkowy do wyświetlenia.
    void display_previous(int index) const;

    /// @brief Przeciążenie operatora [] do dostępu do elementów listy.
    /// @param index Indeks elementu, do którego ma nastąpić dostęp.
    /// @return Stała referencja do wartości na określonym indeksie.
    const int& operator[](int index) const;

    /// @brief Przeciążenie operatora << do wyświetlania listy.
    /// @param stream Strumień wyjściowy.
    /// @param list Lista do wyświetlenia.
    /// @return Referencja do strumienia wyjściowego.
    friend ostream& operator<<(ostream& stream, const List& list);

    /// @brief Przeciążenie operatora << do wyświetlania węzła.
    /// @param stream Strumień wyjściowy.
    /// @param node Wskaźnik na węzeł do wyświetlenia.
    /// @return Referencja do strumienia wyjściowego.
    friend ostream& operator<<(ostream& stream, const List::Node* node);
};

#endif // LIST_H
