/*
 * Copyright (c) 2016-2018, Super GP Individual.
 * All Rights Reserved.
 *
 * Permission to use, copy, modify, and distribute this library for any
 * purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright
 * notice and this permission notice appear in supporting documentation,
 * and that the name of SGL not be used in advertising or publicity
 * pertaining to distribution of the software without specific, 
 * written prior permission.
 */


#ifndef SGL_H
#define SGL_H

#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _SGL_V310

#ifdef _DEBUG
#define SG_LIB(name) name "d.lib"
#else
#define SG_LIB(name) name ".lib"
#endif
#define SG_A(name) name ".a"

//#pragma comment(lib, SG_LIB("winsgl"))
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ws2_32.lib")
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <winsock.h>
//#include <gl\gl.h>
//#include <gl\glu.h>
//#include <gl\glaux.h>

#ifdef __cplusplus
#include <iostream>
#include <fstream>
#endif


//SG const macros

#define SG_PI 3.14159265358979323846
#define SG_CHAR_WIDTH 8
#define SG_CHAR_HEIGHT 16
#define SG_LINE_DELTA_DEFAULT 20
#define SG_QSIZE 32768
#define SG_MAX_FONT_SIZE 128
#define SG_MAX_FONT_LENGTH 128
#define SG_MAX_MENU_ITEM_NUM 128
#define SG_MAX_CONNECTION 64
#define SG_MCI_BUFFER_SIZE 256
#define SG_MCI_MAX_NUM 256
#define SG_MAX_POPUP_NUM 256
#define SG_MAX_FORMAT_FILTERS 256
#define SG_MAX_WINDOW_NUM 256

//SG io macros

#define SG_ACCURATE 0
#define SG_COORDINATE 1

#define SG_BUTTON_UP 0x80
#define SG_BUTTON_DOWN 0x00
#define SG_KEY_UP 0x80
#define SG_KEY_DOWN 0x00

#define SG_LEFT_BUTTON 0x01
#define SG_RIGHT_BUTTON 0x02
#define SG_MIDDLE_BUTTON 0x04
#define SG_MIDDLE_BUTTON_UP 0x08
#define SG_MIDDLE_BUTTON_DOWN 0x10

#define SG_WINDOW 0
#define SG_SCREEN 1

#define WIDGET_BACK 0
#define WIDGET_FRONT 1

#define WIDGET_DEFAULT 0x00
#define WIDGET_PASS 0x01
#define WIDGET_PRESSED 0x02
#define WIDGET_SELECTED 0x04
#define WIDGET_FOCUSED 0x08

#define INRECT(x, y, xl, yl, xh, yh) (((x)>=(xl))&&((x)<=(xh))&&((y)>=(yl))&&((y)<=(yh)))

// Windows string.

#ifdef UNICODE
#define SGWINSTR  LPWSTR
#else
#define SGWINSTR  LPCSTR
#endif

//Syncronize and exclude.

#define SEM_INIT() extern long semaphore;
#define SEM_P() InterlockedDecrement(&semaphore);while(semaphore<0);
#define SEM_V() InterlockedIncrement(&semaphore);


//SG enums.

enum _colors { //4 bit standard color.
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	DARKGRAY,
	LIGHTGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};
enum _mode { //bit mode or text mode.
	BIT_MAP,
	TEXT_MAP
};
enum _ascii { //Extended key code specially for SGL.
	SG_TAB = '\t',
	SG_ESC = 0x1b,
	SG_BACKS = '\b',
	SG_ENTER = '\r',
	SG_LEFT = 0x100,
	SG_UP,
	SG_RIGHT,
	SG_DOWN,
	SG_CTRL,
	SG_SHIFT,
	SG_INSERT,
	SG_DELETE,
	SG_HOME,
	SG_END,
	SG_NUMLOC,
	SG_CAPSLOC,
	SG_PAGEUP,
	SG_PAGEDOWN,
	SG_F1,
	SG_F2,
	SG_F3,
	SG_F4,
	SG_F5,
	SG_F6,
	SG_F7,
	SG_F8,
	SG_F9,
	SG_F10,
	SG_F11,
	SG_F12,
	SG_SHIFTBIT = 0x2000,
	SG_CTRLBIT = 0x4000
};
enum _line { //Line modes.
	SOLID_LINE,
	DOTTED_LINE,
	CENTER_LINE,
	DASHED_LINE,
	USERBIT_LINE
};
enum _piccpy { //Bitmap mix modes.
	COPY_PUT,
	XOR_PUT,
	OR_PUT,
	AND_PUT,
	NOT_PUT
};
enum _fill { //Sapes filling modes.
	EMPTY_FILL,
	SOLID_FILL,
	DASH_WRAP,
	CROSS_FILL,
	DOT_FILL
};
enum _control { //Types of widget.
	SG_BUTTON,
	SG_INPUT,
	SG_DIALOG,
	SG_OUTPUT,
	SG_LIST,
	SG_LABEL,
	SG_CHECK,
	SG_PROCESS,
	SG_OPTION,
	SG_DRAG,
	SG_SCROLLVERT,
	SG_SCROLLHORIZ,

	SG_COMBINED
};
enum _style { //Styles of widget.
	SG_DESIGN,
	WIN_XP,
	WIN_10,
	LINUX,
	ANDROID,
	WEBSITE,
};
enum _filter {
	MEAN_FILTER,
	LAPLACIAN_FILTER,
	BILATERAL_FILTER
};
enum _font {
	FONT_ITALIC = 1,
	FONT_UNDERLINE = 2,
	FONT_STRIKEOUT = 4
};
enum _alert {
	ALERT_BUTTON_ABORTRETRYIGNORE = MB_ABORTRETRYIGNORE,
	ALERT_BUTTON_OK = MB_OK,
	ALERT_BUTTON_OKCANCEL = MB_OKCANCEL,
	ALERT_BUTTON_RETRYCANCEL = MB_RETRYCANCEL,
	ALERT_BUTTON_YESNO = MB_YESNO,
	ALERT_BUTTON_YESNOCANCEL = MB_YESNOCANCEL,

	ALERT_ICON_EXCLAMATION = MB_ICONEXCLAMATION,
	ALERT_ICON_WARNING = MB_ICONWARNING,
	ALERT_ICON_INFORMATION = MB_ICONINFORMATION,
	ALERT_ICON_ASTERISK = MB_ICONASTERISK,
	ALERT_ICON_QUESTION = MB_ICONQUESTION,
	ALERT_ICON_STOP = MB_ICONSTOP,
	ALERT_ICON_ERROR = MB_ICONERROR,
	ALERT_ICON_HAND = MB_ICONHAND,

	ALERT_SYS_APPL = MB_APPLMODAL,
	ALERT_SYS_SYSTEM = MB_SYSTEMMODAL,
	ALERT_SYS_TASK = MB_TASKMODAL,
};
enum _instrument {
	MIDI_PIANO
};
enum _errors { //Different return values when error occurs.
	SG_NO_ERORR = 0,
	SG_OBJECT_NOT_FOUND = -1,
	SG_NO_LOAD_MEM = -2,
	SG_INVALID_MODE = -3,
	SG_IO_ERROR = -4,
	SG_INVALID_VERSION = -5,
	SG_SIZE_MISMATCH = -6,
	SG_OUT_OF_RANGE = -7,
	SG_NULL_POINTER = -8,
	SG_INCOMPLETE_STRUCT = -9,
	SG_MULTY_VALUE = -10,
	SG_CONNECTION_FAILED = -11,
	SG_MEDIA_ERROR = -12
};


//type defines.

//typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned long int dword;
typedef void(*vect)(void);
typedef void(*mouseMoveCall)(void *w, int x, int y);
typedef void(*mouseSubMoveCall)(int id, void *w, int x, int y);
typedef void(*mouseClickCall)(void *w, int x, int y, int status);
typedef void(*keyCall)(void *w, int key);

typedef void SGvoid;
typedef char SGchar;
typedef unsigned char SGuchar;
typedef short SGshort;
typedef unsigned short SGushort;
typedef int SGint;
typedef unsigned int SGuint;
typedef long SGlong;
typedef unsigned long SGulong;
typedef unsigned char *SGstring;
typedef float SGfloat;
typedef double SGdouble;
#ifdef __cplusplus
typedef bool SGbool;
#else
typedef char SGbool;
#endif

typedef struct {
	int x, y;
}vecTwo;
typedef struct {
	int x, y, m;
}vecThree;
typedef struct {
	byte r, g, b;
}RGB;
typedef struct {
	int sizeX, sizeY;
	SGstring data;
}bitMap;
typedef struct {
	int width, height;
	short *content;
}textMap;
typedef struct {
	RGB color;
	int size;
	SGWINSTR name;
	int coeff;
}font;
typedef struct _w{
	enum _control type;

	vecTwo pos;
	vecTwo size;

	int visible;
	int priority;
	int status;
	int style;

	int hide;
	int value;
	SGstring name;
	SGstring content;
	bitMap *cover;
	struct _w *associate;
	struct _w *next;
	RGB bgColor, passColor, pressColor, fgColor;

	SGstring tip;
	vecTwo tipPos, tipSize;
	mouseMoveCall showTip;
	bitMap *tipCover;

	mouseMoveCall mouseIn, mouseOut;
	mouseClickCall mouseDown, mouseUp, mouseClick;
	keyCall keyDown, keyUp, keyPress;

}widgetObj;

//The active window id when dealing with widget events.
int subWindow = -1;

SEM_INIT()

#ifdef __cplusplus
extern "C" {
#endif

//Printing function when debugging.

SGvoid debugf(const char *format, ...);


//Widget callbacks. Declared here for users to 'inherit'.

void vectDefault(void);
/* An empty function. */

void mouseMoveDefault(widgetObj *w, int x, int y);
void mouseMoveList(widgetObj *w, int x, int y);
void mouseMoveOption(widgetObj *w, int x, int y);
void mouseMoveDrag(widgetObj *w, int x, int y);
void mouseMoveScrollVert(widgetObj *w, int x, int y);
void mouseMoveScrollHoriz(widgetObj *w, int x, int y);
void mouseMoveCombined(widgetObj *w, int x, int y);
/* Used when the cursor moves no matter in or out of the widgets.
 * Parameter w for the widget object, x and y for the coordinate. */

void mouseClickDefault(widgetObj *w, int x, int y, int status);
void mouseClickInput(widgetObj *w, int x, int y, int status);
void mouseClickDialog(widgetObj *w, int x, int y, int status);
void mouseClickList(widgetObj *w, int x, int y, int status);
void mouseClickCheck(widgetObj *w, int x, int y, int status);
void mouseClickProcess(widgetObj *w, int x, int y, int status);
void mouseClickOption(widgetObj *w, int x, int y, int status);
void mouseClickDrag(widgetObj *w, int x, int y, int status);
void mouseClickScrollVert(widgetObj *w, int x, int y, int status);
void mouseClickScrollHoriz(widgetObj *w, int x, int y, int status);
void mouseClickCombined(widgetObj *w, int x, int y, int status);
/* Used when mouse clicked no matter in or out of the widgets.
 * Parameter w for the widget object, x and y for the coordinate.
 * status to represent which button and whether press or release. */

void keyDefault(widgetObj *w, int key);
void keyInput(widgetObj *w, int key);
void keyList(widgetObj *w, int key);
void keyOption(widgetObj *w, int key);
void keyScrollVert(widgetObj *w, int key);
void keyScrollHoriz(widgetObj *w, int key);
void keyCombined(widgetObj *w, int key);
/* Used when keyboard pressed. Parameter w for the widget object,
 * key for the ascii or the key code of the pressed key. */


/*
 * SG system interfaces
 * Basic IO functions to make the program executive. Widget is
 * for advanced graphic programming and for SG Creater to use.
 */

SGvoid initWindow(int width, int height, const char *title, int mode);
/* Used in sgSetup(), to set the parameters of the graphic window.
 * Actually this function just set the variables, the real window will
 * be created before sgLoop(). */

SGvoid setWindow(int left, int up);
/* Used to move the window to the coordinate (left, up). */

SGvoid setResizeable();
/* When changing the size of the window, the default mode will not change
 * the screen buffer value which means the image will resize as well. If we
 * set the mode to resizeable, the image will not zoom, only the size of the
 * window will change. */

SGvoid setSubResizeable(int id);
/* When changing the size of the sub window with given id, the default mode
 * will not change the screen buffer value which means the image will resize as
 * well. If we set the mode to resizeable, the image will not zoom, only the size
 * of the window will change. */

SGvoid resizeFuntion(void (*func)(int x, int y));
/* The parameter function will be executed when the size of the window
 *changed. */

SGvoid resizeSubFuntion(int id, void(*func)(int x, int y));
/* The parameter function will be executed when the size of the sub window
 * changed. */

SGint getWidth(int obj);
/* Returns the width of the obj. The parameter obj can be SG_WINDOW
 * (the current window) or SG_SCREEN(The screen of the computer). */

SGint getSubWidth(int id, int obj);
/* Returns the width of the obj. The parameter obj can be SG_WINDOW
 * (the current window) or SG_SCREEN(The screen of the computer). Parameter
 * id is the window to fetch. */

SGint getHeight(int obj);
/* Returns the height of the obj. The parameter obj can be SG_WINDOW
 * (the current window) or SG_SCREEN(The screen of the computer). */

SGint getSubHeight(int id, int obj);
/* Returns the height of the obj. The parameter obj can be SG_WINDOW
* (the current window) or SG_SCREEN(The screen of the computer). Parameter
* id is the window to fetch. */

SGvoid initKey();
/* Make keyboard active, or no callback will occur when key pressed. */

SGint biosKey(int cmd);
/* Main function to deal with key event. The parameter cmd can be
 * 0 or 1. Details of the usage are in instruction pdf. */

SGint biosSubKey(int id, int cmd);
/* Main function to deal with key event occured in window with given id. 
 * The parameter cmd can be 0 or 1. Details of the usage are in instruction
 * pdf. */

SGvoid clearKeyBuffer();
/* Delete all key events before current time. */

SGvoid clearSubKeyBuffer(int id);
/* Delete all key events of window with given id before current time. */

SGvoid initMouse(int mode);
/* Make mouse active, or no callback will occur when mouse move or click. */

vecTwo mousePos();
/* Returns the current position of the cursor. */

vecTwo mouseSubPos(int id);
/* Returns the current position at window with given id of the cursor. */

SGint mouseStatus(int b);
/* Returns whether one of the three mouse button is push down.
 * Parameter b can be SG_LEFT_BUTTON or SG_RIGHT_BUTTON or
 * SG_MIDDLE_BUTTON. */

SGint mouseSubStatus(int id, int b);
/* Returns whether one of the three mouse button is push down in window
 * with given id. Parameter b can be SG_LEFT_BUTTON or SG_RIGHT_BUTTON
 * or SG_MIDDLE_BUTTON. */

vecThree biosMouse(int cmd);
/* Main function to deal with mouse event. The parameter cmd can be
 * 0 or 1. Details of the usage are in instruction pdf. */

vecThree biosSubMouse(int id, int cmd);
/* Main function to deal with mouse event in window with given id. The
 * parameter cmd can be 0 or 1. Details of the usage are in instruction pdf. */

SGvoid clearMouseBuffer();
/* Delete all mouse events before current time. */

SGvoid clearSubMouseBuffer(int id);
/* Delete all mouse events of window with given id before current time. */

SGint initMidi();
/* Make midi output device active so that digital music can be
 * played by SGL program. */

SGvoid changeInstrument(int in);
/* Change current instrument to parameter in which is enumed
 * in _instrument. */

SGvoid playMidi(int tune, int volume, int sw);
/* Play one midi note with tune and volume. Parameter sw is set
 * to 1 if it's switched on and 0 if it's switched off.*/

SGint playMidiFile(const char *filename);
/* Play the midi file with name filename. The return value is the
 * music id. */

SGvoid stopMidiFile(int id);
/* Stop the playing midi music with its id. */

SGvoid pauseMidiFile(int id);
/* Pause the playing midi music with its id. */

SGvoid resumeMidiFile(int id);
/* Resume the paused midi music with its id. */

SGvoid initMci();
/* Initialize the media(mp3) device. */

SGint loadMciSrc(const char *filename);
/* Load the file in format mp3 to memory, the return value is its identifier.
 * Then operate the music using this identifier.*/

SGint playMci(int id);
/* Start playing the music with the given id. */

SGint stopMci(int id);
/* Stop playing the music with the given id, then roll back to its start. */

SGint pauseMci(int id);
/* Pause the music with the given id. */

SGint resumeMci(int id);
/* Resume playing the music with the given id at the pause point.*/

SGvoid createThread(vect func);
/* Create a thread with function func which means that the new thread
  * will start running with func. */

SGvoid timerThread(vect func, int millis, int time);
/* Create a timer using multy thread. Parameter func is the timer function,
 * millis is the interval */

SGvoid delay(int t);
/* Wait for t millisecond. During the time the window won't refresh. */

SGvoid delayBegin();
/* Used with delayEnd. To set the least time waiting between begin
 * and end. This pair of function is usually used to cotrol the time
 * of some loops. */

SGint delayEnd(int t);
/* Used with delayBegin. To set the least time waiting between begin
 * and end. This pair of function is usually used to cotrol the time
 * of some loops. */

SGint random(int n);
/* Returns a random integer between 0 and n - 1. */

vect getVect(int intn);
/* Returns the current vector function of number intn. Details are
 * in instruction pdf. */

SGint setVect(int intn, vect v);
/* Set a new function v to vector of number intn. */

SGvoid dosInt(int intn, int *ret);
/* Mainly for vector of number 9, namely the key vector. */

SGvoid setFreq(float f);
/* Determine how many flashes are displayed in one second. */

SGvoid showMouse();
/* Make the cursor visible. */

SGvoid hideMouse();
/* Make the cursor disvisible. */

SGvoid setMousePos(int x, int y);
/* Set the cursor position. */

SGvoid setSubMousePos(int id, int x, int y);
/* Set the cursor position in window with given id. */

SGvoid setMouseIcon(SGWINSTR icon);
/* Set the icon of the cursor. */

SGvoid setActivePage(int page);
/* Choose which page is now under editing. */

SGvoid setSubActivePage(int id, int page);
/* Choose which page is now under editing in window with given id. */

SGvoid setVisualPage(int page);
/* Choose which page is now showing. */

SGvoid setSubVisualPage(int id, int page);
/* Choose which page is now showing in window with given id. */

SGint selectFile(char name[], char start[], char format[], int idx);
/* Use Win API Graphic mode to choose one file. Parameter name
* is used to receive the selected file name with its path, and start
* is the path to begin with so set it to NULL as default. Parameter
* format is the probable file format and each format is seperated
* with \0, and it's set to NULL as default as well. The idx is the
* default format index which is usually set to 1. */

SGint selectSave(char name[], char start[], char format[], char def[], int idx);
/* Use Win API Graphic mode to let user input the file name that
* they want to save. Parameter name is used to receive the input
* file name with its path, and start is the path to begin with so set
* it to NULL as default. Parameter format is the probable file
* format and each format is seperated with \0, and it's set to NULL
* as default as well. Parameter def is the default format to append
* if no format is input. The idx is the default format index which is
* usually set to 1. */

SGint selectDir(char name[], char start[]);
/* Use Win API Graphic mode to choose one directory. Parameter
* name is used to receive the selected directory name with its
* path, and start is the path to begin with so set it to NULL as
* default. */

SGvoid alertInfo(const char *info, const char *title, int mode);
/* Create a new dialog to show or confirm some information.
* Parameter info is the text while title is title, and mode is one
* of the enums in _alert. */

SGint initMenu();
/* Allow this program to use windows main menu. The return value 
 * is the main menu id which will be used when add lists or items into
 * main menu. */

SGint addMenuList(const char *title, int id);
/* Add a new list of name title into the menu with the given id. The 
 * return value is the new list id.*/

SGint addMenuItem(const char *title, int id, void(*func)());
/* Add a new item of name title into the menu with the given id.
 * The parameter func is the callback function which means that it
 * will be called after the user click the item. */

SGint addMenuSeparator(int id);
/* Add a separate line in the list with given id. */

SGint enableItem(int id);
/* Make the item or menu of id enabled. That is, it can be clicked. */

SGint disableItem(int id);
/* Make the item or menu of id disabled. That is, it can't be clicked.*/

SGvoid checkItem(int id);
/* Make the item of id checked with a tick on the left.*/

SGvoid uncheckItem(int id);
/* Make the item of id unchecked and clear the tick on the left.*/

SGint copyText(const char *src);
/* Copy the given text into windows clipboard so that it can be pasted
 * to other programs. */

SGstring pasteText();
/* Return the text in clipboard. The return string need to be freed by
 * the programmer. */

SOCKET createServer(int port);
/* Set up a server(both local and remote), for diy communication, port should
 * be greater than 1023 and less than 65536. The return value is the socket
 * of the server. */

SOCKET createClient(const char *server, int port);
/* Set up a client and connect to server(localhost is "127.0.0.1), the port
 * should be equal to the one set by server. The return value is the socket
 * of the client. */

SOCKET acceptOne(SOCKET server);
/* Used by a server to accept one request, one acceptOne should answer
 * one createClient. The return value is the socket of the connection. */

SGint socketSend(SOCKET s, const char *buffer);
/* Used to send a string via one connection, socket s stands for the socket
 * of the given connection. */

SGint socketReceive(SOCKET s, char *buffer, int len);
/* Used to receive a string via one connection, socket s stands for the
 * socket of the given connection. Parameter len is the max length to receive,
 * if more content is sending, the rest will wait. If the connection is stopped,
 * the return value is SG_CONNECTION_FAILED. */

SGvoid closeSocket(SOCKET s);
/* When one the connection is cut, we should close the socket of this
 * connection. */

SGvoid hideCaption();
/* Hide the caption bar at the top. */

SGvoid hideSubCaption(int id);
/* Hide the caption bar at the top in window with given id. */

SGvoid showCaption();
/* Show the caption bar at the top. */

SGvoid showSubCaption(int id);
/* Show the caption bar at the top in window with given id. */

SGvoid addTray();
/* Add the application icon in the tray bar and enable the program
 * to hide to tray. */

SGvoid hideToTray();
/* Hide the whidow, and it will be shown again after clicking the icon
 * in the tray.*/

SGvoid restoreFromTray();
/* Show the window again. */

SGint initTrayMenu();
/* Enable showing the menu when right click the icon in the tray. The
 * return value is the tray menu id. */

SGint addTrayMenuList(const char *title, int id);
/* Add a list in the tray menu. Parameters are same to main menu.*/

SGint addTrayMenuItem(const char *title, int id, void(*func)());
/* Add an item in the tray menu. Parameters are same to main menu.*/

SGint addTrayMenuSeparator(int id);
/* Add a separator in the tray menu. Parameter is same to main menu.*/

SGint createPopupMenu();
/* Init one popup menu, the return value is the menu id. */

SGint addPopupMenuList(const char *title, int id);
/* Add a list in the popup menu. Parameters are same to main menu.*/

SGint addPopupMenuItem(const char *title, int id, void(*func)());
/* Add an item in the popup menu. Parameters are same to main menu.*/

SGint addPopupMenuSeparator(int id);
/* Add a separator in the popup menu. Parameter is same to main menu.*/

SGint finishPopupMenu(int id);
/* The popup menu need to be finished by the programmer which means
 * it is ready to show. */

SGint showPopupMenu(int menu, int x, int y);
/* The popup menu with given parameter can be shown with top-left corner at (x, y)
 * by calling this function. */

SGint showSubPopupMenu(int id, int menu, int x, int y);
/* The popup menu with given parameter can be shown in window with given id with
 * top-left corner at (x, y) by calling this function. */

int createWindow(int width, int height, const char *title, vect setup, vect loop);
/* Create a new window with SGL canvas. The first three parameters are
 * same as initWindow, while setup and loop are functions similar to sgSetup
 * and sgLoop. */

void closeWindow(int id);
/* Close the sub window with the id given by createWindow. */

SGvoid setIcon(const char *ico);
/* Set the running-time icon for the window. The icon will appear
 * at top_left in the caption bar and in the tray. */

SGvoid setSubIcon(int id, const char *ico);
/* Set the running-time icon for the window with given id. The icon
 * will appear at top_left in the caption bar and in the tray. */

widgetObj *newWidget(int type, SGstring name);
/* Returns a widget with default parameter. */

widgetObj *newCombinedWidget(int num, SGstring name, ...);
/* Create a combined widget. Pass the sub widget number and
 * then those sub widget pointers.*/

SGint registerWidget(widgetObj *obj);
/* After setting all the parameters, give back the widget to
 * the system. After this function, all callbacks are activated.*/

int registerSubWidget(int id, widgetObj *obj);
/* After setting all the parameters, give back the widget to
 * the sub window of given id. After this function, all callbacks are
 * activated.*/

SGint inWidget(widgetObj *obj, int x, int y);
/* Judge if coordinate (x, y) is in widget obj. */

widgetObj *getWidgetByIndex(int index);
/* Returns the widget pointer with the given index. */

widgetObj *getWidgetByName(const char *name);
/* Returns the widget pointer with the given name. */

int getIndexByName(const char *name);
/* Returns the index of the widget in system list with the
 * given parameter name. */

SGvoid showWidget(const char *name);
/* Make the widget of name visible. */

SGvoid ceaseWidget(const char *name);
/* Make the widget of name disvisible. */

SGint deleteWidgetByIndex(int index);
/* Delete the widget with the given index. */

SGint deleteWidgetByName(const char *name);
/* Delete the widget with the given name. */

void moveWidgetByIndex(int index, int xDelta, int yDelta);
/* Move the widget to (x + xDelta, y + yDelta) with the given index. */

void moveWidgetByName(const char *name, int xDelta, int yDelta);
/* Move the widget to (x + xDelta, y + yDelta) with the given name. */


/*
 * SG drawing interfaces
 * Funtions below are used to draw something on the screen.
 * The image after drawing will be shown after the loop function.
 */

SGvoid setColor(int r, int g, int b);
/* Set the current rgb color. */

SGvoid setSubColor(int id, int r, int g, int b);
/* Set the current rgb color in the sub window with the given id. */

SGvoid setFontSize(int height);
/* Set the current font size.*/

SGvoid setSubFontSize(int id, int height);
/* Set the current font size in the sub window with the given id. */

SGvoid setFontName(const char *name);
/* Set the current font name.*/

SGvoid setSubFontName(int id, const char *name);
/* Set the current font name in the sub window with the given id. */

SGvoid setFontStyle(int coeff);
/* Set the current font style.*/

SGvoid setSubFontStyle(int id, int coeff);
/* Set the current font style in the sub window with the given id. */

SGvoid setAlpha(float alpha);
/* Set the alpha value when mixing images. */

SGvoid setSubAlpha(int id, float alpha);
/* Set the alpha value when mixing images in the sub window with
 * the given id. */

SGvoid clearScreen();
/* Fill the whole screen with current color. */

SGvoid clearSubScreen(int id);
/* Fill the whole screen with current color in the sub window
 * with the given id. */

SGint putPixel(int x, int y);
/* Set the pixel of coordinate (x, y) of current color. */

SGint putSubPixel(int id, int x, int y);
/* Set the pixel of coordinate (x, y) of current color in the sub
 * window with the given id. */

RGB getPixel(int x, int y);
/* Returns the rgb color of coordinate (x, y). */

RGB getSubPixel(int id, int x, int y);
/* Returns the rgb color of coordinate (x, y) in the sub window
 * with the given id. */

SGvoid putLine(int x1, int y1, int x2, int y2, int mode);
/* Draw a line from (x1, y1) to (x2, y2) of currrent color with
 * the given mode showed in enum list. */

SGvoid putSubLine(int id, int x1, int y1, int x2, int y2, int mode);
/* Draw a line from (x1, y1) to (x2, y2) of currrent color with
 * the given mode showed in enum list in the sub window with
 * the given id. */

SGvoid putQuad(int x1, int y1, int x2, int y2, int mode);
/* Draw a rectangle from (x1, y1) to (x2, y2) of currrent color
 * with the given mode showed in enum list. */

SGvoid putSubQuad(int id, int x1, int y1, int x2, int y2, int mode);
/* Draw a rectangle from (x1, y1) to (x2, y2) of currrent color
 * with the given mode showed in enum list in the sub window with
 * the given id. */

SGvoid putTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int mode);
/* Draw a triangle from of the given three point of currrent
 * color with the given mode showed in enum list. */

SGvoid putSubTriangle(int id, int x1, int y1, int x2, int y2, int x3, int y3, int mode);
/* Draw a triangle from of the given three point of currrent color
 * with the given mode showed in enum list in the sub window with
 * the given id. */

SGvoid putCircle(int xc, int yc, int r, int mode);
/* Draw a circle with centre (xc, yc) and radius r of currrent
 * color with the given mode showed in enum list. */

SGvoid putSubCircle(int id, int xc, int yc, int r, int mode);
/* Draw a circle with centre (xc, yc) and radius r of currrent
 * color with the given mode showed in enum list in the sub window
 * with the given id. */

SGvoid putEllipse(int xc, int yc, int a, int b, int mode);
/* Draw a circle with centre (xc, yc) and axis a and b of currrent
 * color with the given mode showed in enum list. */

SGvoid putSubEllipse(int id, int xc, int yc, int a, int b, int mode);
/* Draw a circle with centre (xc, yc) and axis a and b of currrent
* color with the given mode showed in enum list in the sub window
 * with the given id. */

SGint loadBmp(int x, int y, const char *filename);
/* Put a bmp picture on the screen with top-left corner (x, y). */

SGint loadSubBmp(int id, int x, int y, const char *filename);
/* Put a bmp picture on the screen with top-left corner (x, y) in
 * the sub window with the given id. */

SGint bmpMemory(bitMap *obj, const char *filename);
/* Load bmp to a bitMap struct other than showing it on screen. */

SGvoid putNumber(int n, int x, int y, char lr);
/* Draw number n on the screen of position (x, y). The parameter
* lr can be 'l', which means that (x, y) is the top-left corner of the
* number, or 'r', which means the bottom-right corner. Details are
* in instruction pdf. */

SGvoid putSubNumber(int id, int n, int x, int y, char lr);
/* Draw number n on the sub window with given id of position (x, y).
* The parameter lr can be 'l', which means that (x, y) is the top-left
* corner of the number, or 'r', which means the bottom-right corner.
* Details are in instruction pdf. */

SGvoid putChar(char ch, int x, int y);
/* Draw one character ch on the screen of position (x, y). */

SGvoid putSubChar(int id, char ch, int x, int y);
/* Draw one character ch on the sub window with given id of position (x, y). */

SGvoid putString(const char *str, int x, int y);
/* Draw one string str on the screen of position (x, y). */

SGvoid putSubString(int id, const char *str, int x, int y);
/* Draw one string str on the sub window with given id of position (x, y). */

SGint stringWidth(const char *str, int x);
/* Get the width on x axis of the given string in current font. */

SGvoid putStringFormat(const char *str, int x, int y, ...);
/* Draw one string str on the screen of position (x, y) with format
 * controling. */

SGint putStringConstraint(const char *str, int x, int y, int start, int constraint);
/* Draw one string str on the screen of position (x, y) with maximum
 * length constraint. */

SGint getImage(int left, int top, int right, int bottom, bitMap *bitmap);
/* Copy the pixel messages of the given area to parameter bitmap. */

SGint getSubImage(int id, int left, int top, int right, int bottom, bitMap *bitmap);
/* Copy the pixel messages of the given area to parameter bitmap in
 * the sub window with the given id. */

SGvoid putImage(int left, int top, bitMap *bitmap, int op);
/* Paste the pixel messages of the given area to (left, top) with mode op. */

SGvoid putSubImage(int id, int left, int top, bitMap *bitmap, int op);
/* Paste the pixel messages of the given area to (left, top) with mode op in
 * the sub window with the given id. */

SGint maskImage(int left, int top, bitMap *mask, bitMap *bitmap);
/* The new pixel */

SGvoid funcMap(int x1, int x2, int y1, int y2, float(*vect)(float x));
/* Draw the graph of function vect with border limitation. */

SGvoid funcSubMap(int id, int x1, int x2, int y1, int y2, float(*vect)(float x));
/* Draw the graph of function vect with border limitation in the sub
 * window with the given id. */

SGvoid floodFill(int x, int y, RGB c);
/* Fill from coordinate (x, y) recursively with current color until
 * meeting the given color c. */

SGvoid floodSubFill(int id, int x, int y, RGB c);
/* Fill from coordinate (x, y) recursively with current color until
* meeting the given color c in the sub window with the given id. */

bitMap *copyPic(bitMap *src);
/* Copy picture from src to dst. */

bitMap *grayPic(bitMap *src);
/* Change source picture to grayscale picture. */

bitMap *binaryPic(bitMap *src, int threshold);
/* Change source picture to binary picture. */

bitMap *zoomPic(bitMap *src, float rate);
/* Zoom in (rate < 1) or zoom out (rate > 1). */

bitMap *rotatePic(bitMap *src, bitMap *mask, float angle);
/* Rotate the source picture and output the mask. */

bitMap *filterPic(bitMap *src, int mode);
/* Use different kinds of filter to enhance the quality of the given
 * source picture. */

bitMap *luminantPic(bitMap *src, int delta);
/* Change the luminance of the source picture. */

bitMap *contrastPic(bitMap *src, int delta);
/* Change the luminance of the source picture. */

SGvoid initOpenGL();
/* Enable SGL to use OpenGL. */


/*
 * SG writing interfaces
 * Functions below can be called only in TEXT_MAP mode. Most functions
 * are similar to those in BIT_MAP mode.
 */

SGvoid setBfc(int bgc, int fgc);
/* Set background color and foreground color. */

SGvoid clearText();
/* Fill the whole screen to the current background color. */

SGvoid setCharColor(char color, int x, int y);
/* Set the background and foreground color of coordinate (x, y). */

SGvoid setCharBgc(char color, int x, int y);
/* Set the background color of coordinate (x, y). */

SGvoid setCharFgc(char color, int x, int y);
/* Set the foreground color of coordinate (x, y). */

SGint getShort(int x, int y);
/* Returns the character and color of coordinate (x, y). */

SGvoid writeChar(char c, int x, int y);
/* Put down one character c with current color at (x, y). */

SGvoid writeString(const char *s, int x, int y);
/* Put down one string s with current color at (x, y). */

SGint getText(int left, int top, int right, int bottom, textMap *text);
/* Copy the text messages of the given area to parameter text. */

SGvoid putText(int left, int top, textMap *text);
/* Paste the text messages at (left, top). */


//User main functions.

void sgSetup();
/* For initializing. */

void sgLoop();
/* For main loop. */

#ifdef __cplusplus
}
#endif
#endif