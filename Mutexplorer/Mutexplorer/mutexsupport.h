#ifndef MUTEXSUPPORT_H
#define MUTEXSUPPORT_H

#include <windows.h>

#define DIRECTORY_QUERY 0x0001
#define OBJ_CASE_INSENSITIVE    0x00000040L


typedef struct _LSA_UNICODE_STRING {
  USHORT Length;
  USHORT MaximumLength;
  PWSTR  Buffer;
} LSA_UNICODE_STRING, *PLSA_UNICODE_STRING, UNICODE_STRING, *PUNICODE_STRING;


typedef struct _OBJECTDIRIRECTORY_INFORMATION
{
  UNICODE_STRING ObjectName;
  UNICODE_STRING ObjectTypeName;
} OBJDIR_INFORMATION, *POBJDIR_INFORMATION;

typedef struct _OBJECT_ATTRIBUTES
{
     ULONG Length;
     PVOID RootDirectory;
     PUNICODE_STRING ObjectName;
     ULONG Attributes;
     PVOID SecurityDescriptor;
     PVOID SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;


#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }


extern "C"
__declspec(dllimport)
void
__stdcall
RtlInitUnicodeString(
  PUNICODE_STRING DestinationString,
  PCWSTR SourceString
);

extern "C"
__declspec(dllimport)
ULONG
__stdcall
NtOpenDirectoryObject(
  PHANDLE DirectoryHandle,
  ACCESS_MASK DesiredAccess,
  POBJECT_ATTRIBUTES ObjectAttributes
);

extern "C"
__declspec(dllimport)
ULONG
__stdcall
NtQueryDirectoryObject(
  HANDLE DirectoryHandle,
  PVOID Buffer,
  ULONG Length,
  BOOLEAN ReturnSingleEntry,
  BOOLEAN RestartScan,
  PULONG Context,
  PULONG ReturnLength
);







#endif // MUTEXSUPPORT_H
