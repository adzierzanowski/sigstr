#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wifi_helper.h"


struct flags_t
{
  bool verbose;
};

void parse_args(int argc, char *argv[], struct flags_t *flags)
{
  for (int i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      printf("%s -- display Wi-Fi stats\n", argv[0]);
      printf("usage: sigstr [-hv]\n\n");
      printf("options:\n");
      printf("  -h, --help    show this help message and exit\n");
      printf("  -v            show all possible stats\n");
      exit(0);
    }

    if (strcmp(argv[i], "-v") == 0)
    {
      flags->verbose = true;
    }
  }
}

void print_wifi_info(struct flags_t flags)
{
  char ssid[0x100] = {'\0'};
  sprintf(ssid, "%s", wh_get_ssid());

  char mac_addr[0x100] = {'\0'};
  sprintf(mac_addr, "%s", wh_get_mac());
  
  char country[0x100] = {'\0'};
  sprintf(country, "%s", wh_get_country());
  
  char iname[0x100] = {'\0'};
  sprintf(iname, "%s", wh_get_iface_name());
  
  int rssi = wh_get_rssi();
  enum wh_wifi_mode mode = wh_get_mode();
  int noise = wh_get_noise();
  int tpwr = wh_get_transmit_pwr();
  double trate = wh_get_transmit_rate();

  printf(
    "%-15s %s\n",
    "ssid:", ssid
  );
  printf(
    "%-15s %s%d%s dBm\n",
    "rssi:", wh_rssi_ansi_prefix(rssi), rssi, ANSI_END
  );
  printf(
    "%-15s %s%d%s dBm\n",
    "noise:", wh_noise_ansi_prefix(noise), noise, ANSI_END
  );
  printf(
    "%-15s %d mW\n",
    "transmit power:", tpwr
  );
  printf(
    "%-15s %0.2lf Mbps (%d max)\n",
    "transmit rate:", trate,
    wh_mode_max_rate(mode)
  );
  
  if (flags.verbose)
  {
    printf(
      "%-15s %s\n",
      "iface name:", iname
    );
    printf(
      "%-15s %s\n",
      "mode:", wh_mode_string(mode)
    );
    printf(
      "%-15s %s\n",
      "mac addr:", mac_addr
    );
    printf(
      "%-15s %s\n",
      "country:", country 
    );
  }
}

int main(int argc, char *argv[])
{
  struct flags_t flags = {
    .verbose = false
  };

  parse_args(argc, argv, &flags);
  print_wifi_info(flags);

  return 0;
}
