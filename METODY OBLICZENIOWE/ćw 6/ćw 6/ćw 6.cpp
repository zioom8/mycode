// �w 6.cpp: Okre�la punkt wej�cia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Wektor {
public:
	size_t W;
	double *a;
	double *b;
	double *c;
	double *x;
	double *y;
public:
	Wektor::Wektor(size_t W);
	~Wektor() {delete[] x; delete[] y; delete[] a; delete[] b; delete[] c;}
	void wpiszWektor();
	void wypiszWektor(double *wektor, int n);
	void metodaThomasa(int n);
	void rozwiaz(int n);

};

Wektor::Wektor(size_t W) : W(W)
{
	a = new double[W-1];
	b = new double[W];
	c = new double[W-1];
	x = new double[W];
	y = new double[W];
	wpiszWektor();
}


void Wektor::wpiszWektor()
{	
	a[0] = 3./4;		b[0] = 30.0;		c[0] = 2./3;		y[0] = 94./3;		
	a[1] = 7./8;		b[1] = 20.0;		c[1] = 5./6;		y[1] = 173./4;		
	a[2] = 11./12;		b[2] = 10.0;		c[2] = 9./10;		y[2] = 581./20;		
	a[3] = 15./16;		b[3] = 10.0;		c[3] = 13./14;		y[3] = -815./28;	
	a[4] = 19./20;		b[4] = 20.0;		c[4] = 17./18;		y[4] = -6301./144;	
						b[5] = 30.0;							y[5] = -319./10;	

}

void Wektor::wypiszWektor(double *wektor, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << wektor[i] << endl;
	}
	cout << endl;
}

void Wektor::metodaThomasa(int n)
{
	for (int i = 0; i < n-1; i++)
	{
		b[i+1] = b[i+1] - a[i] * (c[i] / b[i]);
		a[i] = a[i] / b[i];
	}
}

void Wektor::rozwiaz(int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		y[i] = y[i] - a[i - 1] * y[i - 1];
	}

	x[n-1] = y[n-1] / b[n-1];

	for (int i = n - 2; i >= 0; i--)
	{
		x[i] = (y[i] - c[i] * x[i + 1]) / b[i];
	}
}

int main()
{
	cout.precision(10);
	int n = 6;
	Wektor w(n);
	cout << endl << "Wektor l " << endl;
	w.wypiszWektor(w.a,n-1);
	cout << endl << "Wektor d " << endl;
	w.wypiszWektor(w.b, n);
	cout << endl << "Wektor u " << endl;
	w.wypiszWektor(w.c, n-1);
	cout << endl << "Wektor b " << endl;
	w.wypiszWektor(w.y, n);
	cout << endl;
	
	w.metodaThomasa(n);
	cout << endl << "Wektor l " << endl;
	w.wypiszWektor(w.a, n-1);
	cout << endl << "Wektor d " << endl;
	w.wypiszWektor(w.b, n);
	cout << endl << "Wektor u " << endl;
	w.wypiszWektor(w.c, n-1);
	
	w.rozwiaz(n);
	cout << endl << "Wektor x " << endl;
	w.wypiszWektor(w.x, n);
	cout << endl;
	

	system("Pause");
    return 0;
}

/*
macierz trojgianonalna
3 osobne tablice trzymaj�ce warto�ci przek�tnych ka�da
to co w pi�tym, rozk�ad na LU
wykorzysta� algorythm thomasa
*/
