#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "Video.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Customer{
  
 public:
  Customer(string name){
    m_name = name;
    m_numRented = 0;
  }
  string getName(){
    return(m_name);
  }
  bool rentVideo(Video * rental, int day){
    //can't rent more than 3 videos
    if(m_numRented >=3 ){
      return(false);
    }
    
    //can't rent a video you already have
    for(int i=0; i<m_numRented; i++){
      if(m_rentedVideos[i] == rental){
	return(false);
      }
    }
    
    //rent the video
    rental->rent(day);
    m_rentedVideos.push_back(rental);
    m_numRented++;
    return(true);
    
  }
  
  bool returnVideos(){
    if(m_numRented==0){
      return(false);
    }
    for(int i=0; i<m_numRented; i++){
      (m_rentedVideos[m_numRented-i-1])->returnVideo();
      m_rentedVideos.pop_back();
    }
    m_numRented = 0;
    return(true);
    
  }

  double getDues(int day){
    double dues = 0.00;
    for(int i = 0; i<m_numRented; i++){
      if((m_rentedVideos[i])->isOverdue(day)){
	dues+=3.00;
      }
    }
    
    return(dues);
  }

 private:
  //vector of rented videos
  vector<Video*> m_rentedVideos;
  int m_numRented;
  string m_name;

};

#endif
