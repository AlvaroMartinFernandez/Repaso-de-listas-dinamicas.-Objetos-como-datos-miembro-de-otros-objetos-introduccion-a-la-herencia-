#ifndef UTILS_H
#define UTILS_H
#include <cstdio>
#include <string>
#include<cstdlib>
#include "CHora.h"
#include"CFicha.h"
using namespace std;
namespace Utils {
	class CUtils {
	public:
		static void CrearMenu(const char* opcionesmenu[], int num_opciones);
		static void VisualizarHora(const CHora& hora);
		static void VisualizarFicha(const CFicha& Ficha);
		static string& ConverMayus(string& str);
		static bool LeerDato(int& dato);
		static bool LeerDato(float& dato);
		static bool LeerDato(string& dato);
		static void Pause();
	};
}
#endif