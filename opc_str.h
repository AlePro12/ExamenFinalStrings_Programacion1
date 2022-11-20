#include <iostream>

using namespace std;

StrHndl Controlador;

void AddWord()
{
    Utils::HeaderBonito("Agregar Palabra");
    Utils::Print("PALABRAS: " + Controlador.Words);
    string word = Utils::ObtenerInputUsuario_string("Palabra a agregar");
    Controlador.AddWord(word);
    Utils::Print("Palabra agregada");
}
void EditWord()
{
    Utils::HeaderBonito("Editar Palabra");
    Utils::Print("PALABRAS: " + Controlador.Words);
    string word = Utils::ObtenerInputUsuario_string("Palabra a editar");
    Controlador.EditWord(word);
    Utils::Print("Palabra editada");
}
void AddText()
{
    Utils::HeaderBonito("Agregar Texto");
    Utils::Print("TEXTO: " + Controlador.Texto);
    string text = Utils::ObtenerInputUsuario_string("Texto a agregar");
    Controlador.AddText(text);
    Utils::Print("Texto agregado");
}
void EditText()
{
    Utils::HeaderBonito("Editar Texto");
    Utils::Print("TEXTO: " + Controlador.Texto);
    string text = Utils::ObtenerInputUsuario_string("Texto a editar");
    Controlador.EditText(text);
    Utils::Print("Texto editado");
}
void Stats()
{
    Controlador.PrintStats();
}