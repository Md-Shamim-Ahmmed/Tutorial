#### For competitive programming, I use Ubuntu (a popular free Linux distribution) dual booted alongside Windows. My favorite IDE is Geany and it's perfect for short codes in CP, but I don't recommend it for work and big projects. Here's setup instructions.

1. Download Ubuntu from [Download Ubuntu](https://ubuntu.com/download) or Linuxmint from [Download linuxmint](https://linuxmint.com/download.php)
2. Create a bootable USB with [universal usb installer](https://www.pendrivelinux.com/universal-usb-installer-easy-as-1-2-3/) or [Rufus](https://rufus.ie) or or [iso to usb](https://iso-to-usb.en.softonic.com/?ex=NB-7.2) or any other software.
3. Install Ubuntu from your USB, preferably alongside the current OS (like Windows).
4. Install Geany:
```
    sudo apt install geany 
```
5. Configure Geany preferences:\
   5.1. Open preferences with ctrl+alt+P.\
   5.2. In Keybindings tab, set ```Switch to Editor``` as F1 and confirm overriding,then ```Switch to VTE``` as \
   F2 (VTE is built-in terminal).\
   5.3. In Terminal tab, mark ```Follow path of the current file```. Terminal will now automatically change a path after \
   you open a new file.\
   5.4. (optional) In Editor tab, change ```Comment toggle marker``` to an empty string or a single space.
6. Open any C++ file in Geany, go to ```Build -> Set Build Commands``` and copy my flags.\
   Compile (F8): ```g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result```\
   Build (F9): ```g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG```\
   If you get compilation errors, try changing from c++17 to c++14 and/or removing sanitizers (two fsanitize flags).
7. If your computer beeps after compilation, unmark ```Beep on errors``` in Preferences -> General -> Miscellaneous.
8. Open a file ```~/.bashrc``` and uncomment a line ```#force_color_prompt=yes``` in order to get colorful terminal in Geany.\
Restart geany or run ```source ~/.bashrc``` to trigger the change.

#### Optional steps that I use:

9. Hide Toolbar and Sidebar by unmarking them in ```View```.
10. Install Guake and make it run on start-up:\
    ``` sudo apt install guake```\
     Activities (top-left corner) -> Startup Applications Preferences -> Add -> set name and command as ```guake```
11. Open system settings (top-right corner of the screen) and mark ```Auto-hide the Dock``` in Dock tab.

More info and details below.

* You can install stuff by using Software Center or typing a command in terminal, usually ```sudo apt install program_name```.
This should be displayed if you just type ```geany (Command 'geany' not found, but can be installed with: sudo apt install geany)```. If this doesn't work, I usually google ```ubuntu how to install program_name from terminal``` and follow the instructions.
* Guake allows you to summon a fullscreen terminal by clicking the F12 button, which is more comfortable than a new terminal window that you can open with ctrl+alt+T. It isn't important if you use Geany built-in terminal though.
* ```Comment toggle marker``` refers to a special character added to comments created with shortcut ctrl+E in Geany.
The default ~ means that commented lines will look like ```//~ int a = 2 + 2;```. It's ok to get rid of the ~ character.
* In Preferences -> Interface, you can switch the position of Geany terminal (and message window) between bottom and right.
 * ```python3``` is likely already installed, consider defining ```python``` as the same command [(more info)](https://stackoverflow.com/questions/41986507/unable-to-set-default-python-version-to-python3-in-ubuntu) in terminal:
 ``` update-alternatives --install /usr/bin/python python /usr/bin/python3 10 ```.
