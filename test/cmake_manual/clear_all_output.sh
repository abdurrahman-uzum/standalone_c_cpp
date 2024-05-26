#!/bin/bash

SCRIPT_DIR=$( dirname -- "$( readlink -f -- "$0"; )"; )

echo "Will remove the following contents:"

echo "in $SCRIPT_DIR/build/"
ls -l $SCRIPT_DIR/build/

echo "in $SCRIPT_DIR/lib/"
ls -l $SCRIPT_DIR/lib/

echo "in $SCRIPT_DIR/test/bin/"
ls -l $SCRIPT_DIR/test/bin/

read -p "Continue? [yN] " input

if [ "$input" == "y" ]; then

    rm -rf $SCRIPT_DIR/build/*
    rm -rf $SCRIPT_DIR/lib/*
    rm -rf $SCRIPT_DIR/test/bin/*

else

    echo "Declined. Terminating..."

fi