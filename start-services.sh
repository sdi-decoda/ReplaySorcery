#!/bin/sh

# Enable hardware acceleration
sudo systemctl enable --now replay-sorcery-kms
# Enable user service
systemctl --user enable --now replay-sorcery