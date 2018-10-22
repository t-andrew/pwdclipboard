#include "clipboard.h"

void Cpy2clip(const char *str) {
    if((strlen(str) <= 0) || strlen(str) >= 64) {
        return;
    }

    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, strlen(str)+1);
    memcpy(GlobalLock(hMem), str, strlen(str)+1);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}
