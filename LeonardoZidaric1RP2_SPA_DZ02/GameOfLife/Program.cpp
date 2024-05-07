#include <iostream>
#include "GameOfLife.h"

int main() {
    int redak = 10;
    int stupac = 10;
    bool dalje;
    GameOfLife igra(redak, stupac);
    igra.nasumicnaInicijalizacija(0.25);
    int generacija = 1;
    do
    {
        cout << "Generacija " << generacija << ":" << endl;
        igra.ispis();
        igra.izradaSljedeceGeneracije();
        generacija++;
        cout << "Zelite li dalje? (1/0): ";
        cin >> dalje;
    } while (dalje);

    return 0;
}