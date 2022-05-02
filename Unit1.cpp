//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        ifstream in ("igr18451.txt");
        ofstream out ("output.txt");
        string lishniaiaStroka;
        for (int i=0; i<22; i++)
        {
                getline (in,lishniaiaStroka);
        }
        string epoha;
        getline(in,epoha);
        string sputnik;
        string signali;
        string e;
        string x;
        string y;
        string z;
        vector <string> infa;
        for (int j=0; j<96; j++){
                infa.resize(32);
                for (int i=0; i<infa.size(); i++){
                        in >> sputnik >> x >> y >> z;
                        getline (in, signali);
                        if(sputnik == "PG01") {
                                /*out << sputnik << " " << x << " " << y << " " << z << " " << endl;*/
                                out << x << endl;
                /*out << y << endl;
                out << z << endl;*/
                        }
                }
                getline (in, e);
        }
}
//---------------------------------------------------------------------------