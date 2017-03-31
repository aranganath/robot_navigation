#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/aditya/project/robot_navigation/CSE180/src/controller_manager"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/aditya/project/robot_navigation/CSE180/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/aditya/project/robot_navigation/CSE180/install/lib/python2.7/dist-packages:/home/aditya/project/robot_navigation/CSE180/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/aditya/project/robot_navigation/CSE180/build" \
    "/usr/bin/python" \
    "/home/aditya/project/robot_navigation/CSE180/src/controller_manager/setup.py" \
    build --build-base "/home/aditya/project/robot_navigation/CSE180/build/controller_manager" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/aditya/project/robot_navigation/CSE180/install" --install-scripts="/home/aditya/project/robot_navigation/CSE180/install/bin"
