# sigstr (signal strength)

This is a utility to spit out some Wi-Fi stats.

What makes it a little bit interesting is that I provide a small wrapper over
`CWInterface` from macOS API in Swift. Then I generate assembly and demangle
the names so I can link to the code with C.

It's probably the stupid way to obtain this information* but it was fun.

\* Yes, yes it is. It appears that clicking the Wi-Fi icon while holding ⌥
gives you that info.

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
