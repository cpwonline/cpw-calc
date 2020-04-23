#include "windowMain.h"

windowMain::windowMain() :
    btnN0("0"), btnN1("1"), btnN2("2"), btnN3("3"),
    btnN4("4"), btnN5("5"), btnN6("6"), btnN7("7"),
    btnN8("8"), btnN9("9"), btnPlus("+"), btnLess("-"),
    btnMult("*"), btnDiv("/"), btnIqual("="), btnC("C"),
    btnCA("CA"),
    boxMain(Gtk::ORIENTATION_VERTICAL),
    boxControls(Gtk::ORIENTATION_VERTICAL),
    boxNumbers(Gtk::ORIENTATION_VERTICAL)
{
    // Window basics properties
        set_title("CPW Calc");
        set_default_size(300, 400);
        set_border_width(10);
        set_resizable(false);

    // Widgets set up
        txtCalcs.set_max_length(20);
        txtCalcs.set_text("0");
        txtCalcs.select_region(0, txtCalcs.get_text_length());
        txtCalcs.set_can_default();
        txtCalcs.grab_default();
    // Packing
        add(boxMain);
        boxMain.pack_start(boxText);
        boxMain.pack_start(boxButtons);
            boxText.pack_start(txtCalcs);
            boxButtons.pack_start(boxNumbers, Gtk::PACK_EXPAND_WIDGET, 2);
            boxButtons.pack_start(boxControls, Gtk::PACK_EXPAND_WIDGET, 2);
                boxNumbers.pack_start(boxNCol1);
                boxNumbers.pack_start(boxNCol2);
                boxNumbers.pack_start(boxNCol3);
                    boxNCol1.pack_start(btnN7);
                    boxNCol1.pack_start(btnN8);
                    boxNCol1.pack_start(btnN9);
                    boxNCol2.pack_start(btnN4);
                    boxNCol2.pack_start(btnN5);
                    boxNCol2.pack_start(btnN6);
                    boxNCol3.pack_start(btnN0);
                    boxNCol3.pack_start(btnN1);
                    boxNCol3.pack_start(btnN2);
                boxControls.pack_start(btnPlus);
                boxControls.pack_start(btnLess);
                boxControls.pack_start(btnMult);
                boxControls.pack_start(btnDiv);
                boxControls.pack_start(btnIqual);

        show_all_children();
}

windowMain::~windowMain()
{
}
