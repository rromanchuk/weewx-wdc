#!/bin/bash

# start rsyslog
echo 'Starting rsyslog'
# remove lingering pid file
rm -f /run/rsyslogd.pid
# start service
service rsyslog start

mv "${WEEWX_HOME}"/skins/weewx-wdc/skin-mqtt.conf "${WEEWX_HOME}"/skins/weewx-wdc/skin.conf

# start weewx
echo 'Starting weewx reports (mqtt)'
# shellcheck source=/dev/null
. "${WEEWX_HOME}/weewx-venv/bin/activate" && weectl report run --config "${WEEWX_HOME}/weewx.conf"
cat /var/log/syslog | grep weewx