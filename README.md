# sigstr (signal strength)

This is a utility to spit out some Wi-Fi stats.

What makes it a little bit interesting is that I wrote a small wrapper over
macOS API's `CWInterface` in Swift. Then I generated the assembly from the
Swift code and demangled the function names so I could use them in the main
C code avoiding linking issues.

This is probably a stupid way to obtain this information* but it was fun.

\* Well, yes it is. It appears that clicking the Wi-Fi icon while holding ⌥
gives you this info.

## building

You will probably need the standard XCode CLI stuff and Python3. Then just

```bash
$ make
$ ./sigstr
ssid:           my-cool-network
mode:           802.11n
rssi:           -70 dBm
noise:          -78 dBm
transmit power: 1496 mW
transmit rate:  73.00 Mbps (600 max)
```
