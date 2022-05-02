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
        // 4 output the names of the satellites in the line:
        getline(in,name);// we read the remaining line with the names of the satellites
        //out<< name << endl;
        /*12// 5 we need to make sure that the string G01G04G11G12G14G18G22G24G25G31G32R05 is read by letters, that is, we create a dynamic array with a pointer: 
        string *Sputnik = new string [countSputnik];
        // this is a loop that runs through the name variable, in which you need to pull out the names of the satellites:
        for(int i=0; i<countSputnik; i++){
                Sputnik[i] = "";
        }
        //reading the first line:*/
        /* 12 we have deduced all pseudodalities for each satellite, but only for the first epoch (time is 0:0). 
        To calculate for each epoch, let's redo the program using vectors. 
        First, let's also try to count and output the names of the satellites for the first epoch:*/
        vector <string> allSputnik; // massive vector with satellite names
        int index=-1;
        // 12:
        string tempName = "";
        for(int i=0; i<name.size(); i++) {
                if(name[i] == '-')
                        break;// If there is a "-" in the line with the names of the satellites, then abort the operation
                if(name[i] >= 'A' && name[i] <= 'Z') {
                        index++;
                        //out << name[i] << endl;//this condition gives out only the letters of the satellites
                        // 12:
                        if(tempName != "") {
                                allSputnik.push_back(tempName);
                                tempName="";
                        }
                }
                // 6 Let's add a condition so that the names of satellites with numbers can be read in full
                if (name[i] !=' ') {
                        // Sputnik[index] = Sputnik[index] + name[i]; // the condition checks that there are no spaces in our string
                        // 12:
                        tempName = tempName + name[i];
                }
                //out<< name[i] << endl;
        }
        // 7 Output the second line
        //index - where the array is written to:
        if(index != countSputnik-1) {
                getline(in,name);//считываем вторую строку
                //out<< name << endl;//выводим резлуьтат
                // 8 Print the letters of the satellites in the column:
                //moving along the second line:
                for(int i=0; i<name.size(); i++){//name - line
                        if(name[i] >= 'A' && name[i] <= 'Z') {
                                index++;
                                //out << name[i] << endl;//we output only letters
                                // 12:
                                if(tempName != "") {
                                        allSputnik.push_back(tempName);
                                        tempName="";
                                }
                        }
                        // 9 print by letters and numbers. if we see a space, then the operation should not be performed:
                        // removing spaces:
                        if (name[i] !=' '){
                                //Sputnik[index] = Sputnik[index] + name[i];
                                //out << name[i] << endl;// output all characters in the string except spaces
                                //12: 
                                tempName = tempName + name[i];
                        }
                }
        }
        // 10 output all satellites in a column:
        for(int i=0; i<countSputnik; i++){
                //out << Sputnik[i] << endl;
                // 12
                out << allSputnik[i] << endl;
        }
        /*delete [] Sputnik;
        // 11 It is necessary to output pseudodalities for one/the first epoch (time - 0:0)It is necessary to output pseudodalities for one/the first epoch (time - 0:0)
        double *information = new double [countSputnik];
        for(int i=0; i<countSputnik; i++){
                in >> information[i];// reads all the information in one epoch (counts only 3 lines, since 19 satellites are specified in the condition, the program perceived here as separate information (pseudodalities, frequency signals, etc.), but not by satellite names)
                getline (in,name);// here it reads only the first information, and then goes to a new line
                getline (in,name);// this is a line to go to a new line, that is, reads through one line
        }
        for(int i=0; i<countSputnik; i++){
                out << information[i] << endl;
        }*/
}
//---------------------------------------------------------------------------
