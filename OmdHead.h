#ifndef OMDHEAD_H
#define OMDHEAD_H

class OmdHead
{
	CString m_PnlID;
    CString m_MsrDvc;
    CString m_Prb;
    CString m_CHID;
	CString m_Inch;
	CString m_nitsBkClr;

public:
	CString oPnlID () { return m_PnlID;  };
    CString oMsrDvc() { return m_MsrDvc; };
    CString oPrb   () { return m_Prb;    };
    CString oCHID  () { return m_CHID;   };
    CString oInch  () { return m_Inch;   };
	CString oNitsLv() { return m_nitsBkClr; };
	
    void iPnlID  (const CString& _S) { m_PnlID     = _S;	/*m_PnlID.TrimRight();*/     };
    void iMsrDvc (const CString& _S) { m_MsrDvc    = _S; 	/*m_MsrDvc.TrimRight();*/    };
    void iPrb    (const CString& _S) { m_Prb       = _S; 	/*m_Prb.TrimRight();*/       };
    void iCHID   (const CString& _S) { m_CHID      = _S; 	/*m_CHID.TrimRight();*/      };
    void iInch   (const CString& _S) { m_Inch      = _S; 	/*m_Inch.TrimRight();*/      };
	void iNitsLv (const CString& _S) { m_nitsBkClr = _S; 	/*m_nitsBkClr.TrimRight();*/ };

	void Empty()
	{
		m_PnlID.Empty();
		m_MsrDvc.Empty();
		m_Prb.Empty();
		m_CHID.Empty();
		m_Inch.Empty();
		m_nitsBkClr.Empty();
	};
};
#endif