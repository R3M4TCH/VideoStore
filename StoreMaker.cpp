#include "Video.h"
#include "Store.h"
#include "VHS.h"
#include "DVD.h"
#include "BD.h"
#include <iostream>
using namespace std;

int main(){

  Store bustBlocker(0);
  cout << "We've opened BustBlocker!" << endl;
  //cout << bustBlocker << endl;
  bustBlocker.addDVD("Interception", 2009);
  bustBlocker.addDVD("Angry Maxwell", 2015);
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

  return(0);
}
