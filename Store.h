#ifndef _STORE_H
#define _STORE_H
#include <vector>
#include "Customer.h"
#include "Video.h"
#include "DVD.h"
#include "VHS.h"
#include "BD.h"
#include <iostream>
using namespace std;

class Store{

 public:
  
  int m_currentDay;
  
  Store(int cD = 0){
    
    m_currentDay = cD;
    m_numVideos = 0;
    m_numCustomers = 0;
  
  }

  //print new releases
  //print videos out
  friend ostream& operator<<(ostream& os, Store & s){
    vector<Video*> temp = (s.getVideos());
    os << "This store, as of day " << s.m_currentDay << " of operation, has the following videos:" << endl; 
    for(int i = 0; i < s.getStock(); i++){
      os << *(temp[i]);
      if((temp[i])->isRented()){
	os << "(Rented";
	if((temp[i])->isOverdue(s.m_currentDay)){
	  os << ", overdue";
	  }
	os << ")";
      }
      os << endl;
    }
    return(os);
  }
  
  vector<Video*> getVideos(){
    return(m_videos);
  }
  
  int getStock(){
    return(m_numVideos);
  }

  //print BD?
  //print DVD?
  //print VHS?

  bool addDVD(string title, int year, bool newRelease = true, string actor1 = "", string actor2 = ""){ 
    
    for(int i=0; i<m_numVideos; i++){
      if(m_videos[i]->getYear() == year && m_videos[i]->getName() == title){
	return(false);

      }
    }

    Video * vidToAdd = new DVD(title, year, newRelease, actor1, actor2);
    m_videos.push_back(vidToAdd);
    m_numVideos++;
    return(true);
  }

  bool addVideo(Video * vidToAdd){
    m_videos.push_back(vidToAdd);
    m_numVideos++;
    return(true);
  }

  //bool addVideo(string title, int year, bool newRelease = true, string actor1 = "", string actor2 = "");
  //bool addVideo(Video vidToADD);

  bool addBD(string title, int year, bool newRelease = true, string actor1 = "\
", string actor2 = ""){
    for(int i=0; i<m_numVideos; i++){
      if(m_videos[i]->getYear() == year && m_videos[i]->getName() == title){
        return(false);

      }
    }

    Video * vidToAdd = new BD(title, year, newRelease, actor1, actor2);
    m_videos.push_back(vidToAdd);
    m_numVideos++;
    return(true);
  }


  bool addCustomer(string name){
    for(int i=0; i < m_numCustomers; i++){
      if(name == m_customers[i].getName()){
	return(false);
      }
    }
    
    Customer custToAdd(name);
    m_customers.push_back(custToAdd);
    m_numCustomers++;
    return(true);
  }
  
  bool returnVideos(string custName){

      Customer * cust = NULL;
      for(int i=0; i<m_numCustomers; i++){
	if(m_customers[i].getName() == custName){
	  cust = &(m_customers[i]);
	}
      }

      if(cust == NULL){
	return(false);
      }

      return(cust->returnVideos());
      //return(true);


  }
  
  
  //bool rentVid(Video vid);
  bool rentVid(string name, int year, string custName){
    
    Video * vid = NULL;

    for(int i=0; i<m_numVideos; i++){
      if(m_videos[i]->getName() == name && m_videos[i]->getYear() == year && m_videos[i]->isRented() == false){
	vid = m_videos[i];
      }
    }

    if(vid == NULL){
      return(false);
    }
    
    Customer * cust = NULL;
    for(int i=0; i<m_numCustomers; i++){
      if(m_customers[i].getName() == custName){
	cust = &(m_customers[i]);
      }
    }
    
    if(cust == NULL){
      return(false);
    }
    
    return(cust->rentVideo(vid, m_currentDay));
    //return(true);

  }
  
  bool hasVid(string name, int year){
    for(int i=0; i<m_numVideos; i++){
      if(m_videos[i]->getName() == name && m_videos[i]->getYear() == year){
	return(true);
      }
    }
    return(false);
  
  }
  
  void printAccounts(){
    Customer * curr;
    cout << "The dues are: " << endl;
    for(int i=0;i<m_numCustomers; i++){
      curr = &(m_customers[i]);
      cout << curr->getName() << ": $" <<curr->getDues(m_currentDay) << endl;
    }
  }

  bool changeDay(int incriment = 1){
    if(incriment > 0){
      m_currentDay+=incriment;
      return(true);
    }
    return(false);
    
  }
  
  
  
 private:
  // vector of Customers
  vector<Customer> m_customers;
  int m_numCustomers;
  // vector of Videos
  vector<Video*> m_videos;
  int m_numVideos;
  //int m_currentDay;

};

#endif
