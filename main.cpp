#include <iostream>
#include <string>
#include <sstream>
#include <fstream>



using namespace std;

int main(){

    ifstream dataFile;
    dataFile.open("data.csv");

    string word;
    dataFile >> word;
    cout << dataFile << endl; 




}