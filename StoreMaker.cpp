#include "Video.h"
#include "Store.h"
#include "VHS.h"
#include "DVD.h"
#include "BD.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(){

  ifstream myfile;
  myfile.open("input.txt");
  /**myfile << "Angry_Maxwell 2015\n";
  myfile << "Interception 2009\n";
  myfile << "Atlantic_Swim 2013\n";
  myfile << "Plane_of_Yesterday 2014\n";
  **/
  
  string inputs;
  //myfile >> inputs;
  myfile >> inputs;
  //cout << inputs;
  vector<string> names;
  vector<int> years;
  int count = 0;
  while(inputs != ""){
    if(count%2 == 0){
      names.push_back(inputs);
    }else if(inputs == names[count/2]){
      names.pop_back();
      years.pop_back();
      years.pop_back();
      inputs = "";
    }else{
      int adder;
      istringstream buffer(inputs);
      buffer >> adder;
      /**string* temp = &inputs;
      int* add = &(dynamic_cast<int>(*temp));
      **/
      years.push_back((adder));
      //delete(add);
      //delete(temp);
    }
    count++;
    if(inputs == ""){ 
      count--;
      //cout << names;
    }else{
      myfile >> inputs;
    }
  }

  
  Store bustBlocker(0);

  cout << count << "inputs: " << inputs<< endl;
  for(int i = 0 ; i < count/2; i++){
    switch(i%3){
    case 0: bustBlocker.addDVD(names[i], years[i]);
      break;
    case 1: bustBlocker.addBD(names[i], years[i]);
      break;
    case 2: bustBlocker.addVHS(names[i], years[i]);
    }
    //cout << years[i] << endl;
  }
  
  //  Store bustBlocker(0);
  cout << "We've opened BustBlocker!" << endl;
  //cout << bustBlocker << endl;
  //bustBlocker.addDVD("Interception", 2009);
  //bustBlocker.addDVD("Angry Maxwell", 2015);
  cout << "Inception has been released" << endl;
  cout << bustBlocker;
  //cout << "Moving on... ";
  bustBlocker.addCustomer("Jim");
  Video * aSwim = new BD("Atlantic Swim", 2013);
  bustBlocker.addVideo(aSwim);
  cout << "Jim has walked into BustBlocker on day " << bustBlocker.m_currentDay << "!" << endl;
  if(bustBlocker.rentVid("Interception", 2009, "Jim"))
    cout << "Jim rented Interception!" << endl;
  else
    cout << "Jim could not rent Interception :(" << endl;

  if(bustBlocker.rentVid("Atlantic Swim", 2013, "Jim"))
    cout << "Jim rented Atlantic Swim!" << endl;
  else
    cout << "Jim could not rent Atlantic Swim :(" << endl;
  
  cout << bustBlocker << endl;  
  
  bustBlocker.changeDay(15);
  
  //cout << aSwim->getDayRented() <<endl;
  if(aSwim->isOverdue(bustBlocker.m_currentDay))
    cout << "Atlantic Swim is overdue! Oh no!" << endl;
  cout << bustBlocker << endl;
  bustBlocker.printAccounts();
  bustBlocker.changeDay(2);

  //bustBlocker.addBD("Plane of Yesterday", 2014);
  bustBlocker.returnVideos("Jim");
  cout << "Jim payed his debt." << endl;

  cout << bustBlocker << endl;
  bustBlocker.printAccounts();

  return(0);
}
