/***************************************************************
 * Name:      wykresMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-05-17
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wykresMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>    //dodaj
#include <cmath>            //dodaj

//(*InternalHeaders(wykresFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)


//(*IdInit(wykresFrame)
const long wykresFrame::ID_PANEL = wxNewId();
const long wykresFrame::ID_SIN = wxNewId();
const long wykresFrame::ID_COS = wxNewId();
const long wykresFrame::ID_TG = wxNewId();
const long wykresFrame::ID_CTG = wxNewId();
//*)

BEGIN_EVENT_TABLE(wykresFrame,wxFrame)
    //(*EventTable(wykresFrame)
    //*)
END_EVENT_TABLE()

wykresFrame::wykresFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wykresFrame)
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(1042,541));
    Panel = new wxPanel(this, ID_PANEL, wxPoint(496,304), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL"));
    MenuBar1 = new wxMenuBar();
    Menu2 = new wxMenu();
    Menu1 = new wxMenuItem(Menu2, ID_SIN, _("y = sin(x)"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(Menu1);
    MenuItem1 = new wxMenuItem(Menu2, ID_COS, _("y = cos(x)"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem1);
    MenuItem2 = new wxMenuItem(Menu2, ID_TG, _("y = tg(x)"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem3 = new wxMenuItem(Menu2, ID_CTG, _("y = ctg(x)"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuBar1->Append(Menu2, _("Funkcja"));
    SetMenuBar(MenuBar1);

    Panel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&wykresFrame::OnPanelPaint,0,this);
    Connect(ID_SIN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wykresFrame::OnSin);
    Connect(ID_COS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wykresFrame::OnCos);
    Connect(ID_TG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wykresFrame::OnTg);
    Connect(ID_CTG,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wykresFrame::OnCtg);
    //*)
    funkcja = 0;
}

wykresFrame::~wykresFrame()
{
    //(*Destroy(wykresFrame)
    //*)
}

void wykresFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}



void wykresFrame::OnPanelPaint(wxPaintEvent& event)
{
    int scale = 60;
    wxPaintDC dc(Panel);            //tworzymy obiekt do rysowania na panelu
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();

    int w, h;
    Panel->GetClientSize(&w, &h);   // pobranie aktualnego rozmiaru panelu
    int ox = w / 2;
    int oy = h / 2;

    dc.SetPen(wxPen(wxColour(220,220,220),1));                  //siatka
    for(int x = ox; x < w; x += scale) dc.DrawLine(x, 0, x, h);
    for(int x = ox; x >= 0; x -= scale) dc.DrawLine(x, 0, x, h);
    for(int y = oy; y < h; y += scale) dc.DrawLine(0, y, w, y);
    for(int y = oy; y >= 0; y -= scale) dc.DrawLine(0, y, w, y);

    dc.SetPen(wxPen(*wxBLACK,2));               // rysowaniu ukłdy współrzędnych
    dc.DrawLine(0, oy, w, oy);
    dc.DrawLine(ox, 0, ox, h);

    dc.SetPen(wxPen(*wxRED,3));
    double y = 0;
    wxPoint prev;
    bool first = true;
    for(int px = 0; px < w; px++)
    {
        double x = (px - ox) / (double)scale;   // zamiana współrzędnej ekranowej na matematyczną
        switch(funkcja){
            case 0:
                y = sin(x); break;
            case 1:
                y = cos(x); break;
            case 2:
                if(abs(cos(x)) < 0.001) {first = true; continue;}
                y = tan(x); break;
            case 3:
                if(abs(sin(x)) < 0.001) {first = true; continue;}
                y = cos(x) / sin(x); break;
        }
        int py = oy - (int)(y * scale);         // zamiana współrzędnej matematycznej na ekranową
        wxPoint p(px, py);
        if(!first) dc.DrawLine(prev, p);
        prev = p;
        first = false;
    }
    switch(funkcja){
        case 0: dc.DrawText("y = sin(x)", 20, 20); break;
        case 1: dc.DrawText("y = cos(x)", 20, 20); break;
        case 2: dc.DrawText("y = tg(x)", 20, 20); break;
        case 3: dc.DrawText("y = ctg(x)", 20, 20); break;
    }

}

void wykresFrame::OnSin(wxCommandEvent& event)
{
    funkcja = 0;
    Panel->Refresh();
}

void wykresFrame::OnCos(wxCommandEvent& event)
{
    funkcja = 1;
    Panel->Refresh();
}

void wykresFrame::OnTg(wxCommandEvent& event)
{
    funkcja = 2;
    Panel->Refresh();
}

void wykresFrame::OnCtg(wxCommandEvent& event)
{
    funkcja = 3;
    Panel->Refresh();
}



/*

dc.DrawLine(x1, y1, x2, y2);                       // rysowanie pojedynczej linii

dc.DrawLine(punkt1, punkt2);                       // rysowanie linii między punktami

dc.DrawLines(ilosc, tablicaPunktow);              // rysowanie wielu połączonych linii

dc.DrawSpline(ilosc, tablicaPunktow);             // rysowanie gładkiej krzywej spline

dc.DrawRectangle(x, y, szerokosc, wysokosc);      // rysowanie prostokąta

dc.DrawRectangle(rect);                            // rysowanie prostokąta obiektem wxRect

dc.DrawRoundedRectangle(x, y, w, h, promien);     // rysowanie zaokrąglonego prostokąta

dc.DrawCircle(x, y, promien);                      // rysowanie okręgu

dc.DrawEllipse(x, y, szerokosc, wysokosc);         // rysowanie elipsy

dc.DrawEllipticArc(x, y, w, h, kat1, kat2);       // rysowanie fragmentu elipsy

dc.DrawArc(x1, y1, x2, y2, xc, yc);               // rysowanie łuku

dc.DrawPolygon(ilosc, tablicaPunktow);            // rysowanie wielokąta

dc.DrawPoint(x, y);                                // rysowanie punktu

dc.DrawText("tekst", x, y);                        // rysowanie tekstu

dc.DrawRotatedText("tekst", x, y, kat);           // rysowanie obróconego tekstu

dc.DrawBitmap(bitmapa, x, y);                      // rysowanie bitmapy

dc.DrawIcon(ikona, x, y);                          // rysowanie ikony

dc.SetPen(wxPen(*wxRED, 3));                       // ustawienie koloru i grubości linii

dc.SetBrush(*wxBLUE_BRUSH);                        // ustawienie koloru wypełnienia

dc.SetBrush(*wxTRANSPARENT_BRUSH);                // brak wypełnienia figury

dc.SetBackground(*wxWHITE_BRUSH);                 // ustawienie koloru tła

dc.Clear();                                        // wyczyszczenie obszaru rysowania

dc.SetFont(wxFont(20,
                  wxFONTFAMILY_DEFAULT,
                  wxFONTSTYLE_NORMAL,
                  wxFONTWEIGHT_BOLD));            // ustawienie czcionki

dc.SetDeviceOrigin(x, y);                          // przesunięcie początku układu współrzędnych

dc.SetUserScale(skalaX, skalaY);                  // ustawienie skali rysowania

dc.SetClippingRegion(x, y, w, h);                 // ograniczenie obszaru rysowania

dc.DestroyClippingRegion();                        // usunięcie ograniczenia rysowania

dc.SetLogicalFunction(wxXOR);                     // ustawienie trybu XOR

dc.SetLogicalFunction(wxCOPY);                    // normalny tryb rysowania

dc.GetTextExtent("tekst");                         // pobranie rozmiaru tekstu

dc.GetSize(&w, &h);                                // pobranie rozmiaru obszaru rysowania


*/
