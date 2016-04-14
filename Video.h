#ifndef _VIDEO_H
#define _VIDEO_H



class Video {
 public:
  Video(string title, int year, boool newRelease, string actor1 = "", string actor2 = "");
  
  
  



 private:
  String m_title;
  int    m_year;
  String m_actor1;
  String m_actor2;
  bool   m_newRelease;

};


#endif // protection
