ALPHADEL LAYOUT
===============

My TADA68 Custom Layout

# Base Layer
```
 ,----------------------------------------------------------------.
 |GEsc| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
 |----------------------------------------------------------------|
 |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
 |----------------------------------------------------------------|
 |ESC/CAP|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
 |----------------------------------------------------------------|
 |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
 |----------------------------------------------------------------|
 |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
 `----------------------------------------------------------------'
```

# Function Layer
```
 ,----------------------------------------------------------------.
 |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
 |----------------------------------------------------------------|
 |     |   |Up |   |   |   |   |   |   |   |   |   |   |Pscr |Hme |
 |----------------------------------------------------------------|
 |      |<- |Dn | ->|   |   |   |   |TRP|TR-|TR+|   |        |End |
 |----------------------------------------------------------------|
 |        |ESH|ETF|Bl-|BL |BL+|   |MUT|VU-|VU+|   |   McL|MsU|McR |
 |----------------------------------------------------------------|
 |    |    |    |                       |   |   |    |MsL|MsD|MsR |
 `----------------------------------------------------------------'
```

## Build environment

1) See [The Complete Newbs Guide To QMK](https://docs.qmk.fm/#/newbs) for more information.

2) Clone the QMK repository
```
git clone git@github.com:qmk/qmk_firmware.git
```
3) Clone this repository inside the following folder structure `keyboards/tada68/keymaps/alphadel`
```
git clone git@github.com:rafaeldelboni/alphadel-tada68-keymap.git qmk_firmware/keyboards/tada68/keymaps/alphadel
```

## Flashing Instructions

1) from the `qmk_firmware` directory run:
```
$ make tada68:alphadel:bin
```

2) hit the reset button on the TADA, the lights will start flashing.

3) You'll see a new drive on your computer called TADA68. Backup the original factory `FLASH.BIN` file thats inside it.

4) Delete `FLASH.BIN` from the TADA drive and copy `tada68_alphadel.bin` that was generated at the root of the qmk directory into the TADA drive.
```
rm /Volumes/TADA68\ \ /FLASH.BIN
cp tada68_alphadel.bin /Volumes/TADA68\ \ /FLASH.BIN
```

5) Hit ESC on the keyboard. The lights will stop flashing and your firmware is loaded!
