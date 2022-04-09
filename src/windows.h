/*
MIT License

Copyright (c) 2022 balyedi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <iconv.h>
#include <SDL2/SDL.h>

#define IDOK 0
#define IDYES 1
#define IDNO 2

#define BOOL bool
#define BOOLEAN bool
#define TRUE true
#define FALSE false
#define CONST const

typedef unsigned short WORD;
typedef WORD ATOM;

#define WINAPI
#define CALLBACK

typedef wchar_t WCHAR;
typedef WCHAR *PWSTR;
typedef long LONG;
typedef unsigned char BYTE;
typedef unsigned char CHAR;
typedef unsigned long DWORD;
typedef uint64_t DWORDLONG;
typedef uint32_t DWORD32;
typedef uint64_t DWORD64;
typedef float FLOAT;
typedef void *PVOID;
typedef PVOID WNDPROC;

typedef unsigned int UINT;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef uint32_t UINT32;

typedef signed char INT8;
typedef signed short INT16;
typedef int32_t INT32;

typedef unsigned int UINT_PTR;
typedef int INT_PTR;
typedef INT_PTR *PINT_PTR;
typedef int64_t LONG_PTR; 
typedef uint64_t ULONG_PTR; 

typedef LONG_PTR LRESULT;
typedef PVOID HANDLE;

typedef void *LPVOID;
typedef const void* LPCVOID;
typedef DWORD* LPDWORD;

// Handles
typedef struct HDCSTRUCT* HDC;
typedef struct HWNDSTRUCT* HWND;
typedef HANDLE HINSTANCE;
typedef HANDLE HICON;
typedef struct HBRUSHSTRUCT* HBRUSH;
typedef HICON HCURSOR;
typedef HANDLE HMENU;

// Parameters
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;

// String types
typedef CONST WCHAR *LPCWSTR;
typedef CONST CHAR *LPCSTR;

#ifdef UNICODE
 typedef LPCWSTR LPCTSTR; 
#else
 typedef LPCSTR LPCTSTR;
#endif

typedef CHAR *PSTR;
// ---------------

/* Events */
#define WM_CREATE                       0x0001
#define WM_DESTROY                      0x0002
#define WM_SIZE                         0x0005
#define WM_PAINT                        0x000F
#define WM_CLOSE                        0x0010
#define WM_QUIT                         0x0012
#define WM_ERASEBKGND                   0x0014
#define WM_NCPAINT                      0x0085
#define WM_LBUTTONDOWN                  0x0201
#define WM_LBUTTONUP                    0x0202
#define WM_SYSCOLORCHANGE               0x0203

#define WS_MINIMIZEBOX                  0x00020000L
#define WS_OVERLAPPED                   0x00000000L
#define WS_CAPTION                      0x00C00000L
#define WS_THICKFRAME                   0x00040000L
#define WS_SYSMENU                      0x00080000L
#define WS_MAXIMIZEBOX                  0x00010000L
#define WS_OVERLAPPEDWINDOW WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define CW_USEDEFAULT 400

// Colors

#define COLOR_SCROLLBAR 0
#define COLOR_BACKGROUND 1
#define COLOR_ACTIVECAPTION 2
#define COLOR_INACTIVECAPTION 3
#define COLOR_MENU 4
#define COLOR_WINDOW 5 // Window background
#define COLOR_WINDOWFRAME 6
#define COLOR_MENUTEXT 7
#define COLOR_WINDOWTEXT 8
#define COLOR_CAPTIONTEXT 9
#define COLOR_ACTIVEBORDER 10
#define COLOR_INACTIVEBORDER 11
#define COLOR_APPWORKSPACE 12
#define COLOR_HIGHLIGHT 13
#define COLOR_HIGHLIGHTTEXT 14
#define COLOR_BTNFACE 15
#define COLOR_BTNSHADOW 16
#define COLOR_GRAYTEXT 17
#define COLOR_BTNTEXT 18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT 20

#define COLOR_3DDKSHADOW 21
#define COLOR_3DLIGHT 22
#define COLOR_INFOTEXT 23
#define COLOR_INFOBK 24
#define COLOR_HOTLIGHT 26
#define COLOR_GRADIENTACTIVECAPTION 27
#define COLOR_GRADIENTINACTIVECAPTION 28
#define COLOR_MENUHILIGHT 29
#define COLOR_MENUBAR 30

#define COLOR_DESKTOP COLOR_BACKGROUND
#define COLOR_3DFACE COLOR_BTNFACE
#define COLOR_3DSHADOW COLOR_BTNSHADOW
#define COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#define COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#define COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

#define COLOR_LAST COLOR_MENUBAR
//-------------------
// GetWindowLongPtr
#define GWL_EXSTYLE -20 //Retrieves the extended window styles.
#define GWLP_HINSTANCE -6 //Retrieves a handle to the application instance.
#define GWLP_HWNDPARENT -8 //Retrieves a handle to the parent window, if there is one.
#define GWLP_ID -12 //Retrieves the identifier of the window.
#define GWL_STYLE -16 //Retrieves the window styles.
#define GWLP_USERDATA -21 
//Retrieves the user data associated with the window. This data is intended for use by the application that created the window. Its value is initially zero.

#define GWLP_WNDPROC -4 
//Retrieves the pointer to the window procedure, or a handle representing the pointer to the window procedure. You must use the CallWindowProc function to call the window procedure.

// The following values are also available when the hWnd parameter identifies a dialog box.
#define DWLP_DLGPROC DWLP_MSGRESULT + sizeof(LRESULT) 
//Retrieves the pointer to the dialog box procedure, or a handle representing the pointer to the dialog box procedure. You must use the CallWindowProc function to call the dialog box procedure.

#define DWLP_MSGRESULT 0 //Retrieves the return value of a message processed in the dialog box procedure.
#define DWLP_USER DWLP_DLGPROC + sizeof(DLGPROC)
// ----------------

// MessageBox defines

#define MB_ABORTRETRYIGNORE 0x00000002L
//The message box contains three push buttons: Abort, Retry, and Ignore.

#define MB_CANCELTRYCONTINUE 0x00000006L
//The message box contains three push buttons: Cancel, Try Again, Continue. Use this message box type instead of MB_ABORTRETRYIGNORE.

#define MB_HELP 0x00004000L
//Adds a Help button to the message box. When the user clicks the Help button or presses F1, the system sends a WM_HELP message to the owner.

#define MB_OK 0x00000000L
//The message box contains one push button: OK. This is the default.

#define MB_OKCANCEL 0x00000001L
//The message box contains two push buttons: OK and Cancel.

#define MB_RETRYCANCEL 0x00000005L
//The message box contains two push buttons: Retry and Cancel.

#define MB_YESNO 0x00000004L
//The message box contains two push buttons: Yes and No.

#define MB_YESNOCANCEL 0x00000003L

typedef struct tagRECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef struct tagPAINTSTRUCT {
  HDC  hdc;
  BOOL fErase;
  RECT rcPaint;
  BOOL fRestore;
  BOOL fIncUpdate;
  BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct _WNDCLASS {
 UINT style; 
 WNDPROC lpfnWndProc; 
 int cbClsExtra; 
 int cbWndExtra; 
 HANDLE hInstance; 
 HICON hIcon; 
 HCURSOR hCursor; 
 HBRUSH hbrBackground; 
 LPCTSTR lpszMenuName; 
 LPCTSTR lpszClassName; 
} WNDCLASS;

typedef struct tagPOINT {
  LONG x;
  LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct tagMSG {
  HWND   hwnd;
  UINT   message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD  time;
  POINT  pt;
  DWORD  lPrivate;
} MSG, *PMSG, *NPMSG, *LPMSG;

typedef struct _SECURITY_ATTRIBUTES {
  DWORD nLength;
  LPVOID lpSecurityDescriptor;
  BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _OVERLAPPED {
  ULONG_PTR Internal;
  ULONG_PTR InternalHigh;
  union {
    struct {
      DWORD Offset;
      DWORD OffsetHigh;
    } DUMMYSTRUCTNAME;
    PVOID Pointer;
  } DUMMYUNIONNAME;
  HANDLE    hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct tagCREATESTRUCTW {
  LPVOID    lpCreateParams;
  HINSTANCE hInstance;
  HMENU     hMenu;
  HWND      hwndParent;
  int       cy;
  int       cx;
  int       y;
  int       x;
  LONG      style;
  LPCWSTR   lpszName;
  LPCWSTR   lpszClass;
  DWORD     dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;
#ifdef UNICODE
#define CREATESTRUCT CREATESTRUCTW
#else
#define CREATESTRUCT CREATESTRUCTA
#endif

typedef DWORD COLORREF;
typedef DWORD* LPCOLORREF;

#define RGB(r,g,b)      ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
typedef struct HWNDSTRUCT {
  LPCTSTR windowname;
  LPCTSTR classname; 
  SDL_Window* _Wwindow;
  HWND parent;
  DWORD dwExStyle;
  DWORD dwStyle;
  UINT xpos;
  UINT ypos;
  UINT width;
  UINT height;
  UINT type;
  UINT id;
  HDC _Wassochdc;
  WNDCLASS* _Wassocclass;
} _Whwnd;

typedef struct HDCSTRUCT {
  _Whwnd* _Wassochwnd;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  COLORREF bg;
  COLORREF fg;
} _Whdc;

typedef struct HBRUSHSTRUCT {
  COLORREF color;
} _Whbrush;

uint16_t _Whwndsize = sizeof(_Whwnd);
uint16_t _Whdcsize = sizeof(_Whdc);
uint16_t _Whbrushsize = sizeof(_Whbrush);
uint16_t _Wcstructsize = sizeof(CREATESTRUCTW);

//#define _WHWNDINIT(_Wwindow, grade) (_Whwnd){ name, grade }

#define APIENTRY WINAPI

WNDCLASS _Wclasses[30];
_Whwnd *_Whwnds[30];
MSG _Wmsgqueue[40];

int _Whwndsitr = 0;
int _Wclassesitr;
int _Wmsgqueueitr = 40;

UINT _Wevent;

void Sleep(int ms) { SDL_Delay(ms);return; } 

// Function prototypes
LRESULT CALLBACK _WsendWMmessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//-----------------------
unsigned int _Wget_component(unsigned int color, unsigned int index)
{
    const unsigned int shift = index * 8;
    const unsigned int mask = 0xFF << shift;
    return (color & mask) >> shift;
}
// Internal macros
#define _WCWBUTTON 1
#define _WCWWINDOW 2
#define _WCWTEXTINPUT 3

#ifdef UNICODE
#define CreateWindow CreateWindowW
#define GetWindowLongPtr GetWindowLongPtrW
#else
#define CreateWindow CreateWindowA
#define GetWindowLongPtr GetWindowLongPtrA
#endif
// ---------------
//iconv_open(const char *tocode, const char *fromcode);

#include "winerror.h" // pretty long
// other
#include "winnt.h"
#include "wingdi.h"
#include "shellapi.h"
#include "appmgmt.h"
#include "fileapi.h"
// -----

#include "src/entrypoint.c"
#include "src/createwindowex.c"
#include "src/createwindow.c"
#include "src/defwindowproc.c"
#include "src/showwin.c"
#include "src/regclass.c"
#include "src/beginpaint.c"
#include "src/endpaint.c"
#include "src/msgbox.c"

#include "src/getmsg.c"
#include "src/translmsg.c"
#include "src/dpatchmsg.c"

#include "src/fillrect.c"
#include "src/postqmsg.c"

#include "src/getcmdline.c"

// Internal functions
#include "src/internalwsend.c"
#include "src/internalwdrawcircle.c"

#ifdef __cplusplus
}
#endif