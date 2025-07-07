#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QAction>

enum class PomodoroState { Work, Break, Stopped };

class Pomodoro : public QObject {
    Q_OBJECT

public:
    Pomodoro(QObject* parent = nullptr);

private slots:
    void start();
    void stop();
    void switchState();
    void setWorkTime();
    void setBreakTime();

private:
    void showNotification(const QString& title, const QString& message);

    QSystemTrayIcon* trayIcon;
    QAction* startAction;
    QAction* stopAction;
    QTimer* timer;

    int workDuration;
    int breakDuration;
    PomodoroState currentState;
};

#endif
