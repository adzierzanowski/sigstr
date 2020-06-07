import CoreWLAN


func _get_current_iface() -> CoreWLAN.CWInterface {
  let wclient = CoreWLAN.CWWiFiClient()
  let iface = wclient.interface()
  return iface!
}

func wh_get_rssi() -> Int {
  let iface = _get_current_iface()
  return iface.rssiValue()
}

func wh_get_noise() -> Int {
  let iface = _get_current_iface()
  return iface.noiseMeasurement()
}

func wh_get_ssid() -> UnsafePointer<Int8> {
  let iface = _get_current_iface()
  let ssid = iface.ssid() ?? "<unknown>"
  let cstr = ssid.utf8CString
  let cptr = cstr.withUnsafeBufferPointer { ptr -> UnsafePointer<Int8> in
    return ptr.baseAddress!
  }
  return cptr
}

func wh_get_transmit_pwr() -> Int {
  let iface = _get_current_iface()
  return iface.transmitPower()
}

func wh_get_transmit_rate() -> Double {
  let iface = _get_current_iface()
  return iface.transmitRate()
}

func wh_get_mode() -> Int {
  let iface = _get_current_iface()
  return iface.activePHYMode().rawValue
}
