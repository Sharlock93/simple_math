pushd build-win
call "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat" x64
set CommonLinkers=/INCREMENTAL:NO /OPT:REF
set CommonCompilerFlags=/MT /nologo /Gm-  /GR- /EHsc- /EHa- /W4 /wd4505 /wd4244 /wd4305 /wd4456 /wd4201 /wd4100 /wd4189 /FC /Zi /LD /DHELLO /I../headers /I../include /O2

cl %CommonCompilerFlags% ..\src\shar.cpp  /link %CommonLinkers% /IMPLIB:lib/shar.lib /OUT:dll/shar.dll 
cl %CommonCompilerFlags% ..\src\sharfunc.cpp lib\shar.lib /link %CommonLinkers% /IMPLIB:lib/sharfunc.lib /OUT:dll/sharfunc.dll 
cl %CommonCompilerFlags% ..\src\sharinit.cpp lib\shar.lib lib\sharfunc.lib ..\exlib\glew\glew32.lib ..\exlib\glfw\glfw3dll.lib /link %CommonLinkers% /IMPLIB:lib/sharinit.lib /OUT:dll/sharinit.dll
cl %CommonCompilerFlags% ../src/sh_bmp_reader.cpp lib/sharinit.lib /link /IMPLIB:"lib/sh_bmp_reader.lib" /OUT:"dll/sh_bmp_reader.dll" %CommonLinkers%
cl %CommonCompilerFlags% ../src/sh_camera3D.cpp lib/shar.lib lib/sharfunc.lib /link /IMPLIB:"lib/sh_camera3D.lib" /OUT:"dll/sh_camera3D.dll" %CommonLinkers%
cl %CommonCompilerFlags% ../src/sh_circle.cpp lib/shar.lib lib/sharfunc.lib ../exlib/glew/glew32.lib opengl32.lib /link /IMPLIB:"lib/sh_circle.lib" /OUT:"dll/sh_circle.dll" %CommonLinkers%
cl %CommonCompilerFlags% ../src/sh_rect.cpp lib/shar.lib lib/sharfunc.lib ../exlib/glew/glew32.lib opengl32.lib /link /IMPLIB:"lib/sh_rect.lib" /OUT:"dll/sh_rect.dll" %CommonLinkers%

cl %CommonCompilerFlags% ../src/sh_line.cpp lib/shar.lib lib/sharfunc.lib ../exlib/glew/glew32.lib opengl32.lib /link /IMPLIB:"lib/sh_line.lib" /OUT:"dll/sh_line.dll" %CommonLinkers%


popd
