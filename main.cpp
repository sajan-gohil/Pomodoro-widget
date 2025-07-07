#include <QApplication>
#include <QMessageBox>
#include "pomodoro.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, "Error", "System tray not available.");
        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);

    Pomodoro pomodoro;
    return app.exec();
}
