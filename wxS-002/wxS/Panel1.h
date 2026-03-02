#ifndef PANEL1_H
#define PANEL1_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(Panel1)
	#include <wx/panel.h>
	//*)
#endif
//(*Headers(Panel1)
//*)

class Panel1: public wxPanel
{
	public:

		Panel1(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Panel1();

		//(*Declarations(Panel1)
		//*)

	protected:

		//(*Identifiers(Panel1)
		//*)

	private:

		//(*Handlers(Panel1)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
