//---------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <iomanip.h>
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
        ifstream in ("irkj1380.txt");
        ofstream out ("out.txt");
        // Let's try in the file irkj1380.txt output all information up to the END OF HEADER in out.txt:
        string a;
        while(true) {
                getline (in,a); //reading the first line in the file
                //out<<a<<endl;
                // 1 we give a condition that when the program sees a string with the value END OF HEADER, the program is interrupted:
                if(a == "                                                            END OF HEADER") {
                        break;
                }
        } 
        // 2 Print the following line after END OF HEADER: 
        string name;
        /*getline(in,name);// read the following line
        out<<name<<endl;// output this line*/
        // 3 Output the number of satellites:
        int temp;
        double temp2;
        in >> temp;// reading the time - 15
        in >> temp;// reading the time - 5
        in >> temp;// reading the time - 18
        in >> temp;// reading the time - 0
        in >> temp;// reading the time - 0
        in >> temp2;// reading the status of the satellite - 0.0000000
        in >> temp;// reading the status of the satellite - 1
        int countSputnik;
        in >> countSputnik; // reading the number of satellites - 19
        out<< countSputnik << endl; // output the number of satellites
        // output the names of the satellites in the line:
        getline(in,name);// we read the remaining line with the names of the satellites
        out<< name;
}
//---------------------------------------------------------------------------
