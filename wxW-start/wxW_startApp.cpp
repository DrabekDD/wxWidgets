#include "wxW_startApp.h"
#include "wxW_startMain.h"

const wxString appName = "Pierwszy program wxWidgets";
// globalna nazwa aplikacji używana jako tytuł okna
// wxString; potrafi poprawnie liczyć znak, używa UTF8, implementuje Unicod, jest portable

wxIMPLEMENT_APP(MyApp);
// NAJWAżNIEJSZA LINIA W CAŁYM PROJEKCIE - generuje main, tworzy obiekt MyApp, czyli "odpala wxWidgets"
// MUSI WYSTĄPIĆ DOKŁADNIE JEDEN RAZ W CAŁYM PROJEKCIE

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(appName);
    frame->Show(true);
    return true;
}
// Tu jest implementacja OnInit();
// To jest punkt startowy GUI czyli taki odpowiednik int main() w konsoli
// Teraz tworzy się główne okno i zostanie ono pokazane - Show(true)
// zwraca true → aplikacja działa, false → program się NIE uruchomił.

