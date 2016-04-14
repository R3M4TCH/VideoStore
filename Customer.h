#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "Video.h"
#include <iostream>
#include <string>
using namespace std;

class Customer{
  
 public:
  Customer(string name){
    m_name = name;
  }
  string getName(){
    return(m_name);
  }
  bool rentVideo(Video * rental, int day){
    if(m_numRented >=3 ){
      return(false);
    }
    
    for(int i=0; i<m_numRented; i++){
      if(m_rentedVideos[i] == rental){
	return(false);
      }
    }
    rental->rent(day);
    m_rentedVideos.push_back(rental);
    
    return(true);
    
  }
  
  bool returnVideo(Video * rental){
    if(m_numRented==0){
      return(false);
    }
    
  }

 private:
  //vector of rented videos
  vector<Video*> m_rentedVideos;
  int m_numRented;
  string m_name;

};

#endif
