#include <iostream>
#include "Station.h"
using namespace std;

template <class T>
class List{
	public:
		List();
		~List();
 node<T> * front;
 node<T> * back;

 	bool isEmpty();
 	void insertFirst(T data);
 	void insertBack(T data);
 	void insertBefore(node<T> * before, T data);
 	void insertAfter(node<T> * after, T data);
 	int removeFirst();
 	int removeLast();
 	int removeBefore(node<T>* before);
 	int removeAfter(node<T> * after);
 	void destroy();
 	node<T>* find(T data);
 	void insertRangeBefore(node<T>* before, List<T> range);
 	void insertRangeAfter(node<T>* after, List<T> range);
  	void removeRange(node<T>* rangeFirst, node<T>* rangeLast);
  	List<T> getSublist(node<T>* rangeFirst, node<T>* rangeLast);

};
template <class T>
		bool List<T>::isEmpty(){
        return front == NULL;
    	}
template <class T>
		void List<T>::insertFirst(T data){

        node<T> * p = NULL;

        p.data = data;
        p.next = front;
        front.prev = p;
        p.prev = NULL;
        front = p;
    }
    template <class T>
		void List<T>::insertBack(T data){

        node<T> * p = NULL;

        p.data = data;
        p.prev = back;
        p.next = NULL;
        back.next = p;
        back = p;
    };
    template <class T>
  void List<T>::insertBefore(node<T> * before, T data){
      node<T> * p = NULL, * t = NULL;
      t = before.prev;
      p.data = data;
      p.next = before;
      p.prev = t;
      t.next = p;
      before.prev = p;
  };
  template <class T>
  void List<T>::insertAfter(node<T> * after, T data){
      node<T> * p = NULL, * t = NULL;
      t = after.next;
      p.data = data;
      p.next = t;
      p.prev = after;
      after.next = p;
      t.prev = p;

  };
  template <class T>
  int List<T>::removeFirst(){
    if(front != NULL){
			node<T> * p = front;
      front = front.next;
      front.prev = NULL;
			delete p;

        return 1;
    }
    else
        return 0;
  };
  template <class T>
  int List<T>::removeLast(){
    if(back != NULL){
			node<T> * p = back;
	    back = back.prev;
	    back.next = NULL;
			delete p;

    return 1;
      }
      else
          return 0;
  };
  template <class T>
  int List<T>::removeBefore(node<T>* before){
    if (before != NULL) {
      node<T> * p = before.prev;
      before.prev = p.prev;
      p.prev.next = before;
			delete p;

      return 1;
    }
    else
        return 0 ;
  };
  template <class T>
  int List<T>::removeAfter(node<T> * after){
    if (after != NULL) {
      node<T> * p = after.next;
      after.next = p.next;
      p.next.prev = after;
			delete p;
      return 1;
    }
    else
        return 0;

  };
  template <class T>
  node<T>* List<T>::find(T data){
			node<T> * p = NULL;
			p = front;
			while(p != NULL){
				if (p.data == data) {
					return p;
				}
				p = p.next;
			}
			return NULL;

	};
	template <class T>
  void List<T>::destroy(){
			node<T> * p = NULL;

			while (front != NULL) {
				p = front;
				front = front.next;
				delete p;
			}
	};
	template <class T>
  void List<T>::insertRangeBefore(node<T>* before, List<T> range){

	};
	template <class T>
  void List<T>::insertRangeAfter(node<T>* after, List<T> range){

  };
  template <class T>
  void List<T>::removeRange(node<T>* rangeFirst, node<T>* rangeLast){

  };
template <class T>
	List<T> List<T>::getSublist(node<T>* rangeFirst, node<T>* rangeLast){
		List<T> p = NULL;
		p.front = rangeFirst;
		p.back = rangeLast;

		return p;
	};
