#ifndef BULLET_H
#define BULLET_H

//Bullet �u�Y
class Bullet
{
    float m_fLv;                                     float m_fX;
    float m_fSx;    long  m_lT;      float m_fDu;    float m_fY;
    float m_fSy;    float m_fDuv;    float m_fDv;    float m_fZ;

    CString m_strLv;                                            CString m_strX;
    CString m_strSx;    CString m_strT;     CString m_strDu;    CString m_strY;
    CString m_strSy;    CString m_strDuv;   CString m_strDv;    CString m_strZ;

	CTime 	m_LastModifyTime;
public:
    Bullet();
    Bullet(const Bullet&);
    virtual ~Bullet();

    BOOL SetLv(CString);
    BOOL SetSx(CString);
    BOOL SetSy(CString);
    
    BOOL SetT(CString);
    BOOL SetDuv(CString);
    
    BOOL SetDu(CString Du);
    BOOL SetDv(CString Dv);
    
    BOOL SetX(CString X);
    BOOL SetY(CString Y);
    BOOL SetZ(CString Z);
    
    float GetLv()  const; CString GetStrLv()  const;  BOOL SetLv(float);
    float GetSx()  const; CString GetStrSx()  const;  BOOL SetSx(float);
    float GetSy()  const; CString GetStrSy()  const;  BOOL SetSy(float);

    long  GetT()   const; CString GetStrT()   const;  BOOL SetT(long);
    float GetDuv() const; CString GetStrDuv() const;  BOOL SetDuv(float);

    float GetDu()  const; CString GetStrDu()  const;  BOOL SetDu(float);
    float GetDv()  const; CString GetStrDv()  const;  BOOL SetDv(float);

    float GetX()   const; CString GetStrX()   const;  BOOL SetX(float);
    float GetY()   const; CString GetStrY()   const;  BOOL SetY(float);
    float GetZ()   const; CString GetStrZ()   const;  BOOL SetZ(float);

    virtual void    operator= (const Bullet&);

    BOOL isEmpty() const;
	CString GetLastTime() const;

    //////////////////////////////////////////////////////////////////////////
    //debug function
#ifdef _DEBUG
    CString MsgBoxStr() const;
#endif
};

#endif