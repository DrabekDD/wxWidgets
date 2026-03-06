#ifndef _GLOBAL_KBD_EVENT_H_
#define _GLOBAL_KBD_EVENT_H_

#include <wx/wx.h>

class GlobalKeyEvtHandler : public wxEvtHandler
{
public:
    GlobalKeyEvtHandler();
    virtual ~GlobalKeyEvtHandler();

    static void Register(wxWindow* w);
    static void Unregister(wxWindow* w);

private:
    void OnChar(wxKeyEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnKeyUp(wxKeyEvent& event);
};

GlobalKeyEvtHandler::GlobalKeyEvtHandler()
{
    Bind(wxEVT_CHAR,     &GlobalKeyEvtHandler::OnChar, this);
    Bind(wxEVT_KEY_DOWN, &GlobalKeyEvtHandler::OnKeyDown, this);
    Bind(wxEVT_KEY_UP,   &GlobalKeyEvtHandler::OnKeyUp, this);
}

GlobalKeyEvtHandler::~GlobalKeyEvtHandler()
{
    Unbind(wxEVT_CHAR,     &GlobalKeyEvtHandler::OnChar, this);
    Unbind(wxEVT_KEY_DOWN, &GlobalKeyEvtHandler::OnKeyDown, this);
    Unbind(wxEVT_KEY_UP,   &GlobalKeyEvtHandler::OnKeyUp, this);
}

void GlobalKeyEvtHandler::OnChar(wxKeyEvent& event)
{
    event.ResumePropagation(1);
    event.Skip();
}

void GlobalKeyEvtHandler::OnKeyDown(wxKeyEvent& event)
{
    event.ResumePropagation(1);
    event.Skip();
}

void GlobalKeyEvtHandler::OnKeyUp(wxKeyEvent& event)
{
    event.ResumePropagation(1);
    event.Skip();
}

void GlobalKeyEvtHandler::Register(wxWindow* w)
{
    if (!w) return;

    // także na samym oknie
    w->PushEventHandler(new GlobalKeyEvtHandler());

    // i na wszystkich dzieciach
    wxWindowListNode* childNode = w->GetChildren().GetFirst();
    while (childNode)
    {
        childNode->GetData()->PushEventHandler(new GlobalKeyEvtHandler());
        childNode = childNode->GetNext();
    }
}

void GlobalKeyEvtHandler::Unregister(wxWindow* w)
{
    if (!w) return;

    // zdejmij z dzieci
    wxWindowListNode* childNode = w->GetChildren().GetFirst();
    while (childNode)
    {
        childNode->GetData()->PopEventHandler(true);
        childNode = childNode->GetNext();
    }

    // zdejmij z samego okna
    w->PopEventHandler(true);
}

#endif
