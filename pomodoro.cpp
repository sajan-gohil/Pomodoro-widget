#include "pomodoro.h"
#include <QMenu>
#include <QInputDialog>
#include <QProcess>
#include <QApplication>

Pomodoro::Pomodoro(QObject* parent)
    : QObject(parent), workDuration(25), breakDuration(5), currentState(PomodoroState::Stopped) {

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Pomodoro::switchState);

    trayIcon = new QSystemTrayIcon(QIcon::fromTheme("clock"), this);

    QMenu* menu = new QMenu();

    startAction = menu->addAction("Start");
    connect(startAction, &QAction::triggered, this, &Pomodoro::start);

    stopAction = menu->addAction("Stop");
    connect(stopAction, &QAction::triggered, this, &Pomodoro::stop);

    menu->addSeparator();

    QAction* setWork = menu->addAction("Set Work Duration");
    connect(setWork, &QAction::triggered, this, &Pomodoro::setWorkTime);

    QAction* setBreak = menu->addAction("Set Break Duration");
    connect(setBreak, &QAction::triggered, this, &Pomodoro::setBreakTime);

    menu->addSeparator();

    QAction* quit = menu->addAction("Quit");
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    trayIcon->setContextMenu(menu);
    trayIcon->setToolTip("Pomodoro Timer");
    trayIcon->show();
}

void Pomodoro::start() {
    if (currentState == PomodoroState::Stopped) {
        currentState = PomodoroState::Work;
        showNotification("Work session started", QString("%1 minutes").arg(workDuration));
        timer->start(workDuration * 60 * 1000);
    }
}

void Pomodoro::stop() {
    timer->stop();
    currentState = PomodoroState::Stopped;
    showNotification("Pomodoro stopped", "");
}

void Pomodoro::switchState() {
    if (currentState == PomodoroState::Work) {
        currentState = PomodoroState::Break;
        showNotification("Break started", QString("%1 minutes").arg(breakDuration));
        timer->start(breakDuration * 60 * 1000);
    } else if (currentState == PomodoroState::Break) {
        currentState = PomodoroState::Work;
        showNotification("Work session restarted", QString("%1 minutes").arg(workDuration));
        timer->start(workDuration * 60 * 1000);
    }
}

void Pomodoro::setWorkTime() {
    bool ok;
    int minutes = QInputDialog::getInt(nullptr, "Set Work Duration", "Enter minutes:", workDuration, 1, 180, 1, &ok);
    if (ok) workDuration = minutes;
}

void Pomodoro::setBreakTime() {
    bool ok;
    int minutes = QInputDialog::getInt(nullptr, "Set Break Duration", "Enter minutes:", breakDuration, 1, 60, 1, &ok);
    if (ok) breakDuration = minutes;
}

void Pomodoro::showNotification(const QString& title, const QString& message) {
    QProcess::execute("notify-send", { title, message });
}
