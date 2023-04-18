#ifndef CREGISTRO_H
#define CREGISTRO_H

#include <iostream>
#include <vector>
#include "CEmpleado.h"
#include "CCliente.h"

class CRegistroDiario {
private:
   vector<CFicha*> personas;
public:
    CRegistroDiario();
    CRegistroDiario(int i);
    CRegistroDiario(const CRegistroDiario& Persona);
    CRegistroDiario& operator=(const CRegistroDiario& Persona);
    bool AgregarPersona(CFicha* p);
    void VisualizarRegistro();
    static bool EsEmpleado(CFicha* Ficha);
    void VisualizarEmpleados();
    CFicha& operator[](int i) const;
    void BuscarNombre(const string& name);
    ~CRegistroDiario();
    int NumPersonas();
};

#endif