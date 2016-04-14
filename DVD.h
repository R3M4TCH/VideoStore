#ifndef _DVD_H
#define _DVD_H
#include "Video.h"

class DVD: public Video{

 public:
  DVD(string title, int year, bool newRelease = true, string actor1 = "", string ac\
tor2 = "")
    : Video(title, year, newRelease, actor1, actor2){
    
  
  }
  
  
 private:


};

#endif
