#ifndef CCLIENTE_H
#define CCLIENTE_H
#include<cstdio>
#include<iostream>
#include"CFicha.h"
using namespace std;

class CCliente:public CFicha
{
private:
	string m_sDNI;
public:
	CCliente(const string& sNombre = " ", int nEdad = 0, int nHoras = 12, int nMinutos = 0, int nSegundos = 0, const string& sFormato = "AM", const string& sDNI = "");
	~CCliente() { cout << "Destructor CCliente" << endl; };
	void SetDNI(const string& sDNI) { m_sDNI = sDNI; }
	string GetDNI() { return m_sDNI; }
	void Visualizar();
	CFicha* Clonar();
};
#endif