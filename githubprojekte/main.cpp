#include <iostream>
#include "gerade.h"
#include "parabel.h"

int main() {
    // Eine Gerade und eine Parabel erstellen
    gerade g(2, 3);          // y = 2x + 3
    parabel p(1, 0, 0);      // y = 1x^2 

    std::cout << "Geometrie Test" << std::endl;

    // Schnittpunkt-Check
    g.schnittpunktParabel(p);

    // Liegt der Punkt auf der Geraden?
    if (g.liegtAufGerade(2, 7)) {
        std::cout << "Punkt (2|7) liegt auf der Geraden." << std::endl;
    }

    return 0;
}