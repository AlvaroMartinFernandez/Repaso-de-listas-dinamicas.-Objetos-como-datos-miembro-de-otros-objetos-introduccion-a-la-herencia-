#include "CCliente.h"
#include"Utils.h"
using namespace std;
using namespace Utils;

CCliente::CCliente(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato, const string& sDNI) :
	CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato), m_sDNI{ sDNI }
{
	cout << "Llamada al constructor del Objeto CLiente." << endl;
}
void CCliente::Visualizar()
{
	cout << "Nombre: " << ObtenerNombre() << endl << "Edad: " << ObtenerEdad() << endl << "DNI: " << GetDNI() << endl;
	CHora aux = ObtenerNacio();
	CUtils::VisualizarHora(aux);
}
CFicha* CCliente::Clonar() {
	return new CCliente(*this);
}