#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>




using namespace std;

vector<string> displayAll(string );
vector<string> searchRecords(string, string);

vector<string> recordLine(string stuFirstName, string stuLastName, string studentID, 
    string semester, string courses1, double grade1, string courses2, double grade2, 
    string courses3, double grade3, string courses4, double grade4, string courses5, 
    double grade5, string courses6, double grade6, double GPA );


int main(){

//stuFirstName, string stuLastName, string studentID, string semester, string courses1, double grade1, string courses2, double grade2, string courses3, double grade3, string courses4, double grade4, string courses5, double grade5, string courses6, double grade6, string GPA
       
    //displayAll("data.csv"); //Display all student records
    string file_name = "data.csv", studentID = "1001074405";

    //cout << "Searching for: " << file_name << ' ' << studentID <<   endl;

    searchRecords(file_name, studentID);

    return 0;
}

vector<string> searchRecords(string file_name, string searchTerm){ 
    //search term, what value they will look for

        vector<string> record;
        ifstream file; //input file stream

        file.open(file_name);
        string singleField;

        bool found_record = false;

        vector<string> fields;
        //discard the first line
        getline(file, singleField);
        singleField = "";
        while (!found_record )
        {
            
            
            while (getline(file, singleField, ','))
            {
                fields.push_back(singleField);
                cout << "PUSHED THIS INTO VECTOR >>>>>" << singleField << endl;
                
            }
            getline(file, singleField, '\n');
            fields.push_back(singleField); //will fill up a vector with row information

            cout << endl;
            cout << "Looking for " << fields[0] << endl;
            if (fields[0] == searchTerm)
            {
                cout << "FOUND MATCH!!!" << endl;
                for (size_t i = 0; i < fields.size(); i++)
                {
                    cout << fields[i];
                }
                
                
                found_record = true;
            }
            
                


           
        }
            
        
        
    return record;
}


vector<string> displayAll(string file_name){

        vector<string> record;
        ifstream file;
        file.open(file_name); //enter data file name
        int fieldCount = 0;
        string test;


        while (getline(file,test,',') && file.good() )
        {
            
            fieldCount++;
            if(fieldCount < 16){
                cout << test << ", ";
            } else {
                cout << ",\n";
                fieldCount = 0;
            }
        }
        file.close();
        



        return record;

    }
