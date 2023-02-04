#include <iostream>
#include <tray.hpp>

int main()
{
    Tray::Tray tray("Test App", "icon.ico");

    tray.addEntry(Tray::Button("Test"));
    tray.addEntry(Tray::Button("Test Disabled"))->setDisabled(true);
    tray.addEntry(Tray::Separator());
    tray.addEntry(Tray::Label("Test Label"));
    tray.addEntry(Tray::Toggle("Test Toggle", false, [](bool state) { printf("State: %i\n", state); }));

    tray.addEntry(Tray::Separator());
    tray.addEntry(Tray::Submenu("Test Submenu"))->addEntry(Tray::Button("Submenu button!"))->setDisabled(true);
    tray.addEntry(Tray::Separator());
    tray.addEntry(Tray::Button("Exit", [&] { tray.exit(); }));

    tray.run();

    return 0;
}