#include "AutoPtr.h"


template <typename T>
AutoPtr<T>::AutoPtr():ptr(0),ref_cnt(0)
{
	//create a ref_cnt here though we don't have any object to point to
	ref_cnt)++;
}

template <typename T>
AutoPtr<T>::AutoPtr(T* p):ptr(p){
	//we create a reference counter in heap
	ref_cnt++;
}

template <typename T>
AutoPtr<T>::~AutoPtr()
{
	//delete only if our ref count is 0
	--ref_cnt;
	if(ref_cnt == 0)
		delete ptr;
}

template <typename T>
T&  AutoPtr<T>::operator*()
{
	return *ptr;
}

template <typename T>
T* AutoPtr<T>::operator->()
{
	return ptr;
}

template <typename T>
AutoPtr<T>::AutoPtr(const AutoPtr<T>& sp):ptr(sp.ptr),ref_cnt(sp.ref_cnt)
{
	ref_cnt++;
}

template <typename T>
AutoPtr<T>& AutoPtr<T>::operator=(const AutoPtr<T>& sp)
{
	if(&sp != this)
	{
		//we shouldn't forget to handle the ref_cnt our AutoPtr previously pointed to
		--ref_cnt;
		if(ref_cnt == 0)
		{
			delete ref_cnt;
			delete ptr;
		}
		//copy the ptr and ref_cnt and increment the ref_cnt
		ptr = sp.ptr;
		ref_cnt = sp. ref_cnt;
		ref_cnt++;
	}
	return *this;
}