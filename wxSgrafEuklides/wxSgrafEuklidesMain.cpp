/***************************************************************
 * Name:      wxSgrafEuklidesMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-04-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSgrafEuklidesMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxSgrafEuklidesFrame)
#include <wx/font.h>
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

//(*IdInit(wxSgrafEuklidesFrame)
const long wxSgrafEuklidesFrame::ID_STATICTEXT1 = wxNewId();
const long wxSgrafEuklidesFrame::ID_STATICTEXT2 = wxNewId();
const long wxSgrafEuklidesFrame::ID_STATICTEXT3 = wxNewId();
const long wxSgrafEuklidesFrame::ID_TEXM = wxNewId();
const long wxSgrafEuklidesFrame::ID_STATICTEXT4 = wxNewId();
const long wxSgrafEuklidesFrame::ID_TEXTN = wxNewId();
const long wxSgrafEuklidesFrame::ID_BTNNWD = wxNewId();
const long wxSgrafEuklidesFrame::ID_TEXEUK = wxNewId();
const long wxSgrafEuklidesFrame::ID_LBLNWD = wxNewId();
const long wxSgrafEuklidesFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxSgrafEuklidesFrame,wxFrame)
    //(*EventTable(wxSgrafEuklidesFrame)
    //*)
END_EVENT_TABLE()

wxSgrafEuklidesFrame::wxSgrafEuklidesFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxSgrafEuklidesFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,545));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Algorytm Euklidesa - graficznie"), wxDefaultPosition, wxSize(397,38), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(13,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sawasdee"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 0, wxALL, 25);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("    Podaj liczy, ktorych NWD chcesz policzyc"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(StaticText2, 0, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("    m: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer2->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    txtM = new wxTextCtrl(Panel1, ID_TEXM, _("10946"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXM"));
    BoxSizer2->Add(txtM, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(29,2,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("n: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer2->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    txtN = new wxTextCtrl(Panel1, ID_TEXTN, _("6765"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTN"));
    BoxSizer2->Add(txtN, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_LEFT, 5);
    bntNWD = new wxButton(Panel1, ID_BTNNWD, _("Oblicz NWD"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNNWD"));
    BoxSizer1->Add(bntNWD, 0, wxLEFT|wxALIGN_LEFT, 25);
    txtEuk = new wxTextCtrl(Panel1, ID_TEXEUK, wxEmptyString, wxDefaultPosition, wxSize(390,245), wxTE_MULTILINE|wxTE_READONLY|wxTE_RIGHT|wxWANTS_CHARS|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_TEXEUK"));
    BoxSizer1->Add(txtEuk, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 25);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    lblNWD = new wxStaticText(Panel1, ID_LBLNWD, _("NWD = 1"), wxDefaultPosition, wxSize(378,19), wxALIGN_CENTRE, _T("ID_LBLNWD"));
    BoxSizer3->Add(lblNWD, 0, wxTOP|wxBOTTOM|wxEXPAND, 15);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND, 2);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);

    Connect(ID_BTNNWD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxSgrafEuklidesFrame::OnbntNWDClick);
    //*)
}

wxSgrafEuklidesFrame::~wxSgrafEuklidesFrame()
{
    //(*Destroy(wxSgrafEuklidesFrame)
    //*)
}

void wxSgrafEuklidesFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxSgrafEuklidesFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxSgrafEuklidesFrame::OnbntNWDClick(wxCommandEvent& event)
{
    long a, b;
    if (!txtM->GetValue().ToLong(&a) || !txtN->GetValue().ToLong(&b)) {
        wxMessageBox("Podaj poprawne liczby!", "Błąd", wxOK | wxICON_ERROR);
        return;
    }
    txtEuk->Clear();

    long x = a;  //Algorytm Euklidesa
    long y = b;
    wxString linia;
    long r;
    while (y != 0){
        r = x % y;
        linia = wxString::Format("%ld = %ld * %ld + %ld", x, y, x / y, r);
        txtEuk->AppendText(linia + "    \n");
        x = y;
        y = r;
    }

    lblNWD->SetLabel("NWD = " + wxString::Format("%ld", x)+"    NWW = "+wxString::Format("%ld", a/x*b));


}
