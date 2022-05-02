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
        using namespace std;
        ifstream in ("irkj1380.txt");
        ofstream out ("output.txt");
        string a;
        while(true) {
                getline (in,a);
                if(a == "                                                            END OF HEADER") {
                        break;
                }
        }
        string name;
        int temp;
        double temp2;
        int countSputnik;
        vector <vector <double> > info;
        vector <double> tempVector;
        // 17: 
        //tempVector.resize(100);
        tempVector.resize(55);
        vector <string> Sputnik;
        vector <string> allSputnik;
        int index=-1;
        string tempName = "";
        //15 4 epochs (time 0:00-1:30):
        //for(int i=0; i<4; i++){
        //16 Let's try to output satellite data for all epochs. Just adjust the cycle:
        for(int i=0; i<; i++){        
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp2;
                in >> temp;
                in >> countSputnik;
                out << countSputnik << endl;
                getline(in,name);
                allSputnik.resize(0);
                index=-1;
                tempName = "";
                for(int i=0; i< name.size(); i++) {
                        if(name[i] == '-')
                                break;
                        if(name[i] >= 'A' && name[i] <= 'Z') {
                                index++;
                                if(tempName != "") {
                                        allSputnik.push_back(tempName);
                                        tempName="";
                                }
                        }
                        if (name[i] != ' '){
                                tempName = tempName + name[i];
                        }
                }
                if(tempName != "") {
                        allSputnik.push_back(tempName);
                        tempName="";
                }
                tempName="";
                if(index <= countSputnik-1) {
                        getline(in,name);
                        for(int i=0; i<name.size(); i++){
                                if(name[i] >= 'A' && name[i] <= 'Z') {
                                        index++;
                                        if(tempName != "") {
                                                allSputnik.push_back(tempName);
                                                tempName="";
                                        }
                                }
                                if (name[i] != ' '){
                                        tempName = tempName + name[i];
                                }
                        }
                }
                if(tempName != "") {
                        allSputnik.push_back(tempName);
                        tempName="";
                }
                info.push_back(tempVector);
                for(int i = 0; i<allSputnik.size(); i++) {
                        /*double dalnost;
                        in >>  dalnost;
                        in >>  dalnost;
                        getline (in,name);*/
                        // 17 Let's try to output satellite data for all epochs. Just adjust the cycle:
                        double dalnost=0;
                        string b = "";
                        getline (in, b);//we read all the lines where there is data on the pseudo-distances of our satellites in all epochs
                        a ="";
                        if(b.size()>=30){
                                a=b.substr(17,13);//we select exactly the data that we need. In our case, we read the data of the second column. In the future, we will need this column to solve the main task. but our task so far is simply to output all the satellites and sort the pseudo-modality data for it
                        }
                        int tochka=-1;
                        int chislo=0;
                        for (int i=0; i<a.size(); i++){
                                if (a[i]>='0' && a[i]<='9'){
                                        dalnost = dalnost *10 + (a[i]-'0');
                                }
                                else {
                                        if(a[i]== '.') {
                                                tochka=i;
                                        }
                                }
                        }
                        if(tochka != -1){
                                chislo = a.size()-1 - tochka;
                                chislo = (int) pow(10, (double)chislo);
                                dalnost=dalnost/chislo;
                        }
                        getline (in,name);
                        index=-1;
                        for(int j=0; j<Sputnik.size(); j++) {
                                if(allSputnik[i] == Sputnik[j]) {
                                        index = j;
                                        break;
                                }
                        }
                        if(index == -1) {
                                Sputnik.push_back(allSputnik[i]);
                                info[info.size()-1][Sputnik.size()-1] = dalnost;
                        }
                        else {
                                info[info.size()-1][index] = dalnost;
                        }
                }
        }
        out << endl;
        for(int j=0; j<Sputnik.size(); j++) {
                out << setw(13) << Sputnik[j] << " ";
        }
        /*out << endl;
        for(int i=0; i<info.size(); i++) {
                for(int j=0; j<info[i].size(); j++) {
                        out << setw(13) << setprecision(13) << info[i][j] << " ";
                }
                out << endl;
        }
        17 we will display data for two satellites on the screen:*/
        out << endl;
        for(int i=0; i<info.size(); i++){
                out << setw(13) << setprecision(13) << info[i][0] << setw(14) << info[i][1] << endl;//считываем данные двух спутников
        }
}
//---------------------------------------------------------------------------
