/***************************************************************
 * Name:      cykloMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-05-14
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "cykloMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>  //dodaj
#include <cmath>          //dodaj

//(*InternalHeaders(cykloFrame)
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

//(*IdInit(cykloFrame)
const long cykloFrame::ID_CHOICE_CYKLO = wxNewId();
const long cykloFrame::ID_PANEL = wxNewId();
const long cykloFrame::ID_TIMER_CYKLO = wxNewId();
//*)

BEGIN_EVENT_TABLE(cykloFrame,wxFrame)
    //(*EventTable(cykloFrame)
    //*)
END_EVENT_TABLE()

cykloFrame::cykloFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(cykloFrame)
    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1000,500));
    Panel = new wxPanel(this, ID_PANEL, wxPoint(264,280), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL"));
    ChoiceCyklo = new wxChoice(Panel, ID_CHOICE_CYKLO, wxPoint(32,32), wxSize(272,30), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_CYKLO"));
    ChoiceCyklo->Append(_("Cykloida"));
    ChoiceCyklo->Append(_("Cykloida skrocona"));
    ChoiceCyklo->Append(_("Epicykloida"));
    ChoiceCyklo->Append(_("Hipocykloida"));
    TimerCyklo.SetOwner(this, ID_TIMER_CYKLO);

    Connect(ID_CHOICE_CYKLO,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&cykloFrame::OnChoiceCykloSelect);
    Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&cykloFrame::OnPanelPaint,0,this);
    Connect(ID_TIMER_CYKLO,wxEVT_TIMER,(wxObjectEventFunction)&cykloFrame::OnTimerTrigger);
    //*)
    TimerCyklo.Start(1);
    ChoiceCyklo->SetSelection(wxNOT_FOUND);
}

cykloFrame::~cykloFrame()
{
    //(*Destroy(cykloFrame)
    //*)
}

void cykloFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void cykloFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void cykloFrame::DrawCyklo(wxDC& dc, int type, wxColour color)
{
    dc.SetPen(wxPen(color, 2));

    //const double PI = 3.141592653589793;
    double R = 100;
    double r = 35.5;
    double d = 45;

    int cx = 430;
    int cy = 300;

    wxPoint prev;
    bool first = true;

    for(double t = 0; t <= currentT; t += 0.01)
    {
        double x = 0, y = 0;

        switch (type)
        {
        case 0:
            x = r * (t - sin(t));
            y = r * (1 - cos(t));
            x -= 350; y -= 100;
            break;
        case 1:
            x = r * t - d * sin(t);
            y = r - d * cos(t);
            x -= 350; y += 80;
            break;
        case 2:
            x = (R + r) * cos(t) - d * cos((R + r) / r * t);
            y = (R + r) * sin(t) - d * sin((R + r) / r * t);
            break;

        case 3:
            x = (R - r) * cos(t) + d * cos((R - r) / r * t);
            y = (R - r) * sin(t) - d * sin((R - r) / r * t);
            break;
        }

        wxPoint p(cx + (int)x, cy + (int)y);

        if (!first)
            dc.DrawLine(prev, p);

        prev = p;
        first = false;
    }
}

void cykloFrame::OnPanelPaint(wxPaintEvent& event)
{
    wxPaintDC dc(Panel);

    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();

    int typ = ChoiceCyklo->GetSelection();
    if(typ != wxNOT_FOUND)
    {
    DrawCyklo(dc, typ, *wxRED);
    }

}



void cykloFrame::OnTimerTrigger(wxTimerEvent& event)
{
    int typ = ChoiceCyklo->GetSelection();
    if(typ == 0) currentT += 0.06;   // cykloida
    else if(typ == 1) currentT += 0.06;   // skrócona/wydłużona
    else if(typ == 2) currentT += 0.03;   // epicykloida
    else if(typ == 3) currentT += 0.03;   // hipocykloida

    //currentT += 1;
    if(currentT > 12 * 3.1415926535) currentT = 0;
    Panel->Refresh();
}

void cykloFrame::OnChoiceCykloSelect(wxCommandEvent& event)
{
    currentT = 0;
    TimerCyklo.Stop();
    TimerCyklo.Start(10);
    Panel->Refresh();
}
