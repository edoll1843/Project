#include <iostream>
using namespace std;
#pragma once
class PatientInfo
{
private:
	char* name = nullptr;//declare private
	char* address = nullptr;
	int registration_number = 0;
	int phone_number = 0;

public:
	PatientInfo(char* name, char* address, int registration_number, int phone_number);
	~PatientInfo();//declare public

	char* getName();//get func
	char* getAddress();
	int get_R_Number();
	int get_P_Number();

	void SetName(char* n);//set func
	void SetAddress(char* a);
	void Set_R_Number(int r);
	void Set_P_Number(int p);
};
PatientInfo::PatientInfo(char* name, char* address, int registration_number, int phone_number)
{
	name = new char[50];//patientInfo
	address = new char[50];
	registration_number = 0;
	phone_number = 0;
}

PatientInfo::~PatientInfo()
{

}
char* PatientInfo::getName()
{
	return name;//get name
}
char* PatientInfo::getAddress()
{
	return address;
}
int PatientInfo::get_R_Number()
{
	return registration_number;
}
int PatientInfo::get_P_Number()
{
	return phone_number;
}
void PatientInfo::SetName(char* n)
{
	name = n;
}

void PatientInfo::SetAddress(char* a)
{
	address = a;
}

void PatientInfo::Set_R_Number(int r)
{
	registration_number = r;
}

void PatientInfo::Set_P_Number(int p)
{
	phone_number = p;
}

int main()
{
	char* n = new char[50];//declare
	char* a = new char[50];
	int r = 0;
	int p = 0;
	char* n1 = new char[50];
	char* a1 = new char[50];
	int r1 = 0;
	int p1 = 0;
	char* n2 = new char[50];
	char* a2 = new char[50];
	int r2 = 0;
	int p2 = 0;
	char* n3 = new char[50];
	char* a3 = new char[50];
	int r3 = 0;
	int p3 = 0;

	PatientInfo Info = PatientInfo(n, a, r, p);//declare infos
	PatientInfo Info1 = PatientInfo(n1, a1, r1, p1);
	PatientInfo Info2 = PatientInfo(n2, a2, r2, p2);
	PatientInfo Info3 = PatientInfo(n3, a3, r3, p3);


	cout << "NAME: ";//get name
	cin >> n;
	Info.SetName(n);//set name
	cout << "Address: ";//get address
	cin >> a;
	Info.SetAddress(a);//set address
	cout << "Registration Number: ";//get R_num
	cin >> r;
	Info.Set_R_Number(r);//set R_NUM
	cout << "Phone Number: ";//get phone num
	cin >> p;
	Info.Set_P_Number(p);//set phone num
	cout << endl;

	cout << "NAME: ";
	cin >> n1;
	Info1.SetName(n1);
	cout << "Address: ";
	cin >> a1;
	Info1.SetAddress(a1);
	cout << "Registration Number: ";
	cin >> r1;
	Info1.Set_R_Number(r1);
	cout << "Phone Number: ";
	cin >> p1;
	Info1.Set_P_Number(p1);
	cout << endl;

	cout << "NAME: ";
	cin >> n2;
	Info2.SetName(n2);
	cout << "Address: ";
	cin >> a2;
	Info2.SetAddress(a2);
	cout << "Registration Number: ";
	cin >> r2;
	Info2.Set_R_Number(r2);
	cout << "Phone Number: ";
	cin >> p2;
	Info2.Set_P_Number(p2);
	cout << endl;

	cout << "NAME: ";
	cin >> n3;
	Info3.SetName(n3);
	cout << "Address: ";
	cin >> a3;
	Info3.SetAddress(a3);
	cout << "Registration Number: ";
	cin >> r3;
	Info3.Set_R_Number(r3);
	cout << "Phone Number: ";
	cin >> p3;
	Info3.Set_P_Number(p3);

	cout << endl;
	cout << Info.getName() << endl;//print name
	cout << Info.getAddress() << endl;//print address
	cout << Info.get_R_Number() << endl;//print R_num
	cout << Info.get_P_Number() << endl;//print phone num

	cout << endl;
	cout << Info1.getName() << endl;
	cout << Info1.getAddress() << endl;
	cout << Info1.get_R_Number() << endl;
	cout << Info1.get_P_Number() << endl;

	cout << endl;
	cout << Info2.getName() << endl;
	cout << Info2.getAddress() << endl;
	cout << Info2.get_R_Number() << endl;
	cout << Info2.get_P_Number() << endl;

	cout << endl;
	cout << Info3.getName() << endl;
	cout << Info3.getAddress() << endl;
	cout << Info3.get_R_Number() << endl;
	cout << Info3.get_P_Number() << endl;
	cout << endl;
	return 0;
}