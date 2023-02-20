
#!/usr/bin/env bash

scp -r ./skins ./bin ./install.py  pi@wx.local:/home/pi/weewx-wdc

echo "sudo wee_extension --install weewx-wdc"