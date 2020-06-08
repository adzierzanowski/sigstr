import CoreWLAN


func _get_current_iface() -> CoreWLAN.CWInterface {
  let wclient = CoreWLAN.CWWiFiClient()
  let iface = wclient.interface()
  return iface!
}

func _cstr_ptr(_ s: String) -> UnsafePointer<Int8> {
  let cstr = s.utf8CString
  let cptr = cstr.withUnsafeBufferPointer { ptr -> UnsafePointer<Int8> in 
    return ptr.baseAddress!
  }
  return cptr
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
  return _cstr_ptr(ssid)
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

func wh_get_mac() -> UnsafePointer<Int8> {
  let iface = _get_current_iface()
  let mac = iface.hardwareAddress() ?? "-"
  return _cstr_ptr(mac)
}

func wh_get_country() -> UnsafePointer<Int8> {
  let iface = _get_current_iface()
  let ccode = iface.countryCode() ?? "-"
  return _cstr_ptr(ccode)
}

func wh_get_iface_name() -> UnsafePointer<Int8> {
  let iface = _get_current_iface()
  let iname = iface.interfaceName ?? "<unknown>"
  return _cstr_ptr(iname)
}
