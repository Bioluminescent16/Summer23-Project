#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstring>
#include <unordered_set>
#include <utility>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

struct Person {
  string medicalRecordNumber;
  string diseaseSite;
  string histType;

};

const int MAX_PEOPLE = 5711; // Maximum number of people to read from the CSV file
int readCSV(const string& filename, Person people[]) {
  ifstream file(filename);
  string line;
  int count = 0;
  while(getline(file, line) && count < MAX_PEOPLE) {
    istringstream iss(line);
    
    string medicalRecordNumber;
    string diseaseSite;
    string histType;
    
      // Read name, birthdate, and age from each line of the CSV
    if(getline(iss, medicalRecordNumber, ',') && getline(iss, diseaseSite, ',') && getline(iss, histType, ',')) {
        people[count] = {medicalRecordNumber, diseaseSite, histType};
        count++;
    }
  }
  return count;
}

int main() {
    Person people[MAX_PEOPLE];
    int numPeople = readCSV("btr2022.csv", people);
    /*for(int i = 0; i < numPeople; i++) {
      cout << "(Person " << i+1 << ")" << " Year: " << people[i].year << " Medical Record Number: " << people[i].medicalRecordNumber << " Birthdate: " << people[i].birthDate << " Last Name: " << people[i].lastName << " Sex: " << people[i].sex << " Address: " << people[i].address << " County: " << people[i].county << " Date of First Contact: " << people[i].dateFirstContact << " Class of Case: " << people[i].classOfCase << " Site: " << people[i].site << " Classic Site Group: " << people[i].classicSiteGroup << " Disease Site: " << people[i].diseaseSite << " Disease Grouping: " << people[i].diseaseGrouping << " Hist Type: " << people[i].histType << " Hist Text: " << people[i].histText << " Laterality: " << people[i].laterality << " Date of Diagnosis: " << people[i].dateOfDiagnosis << endl;
      cout << endl;

    }

  //unordered_set<string> mrnDuplicates;
  //unordered_set<string> histTypeDuplicates;
  //unordered_set<int> theDups;
  //unordered_map<string, string> mrnAndHistType;
  //pair<string, string> mrnAndHistType[numPeople]; */
  ofstream fout("BapDuplicates2022.txt");
  fout << "Medical Record Number - Disease Site - Histology Type " << endl;
  int dup = 0;
  /*cout << numPeople << endl;

  typedef pair<string, string> mrnHistPair;
  vector<mrnHistPair> mrnHistPairs;*/
  unordered_set<string> uniquePairs;

  for(int i = 0; i < numPeople; i++){
    if(people[i].medicalRecordNumber == "Unknown" || people[i].medicalRecordNumber == "UNKNOWN"){
      continue;
    }
    string combinedData = people[i].medicalRecordNumber + people[i].histType;
    if(uniquePairs.find(combinedData) == uniquePairs.end()){
      uniquePairs.insert(combinedData);
        }
    else{
      fout << people[i].medicalRecordNumber << " - " << people[i].diseaseSite << " - " << people[i].histType << endl;
      dup++;
      }
    }
  
  if(dup != 0) {
      fout << "There are " << dup << " duplicates";
  }
  else{
      fout << "No duplicates found" << endl;
    }
  /*for(const auto& pair : mrnHistPairs){
      string combinedData = pair.first + pair.second;
      if(uniquePairs.find(combinedData) != uniquePairs.end()){
          cout << "Duplicate found: " << pair.first << " - " << pair.second << endl;
          dup++;
        } 
      else{
          uniquePairs.insert(combinedData);
      }
    }
  
  
  
    

  for(int i = 0; i < numPeople; i++){
    
    
  
if(mrnDuplicates.find(people[i].medicalRecordNumber) == mrnDuplicates.end()){
    cout << "Person " << i << endl;
    cout << "Medical Record Num: " << people[i].medicalRecordNumber << endl;
    cout << "Histology Type: " << people[i].histType << endl;
    //cout << "Histology Text: " << people[i].histText << endl;
    cout << endl;             mrnDuplicates.insert(people[i].medicalRecordNumber); 
//histTypeDuplicates.insert(people[i].histType);   
      }
else if(histTypeDuplicates.find(people[i].histType) == histTypeDuplicates.end()){
  cout << "Person " << i << endl;
  cout << "Medical Record Num: " << people[i].medicalRecordNumber << endl;
  cout << "Histology Type: " << people[i].histType << endl;
  //cout << "Histology Text: " << people[i].histText << endl;
  cout << endl;                 
  histTypeDuplicates.insert(people[i].histType);
}
  
    else if(people[i].diseaseSite == "Breast" || people[i].diseaseGrouping == "LUNG/BRONCHUS-NON SM CELL"){
      if(people[i].laterality == "1 (RIGHT)" || people[i].laterality == "2 (LEFT)"){
      cout << "Person " << i+1 << endl;
      cout << "Histology Type: " << people[i].histType << endl;
      //cout << "Histology Text: " << people[i].histText << endl;
      cout << endl;
      }
    }
    else{
      theDups.insert(i);
      dup++;
      }
    }
  cout << "There are " << dup << " duplicates" << endl;
  for(auto const &i: theDups){
      cout << i << " ";
    }*/
  
    
  return 0;
}
