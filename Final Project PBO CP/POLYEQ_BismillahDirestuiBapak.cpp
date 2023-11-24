#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#define PHI acos(-1)
using namespace std;
double Xroot(double a, double x)
{
    // Xroot ini digunakan untuk akar pangkat x
    double i = 1;
    if (a < 0)
        i = -1;
    return (i * exp(log(a * i) / x));
}

class CubicEquation
{
private:
    double A;
    double B;
    double C;
    double D;

public:
    CubicEquation(double a, double b, double c, double d)
    {
        A = a;
        B = b;
        C = c;
        D = d;
    }

    vector<double> Solve()
    {
        vector<double> roots;
        double a, b, c, d;
        a = B / A;
        b = C / A;
        c = D / A;
        d = D;

        double p = -(a * a / 3.0) + b;
        double q = (2.0 / 27.0 * a * a * a) - (a * b / 3.0) + c;
        double discriminant = q * q / 4.0 + p * p * p / 27.0;

        if (abs(discriminant) < pow(10.0, -11.0))
            discriminant = 0;

        if (abs(discriminant) == 0)
        {

            double u = Xroot(-q / 2.0, 3.0);
            double v = Xroot(-q / 2.0, 3.0);
            double solve1 = u + v - a / 3.0;
            double solve2 = -(u + v) / 2.0 - a / 3.0;
            roots.push_back(solve1);
            roots.push_back(solve2);
            roots.push_back(solve2);
        }
        if (discriminant < 0)
        {

            double r = sqrt(-p * p * p / 27.0);
            double alpha = atan(sqrt(-discriminant) / -q * 2.0);
            if (q > 0) // if q > 0 maka sudut menjadi PI + alpha
                alpha = PHI + alpha;

            double solve1 = Xroot(r, 3.0) * (cos((6.0 * PHI - alpha) / 3.0) + cos(alpha / 3.0)) - a / 3.0;
            double solve2 = Xroot(r, 3.0) * (cos((2.0 * PHI + alpha) / 3.0) + cos((4.0 * PHI - alpha) / 3.0)) - a / 3.0;
            double solve3 = Xroot(r, 3.0) * (cos((4.0 * PHI + alpha) / 3.0) + cos((2.0 * PHI - alpha) / 3.0)) - a / 3.0;
            roots.push_back(solve1);
            roots.push_back(solve2);
            roots.push_back(solve3);
        }

        return roots;
    }
};

vector<double> pangkat_empat;
class PerpangkatanEmpat
{
private:
    double A;
    double B;
    double C;
    double D;
    double E;

public:
    PerpangkatanEmpat(double a, double b, double c, double d, double e)
    {
        A = a;
        B = b;
        C = c;
        D = d;
        E = e;
    }

    double f(double x)
    {
        double ans = 0;
        for (int i = 0; i < 7; i++)
        {
            ans += pangkat_empat[i] * pow(x, i);
        }
        return ans;
    }

    double df(double x)
    {
        double ans = 0;
        for (int i = 1; i < 7; i++)
        {
            ans += i * pangkat_empat[i] * pow(x, i - 1);
        }
        return ans;
    }

    double newton(double x)
    {
        x = x - f(x) / df(x);
        return x;
    }

    bool depressedQuartic = false;
    double X0;
    vector<double> biquadratic()
    {
        vector<double> res;
        double z1 = (-C + sqrt((C * C) - (4.0 * A * E))) / (2.0 * A);
        double z2 = (-C - sqrt((C * C) - (4.0 * A * E))) / (2.0 * A);
        double x1 = sqrt(z1);
        double x2 = -sqrt(z1);
        double x3 = sqrt(z2);
        double x4 = -sqrt(z2);
        if (depressedQuartic)
        {
            x1 = x1 + X0;
            x2 = x2 + X0;
            x3 = x3 + X0;
            x4 = x4 + X0;
        }
        res.push_back(x1);
        res.push_back(x2);
        res.push_back(x3);
        res.push_back(x4);
        return res;
    }
    vector<double> solve()
    {
        depressedQuartic = false;
        // FERRARI
        vector<double> roots;
        if (B == 0 && D == 0)
        {
            return biquadratic();
        }

        B = B / A;
        C = C / A;
        D = D / A;
        E = E / A;
        A = A / A;
        X0 = -B / 4.0 * A;
        // depressed QUARTIC
        double p = ((8.0 * A * C) - (3.0 * B * B)) / (8.0 * A * A);
        double q = ((B * B * B) - (4.0 * A * B * C) + (8.0 * A * A * D)) / (8.0 * A * A * A);
        double r = ((-3.0 * B * B * B * B) + (256.0 * E * A * A * A) - (64.0 * B * D * A * A) + (16 * B * B * C * A)) / (256.0 * A * A * A * A);
        if (q == 0)
        {
            A = 1;
            C = p;
            E = r;
            depressedQuartic = true;
            return biquadratic();
        }
        // FIND FERRARI Y (mencari lambda)
        double a3 = 1.0;
        double a2 = 5.0 / 2.0 * p;
        double a1 = (2.0 * (p * p)) - r;
        double a0 = ((p * p * p) / 2.0) - (p * r / 2.0) - (q * q / 8.0);
        CubicEquation solver(a3, a2, a1, a0);
        vector<double> hasilpangkattiga = solver.Solve();
        double y;
        for (double root : hasilpangkattiga)
        {
            if (p + 2.0 * root != 0.0)
            {
                y = root;
                break;
            }
        }

        double firstPart = sqrt(p + 2.0 * y);
        double positiveSecondPart = sqrt(-3.0 * p - 2.0 * y + 2.0 * q / sqrt(p + 2.0 * y));
        double negativeSecondPart = sqrt(-3.0 * p - 2.0 * y - 2.0 * q / sqrt(p + 2.0 * y));
        // x1 sampai x4
        double solve1 = X0 + (firstPart + negativeSecondPart) / 2.0;
        double solve2 = X0 + (-firstPart + positiveSecondPart) / 2.0;
        double solve3 = X0 + (firstPart - negativeSecondPart) / 2.0;
        double solve4 = X0 + (-firstPart - positiveSecondPart) / 2.0;
        roots.push_back(newton(solve1));
        roots.push_back(newton(solve2));
        roots.push_back(newton(solve3));
        roots.push_back(newton(solve4));
        return roots;
    }
};

template <typename T>
class poly
{
public:
    poly() { coff.assign(7, 0); }

    T f(double x)
    {
        double ans = 0;
        for (int i = 0; i < 7; i++)
        {
            ans += coff[i] * pow(x, i);
        }
        return ans;
    }

    T df(double x)
    {
        double ans = 0;
        for (int i = 1; i < 7; i++)
        {
            ans += i * coff[i] * pow(x, i - 1);
        }
        return ans;
    }

    T newton(double x)
    {
        for (int i = 0; i < 27; i++)
        {
            x = x - f(x) / df(x);
        }
        return x;
    }

    void horner(double x)
    {
        double ans = 0;
        double newPolynomial[7] = {0, 0, 0, 0, 0, 0, 0};
        for (int i = 6; i > 0; i--)
        {
            ans = ans * x + coff[i];
            newPolynomial[i - 1] = ans;
        }
        for (int i = 0; i < 7; i++)
        {
            coff[i] = newPolynomial[i];
        }
    }

    void ABC()
    {
        double x1 = (-coff[1] + sqrt((coff[1] * coff[1]) - (4 * coff[0] * coff[2]))) / (2 * coff[2]);
        double x2 = (-coff[1] - sqrt((coff[1] * coff[1]) - (4 * coff[0] * coff[2]))) / (2 * coff[2]);
        printf("%.2f %.2f", x1 < x2 ? x1 : x2, x1 > x2 ? x1 : x2);
    }

    void parse(char eq[])
    {
        for (int i = 0; eq[i] != '\0'; i++)
        {
            if (eq[i] == '-' || eq[i] == '+')
            {
                if (!deg0)
                {
                    coff[1] += (minop ? -1 : 1) * curcoef;
                    curcoef = -1;
                    deg0 = true, minop = false;
                    maxdeg = max(maxdeg, 1);
                }
                else if (tempcoef != "")
                {
                    coff[0] += (minop ? -1 : 1) * stoi(tempcoef);
                    tempcoef = "";
                    maxdeg = max(maxdeg, 0);
                }
                minop = (eq[i] == '-');
            }
            if (eq[i] == 'x')
            {
                curcoef = (tempcoef == "" ? 1 : stoi(tempcoef));
                tempcoef = "";
                deg0 = false;
            }
            if (eq[i] >= '0' and eq[i] <= '9')
            {
                if (!deg0)
                {
                    int idx = eq[i] - '0';
                    coff[idx] += (minop ? -1 : 1) * curcoef;
                    maxdeg = max(maxdeg, idx);
                    minop = false, deg0 = true;
                    curcoef = -1;
                }
                else
                {
                    tempcoef += eq[i];
                }
            }
        }

        if (!deg0)
            coff[1] += (minop ? -1 : 1) * curcoef;
        if (tempcoef != "")
            coff[0] += (minop ? -1 : 1) * stoi(tempcoef);
        maxdeg = max(maxdeg, (!deg0 ? 1 : 0));
    }

    void solve(char eq[])
    {
        parse(eq);
        if (maxdeg == 1)
            printf("%.2f", -coff[0] / coff[1]);
        else if (maxdeg == 2)
            ABC();
        else if (maxdeg == 3)
        {
            double a = coff[3];
            double b = coff[2];
            double c = coff[1];
            double d = coff[0];
            CubicEquation equation(a, b, c, d);
            vector<double> roots = equation.Solve();
            sort(roots.begin(), roots.end());
            for (double root : roots)
            {
                printf("%.2f ", root);
            }
        }
        else if (maxdeg == 4)
        {
            double a = coff[4];
            double b = coff[3];
            double c = coff[2];
            double d = coff[1];
            double e = coff[0];
            PerpangkatanEmpat equation(a, b, c, d, e);
            pangkat_empat.push_back(e);
            pangkat_empat.push_back(d);
            pangkat_empat.push_back(c);
            pangkat_empat.push_back(b);
            pangkat_empat.push_back(a);
            vector<double> roots = equation.solve();
            sort(roots.begin(), roots.end());
            for (double root : roots)
            {
                printf("%.2f ", root);
            }
            pangkat_empat.clear();
        }
        else
        {
            // pembatasan maxdeg-3 sehingga sisanya adalah cubic equation
            for (int i = 0; i < maxdeg - 3; i++)
            {
                double x = newton(15);
                horner(x);
                if (abs(x) < 5e-3)
                    x = 0;
                res.push_back(x);
            }
            // menggunakan cardano untuk sisa dari newton dan horner
            double a = coff[3];
            double b = coff[2];
            double c = coff[1];
            double d = coff[0];
            CubicEquation equation(a, b, c, d);
            vector<double> roots = equation.Solve();
            for (double data : roots)
            {
                if (abs(data) < 5e-3)
                    data = 0.0;
                res.push_back(data);
            }
            sort(res.begin(), res.end());
            for (int i = 0; i < res.size(); i++)
            {
                printf("%.2f ", res[i]);
            }
        }
        printf("\n");
    }

private:
    vector<T> coff, res;
    int curcoef, maxdeg = -1;
    string tempcoef = "";
    bool minop = false, deg0 = true;
};

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        char eq[300];
        memset(eq, 0, sizeof eq);
        scanf(" %[^\n]s", eq);
        poly<double> p;
        p.solve(eq);
    }
    return 0;
}
