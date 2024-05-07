#include "GameOfLife.h"
using namespace std;
#include <ctime>
#include <iostream>
GameOfLife::GameOfLife(int redak, int stupac) : redak(redak), stupac(stupac) {
    generacija.resize(redak * stupac, false);
    sljedecaGeneracija.resize(redak * stupac, false);
}

void GameOfLife::nasumicnaInicijalizacija(double sansa) {
    srand(time(NULL));
    for (int i = 0; i < redak * stupac; ++i) {
        double r = rand() / static_cast<double>(RAND_MAX);
        if (r < sansa) {
            generacija[i] = true;
        }
    }
}

int GameOfLife::prebrojiSusjede(int redak, int stupac) {
    int brojac = 0;
    for (int i = redak - 1; i <= redak + 1; ++i) {
        for (int j = stupac - 1; j <= stupac + 1; ++j) {
            if (i >= 0 && i < this->redak && j >= 0 && j < this->stupac && !(i == redak && j == stupac) && generacija[i * this->stupac + j]) {
                brojac++;
            }
        }
    }
    return brojac;
}

void GameOfLife::izradaSljedeceGeneracije() {
    for (int i = 0; i < redak; ++i) {
        for (int j = 0; j < stupac; ++j) {
            int susjedi = prebrojiSusjede(i, j);
            if (generacija[i * stupac + j]) {
                if (susjedi < 2 || susjedi > 3) {
                    sljedecaGeneracija[i * stupac + j] = false;
                }
                else {
                    sljedecaGeneracija[i * stupac + j] = true;
                }
            }
            else {
                if (susjedi == 3) {
                    sljedecaGeneracija[i * stupac + j] = true;
                }
            }
        }
    }
    generacija = sljedecaGeneracija;
}

void GameOfLife::ispis() {
    for (int i = 0; i < redak; ++i) {
        for (int j = 0; j < stupac; ++j) {
            if (generacija[i * stupac + j]) {
                cout << "* ";
            }
            else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}
