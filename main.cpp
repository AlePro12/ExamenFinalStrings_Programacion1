#include <iostream>
#include "ApFramework.h"
#include "StringHandle.h"
#include "opc_str.h"
using namespace std;

string SearchWord(string, string);

string opc[6] = {
    "Agregar palabras",
    "Editar palabras",
    "Agregar texto",
    "Editar texto",
    "Estadísticas",
    "Salir",
};

void PrintOpc() // Dont repeat the code!
{
    for (size_t i = 0; i < 6; i++)
    {
        cout << "" << i + 1
             << " | " << opc[i] << "\n";
    }
}
int main()
{
    bool Exit = true;
    bool Confirm = false;
    int opc = 100;
    while (Exit == true)
    {
        Utils::HeaderBonito("Examen Strings Alejandro Sanchez");
        // print opcs
        PrintOpc();
        opc = Utils::ObtenerInputUsuario_int("Seleccione una opcion");
        switch (opc)
        {
        case 1:
            AddWord();
            break;
        case 2:
            EditWord();
            break;
        case 3:
            AddText();
            break;
        case 4:
            EditText();
            break;
        case 5:
            Stats();
            break;
        case 6:
            Exit = false;
            break;
        default:
            Utils::Alert("Opcion no valida: " + Utils::IntAString(opc), "string");
            break;
        }
    }
    return 0;
}