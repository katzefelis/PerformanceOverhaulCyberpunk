#include "REDString.h"

#include "Pattern.h"

REDString::REDString()
{
    using TStringCtor = void(REDString*, const char*);
    static TStringCtor* RealStringCtor = reinterpret_cast<TStringCtor*>(FindSignature({
        0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x33, 0xC0,
        0xC6, 0x01, 0x00, 0x48, 0x89, 0x41, 0x18, 0x48,
        0x8B, 0xD9, 0x89, 0x41, 0x14, 0x48, 0x85, 0xD2,
        0x74, 0x10, 0x48, 0xC7, 0xC0, 0xFF, 0xFF, 0xFF
        }));

    RealStringCtor(this, "");
}

REDString::REDString(const char* acpData)
{
    using TStringCtor = void(REDString*, const char*);
    static TStringCtor* RealStringCtor = reinterpret_cast<TStringCtor*>(FindSignature({
        0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x33, 0xC0,
        0xC6, 0x01, 0x00, 0x48, 0x89, 0x41, 0x18, 0x48,
        0x8B, 0xD9, 0x89, 0x41, 0x14, 0x48, 0x85, 0xD2,
        0x74, 0x10, 0x48, 0xC7, 0xC0, 0xFF, 0xFF, 0xFF
        }));

    RealStringCtor(this, acpData);
}

void REDString::Destroy()
{
    using TStringDtor = void(REDString*);
    static TStringDtor* RealStringDtor = reinterpret_cast<TStringDtor*>(FindSignature({
        0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B,
        0xD9, 0x8B, 0x49, 0x14, 0x8B, 0xC1, 0xC1, 0xE8
        }));

    RealStringDtor(this);
}