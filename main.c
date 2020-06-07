#include <stdio.h>

#include "wifi_helper.h"


int main()
{
  int rssi = wh_get_rssi();
  enum wh_wifi_mode mode = wh_get_mode();
  int noise = wh_get_noise();
  int tpwr = wh_get_transmit_pwr();
  double trate = wh_get_transmit_rate();

  printf("%-15s %s\n", "ssid:", wh_get_ssid());
  printf("%-15s %s\n", "mode:", wh_mode_string(mode));
  printf("%-15s %s%d%s dBm\n", "rssi:", wh_rssi_ansi_prefix(rssi), rssi, ANSI_END);
  printf("%-15s %s%d%s dBm\n", "noise:", wh_noise_ansi_prefix(noise), noise, ANSI_END);
  printf("%-15s %d mW\n", "transmit power:", tpwr);
  printf("%-15s %0.2lf Mbps (%d max)\n", "transmit rate:", trate, wh_mode_max_rate(mode));

  return 0;
}
