1. Device doesn’t display anything
  - Check if the connected pins are correct https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
  - Check PC_static_display.ino line 3, it may not be "0x27"
  - Check PC_static_display.ino line 11, if you're not using ESP32, buad rate may not be "112500"
  - Try to build a simple test program to display something

2. Device doesn't show the data
  - Check PC_static_display.ino line 11, if you're not using ESP32, buad rate may not be "112500"
  - Check if Windows application (version 2) is showing data
  - In "USB Displat", select correct port and baud rate, click "apply", then click "run"

3. Windows app doesn't show the data
  - Not support onboard GPU
  - Program not test in Win 11
  - In "Setting" => "Console" => "Show index", Check if there are "CPU | CPU Total [Load]", "CPU | CPU Package [Temperature]", "GpuXXXXX | GPU Core [Load]", "GpuXXXXX | GPU Core [Temperature]"
  - In "Setting" => "Console" => "Check value"
  - download https://openhardwaremonitor.org/, the program is base on this
