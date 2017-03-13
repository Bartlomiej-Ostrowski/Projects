#include "cmathparser.h"

double CMathParser::_dodawanie(double a, double b)
{
    return (b + a);
}

double CMathParser::_odejmowanie(double a, double b)
{
    return (b - a);
}

double CMathParser::_mnozenie(double a, double b)
{
    return (b * a);
}

double CMathParser::_dzielenie(double a, double b)
{
    if(a == 0)
    {
        SetError(true);
        return 1;
    }
    else
        return(b / a);
}

double CMathParser::_potegowanie(double a, double b)
{
    return (pow(b, a));
}


//************************************************************************************************
CMathParser::CMathParser()
{
    error = false;
}

CMathParser::~CMathParser()
{
    //dtor
}

// konwertuje dzialanie do notacji ONP
void CMathParser::ConvertToONP()
{
    char c1, c2;
    string s1, s2;
    for(int i = 0; i < lex.size(); i++)
    {
        s1 = lex[i];
        c1 = s1[0];
        // liczba
        if((c1 >= '0' && c1 <= '9') || c1 == '.')
        {
            out.push_back(s1);
        }
        // funkcja
        else if(c1 >= 'a' && c1 <= 'z')
        {
            operators opp;
            opp.priorytet = -1;
            if(s1 == "abs")
            {
                opp.znak = "a";
            }
            else if(s1 == "sin")
            {
                opp.znak = "b";
            }
            else if(s1 == "cos")
            {
                opp.znak = "c";
            }
            else if(s1 == "tg")
            {
                opp.znak = "d";
            }
            else if(s1 == "ctg")
            {
                opp.znak = "e";
            }
            else if(s1 == "sqrt")
            {
                opp.znak = "f";
            }
            else if(s1 == "ln")
            {
                opp.znak = "g";
            }
            else if(s1 == "asin")
            {
                opp.znak = "h";
            }
            else if(s1 == "acos")
            {
                opp.znak = "i";
            }
            else if(s1 == "atan")
            {
                opp.znak = "j";
            }
            else if(s1 == "sinh")
            {
                opp.znak = "k";
            }
            else if(s1 == "cosh")
            {
                opp.znak = "l";
            }
            else if(s1 == "tanh")
            {
                opp.znak = "m";
            }
            else if(s1 == "exp")
            {
                opp.znak = "n";
            }
            else if(s1 == "floor")
            {
                opp.znak = "o";
            }
            else if(s1 == "ceil")
            {
                opp.znak = "p";
            }
            else if(s1 == "sgn")
            {
                opp.znak = "r";
            }
            else if(s1 == "pi")
            {
                opp.znak = "s";
            }
            else if(s1 == "e")
            {
                opp.znak = "t";
            }
            else if(s1 == "log")
            {
                opp.znak = "u";
            }
            stack.push_back(opp);
        }
        // lewy nawias
        else if(s1 == "(")
        {
            operators opp;
            opp.znak = "(";
            opp.priorytet = 0;
            stack.push_back(opp);
        }
        // prawy nawias
        else if(s1 == ")")
        {
            while(true)
            {
                if(stack[stack.size()-1].znak == "(")
                    break;
                out.push_back(stack[stack.size()-1].znak);
                stack.pop_back();
            }
            stack.pop_back();
            if(stack.size() != 0)
            {
                // pobranie znaku od czegos stojacego przed nawiasem
                char q = stack[stack.size() - 1].znak[0];
                // jesli tak, jest to funkcja
                if(q >= 'a' && q <= 'z')
                {
                    out.push_back(stack[stack.size() - 1].znak);
                    stack.pop_back();
                }
            }
        }
        // operator
        else if(c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/' || c1 == '^')
        {
            operators op = isOperator(c1);
            if(stack.size() <= 0)
            {
                stack.push_back(op);
                continue;
            }
            operators op2 = stack[stack.size()-1];
            while((op.left == true && op.priorytet <= op2.priorytet) || (op.left == false && op.priorytet < op2.priorytet))
            {
                // zdejmij ze stosu op2;
                stack.pop_back();
                // odloz na wyjscie op2
                out.push_back(op2.znak);
                //pobierz kolejny operator ze stosu
                if(stack.size() > 0)
                    op2 = stack[stack.size()-1];
                else
                    break;
            }
            stack.push_back(op);
        }
    }
    // dodaj reszte stosu na wyjscie
    for(int i = stack.size()-1; i >= 0; i--)
    {
        out.push_back(stack[i].znak);
        stack.pop_back();
    }
}

// dzieli wyrazenie na czesci
void CMathParser::Lexems(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        string sub = str.substr(i, 1);
        string str2;
        // liczba
        if((c >= '0' && c <= '9') || c == '.')
        {
            while((c >= '0' && c <= '9') || c == '.')
            {
                str2 += c;
                c = str[++i];
            }
            lex.push_back(str2);
            --i;
        }
        // funkcja
        else if(c >= 'a' && c <= 'z')
        {
            while(c >= 'a' && c <= 'z')
            {
                str2 += c;
                c = str[++i];
            }
            lex.push_back(str2);
            --i;
        }
        // operator lub nawias
        else
        {
            lex.push_back(sub);
        }
    }
}

// wstawia 0 przed minusy unarne
string CMathParser::MinusyUnarne(string str)
{
    // minus na poczatku
    if(str[0] == '-')
        str.insert(0, "0");
    // minus zaraz za nawiasem
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if(c == '(')
        {
            while(str[++i] == '(') {}
            if(str[i] == '-')
           {
               str.insert(i, "0");
               i++;
           }
        }
    }
return str;
}

// zamienia kazdego x na liczbe odpowiednia
string CMathParser::XToNumber(string str, double x)
{
    char buf[250];
    sprintf(buf, "%f", x);
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if(c == 'x')
        {
            str.replace(i, 1, buf);
        }
    }
return str;
}

// wstawia nawiasy przy kazdym x
string CMathParser::InsertBracklets(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if(c == 'x')
        {
            // za x daj (x)
            str.replace(i, 1, "(x)");
            i += 2;
        }
    }
return str;
}

// funkcja parsujace wyrazenie podane w argumencie i zwracajaca wartosc double
double CMathParser::Parse(string str, double x)
{
    vector<double> stack2;

    if(x >= 0)
    {
        Lexems(MinusyUnarne(XToNumber(str, x)));
    }
    else
    {
        Lexems(MinusyUnarne(XToNumber(InsertBracklets(str), x)));
    }

    ConvertToONP();

    string s1;
    char c1;
    double a, b, wynik = 0;

    for(int i = 0; i < out.size(); i++)
    {
        s1 = out[i];
        c1 = s1[0];
        if((c1 >= '0' && c1 <= '9') || c1 == '.')
        {
            stack2.push_back(atof(s1.c_str()));
        }
        else if(c1 >= 'a' && c1 <= 'z')
        {
            // liczba PI
            if(c1 == 's')
            {
                wynik = 3.1415926535;
            }
            // liczba Eulera
            else if(c1 == 't')
            {
                wynik = 2.7182818284;
            }
            else
            {
                a = stack2[stack2.size() - 1];
                stack2.pop_back();
                if(c1 == 'a')
                {
                    wynik = fabs(a);
                }
                if(c1 == 'b')
                {
                    wynik = sin(a);
                }
                if(c1 == 'c')
                {
                    wynik = cos(a);
                }
                if(c1 == 'd')
                {
                    wynik = tan(a);
                }
                if(c1 == 'e')
                {
                    wynik = 1/tan(a);
                }
                if(c1 == 'f')
                {
                    if(a < 0)
                        error = true;
                    else
                        wynik = sqrt(a);
                }
                if(c1 == 'g')
                {
                    wynik = log(a);
                }
                if(c1 == 'h')
                {
                    wynik = asin(a);
                }
                if(c1 == 'i')
                {
                    wynik = acos(a);
                }
                if(c1 == 'j')
                {
                    wynik = atan(a);
                }
                if(c1 == 'k')
                {
                    wynik = sinh(a);
                }
                if(c1 == 'l')
                {
                    wynik = cosh(a);
                }
                if(c1 == 'm')
                {
                    wynik = tanh(a);
                }
                if(c1 == 'n')
                {
                    wynik = exp(a);
                }
                if(c1 == 'o')
                {
                    wynik = floor(a);
                }
                if(c1 == 'p')
                {
                    wynik = ceil(a);
                }
                if(c1 == 'r')
                {
                    if(a > 0)
                        wynik = 1;
                    else if(a == 0)
                        wynik = 0;
                    else
                        wynik = -1;
                }
                if(c1 == 'u')
                {
                    wynik = log10(a);
                }
            }
            stack2.push_back(wynik);
        }
        else if(c1 == '+' || c1 == '-' || c1 == '*' || c1 == '/' || c1 == '^')
        {
            a = stack2[stack2.size() - 1];
            stack2.pop_back();
            b = stack2[stack2.size() - 1];
            stack2.pop_back();
            switch(c1)
            {
                case '+':
                    wynik = _dodawanie(a, b);
                    break;
                case '-':
                    wynik = _odejmowanie(a, b);
                    break;
                case '*':
                    wynik = _mnozenie(a, b);
                    break;
                case '/':
                    wynik = _dzielenie(a, b);
                    break;
                case '^':
                    wynik = _potegowanie(a, b);
                    break;
            }
            stack2.push_back(wynik);
        }
    }

    return stack2[0];

}

CMathParser::operators CMathParser::isOperator(char c)
{
    operators op;
    switch(c)
    {
        case '+':
            op.priorytet = 1;
            op.left = true;
            op.znak = "+";
            break;
        case '-':
            op.priorytet = 1;
            op.left = true;
            op.znak = "-";
            break;
        case '*':
            op.priorytet = 2;
            op.left = true;
            op.znak = "*";
            break;
        case '/':
            op.priorytet = 2;
            op.left = true;
            op.znak = "/";
            break;
        case '^':
            op.priorytet = 3;
            op.left = false;
            op.znak = "^";
            break;
    }

return op;
}
