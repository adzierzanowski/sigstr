#include "wifi_helper.h"


const char *ANSI_END = "\033[0m";
const char *ANSI_GREEN = "\033[38;5;2m";
const char *ANSI_YELLOW = "\033[38;5;3m";
const char *ANSI_RED = "\033[38;5;1m";

const char *wh_rssi_ansi_prefix(int rssi)
{
  if (rssi >= -75)
    return ANSI_GREEN;
  else if (rssi >= -80)
    return ANSI_YELLOW;
  else
    return ANSI_RED;
}

const char *wh_noise_ansi_prefix(int noise)
{
  if (noise <= -80)
    return ANSI_GREEN; 
  else if (noise <= -85)
    return ANSI_YELLOW;
  else
    return ANSI_RED;
}

const char *wh_mode_string(enum wh_wifi_mode mode)
{
  switch (mode)
  {
    case MODE_11A: return "802.11a";
    case MODE_11AC: return "802.11ac";
    case MODE_11B: return "802.11b";
    case MODE_11G: return "802.11g";
    case MODE_11N: return "802.11n";
    default: return "<unknown>";
  }
}

int wh_mode_max_rate(enum wh_wifi_mode mode)
{
  switch (mode)
  {
    case MODE_11A: return 54;
    case MODE_11AC: return 6928;
    case MODE_11B: return 11;
    case MODE_11G: return 54;
    case MODE_11N: return 600;
    default: return 0;
  }
}
