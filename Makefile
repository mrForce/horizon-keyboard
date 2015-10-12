all:
	gcc `pkg-config --cflags --libs gtk+-2.0` -shared -fPIC horizon.c -o horizon -ldl
