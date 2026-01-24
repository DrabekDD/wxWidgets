#pragma once
// ten plik nagłówkowy wczytaj tylko raz
#include <wx/wx.h>
// wciąga całą bazę wxWidgets - daje dostęp do wxApp, wxString, ... ...

class MyApp : public wxApp
// Nie piszemy jak aplikacja ma działać — tylko dziedziczymy to po wxWidgets i to wxWidgets steruje "życiem aplikacji" (odpiednik czarnego okna w consoli)
// wszystko publiczne w wxApp dziedziczy MyApp i pozostaje to publiczne
{
public:
    //virtual bool OnInit(); w klasie bazowej jest virtual
    bool OnInit() override;
};
// deklaracja: później będzie zdefiniowane OnInit();
