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
    double px = 2;
    double py = 7;

    if (g.liegtAufGerade(px, py)) {

        std::cout << "Punkt (" << px << "|" << py << ") liegt auf der Geraden." << std::endl;

    } 
    else 
    {

        std::cout << "Punkt (" << px << "|" << py << ") liegt NICHT auf der Geraden." << std::endl;

    }

    return 0;
}