#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <iterator>

enum ValueKind{VluK_Lv, VluK_Sx, VluK_Sy, VluK_T, VluK_Duv, VluK_Du, VluK_Dv, VluK_X, VluK_Y, VluK_Z, VluK_Total};

//Bullet �u�Y
class Bullet
{
//�ظѺc�l
public:
    Bullet();
    Bullet(const Bullet&);
    ~Bullet();

//����x�s��
private:
    std::vector<float> m_vfValues;
public:
      const float oFlt(const ValueKind&) const;
    const CString oStr(const ValueKind&) const;
             void i(const ValueKind&, const float&);
             void i(const ValueKind&, const CString&);
//�̫��s�ɶ�
private:
            CTime m_LastModifyTime;
public:
    const CString GetLastTime() const;

//�Ū���P�O
private:
	BOOL isEmptyObj;
public:
	const BOOL IsEmpty() const;


//float, String�ഫ
private:
      const float str2flt(CString ) const;
    const CString flt2str(const float& ) const;
//�B��l
public:
             void operator= (const Bullet&);
    const CString ShowDataReport() const;
	const CString ShowData() const;
};

#endif