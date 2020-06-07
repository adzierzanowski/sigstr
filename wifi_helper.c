#include "wifi_helper.h"

const char *wh_rssi_ansi_prefix(int rssi)
{
  if (rssi >= -75)
    return "\033[38;5;10m";
  else if (rssi >= -80)
    return "\033[38;5;11m";
  else
    return "\033[38;5;9m";
}

const char *wh_noise_ansi_prefix(int noise)
{
  if (noise <= -80)
    return "\033[38;5;10m";
  else if (noise <= -85)
    return "\033[38;5;11m";
  else
    return "\033[38;5;9m";
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
