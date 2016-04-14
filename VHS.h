#ifndef _VHS_H
#define _VHS_H
#include "Video.h"

class VHS: public Video{

 public:
  VHS(string title, int year, bool newRelease = false, string actor1 = "", string actor2 = "")
    : Video(title, year, newRelease, actor1, actor2){


  }


 private:


};

#endif
