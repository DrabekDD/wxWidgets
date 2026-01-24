#include "wxW_Main.h"


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
                 const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    // automatyczne tworzenie paska w danym oknie przy użyciu metody wxFrame
    //wxStatusBar* sb = CreateStatusBar();
    // można uźyć argumentów, ale chyba to nie działa
    //wxStatusBar* sb = CreateStatusBar(2,wxSTB_DEFAULT_STYLE | wxSTB_SHOW_TIPS);

    // ręczne utworzenie paska stanu, rodzic = to okno - UWAGA!!! konieczna deklaracja wxStatusBar* sb = nullptr; w main.h
    sb = new wxStatusBar(this);

    // konfiguracja pól
    int widths[4] = { 300, -1, -2, 240 };     // 4 pola: 250px, 170px, elastyczne, 140px
    sb->SetFieldsCount(4, widths);

    // Style pól
    int st[4] = { wxSB_NORMAL, wxSB_SUNKEN, wxSB_SUNKEN, wxSB_SUNKEN };
    sb->SetStatusStyles(4, st);

    // Zmiana kolorków
    sb->SetBackgroundColour(*wxLIGHT_GREY);
    sb->SetForegroundColour(*wxWHITE);

    // przypisanie paska stanu do okna - konieczne tylko przy ręcznym tworzeniu
    this->SetStatusBar(sb);

    // Wpisujemy coś do istniejącego paska stanu

    // 1) Tytuł okna (to samo co parametr "title")
    SetStatusText(GetTitle(), 0);

    // 2) Pozycja okna na ekranie
    wxPoint p = GetPosition();
    SetStatusText(wxString::Format("Pos: %d,%d", p.x, p.y), 1);

    // 3) Rozmiar okna
    wxSize s = GetSize();
    SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 2);

    // 4) Styl okna (tu po prostu liczba)
    SetStatusText(wxString::Format("style=%ld", style), 3);

    // refresh jest zbędne dba o to SetStatusText
    // sb->Refresh();

    CenterOnScreen();
}


