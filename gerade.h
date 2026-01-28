#ifndef GERADE_H
#define GERADE_H

#include <iostream>
#include <cmath>
#include "parabel.h"

class gerade
{
public:
    double m, b;

    // Konstruktoren: Erstellen der Gerade
    gerade(double m, double b) : m(m), b(b) {}

    gerade(double x1, double y1, double x2, double y2)
    {
        m = (y2 - y1) / (x2 - x1);
        b = y1 - m * x1;
    }

    // Berechnet y für ein x
    double getY(double x)
    {
        return m * x + b;
    }

    // Liegt ein Punkt auf der Gerade?
    bool liegtAufGerade(double x, double y)
    {
        return std::abs(getY(x) - y) < 0.001;
    }

    // Schnittpunkt mit einer anderen Gerade
    void schnittpunkt(gerade a)
    {
        if (m == a.m)
        {
            std::cout << "Parallel: Kein Schnittpunkt!" << std::endl;
        }
        else
        {
            double x = (a.b - b) / (m - a.m);
            std::cout << "Schnittpunkt G/G: P(" << x << "|" << getY(x) << ")" << std::endl;
        }
    }

    // Schnittpunkt mit einer Parabel
    void schnittpunktParabel(parabel p)
    {
        // (ax^2 + bx + c = 0)          ax^2+(b−m)x+(c−n)=0
        double A = p.a;
        double B = p.b - m;
        double C = p.c - b;

        double D = (B * B) - (4 * A * C);

        if (D < 0)
        {
            std::cout << "Kein Schnittpunkt gefunden." << std::endl;
        }
        else if (D == 0)
        {
            double x = -B / (2 * A);
            std::cout << "Ein Beruehrpunkt: P(" << x << " | " << getY(x) << ")" << std::endl;
        }
        else
        {
            double x1 = (-B + std::sqrt(D)) / (2 * A);
            double x2 = (-B - std::sqrt(D)) / (2 * A);

            std::cout << "Zwei Schnittpunkte gefunden:" << std::endl;
            std::cout << "P1(" << x1 << " | " << getY(x1) << ")" << std::endl;
            std::cout << "P2(" << x2 << " | " << getY(x2) << ")" << std::endl;
        }
    }
};

#endif