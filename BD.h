#ifndef _BD_H
#define _BD_H
#include "Video.h"

class BD: public Video{

 public:
  BD(string title, int year, bool newRelease = true, string actor1 = "", string actor2 = "")
    : Video(title, year, newRelease, actor1, actor2){


  }


 private:


};

#endif
