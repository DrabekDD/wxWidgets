#pragma once
#include <wx/wx.h>

/* kasujemy sztywne parametry konstruktora - konstruktor przyjmuje wszystkie argumenty jak wxFrame.
class MyFrame : public wxFrame
{
public:
    explicit MyFrame(const wxString& title);
};
*/
class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent,
            wxWindowID id,
            const wxString& title,
            const wxPoint& pos,
            const wxSize& size,
            long style);
};
