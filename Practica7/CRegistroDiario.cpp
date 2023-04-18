#include "CRegistroDiario.h"

CRegistroDiario::CRegistroDiario() {
    personas = vector<CFicha*>(0);
}
CRegistroDiario::CRegistroDiario(int i) {
    personas.reserve(100);
}
CRegistroDiario::CRegistroDiario(const CRegistroDiario& Persona) {
    personas = vector<CFicha*>(0);
    *this = Persona;
}
CRegistroDiario& CRegistroDiario::operator=(const CRegistroDiario& Persona) {
    for (int i = 0; i < personas.size(); i++) {
        delete personas[i];
        personas[i] = 0;
    }
    personas.clear();
    for (int i = 0; i < Persona.personas.size(); i++) {
        personas.push_back(Persona[i].Clonar());
    }
    return *this;
}
bool CRegistroDiario::AgregarPersona(CFicha* p) {
    personas.push_back(p->Clonar());
    return true;
}

void CRegistroDiario::VisualizarRegistro() {
    for (int i = 0; i < personas.size(); i++) {
        personas[i]->Visualizar();
        cout << endl;
    }
}
bool CRegistroDiario::EsEmpleado(CFicha* Ficha) {
    if (dynamic_cast<CEmpleado*>(Ficha))
        return true;
    return false;
}
void CRegistroDiario::VisualizarEmpleados() {
    for (int i = 0; i < personas.size(); i++) {
        if ((dynamic_cast<CEmpleado*>(personas[i]))) {
            personas[i]->Visualizar();
            cout << endl;
        }
    }
}
void CRegistroDiario::BuscarNombre(const std::string& name) {
    int aux = 0; string txt;
    unsigned int i;
    for (i = 0; i < personas.size(); i++) {
        if (personas[i]->ObtenerNombre() == name) {
            personas[i]->Visualizar();
            cout << endl;
            aux++;
        }
    }
    if (aux == 1)
        txt = " Concidencia encontrada de ";
    else
        txt = " Concidencias encontradas de ";
    cout << aux << txt << i << endl;
}
CFicha& CRegistroDiario::operator[](int i) const {
    return *personas[i];
}
CRegistroDiario::~CRegistroDiario() {
    for (unsigned int i = 0; i < personas.size(); i++) {
        delete personas[i];
        personas[i] = 0;
    }
}

int CRegistroDiario::NumPersonas() {
    return personas.size();
}