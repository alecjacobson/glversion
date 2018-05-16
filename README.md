Get started with 

```
git clone --recursive https://github.com/alecjacobson/glversion.git
```

Then build with

```
mkdir build
cd build
cmake ../
make
```

Then run with


```
./glversion
```

### Running via ssh

This uses GLFW to open an OpenGL context. On a normal terminal with an attached
screen, this will silently use a 1 pixel "background window" and create
buffers. When running over ssh, the program may immediately seg fault. This is
because glfw is failing to create a context (_Could I catch this more
gracefully?_).

The solution is to tell the terminal about the display setup. Issue this once:

    export DISPLAY=:0

