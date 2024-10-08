#ifndef _STRINGARRAYLIST_HPP
#define _STRINGARRAYLIST_HPP

#include <string>

using namespace std;

class StringArrayList {
    private:

        int numElements;
        int maxElements;
        string *list;

    public:

      StringArrayList(int mxSz = 10);
      ~StringArrayList();
      
      void clear();
      
      int size() const;
      int maxSize() const;
      
      bool isEmpty() const;
      bool isFull() const;
      bool add(const string &s);
      bool add(const int index, const string &s);
      bool remove(const int index);
      bool get(const int index, string &s);
      bool set(const int index, const string &s);
      bool contains(const string &s);
      
      int indexOf(const string &s);
      int indexOf(int index, const string &s);
      
      string str() const;
};
#endif
