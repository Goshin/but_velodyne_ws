# but_velodyne_ws

## Build

```bash
$ git submodule update --init --recursive

$ mkdir -p build/opencv
$ cd build/opencv
$ cmake ../../src/opencv  -DCMAKE_INSTALL_PREFIX=`pwd`/../../devel
$ make install
$ cd ../../

$ mkdir -p build/but_velodyne_lib
$ cd build/but_velodyne_lib
$ cmake ../../src/but_velodyne_lib  -DCMAKE_INSTALL_PREFIX=`pwd`/../../devel
$ cd ../../

$ catkin_make
```
