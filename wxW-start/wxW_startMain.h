#pragma once
#include <wx/wx.h>
// każdy plik nagłówkowy ma być niezależny

class MyFrame : public wxFrame
{
public:
    explicit MyFrame(const wxString& title);
};
// wxFrame = normalne okno systemowe - pasek tytułu, przyciski, ramka, ... ... (dziedziczone public)
// wymusza podanie tytułu
// Tu nie ma kodu, tylko interfejs klasy.
