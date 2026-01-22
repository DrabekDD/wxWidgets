#pragma once
#include <wx/wx.h>

/*
class MyFrame : public wxFrame
{
public:
    explicit MyFrame(const wxString& title);
};
*/

// tylko deklaracja klasy MyFrame (okna), bez definicji i metod
class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style);
};
