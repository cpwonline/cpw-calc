#include "windowMain.h"
#include <iostream>

windowMain::windowMain() :
    // Members initiation
        btnN0("0"), btnN1("1"), btnN2("2"), btnN3("3"),
        btnN4("4"), btnN5("5"), btnN6("6"), btnN7("7"),
        btnN8("8"), btnN9("9"), btnPlus("+"), btnLess("-"),
        btnMult("*"), btnDiv("/"), btnIqual("="), btnC("C"),
        btnCA("CA"), btnOPa("("), btnCPa(")"),
        boxMain(Gtk::ORIENTATION_VERTICAL)
{
    // Window basics properties
        set_title("CPW Calc");
        set_default_size(200, 295);
        set_border_width(10);
        set_resizable(false);

    // Widgets set up
        boxText.set_margin_bottom(5);

        txtCalcs.set_max_length(1000);
        txtCalcs.set_text("0");
        txtCalcs.select_region(0, txtCalcs.get_text_length());
        txtCalcs.set_can_default();
        txtCalcs.grab_default();
        txtCalcs.set_alignment(2);

        gridButtons.set_row_spacing(5);
        gridButtons.set_column_spacing(5);

    // Signal handlers
        btnN0.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_0
        ));
        btnN1.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_1
        ));
        btnN2.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_2
        ));
        btnN3.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_3
        ));
        btnN4.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_4
        ));
        btnN5.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_5
        ));
        btnN6.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_6
        ));
        btnN7.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_7
        ));
        btnN8.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_8
        ));
        btnN9.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_9
        ));
        btnC.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_c
        ));
        btnCA.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_ca
        ));
        btnOPa.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_opa
        ));
        btnCPa.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_cpa
        ));
        btnPlus.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_plus
        ));
        btnLess.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_less
        ));
        btnMult.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_mult
        ));
        btnDiv.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_div
        ));
        btnIqual.signal_clicked().connect(sigc::mem_fun(
            *this,
            &windowMain::on_click_iqual
        ));

    // Packing
        add(boxMain);
        boxMain.pack_start(boxText);
        boxMain.pack_start(gridButtons);
            boxText.pack_start(txtCalcs);

            gridButtons.add(btnN7);
            gridButtons.add(btnN8);
            gridButtons.add(btnN9);
            gridButtons.add(btnC);
            gridButtons.add(btnPlus);

            gridButtons.attach_next_to(btnN4, btnN7, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnN5, btnN8, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnN6, btnN9, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnCA, btnC, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnLess, btnPlus, Gtk::POS_BOTTOM, 1, 1);

            gridButtons.attach_next_to(btnN1, btnN4, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnN2, btnN5, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnN3, btnN6, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnDiv, btnCA, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnMult, btnLess, Gtk::POS_BOTTOM, 1, 1);

            gridButtons.attach_next_to(btnN0, btnN1, Gtk::POS_BOTTOM, 2, 1);
            gridButtons.attach_next_to(btnOPa, btnN3, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnCPa, btnDiv, Gtk::POS_BOTTOM, 1, 1);
            gridButtons.attach_next_to(btnIqual, btnMult, Gtk::POS_BOTTOM, 1, 1);

        show_all_children();
}

windowMain::~windowMain()
{
    // Destructor
}

/* Manejadores de señal */
void windowMain::on_click_0()
{
    if(txtCalcs.get_text() != "0")
        txtCalcs.set_text(txtCalcs.get_text() + "2");
}
void windowMain::on_click_1()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("1");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "1");
}
void windowMain::on_click_2()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("2");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "2");
}
void windowMain::on_click_3()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("3");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "3");
}
void windowMain::on_click_4()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("4");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "4");
}
void windowMain::on_click_5()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("5");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "5");
}
void windowMain::on_click_6()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("6");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "6");
}
void windowMain::on_click_7()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("7");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "7");
}
void windowMain::on_click_8()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("8");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "8");
}
void windowMain::on_click_9()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("9");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "9");
}
void windowMain::on_click_c()
{
    /*if(txtCalcs.get_text() != "0")
    {
        short length = txtCalcs.get_text_length();
        char text[] = txtCalcs.get_text();
        char newText[length];
        int cont = 0;
        while(cont < strlen(text) - 1)
        {
            newText[cont] = text[cont];
            cont++;
        }
        std::cout << newText << "\n";
        //txtCalcs.set_text(newText);
    }*/
}
void windowMain::on_click_ca()
{
    txtCalcs.set_text("0");
}
void windowMain::on_click_opa()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("(");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "(");
}
void windowMain::on_click_cpa()
{
    if(txtCalcs.get_text() != "0")
        txtCalcs.set_text(txtCalcs.get_text() + ")");
}
void windowMain::on_click_plus()
{
    if(txtCalcs.get_text() != "0")
        txtCalcs.set_text(txtCalcs.get_text() + "+");
}
void windowMain::on_click_less()
{
    if(txtCalcs.get_text() == "0")
        txtCalcs.set_text("-");
    else
        txtCalcs.set_text(txtCalcs.get_text() + "-");
}
void windowMain::on_click_mult()
{
    if(txtCalcs.get_text() != "0")
        txtCalcs.set_text(txtCalcs.get_text() + "x");
}
void windowMain::on_click_div()
{
    if(txtCalcs.get_text() != "0")
        txtCalcs.set_text(txtCalcs.get_text() + "/");
}
void windowMain::on_click_iqual()
{
}

