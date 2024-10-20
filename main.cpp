#include <iostream>
#include "List.hpp"
using namespace std;

int main() {
    List b; 
    for (int i = 0; i < 30; i++) {
        b.push_front(i); 
    }

    cout << b; 
    b.display_reversed(); 
}
