#! /bin/sh

SCRIPT_DIR=`dirname $0`
gcc \
    $SCRIPT_DIR/../source/ccode/monitor_main.c \
    $SCRIPT_DIR/../source/ccode/temperture/temperture.c \
-o  \
    $SCRIPT_DIR/bin/start_monitor \
-lpthread \
-I$SCRIPT_DIR/../source/header

$SCRIPT_DIR/bin/start_monitor
