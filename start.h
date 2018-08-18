#!/bin/bash

curr_path=$(pwd)


export LD_LIBRARY_PATH=$curr_path/lib; ./httpd 8080

