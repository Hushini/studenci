#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student 
{
public:
    string imie;
    string nazwisko;   
    string grupa;
    int album;
    int rok;

    friend ostream& operator<<(ostream& nazwa1, const Student& student) 
    {
        nazwa1 << "Imie: " << student.imie << endl;
        nazwa1 << "Nazwisko: " << student.nazwisko << endl;
        nazwa1 << "Grupa: " << student.grupa << endl;
        nazwa1 << "Nr albumu: " << student.album << endl;
        nazwa1 << "Rok: " << student.rok << endl;
        return nazwa1;
    }

    friend istream& operator>>(istream& nazwa2, Student& student) 
    {
        nazwa2 >> student.nazwisko;
        nazwa2 >> student.imie;
        nazwa2 >> student.album;
        nazwa2 >> student.grupa;
        nazwa2 >> student.rok;
        return nazwa2;
    }
};

int main() 
{
    vector<Student> lista;

    ofstream plikof("studenci.txt");
    if (plikof.is_open()) 
    {
        plikof << "Hubert Weber 114 wh53911 1" << endl;
        plikof << "Pamela Andrzejewska 115 ap45346 3" << endl;
        plikof << "Izabela Sikorska 114 si56843 2" << endl;
        plikof << "Marcelina Mazurek 112 mm26564 3" << endl;
        plikof << "Konrad Sikorski 113 sk34678 " << endl;
        plikof << "Milan Tomaszewski 112 tm12854 1" << endl;
        plikof << "Hubert Sobczak 111 sh13585 1" << endl;
        plikof.close();
    }

    ifstream plikif("studenci.txt");
    if (plikif.is_open()) 
    {
        Student student;
        while (plikif >> student) 
        {
            lista.push_back(student);
        }
        plikif.close();
    }

    cout << "Wszyscy studenci:" << endl;
    for_each(lista.begin(), lista.end(), [](const Student& student) 
        {
        cout << student << endl;
        });

    int liczbaStudentow3Roku = count_if(lista.begin(), lista.end(), [](const Student& student) 
        {
        return student.rok == 3;
        });
    cout << "Liczba studentow 3 roku: " << liczbaStudentow3Roku << endl;

    return 0;
}