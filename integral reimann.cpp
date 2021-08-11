#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

void rp();
int main()
{
	string ulang;
	do{
		system("cls");
		cout << "Program Integral Riemann" << endl;
		cout << setw(24) << setfill('=') << '=' << endl;

		rp();
		do{
			cout << "\n\nApakah Anda ingin mengulang program?(y/n) : ";
			cin >> ulang;
		}while((ulang!="y" && ulang !="Y") && (ulang !="n" && ulang!="N")); 
		cout << endl;
	}while(ulang=="y" || ulang=="Y");
}
void rp()
{
	int koef[20], max, min, pangkat, a, b;
	float akar,n,h,x[20],xbar[20],fx[20], total, sigmafx, rp;
	string yn;
	
	//Input f(x)
	do{
		min=0; akar=0;
		cout << "\nInput f(x)\n";
		cout << "Masukkan pangkat tertinggi variabel x : "; cin >> max;
		do{
			cout << "Apakah ada pangkat negatif?(y/n) : "; cin >> yn;
		}while((yn!="y" && yn !="Y") && (yn !="n" && yn!="N"));
		if(yn=="y" || yn=="Y"){
			cout << "Masukkan pangkat tekecil variabel x : "; cin >> min;
		}
		do{
			do{
				cout << "Apakah f(x) memakai akar?(y/n) : "; cin >> yn;
			}while((yn!="y" && yn !="Y") && (yn !="n" && yn!="N"));
			if(yn=="y" || yn=="Y"){
				cout << "Masukkan akar f(x) : "; cin >> akar;
				if(akar==0)
					cout << "Error! akar 0 tidak terdefinisi" << endl;
			}
		}while(akar==0 && (yn=="y" || yn=="Y"));
		//input f(x)
		pangkat=max;
		for (int i=max-min; i>=0; i--)
		{
			if (pangkat!=0)
			{
				cout << "Masukkan koefisien x^" << pangkat << " : "; 
				cin >> koef[i];
			}
				else
				{
					cout << "Masukkan konstanta : ";
					cin >> koef[i];
				}
			pangkat--;
		}
		//output f(x)
		pangkat=max;
		cout << "\nf(x) = ";
		if(akar!=0)
		cout << "(";
		for (int i=max-min; i>=0; i--)
		{
			if (pangkat!=0)
			{
				if (koef[i] > 0 && i!=max-min)
					cout << "+";
				if (koef[i] > 1 || koef[i] < 0)
					cout << koef[i];
				if (koef[i] !=0 && pangkat!=1)
					cout << "x^" << pangkat;
				if (koef[i] !=0 && pangkat==1)
					cout << "x";
			}
			else
			{
				if (koef[i] > 0)
					cout << "+";
				if (koef[i] != 0)
					cout << koef[i];
			}
			pangkat--;
		}
		if(akar!=0)
		cout << ")^(1/" << akar << ")";
		cout << endl << endl;
		do{
			cout << "Apakah f(x) sudah benar? (y/n) : "; cin >> yn;
		}while((yn!="y" && yn !="Y") && (yn !="n" && yn!="N")); 
	}while(yn=="n" || yn=="N");
	
	//input batas dan banyak partisi
	do{
		cout << "\nMasukkan a (batas bawah): "; cin >> a;
		cout << "Masukkan b (batas atas)	: "; cin >> b;
		cout << "Masukkan n		: "; cin >> n;
		h=(b-a)/n;
	//output
		cout << "\nPada selang [" << a << "," << b << "]" << "\nDengan partisi ";
		int j=0;
		for (float i=a; i<=b; i=i+h)
		{
			x[j]=i;
			if(i!=b)
			cout << x[j] << " < ";
			else
			cout << x[j] << endl << endl;
			j++;
		}
		do{
			cout << "Apakah sudah benar? (y/n) : "; cin >> yn;
		}while((yn!="y" && yn !="Y") && (yn !="n" && yn!="N")); 
	}while(yn=="n" || yn=="N");
	
	if(akar!=0)
	akar=1/akar;
	//penghitungan
	sigmafx=0;
	for (int i=1; i<=n; i++)
	{
		total=0;
		xbar[i]=x[i-1] + (h/2);
		cout << "x bar " << i << " = " << xbar[i];
		cout << "\t\t|| f(" << xbar[i] << ")\t= ";
		pangkat=min;
		for (int j=0; j<=max-min; j++)
		{
			if(pangkat!=0)
				fx[j]=koef[j]*pow(xbar[i],pangkat);
			else
			{
				fx[j]=0;
				fx[j]=fx[j]+koef[j];
			}
			total=total+fx[j];
			
			pangkat++;
		}
		if(akar!=0)
			total=pow(total,akar);
		fx[i]=total;
		sigmafx=sigmafx+fx[i];
		cout << fx[i];
		cout << endl;
	}
	cout << "\t\t\t|| sigma f(xbar)= " << sigmafx;
	rp = sigmafx * h;
	cout << "\n\nRp = sigma f(xbar) * h" << endl;
	cout << "   = " << sigmafx << " * " << h << endl;
	cout << "   = " << rp;
}
