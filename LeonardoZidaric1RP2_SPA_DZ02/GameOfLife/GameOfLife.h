#pragma once
using namespace std;
#include <vector>
class GameOfLife
{
private:
    int redak;
    int stupac;
    vector<bool> generacija;
    vector<bool> sljedecaGeneracija;
    int prebrojiSusjede(int redak, int stupac);
public:
    GameOfLife(int redak, int stupac);
    void nasumicnaInicijalizacija(double sansa);
    void izradaSljedeceGeneracije();
    void ispis();
};

