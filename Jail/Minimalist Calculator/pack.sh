#!/bin/bash

set -xe

if [ -f dist.zip ]; then
    rm dist.zip
fi

pushd src
cp secret.py secret.py.bak
sed -i -r 's/([^{]*)\{[^}]+\}/\1{test_flag}/' secret.py
zip dist.zip chall.py secret.py Dockerfile docker-compose.yml
mv secret.py.bak secret.py
mv dist.zip ..
popd
