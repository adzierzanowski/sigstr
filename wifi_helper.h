#ifndef WIFI_HELPER_H
#define WIFI_HELPER_H

#include <stdbool.h>


const char *ANSI_END; 
const char *ANSI_RED;
const char *ANSI_YELLOW;
const char *ANSI_GREEN;

enum wh_wifi_mode {
  MODE_11A,
  MODE_11AC,
  MODE_11B,
  MODE_11G,
  MODE_11N,
  MODE_NONE
};

extern const char *wh_get_ssid();
extern const char *wh_get_mac();
extern const char *wh_get_country();
extern const char *wh_get_iface_name();
extern int wh_get_noise();
extern int wh_get_rssi();
extern int wh_get_transmit_pwr();
extern int wh_get_channel();
extern double wh_get_transmit_rate();
extern enum wh_wifi_mode wh_get_mode();

const char *wh_rssi_ansi_prefix(int rssi);
const char *wh_noise_ansi_prefix(int noise);
const char *wh_mode_string(enum wh_wifi_mode mode);
int wh_mode_max_rate(enum wh_wifi_mode mode);

#endif
