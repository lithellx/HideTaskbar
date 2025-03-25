# HideTaskbar
Force Auto-Hide Taskbar

## About HideTaskbar
Allows you to force the "Automatically hide the taskbar in Desktop mode" option in Taskbar Settings even if you didn't activated your Windows.
It returns to normal upon restart.

If you're facing any unexpected errors, copy the code below and save it as ".reg" file then execute it.

```
Windows Registry Editor Version 5.00

[HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\StuckRects3]
"Settings"=hex:30,00,00,00,fe,ff,ff,ff,02,80,00,00,03,00,00,00,3e,00,00,00,28,\
  00,00,00,00,00,00,00,10,04,00,00,80,07,00,00,38,04,00,00,60,00,00,00,01,00,\
  00,00 
```

## Authors
[lithellx](https://github.com/lithellx)
