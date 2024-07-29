# HTTPS Client Manager Project

This project demonstrates how to use PlatformIO with the ESP32 to handle HTTPS requests using the `HTTPSClientManager` class. The class reads a root certificate from LittleFS and performs secure HTTP requests with it. 

## Features

- **HTTPS Requests**: Supports GET, POST, PUT, DELETE, HEAD, PATCH, and OPTIONS requests.
- **Root Certificate Handling**: Reads the root certificate from a file in LittleFS.
- **Flexible Configuration**: Easily configurable for different HTTP methods and server certificates.


## Project Structure
```
├── data
│ ├── image.png
│ ├── test_file.txt
├── include
│ ├── WiFiHandler.h
│ ├── HTTPSClientManager.h
│ └── security.h
├── src
│ ├── WiFiHandler.cpp
│ ├── HTTPSClientManager.cpp
│ └── main.cpp
├── platformio.ini
└── README.md
```

## Prerequisites
- Platformio with ESP8266 board support.
- Libraries:
    - ESP8266WiFi
    - ESP8266HTTPClient
	- LittleFS

## Installation

1. Clone the repository:
```sh
git clone https://github.com/burakkcmn/nodemcu-httpsRequests.git
cd nodemcu-httpsRequests
```
2. Open the project in Platformio.
3. Install required libraries:
    - ESP8266WiFi
    - ESP8266HTTPClient
	- LittleFS
4. Upload the code to your ESP8266:
    - Ensure the correct board and port are selected in the Platformio.
    - Upload the code to the ESP8266.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is based on tutorials by Rui Santos & Sara Santos - [Random Nerd Tutorials](https://RandomNerdTutorials.com/)