#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

#ifndef HEADER_H
#define HEADER_H

using namespace std;

class StrHndl
{
public:
    string Words = "";
    string Texto = "";

    // Metodos para el manejo de las palabras ingresadas
    void AddWord(string word)
    {
        Words += word + " ";
    }
    void EditWord(string toReplace)
    {
        // edita la palabra que coincida con el parametro
        int index = Words.find(toReplace);
        if (index != -1)
        {
            Words.replace(index, toReplace.length(), Utils::ObtenerInputUsuario_string("Nueva Palabra"));
        }
        else
        {
            Utils::Print("Palabra no encontrada");
        }
    }
    void PrintWords()
    {
        cout << Words << endl;
    }
    // Texto search
    void TextoWord(string word)
    {
        Texto = word;
    }
    void PrintTexto()
    {
        cout << Texto << endl;
    }
    // Metodos para el manejo del texto
    void AddText(string text)
    {
        Texto += text;
    }
    void EditText(string toReplace)
    {
        int index = Texto.find(toReplace);
        if (index != -1)
        {
            Texto.replace(index, toReplace.length(), Utils::ObtenerInputUsuario_string("Nueva Texto de busqueda"));
        }
        else
        {
            Utils::Print("Palabra no encontrada");
        }
    }
    vector<string> Split(string str, string separator)
    {
        vector<string> arr;
        int pos = 0;
        string token;
        while ((pos = str.find(separator)) != string::npos)
        {
            token = str.substr(0, pos);
            arr.push_back(token);
            str.erase(0, pos + separator.length());
        }
        arr.push_back(str);
        return arr;
    }
    // estadistica
    void CantidadVecesAparecioPalabra()
    {
        vector<string> WordsArray = Split(Words, " ");
        string WordsContadas[100];
        for (size_t i = 0; i < WordsArray.size(); i++)
        {
            string palabra = WordsArray[i];
            int concidencias = Utils::StringsInArray_Vector(palabra, WordsArray);
            if (!Utils::StringsInArray(palabra, WordsContadas, 100))
            {
                WordsContadas[i] = palabra;
                Utils::Print("La palabra " + palabra + " aparecio " + Utils::IntAString(concidencias) + " de veces");
            }
        }
    }
    void CantidadDePalabrasTexto()
    {
        // b.Cantidad de palabras agregada en el texto.
        Utils::Print("Cantidad de palabras agregada en el texto");
        int count = 0;
        for (int i = 0; i < Texto.length(); i++)
        {
            if (Texto[i] == ' ')
            {
                count++;
            }
        }
        Utils::Print("Cantidad de palabras: " + to_string(count + 1));
    }
    void CantidadDeCaracteresTexto()
    {
        // c.Cantidad de caracteres agregada en el texto.
        Utils::Print("Cantidad de caracteres agregada en el texto");
        Utils::Print("Cantidad de caracteres: " + to_string(Texto.length()));
    }
    void PrintStats()
    {
        Utils::HeaderBonito("Estadisticas");
        Utils::Print("Oracion: " + Words);
        Utils::Print("Texto: " + Texto);
        CantidadVecesAparecioPalabra();
        CantidadDePalabrasTexto();
        CantidadDeCaracteresTexto();
    }
};
#endif