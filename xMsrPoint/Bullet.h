#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <iterator>

enum ValueKind{VluK_Lv, VluK_Sx, VluK_Sy, VluK_T, VluK_Duv, VluK_Du, VluK_Dv, VluK_X, VluK_Y, VluK_Z, VluK_Total};

//Bullet ºu¿Y
class Bullet
{
private:
	std::vector<float> m_vfValues;
public:
	float oFlt(ValueKind) const;
	CString oStr(ValueKind) const;
	void i(ValueKind, float);
	void i(ValueKind, CString);


private:
	CTime 	m_LastModifyTime;
public:
	CString GetLastTime() const;

public:
    Bullet();
    Bullet(const Bullet&);
    virtual ~Bullet();
    BOOL isEmpty() const;
    virtual void    operator= (const Bullet&);
	CString Bullet::show() const;

private:
	float str2flt(CString ) const;
	CString flt2str(float ) const;
};

#endif