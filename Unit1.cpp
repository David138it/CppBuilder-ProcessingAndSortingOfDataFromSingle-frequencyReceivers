//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <iomanip.h>
#include <cmath>
#include <vcl.h>>
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
        ifstream in ("sirfrin1.txt");
        ofstream out ("output.txt");
////////   пропуск END OF HEADER
        string a;
        while(true) {
                getline (in,a);
                if(a == "                                                            END OF HEADER") {
                                break;
                }
        }
//////// дано
        string name; // обычная строка
        int temp; // число
        double temp2; // число с точкой
        int countSputnik; // количество спутников
        vector <vector <double> > info; // создаем массив
        vector <double> tempVector;
        tempVector.resize(15); // размер массива
        vector <string> Sputnik; // создаем элемент со спутником
        vector <string> allSputnik; // создаем элемент со всеми спутниками
        int index=-1; // начальные значения
        string tempName = ""; // строка названий спутников
//////// пропуск времени и состояния
        for(int i=0; i<4797; i++) {  // сколько всего эпох
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp2;
                in >> temp;
                in >> countSputnik;
                // out << countSputnik << endl; // количество спутников
//////////////// считываем до конца
                getline(in,name);
                // out << name; // названия спутников
//////////////// считываем названия спутников
                allSputnik.resize(0);
                index=-1;
                tempName = "";
                for(int i=0; i< name.size(); i++) {
                        if(name[i] == '-') // если встречаем -
                        break; // то прерываем
                        if(name[i] >= 'A' && name[i] <= 'Z') { // если встречаем букву
                                index++; // то добавляем индекс
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
                //tempName="";
//////////////// выводим все называния спутников первой строки
                /* for(int i=0; i<allSputnik.size(); i++){
                        out << allSputnik[i] << endl;
                } */
//////////////// 2ая строка названий спутников
                /*if(index <= countSputnik-1) {  //проверяем записсаны ли имена всех сутников
                        //getline(in,name); // считываем строку до конца
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
                /* for(int i=0; i<allSputnik.size(); i++){
                        out << allSputnik[i] << endl; // выводим все называния спутников с первой и второй строки
                } */
/////////////// считываем расстояния спутников
                info.push_back(tempVector);
                for(int i = 0; i<allSputnik.size(); i++) {
                        double dalnost=0;
                        string b = "";
                        getline (in, b);
                        a ="";
                        if(b.size()>=14){
                                a=b.substr(2,12); // выбираем нужное нам расстояние
                        }
                        // out << a << endl; // выводим расстояния спутников
/////////////////////// пронумеруем каждый элемент и вырежем для того чтобы определить пустые ячейки
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
/////////////////////// считываем спутники и связываем с расстояниями
                        // getline (in,name); //считываем до конца через строку
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
//////// выводим спутникими на консоле
        // out << endl;
        for(int j=0; j<Sputnik.size(); j++) {
                out << setw(13) << Sputnik[j] << " ";
        }
        out << endl;
/////// выводим расстояния на консоле
        for(int i=0; i<info.size(); i++) {
                for(int j=0; j<info[i].size(); j++) {
                        out << setw(13)  << setprecision(13) << info[i][j] << " ";
                }
                out << endl;
        }
}

//---------------------------------------------------------------------------

