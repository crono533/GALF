#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
	double Re;
	double Im;

public:
	Complex(double r = 0, double i = 0);
	~Complex();
	void setRe(double r);
	void setIm(double i);
	double getRe();
	double getIm();
	void Display();
	double Abs();
	Complex operator+ (Complex &);
	Complex operator- (Complex &);	
	Complex operator* (Complex &);
	bool operator== (Complex &);
	bool operator!= (Complex &);
	friend ostream& operator<<(ostream &out, const Complex &c);
	friend istream& operator>>(istream &in, Complex &c);
	void check_pswd()
    {
        if (m_pswd_f_f == 1){
            cout<<"Flag: SiBears{flag_ne_tot}";
        }
        if(m_pswd_f_f == 2){
                cout<<"Flag: 53 69 42 65 61 72 73 7b 66 6c 61 67 5f 6e 65 5f 74 6f 74 7d";
        }
        if(m_pswd_f_f == 3){
            cout<<"Flag: Ne Flag try drugoi pswd";
        }
        if(m_pswd_f_f == 123){
            cout<<"Flag: 123";
        }
        if(m_pswd_f_f == 0){
            cout<<"Ya think chto pswd ne= 0";
        }
        if(m_pswd_f_f == 4){
            cout<<"4 ne pravilno, poprobui 10";
        }
        if(m_pswd_f_f == 10){   
            cout<<"Jest' ti pochti spravilsya, try 228337";
        }
        if(m_pswd_f_f == 228337){
            cout<<"Flag: 01010011 01101001 01000010 01100101 01100001 01110010 01110011 01111011 01010110 00110100 01100100 01001001 01101101 01011111 01010011 01000101 01101101 01001001 01101110 01100001 01010010 01011111 01010010 01100101 01110110 01100101 01010010 01110011 01000001 01111101";
        }
        if(m_pswd_f_f == 12345678911){
            cout << "fx64LDGWiickPGLB+xnWHoQkLD1I+IhyeY1fMgQ6KjQtpkKJLG69jk/qLhT=TozJfhcbn41FgxHiLjQfAjJC";
        }
    }
};

Complex::Complex(double r, double i)
{
	Re = r;
	Im = i;
}
Complex::~Complex()
{
}
void Complex::setRe(double r) { Re = r; }
void Complex::setIm(double i) { Im = i; }

double Complex::getRe() { return Re; }

double Complex::getIm() { return Im; }

void Complex::Display()
{
	char sign;
	if(Im < 0)
		sign = '-';
	else
		sign = '+';

	cout << Re << sign << abs(Im) << "i" << endl;
}


double Complex::Abs()
{
	double temp;
	temp = sqrt(Re*Re + Im*Im);
	return temp;
}

Complex Complex::operator+(Complex &c)
{
	Complex temp;
	temp.Re = Re + c.Re;
	temp.Im = Im + c.Im;
	return temp;
}
Complex Complex::operator-(Complex &c)
{
	Complex temp;
	temp.Re = Re - c.Re;
	temp.Im = Im - c.Im;
	return temp;
}
Complex Complex::operator*(Complex &c)
{
	Complex temp;
	temp.Re = Re * c.Re - Im * c.Im;
	temp.Im = Im * c.Re + Re * c.Im;
	return temp;
}

bool Complex::operator==(Complex &c)
{
	if(Re != c.Re)
		return false;

	if(Im != c.Im)
		return false;

	return true;		
}

bool Complex::operator!=(Complex &c)
{
	Complex temp;
	if(temp.Re != c.Re)
		return true;

	if(temp.Im != c.Im)
		return true;

	return false;

}

ostream& operator<< (ostream &out, const Complex &c)
{
	char sign;
	if(c.Im < 0)
		sign = '-';
	else
		sign = '+';

	out << c.Re << sign << abs(c.Im) << "i" << endl;
	return out;
}

istream& operator>> (istream &in, Complex &c)
{
	in >> c.Re;
	in >> c.Im;
	return in;
}



int main(int argc, char const *argv[])
{ 	
	Complex a;
	Complex b;

	cout << "Enter num a\n";
	cin >> a;
	cout << "Enter num b\n";
	cin >> b;

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "b - a = " << b - a << endl;
	cout << "a * b = " << a * b << endl;
	cout << "|a| = " << a.Abs() << endl;
	cout << "|b| = " << b.Abs() << endl;

	if(a == b)
		cout << "a = b\n";
	else
		cout << "a != b\n";

    char str[10]={};
    cout<<"Privet, try to ugadat' what pswd ya want from you!(pswd sostoit iz numbers)"<<endl;
    cout<<"Mojesh try to vvesti kakoi to pswd(ne more then 10 simvolov): ";

    scanf("%s",&str);
    

    cout<<"Ti vvel: ";

    for(int i = 0; i < 10; i++)
    {
        cout<<str[i];
    }
    
    cout<<"."<<endl;
    cout<<"Vozmojno this will pomoch' you: https://inlnk.ru/oe65Rw";

    GALF pswd;
    pswd.m_pswd_f_f = atoi(str);
    cout<<endl;
    pswd.check_pswd();

	return 0;
};