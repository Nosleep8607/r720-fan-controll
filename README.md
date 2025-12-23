# fan_r720

**Dell R720 Fan Control Program (C Rewrite)**

This is a C rewrite of the original Bash script by [Lareira Digital](https://github.com/lareira-digital/fancontrol_r720) for controlling Dell R720 fan speeds via IPMI.

Full credit goes to Lareira Digital.  
C rewrite and Debian packaging by redeforit@manyhost.org.

---

## Installation

Download the Debian package and install it:

```bash
sudo dpkg -i fan_r720-1.0.deb


# Usage

## Set fan speed
./fan_r720 set 0
./fan_r720 set 50
./fan_r720 set 100

## Enable automatic fan control
./fan_r720 enableauto

## Disable automatic fan control
./fan_r720 disableauto

