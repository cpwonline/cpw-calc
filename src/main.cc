#include "windowMain.h"
#include <gtkmm/application.h>
#include "Config.h"

int main (int argc, char *argv[])
{
	// Creamos la aplicación
		auto mApp = Gtk::Application::create(
			argc,
			argv,
			"org.cpwonline.cpw-calc"
		);
	// Creamos un objeto de la clase
		windowMain mWindow;

	//Mostramos la ventana y retornamos cuando se cierre
		return mApp->run(mWindow);
}
