#ifndef _VIDEO_H
#define _VIDEO_H
#include <iostream>
#include <string>
using namespace std;


class Video {
 public:
  
  Video(string title, int year, bool newRelease = true, string actor1 = "", string actor2 = ""){
    
    m_title = title;
    m_year = year;
    m_newRelease = newRelease;
    m_actor1 = actor1;
    m_actor2 = actor2;
    m_dayRented = -1;
    
  }
  
  friend ostream& operator<<(ostream& os, const Video & vid){
    os << vid.getName() << "(" << vid.getYear() << ")";
    return os;
  }

  string getName() const{
    return(m_title);
  }
  
  int getYear() const{
    return(m_year);
  }

  bool isOverDue(int currentDay){
    if(m_dayRented == -1){
      return(false);
    }
    if(m_dayRented-currentDay >= 14){
      return(true);
    }
    return(false);
  }
  
  bool rent(int currentDay){
    if(m_dayRented == -1){
      m_dayRented = currentDay;
      return(true);
    }
    return(false);

  }

  bool returnVid(){
    if(m_dayRented == -1){
      return(false);
    }
    m_dayRented = -1;
    return true;
  }
  


 private:
  string m_title;
  int    m_year;
  string m_actor1;
  string m_actor2;
  bool   m_newRelease;
  int    m_dayRented;

};


#endif // protection
