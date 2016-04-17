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
    m_ID = nextID;
    nextID++;
    
  }
  
  friend ostream& operator<<(ostream& os, const Video & vid){
    os << vid.getName() << "(" << vid.getYear() << ")";
    return os;
  }

  int getID(){
    return(m_ID);
  }

  string getName() const{
    return(m_title);
  }
  
  int getYear() const{
    return(m_year);
  }
  
  int getDayRented(){
    return(m_dayRented);
  }

  bool isOverdue(int currentDay){
    if(m_dayRented == -1){
      return(false);
    }
    if(currentDay-m_dayRented >= 14){
      return(true);
    }
    return(false);
  }
  
  bool isRented(){
    if(m_dayRented==-1){
      return(false);
    }
    return(true);
  }
  
  bool rent(int currentDay){
    if(m_dayRented == -1){
      m_dayRented = currentDay;
      //cout << m_dayRented << endl;
      return(true);
    }
    return(false);

  }

  bool returnVideo(){
    if(m_dayRented == -1){
      return(false);
    }
    m_dayRented = -1;
    return true;
  }
  


 private:
  static int nextID;
  string m_title;
  int    m_ID;
  int    m_year;
  string m_actor1;
  string m_actor2;
  bool   m_newRelease;
  int    m_dayRented;

};


#endif // protection
