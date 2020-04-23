#include "windowMain.h"

windowMain::windowMain() :
    btnN0("0"), btnN1("1"), btnN2("2"), btnN3("3"),
    btnN4("4"), btnN5("5"), btnN6("6"), btnN7("7"),
    btnN8("8"), btnN9("9"), btnPlus("+"), btnLess("-"),
    btnMult("*"), btnDiv("/"), btnIqual("="), btnC("C"),
    btnCA("CA"),
    boxText(Gtk::ORIENTATION_VERTICAL)
{
    // Características básicas de la ventana
        set_title("CPW Calc");
        set_default_size(200, 100);
        set_border_width(10);
        set_resizable(false);

    // Configuramos los Widgets
        txtCalcs.set_max_length(20);
        txtCalcs.set_text("0");
        txtCalcs.set_can_default();
        txtCalcs.grab_default();
    // Empaquetamos
        boxText.pack_start(txtCalcs);
        add(boxMain);
        boxMain.pack_start(boxText);
        boxMain.pack_start(btnN0);
        //boxMain.pack_end(boxButtons);
        //boxButtons.pack_start(btnN0, Gtk::PACK_SHRINK, 0);
        //boxButtons.pack_start(btnN1);
        //boxButtons.pack_start(btnN2);


        show_all_children();
}

windowMain::~windowMain()
{
    //dtor
}
