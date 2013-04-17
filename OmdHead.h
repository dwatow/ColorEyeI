#ifndef OMDHEAD_H
#define OMDHEAD_H

#include "DNA.h"

class OmdHead
{
	CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
	CString m_Inch;
	CString m_nitsBkClr;
	DNA     m_omdDNA;

public:
	CString   oPnlID () const { return m_PnlID;     };
    CString   oMsrDvc() const { return m_MsrDvc;    };
    CString   oPrb   () const { return m_Prb;       };
    CString   oCHID  () const { return m_CHID;      };
    CString   oInch  () const { return m_Inch;      };
	CString   oNitsLv() const { return m_nitsBkClr; };
	const DNA oDNA()    const { return m_omdDNA;    };
	
    void iPnlID  (const CString& _S) { m_PnlID     = _S;	m_PnlID.TrimRight();     };
    void iMsrDvc (const CString& _S) { m_MsrDvc    = _S; 	m_MsrDvc.TrimRight();    };
    void iPrb    (const CString& _S) { m_Prb       = _S; 	m_Prb.TrimRight();       };
    void iCHID   (const CString& _S) { m_CHID      = _S; 	m_CHID.TrimRight();      };
    void iInch   (const CString& _S) { m_Inch      = _S; 	m_Inch.TrimRight();      };
	void iNitsLv (const CString& _S) { m_nitsBkClr = _S; 	m_nitsBkClr.TrimRight(); };
	void iDNA    (const     DNA& _D) { m_omdDNA    = _D;                             };

	void Empty()
	{
		m_PnlID.Empty();
		m_MsrDvc.Empty();
		m_Prb.Empty();
		m_CHID.Empty();
		m_Inch.Empty();
		m_nitsBkClr.Empty();
		m_omdDNA.Empty();
	};
};
#endif