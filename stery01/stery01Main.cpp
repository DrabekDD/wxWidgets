/***************************************************************
 * Name:      stery01Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "stery01Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(stery01Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(stery01Frame)
const long stery01Frame::ID_LISTCTRL2 = wxNewId();
const long stery01Frame::ID_LISTBOX1 = wxNewId();
const long stery01Frame::ID_LISTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(stery01Frame,wxFrame)
    //(*EventTable(stery01Frame)
    //*)
END_EVENT_TABLE()

stery01Frame::stery01Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(stery01Frame)
    wxGridSizer* GridSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    ListCtrl2 = new wxListCtrl(this, ID_LISTCTRL2, wxDefaultPosition, wxSize(334,107), wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL2"));
    ListCtrl2->Disable();
    GridSizer1->Add(ListCtrl2, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_BOTTOM, wxDLG_UNIT(this,wxSize(3,0)).GetWidth());
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(200,131), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    ListBox1->Append(_("raz"));
    ListBox1->Append(_("dwa"));
    ListBox1->Append(_("trzy"));
    GridSizer1->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL1"));
    GridSizer1->Add(ListCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridSizer1);
    GridSizer1->Fit(this);
    GridSizer1->SetSizeHints(this);

    Connect(ID_LISTCTRL2,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&stery01Frame::OnListCtrl2BeginDrag);
    //*)
}

stery01Frame::~stery01Frame()
{
    //(*Destroy(stery01Frame)
    //*)
}

void stery01Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void stery01Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void stery01Frame::OnListCtrl2BeginDrag(wxListEvent& event)
{
}
