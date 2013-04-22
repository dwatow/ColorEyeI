#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <iterator>

enum ValueKind{VluK_Lv, VluK_Sx, VluK_Sy, VluK_T, VluK_Duv, VluK_Du, VluK_Dv, VluK_X, VluK_Y, VluK_Z, VluK_Total};

//Bullet 彈頭
class Bullet
{
//建解構子
public:
    Bullet();
    Bullet(const Bullet&);
    ~Bullet();

//資料儲存串
private:
    std::vector<float> m_vfValues;
public:
      const float oFlt(const ValueKind&) const;
    const CString oStr(const ValueKind&) const;
             void i(const ValueKind&, const float&);
             void i(const ValueKind&, const CString&);
//最後更新時間
private:
            CTime m_LastModifyTime;
public:
    const CString GetLastTime() const;

//空物件判別
private:
	BOOL isEmptyObj;
public:
	const BOOL IsEmpty() const;


//float, String轉換
private:
      const float str2flt(CString ) const;
    const CString flt2str(const float& ) const;
//運算子
public:
             void operator= (const Bullet&);
    const CString ShowDataReport() const;
	const CString ShowData() const;
};

#endif