#ifndef CEMPLEADO_H
#define CEMPLEADO_H
#include<cstdio>
#include<iostream>
#include"CFicha.h"
using namespace std;

class CEmpleado:public CFicha
{
private:
	string m_sCategoria;
	int m_nAntiguedad;
public:
	CEmpleado(const string& sNombre = " ", int nEdad = 0, int nHoras = 12, int nMinutos = 0, int nSegundos = 0, const string& sFormato = "AM", const string& sCategoria = "", int nAntiguedad = 0);
	~CEmpleado() { cout << "Destructor CEmpleado" << endl; }
	void SetCategoria(const string& sCategoria){m_sCategoria = sCategoria;}
	void SetAntiguedad(int nAntiguedad) { m_nAntiguedad = nAntiguedad; }
	string GetCategoria() { return m_sCategoria; }
	int GetAntiguedad() { return m_nAntiguedad; }
	void Visualizar();
	CFicha* Clonar();
	
};
#endif
