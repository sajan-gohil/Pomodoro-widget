# PomodoroTray

A lightweight Pomodoro timer for Linux, written in C++ with Qt. Runs in the system tray, supports notifications, configurable durations, and cycle auto-restarts.

---

## Installation

Build and run the application:

```
mkdir build && cd build
cmake ..
make
./PomodoroTray
```

---

## Making PomodoroTray Discoverable in System Launcher (Without Autostart)

### 1. Install the binary to a permanent location

System-wide:

```
sudo cp ./PomodoroTray /usr/local/bin/
```

Or user-local:

```
mkdir -p ~/bin
cp ./PomodoroTray ~/bin/
chmod +x ~/bin/PomodoroTray
```

Ensure the path is in your `PATH` environment variable if using `~/bin`.

---

### 2. Create a `.desktop` file

Location: `~/.local/share/applications/PomodoroTray.desktop`

```
mkdir -p ~/.local/share/applications
nano ~/.local/share/applications/PomodoroTray.desktop
```

Paste the following content:

```
[Desktop Entry]
Type=Application
Name=Pomodoro
Exec=/usr/local/bin/PomodoroTray
Icon=clock
Comment=Pomodoro timer in system tray
Categories=Utility;
Terminal=false
StartupNotify=false
```

- Replace `Exec=` with the full path to your binary.
- Replace `Icon=` with a theme icon (e.g., `clock`) or an absolute path to a PNG/SVG file.

Make the file executable:

```
chmod +x ~/.local/share/applications/PomodoroTray.desktop
```

This makes the app searchable from your desktop environment’s launcher (e.g., GNOME, KDE, XFCE).

---

## Optional: Autostart on Login

### 1. Create autostart directory (if needed)

```
mkdir -p ~/.config/autostart
```

### 2. Create the autostart `.desktop` file

```
nano ~/.config/autostart/PomodoroTray.desktop
```

Paste the following:

```
[Desktop Entry]
Type=Application
Name=PomodoroTray
Exec=/usr/local/bin/PomodoroTray
Icon=clock
Comment=Pomodoro timer in system tray
X-GNOME-Autostart-enabled=true
```

Make it executable:

```
chmod +x ~/.config/autostart/PomodoroTray.desktop
```

---

### 3. (Optional) Register system-wide

To make the app visible in all user menus:

```
sudo cp ~/.local/share/applications/PomodoroTray.desktop /usr/share/applications/
```

---

## Verification

You can test your launcher integration:

```
gtk-launch PomodoroTray
```

Or just search for "Pomodoro" in your desktop environment's application menu.

---
