/***************************************************************
 * Name:      wwxSMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-04
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wwxSMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wwxSFrame)
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

//(*IdInit(wwxSFrame)
const long wwxSFrame::ID_SHOW_DATE = wxNewId();
const long wwxSFrame::ID_SHOW_VERSION = wxNewId();
const long wwxSFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wwxSFrame,wxFrame)
    //(*EventTable(wwxSFrame)
    //*)
END_EVENT_TABLE()

wwxSFrame::wwxSFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wwxSFrame)
    wxMenu* mInfo;
    wxMenuBar* mb;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(685,450));
    mb = new wxMenuBar();
    mInfo = new wxMenu();
    miData = new wxMenuItem(mInfo, ID_SHOW_DATE, _("Pokaz date"), wxEmptyString, wxITEM_CHECK);
    mInfo->Append(miData);
    miWersja = new wxMenuItem(mInfo, ID_SHOW_VERSION, _("Pokaz wersje systemu"), wxEmptyString, wxITEM_NORMAL);
    mInfo->Append(miWersja);
    mb->Append(mInfo, _("&Informacje"));
    SetMenuBar(mb);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[3] = { -1, -10, -10 };
    int __wxStatusBarStyles_1[3] = { wxSB_RAISED, wxSB_RAISED, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(3,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(3,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_SHOW_DATE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wwxSFrame::OnShowDate);
    Connect(ID_SHOW_VERSION,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wwxSFrame::OnShowVersion);
    Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_MIDDLE_DOWN,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_MIDDLE_UP,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_MIDDLE_DCLICK,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_RIGHT_DOWN,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    Connect(wxEVT_RIGHT_DCLICK,(wxObjectEventFunction)&wwxSFrame::OnUseMouse);
    //*)
    //parametry paska stanu
    int myWidths[3] = {-3, -2, -2 };
    StatusBar1->SetFieldsCount(3, myWidths);
    SetStatusText(GetTitle(), 0);
    wxSize s = GetSize();
    SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 2);

    //poprawki nazw polskich
    SetTitle(wxString::FromUTF8("Użycie zdarzeń"));
    mInfo->SetLabel(ID_SHOW_DATE, wxT("Pokaż &datę\tCtrl-D"));
    mInfo->SetLabel(ID_SHOW_VERSION, wxT("Pokaż &wersję systemu\tCtrl-W"));
}

wwxSFrame::~wwxSFrame()
{
    //(*Destroy(wwxSFrame)
    //*)
}

void wwxSFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wwxSFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wwxSFrame::OnShowDate(wxCommandEvent& event)
{
  bool status = event.IsChecked();
  if(status){
    this->SetStatusText(wxDateTime::Now().FormatISODate(), 1);
  }else{
    this->SetStatusText(wxEmptyString, 1);
  }

}

void wwxSFrame::OnShowVersion(wxCommandEvent& event)
{
  wxString system_vers = wxPlatformInfo::Get().GetOperatingSystemDescription();
  wxMessageBox(system_vers, wxT("Informacja o systemie"), wxOK|wxICON_INFORMATION);
}

void wwxSFrame::OnUseMouse(wxMouseEvent& event)
{
    wxString key;
    if (event.LeftDClick())
        key = "Lewy - dwuklik";
    else if (event.LeftUp())
        key = "Lewy - klik";
    else if (event.RightUp())
        key = "Prawy - klik";
    else
    return;

    wxMessageBox(
        wxString::Format("Przycisk: %s\nPozycja: %d, %d", key, event.GetX(), event.GetY()), "Informacja");
}
