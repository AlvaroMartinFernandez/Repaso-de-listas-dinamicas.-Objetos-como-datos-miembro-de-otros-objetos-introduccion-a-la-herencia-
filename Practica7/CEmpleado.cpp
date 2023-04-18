#include "CEmpleado.h"
#include"Utils.h"
using namespace std;
using namespace Utils;

CEmpleado::CEmpleado(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato, const string& sCategoria, int nAntiguedad) :
	CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato), m_sCategoria{ sCategoria }, m_nAntiguedad{ nAntiguedad }
{
	cout << "Llamada al constructor del Objeto Empleado." << endl;

}
void CEmpleado::Visualizar()
{
	cout << "Nombre: " << ObtenerNombre() << endl << "Edad: " << ObtenerEdad() << endl << "Categoria: " << GetCategoria()<< endl << "Antiguedad: "<< GetAntiguedad()<< endl;
	CHora aux = ObtenerNacio();
	CUtils::VisualizarHora(aux);
}
CFicha* CEmpleado::Clonar() {
	return new CEmpleado(*this);
}