# Somfy RTS Module for Homegear

This is a Homegear module to control Somfy RTS blinds via a CUNX. 

## Installation

Follow the Homegear compilation instructions at https://doc.homegear.eu/homegear/installation.html
and treat Homegear-Somfy as any other module, i.e.:

  * Clone it from Github
  * unzip
  * run ./makeRelease.sh

You need to copy the Device Description Files and Configuration file manually from
the "misc" directory to `/etc/homegear`.

## Requirements

Currently, the only supported transceiver is a CUNX. The author uses a MAX!Cube
with two additional modules, one of which is a 433MHz TI CC1101 transceiver.

Supporting USB-based CUL devices should be easily doable, SPI-based CC1101
transceivers is more work.

## Usage

The module adds a new family and acts like a central. You then create a new
peer with a custom address and pair it to your Somfy receiver. After pairing
is complete, you can run the commands `PROG`, `UP`, `DOWN` and `MY`.

### Pairing

Call `homegear -r` and execute:

```
families select 26
pc COMMUNICATION_MODULE_ID TYPE_ID ADDRESS
```

`COMMUNICATION_MODULE_ID` is the ID of your CUNX, the `TYPE_ID` is always 1 and
the address is a randomly created 6-digit hex number. For example:

```
families select 26
pc My-CUNX 1 0xdeadbe
```

Then, bring your Somfy device into pairing mode by pressing the PROG button for
three seconds on an existing remote. The blinds should move down and up. 

Trigger the `PROG` button in Homegear by issuing:

```
homegear -e rc '$hg->setValue(<peer ID>, 1, "PROG", true);'
```

`<peer ID>` is the ID of the peer that you added with the first command. Your
blinds should be paired. You can test them by running any of the commands:

```
homegear -e rc '$hg->setValue(<peer ID>, 1, "DOWN", true);'
homegear -e rc '$hg->setValue(<peer ID>, 1, "MY", true);'
homegear -e rc '$hg->setValue(<peer ID>, 1, "UP", true);'
```

## TODO, Known issues

The module has not been extensively tested and there might be tons of bugs. The
device description XML file is just "something" and is a work in progress.
