#ifndef AUTOPTR_H
#define AUTOPTR_H
//
//AutoPtr.h : our simple smart pointer
//refreance: http://blog.csdn.net/ruizeng88/article/details/6691191
//
template <typename T>
class AutoPtr
{
	T* ptr;
	int ref_cnt;

public:
	AutoPtr();
	AutoPtr(T* p);
	AutoPtr(const AutoPtr<T>& sp);
	AutoPtr<T>& operator=(const AutoPtr<T>& sp);
	~AutoPtr();

//operator
	T& operator*();
	T* operator->();
};
#endif
