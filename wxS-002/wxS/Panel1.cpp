#include "wx_pch.h"
#include "Panel1.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(Panel1)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(Panel1)
//*)

//(*IdInit(Panel1)
//*)

BEGIN_EVENT_TABLE(Panel1,wxPanel)
	//(*EventTable(Panel1)
	//*)
END_EVENT_TABLE()

Panel1::Panel1(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(Panel1)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

Panel1::~Panel1()
{
	//(*Destroy(Panel1)
	//*)
}

