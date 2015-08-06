#!/bin/bash

# update /usr/lib/sysctl.d/50-default.conf
echo "1" > /proc/sys/net/ipv4/ip_forward

# Define static IP for WLAN

# Install & configure DHCPD

# set ipt rules
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
sudo iptables -A FORWARD -i eth0 -o wlan0 -m state --state RELATED,ESTABLISHED -j ACCEPT
sudo iptables -A FORWARD -i wlan0 -o eth0 -j ACCEPT
