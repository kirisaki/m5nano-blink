# M5NanoC6 Blink Project

This repository contains a simple "blink" project for the M5NanoC6 development board based on the ESP32-C6 chip. The project is built using the ESP-IDF framework.

## Hardware Requirements

- M5NanoC6 board (ESP32-C6 based)
- USB-C cable for programming

## Development Environment Setup

### Prerequisites

Install the following dependencies:

```bash
sudo apt-get update
sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```

### ESP-IDF Installation

1. Clone the ESP-IDF repository:

```bash
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
git checkout release/v5.1  # Use a stable version
./install.sh esp32c6
```

2. Set up the environment variables:

```bash
. ~/esp/esp-idf/export.sh
```

You can add this to your `.bashrc` for convenience:

```bash
echo '. $HOME/esp/esp-idf/export.sh' >> ~/.bashrc
source ~/.bashrc
```

## Building and Flashing

1. Set the target to ESP32-C6:

```bash
idf.py set-target esp32c6
```

2. Build the project:

```bash
idf.py build
```

3. Flash the application to your device:

```bash
idf.py -p /dev/ttyACM0 flash
```

Replace `/dev/ttyACM0` with the correct port for your device.

4. Monitor the output:

```bash
idf.py -p /dev/ttyACM0 monitor
```

Press `Ctrl+]` to exit the monitor.

## License

This project is released under the BSD-0 License. See the [LICENSE] file for details.