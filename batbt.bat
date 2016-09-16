pushd build-win
call "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat" x64

set CommonCompilerFlags=-MT -nologo -Gm-  -GR- -EHsc- -EHa- -Od -Oi -W4 -wd4505 -wd4456 -wd4201 -wd4100 -wd4189 -FC -Zi

cl %CommonCompilerFlags% /I..\headers ..\src\main.cpp shar.lib
rem link ..\build-win\main.obj 

popd
