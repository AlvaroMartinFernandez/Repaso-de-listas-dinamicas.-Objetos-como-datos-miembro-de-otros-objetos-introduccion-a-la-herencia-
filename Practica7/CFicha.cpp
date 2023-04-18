#include "CHora.h"
#include"Utils.h"
#include"CFicha.h"
using namespace std;
using namespace Utils;
	CFicha::CFicha(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato):m_sNombre{ sNombre }, m_nEdad{ nEdad },
	m_horaNacio(nHoras, nMinutos, nSegundos, sFormato)
	{
		//cout << "Llamada al constructor del Objeto Ficha." << endl;
		bool aux = m_horaNacio.EsHoraCorrecta();
		if (aux == false)
		{
			cout << "Formato de hora incorrecto creamos objeto predeterminado." << endl;
			CHora aux(12, 0, 0, "AM");
			m_horaNacio = aux;
		}
	}
	void CFicha::AsignarNombre(const string&  sNombre)
	{
		m_sNombre = sNombre;
		return;
	}
	string CFicha::ObtenerNombre()const
	{
		return m_sNombre;
	}
	void CFicha::AsignarEdad(int nEdad)
	{
		m_nEdad = nEdad;
		return;
	}
	int CFicha::ObtenerEdad() const
	{
		return m_nEdad;
	}
	bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string& nFormato)
	{
		bool aux=m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, nFormato);
		
		if (aux == false)
		{
			cout << "Formato de hora incorrecto creamos objeto predeterminado." << endl;
			CHora obj(12, 0, 0, "AM");
			m_horaNacio = obj;
		}
		return true;
	}
	CHora CFicha::ObtenerNacio() const
	{
		return m_horaNacio;
	}
	void CFicha::Visualizar()
	{
		cout << "Nombre: " << ObtenerNombre() << endl << "Edad: " << ObtenerEdad() << endl;
		CHora aux = ObtenerNacio();
		CUtils::VisualizarHora(aux);
	}