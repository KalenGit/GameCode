#编译方式
CC = g++
#C++版本，显示所有警告
VERSION = -g -std=c++11 -Wall
#头文件和库文件/usr/lib/x86_64-linux-gnu/libglut.so和/usr/lib/x86_64-linux-gnu/libGL.so
INCLUDE = -I../include -lglut -lGL
#目标文件，最后生成文件
TARGET = ../bin/Pacman
#源代码路径，wildcard是一个函数，代表展开所有匹配的*.cpp文件，否则被认为是文件‘*.cpp’
SRCS = $(wildcard *.cpp)
#编译为.o文件，patsubst是一个函数，替换通配符
OBJS = $(patsubst %cpp,%o,$(SRCS))

all:$(TARGET)
#执行编译
$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(VERSION) $(INCLUDE) -o $(TARGET)

%.o:%.cpp
	$(CC) $(VERSION) $(INCLUDE) -c $< #$<表示，第一个依赖文件
#清除
.PHONY:clean
clean:
	rm -rf $(OBJS) $(TARGET)