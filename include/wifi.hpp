#include <OTAHandler.h>
#include <WiFi.h>
#include <esp_wifi.h>

#include <CanAirIoApi.hpp>
#include <ConfigApp.hpp>
#include <InfluxArduino.hpp>
#include <bme680.hpp>
#include <pmsensor.hpp>
#include <status.hpp>

#define PUBLISH_INTERVAL 30  // publish to cloud each 30 seconds
#define WIFI_RETRY_CONNECTION 20
#define IFX_RETRY_CONNECTION 2

void otaLoop();
void otaInit();
bool wifiCheck();
void wifiConnect(const char* ssid, const char* pass);
void wifiInit();
void wifiStop();
void wifiRestart();
void wifiLoop();

bool apiIsConfigured();
void apiInit();
void apiLoop();

bool influxDbIsConfigured();
void influxDbInit();
void influxDbParseFields(char* fields);
void influxDbAddTags(char* tags);
bool influxDbWrite();
void influxDbLoop();