#ifndef CMATHPARSER_H
#define CMATHPARSER_H

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

class CMathParser
{
    public:
        CMathParser();
        ~CMathParser();
        // funkcja parsujace wyrazenie podane w argumencie i zwracajaca wartosc
        double Parse(string str, double x);
        bool IsError()            { return error; }
        void SetError(bool err)   { error = err; }
    protected:
    private:
        // konwertuje dzialanie do notacji ONP
        void ConvertToONP();

        // dzieli wyrazenie na czesci
        void Lexems(string str);

        // wstawia minusy unarne
        string MinusyUnarne(string str);

        // zamienia kazdego x na liczbe odpowiednia
        string XToNumber(string str, double x);

        // wstawia nawiasy przy kazdym x
        string InsertBracklets(string str);

        // tablica reprezentujaca wyjscie
        vector<string> out;

        vector<string> lex;

        // struktura reprezentujaca operator
        struct operators
        {
            int priorytet;  // priorytet
            bool left; // lewostronnosc
            string znak;
        };

        // tablica reprezentujaca stos
        vector<operators> stack;
        operators isOperator(char c);

        // zmienna przechowujaca informacje czy jest blad
        bool error;

        // funkcje wykonujace podstawowe operacje matematyczne
        double _dodawanie(double a, double b);
        double _odejmowanie(double a, double b);
        double _mnozenie(double a, double b);
        double _dzielenie(double a, double b);
        double _potegowanie(double a, double b);

};

#endif // CMATHPARSER_H
