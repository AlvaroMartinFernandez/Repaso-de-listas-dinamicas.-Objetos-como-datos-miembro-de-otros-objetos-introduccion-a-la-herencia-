#include<cstdio>
#include <iostream>
#include "CRegistroDiario.h"
#include "Utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace Utils;

int main()
{
    {
        int sel = 1, ext = 1;
        CFicha* p = 0;
        CRegistroDiario Persona, * copiaPersona = 0;
        while (1) {
            do {
                if (sel < 1 || sel > 8) {
                    cout << "!!! Opcion incorrecta !!!" << endl << endl;
                    CUtils::Pause();
                }
                cout << "1. Introducir empleado." << endl
                    << "2. Introducir cliente." << endl
                    << "3. Buscar por nombre." << endl
                    << "4. Mostrar registro diario." << endl
                    << "5. Mostrar empleados." << endl
                    << "6. Copia de seguridad del registro diario." << endl
                    << "7. Restaurar copia de seguridad." << endl
                    << "8. Salir." << endl;
                CUtils::LeerDato(sel);
            } while (sel < 1 || sel > 8);
            switch (sel) {
            case 1: {
                string name = "", format = "", cat = "";
                int hh, mm, ss, ant, edad, up = 24, low = 0;
                cout << "Datos de Empleado:" << endl;
                do {
                    cout << "Nombre:\t";
                    CUtils::LeerDato(name);
                } while (name == "");
                do {
                    cout << "Categoria:\t";
                    CUtils::LeerDato(cat);
                } while (cat == "");
                do {
                    cout << "Antiguedad:\t";
                    CUtils::LeerDato(ant);
                } while (ant < 0 || ant > 100);
                do {
                    cout << "Edad:\t";
                    CUtils::LeerDato(edad);
                } while (edad < 0 || edad > 100);
                do {
                    cout << "Introduzca la Hora." << endl
                        << "Formato:\t";
                    CUtils::LeerDato(format);
                    CUtils::ConverMayus(format);
                } while (format != "AM" && format != "PM" && format != "24 HORAS");
                if (format != "24 HORAS") {
                    low = 1;
                    up = 12;
                }
                do {
                    cout << "Hora:\t";
                    CUtils::LeerDato(hh);
                } while (hh < low || hh > up);
                do {
                    cout << "Minutos:\t";
                    CUtils::LeerDato(mm);
                } while (mm < 0 || mm > 59);
                do {
                    cout << "Segundos:\t";
                    CUtils::LeerDato(ss);
                } while (ss < 0 || ss > 59);
                p = new (nothrow) CEmpleado(name, edad, hh, mm, ss, format, cat, ant);
                Persona.AgregarPersona(p);
                cout << endl;
                if (p->ObtenerNacio().EsHoraCorrecta())
                    cout << "Empleado introducido correctamente" << endl;
                if (p)
                    delete p;
                CUtils::Pause();
                break;
            }case 2: {
                string name = "", format = "", sDNI = "";
                int hh, mm, ss, edad, up = 24, low = 0;
                cout << "Datos de Cliente:" << endl;
                do {
                    cout << "Nombre:\t";
                    CUtils::LeerDato(name);
                } while (name == "");
                do {
                    cout << "DNI:\t";
                    CUtils::LeerDato(sDNI);
                } while (sDNI == "");
                do {
                    cout << "Edad:\t";
                    CUtils::LeerDato(edad);
                } while (edad < 0 || edad > 100);
                do {
                    cout << "Introduzca la Hora." << endl
                        << "Formato:\t";
                    CUtils::LeerDato(format);
                    CUtils::ConverMayus(format);
                } while (format != "AM" && format != "PM" && format != "24 HORAS");
                if (format != "24 HORAS") {
                    low = 1;
                    up = 12;
                }
                do {
                    cout << "Hora:\t";
                    CUtils::LeerDato(hh);
                } while (hh < low || hh > up);
                do {
                    cout << "Minutos:\t";
                    CUtils::LeerDato(mm);
                } while (mm < 0 || mm > 59);
                do {
                    cout << "Segundos:\t";
                    CUtils::LeerDato(ss);
                } while (ss < 0 || ss > 59);
                p = new (nothrow) CCliente(name, edad, hh, mm, ss, format, sDNI);
                Persona.AgregarPersona(p);
                cout << endl;
                if (p->ObtenerNacio().EsHoraCorrecta())
                    cout << "CLiente introducido correctamente" << endl;
                if (p)
                    delete p;
                CUtils::Pause();
                break;
            }case 3: {
                string name = "";
                do {
                    cout << "Nombre:\t";
                    CUtils::LeerDato(name);
                } while (name == "");
                cout << endl;
                Persona.BuscarNombre(name);
                CUtils::Pause();
                break;
            }case 4: {
                Persona.VisualizarRegistro();
                CUtils::Pause();
                break;
            }case 5: {
                Persona.VisualizarEmpleados();
                CUtils::Pause();
                break;
            }case 6: {
                CRegistroDiario rdNuevo(Persona);
                if (!copiaPersona) {
                    copiaPersona = new (nothrow) CRegistroDiario(Persona);
                    if (!copiaPersona)
                        exit(-1);
                    cout << " Copia realiza con exito " << endl;
                }
                else {
                    cout << " Existe ya una copia " << endl;
                }
                CUtils::Pause();
                break;
            }case 7: {
                if (copiaPersona) {
                    cout << "!! Seguro quiere restaurar la copia !!" << endl << endl;
                    copiaPersona->VisualizarRegistro();
                    string resp;
                    do {
                        cout << "(Si/No):\t";
                        CUtils::LeerDato(resp);
                        CUtils::ConverMayus(resp);
                        if (resp == "SI") {
                            Persona = *copiaPersona;
                            delete copiaPersona;
                            copiaPersona = 0;
                        }
                    } while (resp != "SI" && resp != "NO");
                }
                else {
                    cout << "!! No existe ninguna copia !!" << endl;
                }
                CUtils::Pause();
                break;
            }case 8:
                if (copiaPersona)
                    delete copiaPersona;
                ext = 0;
            }
            if (!ext)
                break;
        }
    }
    cout << endl;
MemoryManager_DumpMemoryLeaks();
    cout << endl;
    CUtils::Pause();
}
