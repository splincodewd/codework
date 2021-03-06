#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");

int APIENTRY WinMain(HINSTANCE This, HINSTANCE Prev, LPSTR cmd, int mode) {

	HWND hWnd; // дескриптор главного окна программы
	MSG msg; // структура для хранения сообщений
	WNDCLASS wc; // класс окна

	wc.hInstance = This;
	wc.lpszClassName = WinName; // имя класса окна
	wc.lpfnWndProc = WndProc; // функция окна
	wc.style = CS_HREDRAW / CS_VREDRAW; // cтиль окна
	wc.hIcon = LoadIcon(NULL, IDC_ARROW); // иконка
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //  cтандартный курсор
	wc.lpszMenuName = NULL; // отключение меню
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	// заполнение окна белым цветом
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // установка цвета

	if (!RegisterClass(&wc)) return 0;

	// Создание окна
	hWnd = CreateWindow(
		WinName,
		_T("Солнце"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, // x
		CW_USEDEFAULT, // y
		CW_USEDEFAULT, // width
		CW_USEDEFAULT, // height
		HWND_DESKTOP, // дескриптор родительского окна
		NULL, // отключение меню
		This, // дескриптор приложения
		NULL // дополнительной информации нет
	);

	ShowWindow(hWnd, mode);

	while (GetMessage(&msg, NULL, 0, 0)) {

		TranslateMessage(&msg); // трансляция кодов нажатой клавиши
		DispatchMessage(&msg); // посылает сообщение функции WndProc()

	}


	return 0;

}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	PAINTSTRUCT ps;
	HDC hdc;

	static int sx, sy;

	int sizeCircle = 100;
	int x1Circle = (sx / 2) - sizeCircle;
	int y1Circle = (sy / 2) - sizeCircle;
	int x2Circle = (sx / 2) + sizeCircle;
	int y2Circle = (sy / 2) + sizeCircle;

	switch (message) {

	case WM_SIZE:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		break;

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);

		SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(255, 255, 0)));
		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 0)));

		// centered circle
		Ellipse(hdc, x1Circle, y1Circle, x2Circle, y2Circle);


		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY: PostQuitMessage(0);
		break;

	default: return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;

}
