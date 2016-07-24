#! /bin/sh

SCRIPT_DIR=`dirname $0`
gcc \
    $SCRIPT_DIR/../source/ccode/load_main.c \
    $SCRIPT_DIR/../source/ccode/thread/thread.c \
    $SCRIPT_DIR/../source/ccode/load/load.c \
-o  \
    $SCRIPT_DIR/bin/start_load \
-lpthread \
-I$SCRIPT_DIR/../source/header

$SCRIPT_DIR/bin/start_load
