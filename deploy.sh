
#!/bin/sh
set -euxo pipefail;
eval "$(./shdotenv)"

yarn build
scp -r ./skins ./bin ./install.py  pi@wx.local:/home/pi/weewx-wdc

#aws s3 sync vendored/ s3://personal-www/static/weewx --storage-class INTELLIGENT_TIERING --cache-control max-age=31536000

echo "sudo wee_extension --install weewx-wdc"