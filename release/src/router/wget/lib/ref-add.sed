/^# Packages using this file: / {
  s/# Packages using this file://
  ta
  :a
  s/ wget / wget /
  tb
  s/ $/ wget /
  :b
  s/^/# Packages using this file:/
}
