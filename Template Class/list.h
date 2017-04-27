#ifndef	LIST_H
#define	LIST_H
template<typename E> class List
{
private:
void operator =(const List&) {} 
List(const List&) {} 
public:
List() {}
virtual ~List() {} 
virtual void clear() = 0;
virtual int numFree() = 0;
virtual void append(const E& item) = 0;
virtual bool moveToStart() = 0;
virtual void prepend(const E& item) = 0;
virtual bool moveToEnd() = 0;
virtual bool next() = 0;
virtual bool prev() = 0;
virtual const E* getValue() const = 0;
virtual int numActive() = 0;
};
#endif
