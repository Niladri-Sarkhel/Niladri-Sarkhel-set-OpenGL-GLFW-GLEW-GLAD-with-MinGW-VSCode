# set-OpenGL-(GLFW-GLEW-GLAD)-with-MinGW(C/C++)-VSCode

# this repo shows 
1.  how to build these OpenGL libraries for MinGW using CMake

-   GLFW
-   GLEW
-   GLAD

2.  how to **statically** link those libraries with **MinGW C/C++** compiler using **mingw32-make** with the help of a simple **Makefile**

3.  set up with VSCode using **code-runner**

## that's it !! 


>if you don't want to build anything then just grab the **glew.h , glfw3.h, glad.h, glad.c, libglew32.a, libglfw3.a** from this repo and go to linking step . however it is recommended to build the libraries by yourself 


# BUILD LIBRARIES

##  0.  update the graphics drivers of your computer (recomended)

##  1.  install **CMake** and **MinGW(C/C++)** and add to your **environment variable** 

run these commands in the terminal to check cmake and g++ 
> g++ --version

> cmake --version

##  2.  build GLFW ( we need to build the libglfw3.a file )

go [here](https://www.glfw.org/download.html) then download and extract the **Source package** . 

then run
>cmake -S path/to/the/downloaded/source-package/folder -B path/to/the/folder/where/you/want/the/build -G "MinGW Makefiles"

now open terminal inside your build folder then run this command
>mingw32-make

inside the build folder goto the **src** folder and you should see the **libglfw3.a** file ( well done !! )

and inside the source package folder goto the **include** folder and here you have the **glfw3.h** file

we need **glfw3.h** and **libglfw3.a** to use GLFW

## 3. build GLEW ( we need to build the libglew32.a file )

click [here](https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip/download) to download the source package and extract 

in the extracted folder go to the location of CMakeLists.txt and open terminal

>   It’s here: glew-2.1.0\build\cmake\CMakeLists.txt

now run
>   cmake -S . -B path/to/the/folder/where/you/want/the/build -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX=C:\mingw64\x86_64-w64-mingw32

then run
>   mingw32-make

in the build forlder go to the **lib** folder . here you should see **libglew32.a** file

inside the source package folder goto the **include** folder and here you have the **glew.h** file

# LINK LIBRARIES

create a make file named **Makefile** and put the below code 
inside it

put the Makefile inside the root directory of the project

```
all: compile run

compile:
	g++ -I relative/path/to/the/.h/files -L relative/path/to/the/.a/files -o application_name ./main.cpp -lglfw3 -lglew32 -lopengl32 -lshell32 -lgdi32 -luser32

run: 
	./application.exe
```

# COMPILE 

go to the root directory of the project where the Makefile is located 

then run the command 
>   mingw32-make

