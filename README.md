This CMake project shows a bug using a "using" imported from a module.
The using should produce a std::function like signature.
Doing the same without "module import" all work as expected.

```
**********************************************************************
** Visual Studio 2022 Developer Command Prompt v17.11.5
** Copyright (c) 2022 Microsoft Corporation
**********************************************************************
[vcvarsall.bat] Environment initialized for: 'x64'

C:\Program Files\Microsoft Visual Studio\2022\Community>cl /Bv
Microsoft (R) C/C++ Optimizing Compiler Version 19.41.34123 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

Compiler Passes:
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\cl.exe:        Version 19.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\c1.dll:        Version 19.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\c1xx.dll:      Version 19.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\c2.dll:        Version 19.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\c1xx.dll:      Version 19.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\link.exe:      Version 14.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\mspdb140.dll:  Version 14.41.34123.0
 C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\1033\clui.dll: Version 19.41.34123.0

cl : Command line error D8003 : missing source filename

C:\Program Files\Microsoft Visual Studio\2022\Community>
```

Ouput produced:
```
OK: class library_namespace::declare<void const * __ptr64 __cdecl(void const * __ptr64,class type_info const & __ptr64)>
ERROR:class library_namespace::declare<void const * __ptr64 __cdecl(void * __ptr64,class type_info const & __ptr64)>
```
You see, the *const* for the first parameter is lost in the module version.


