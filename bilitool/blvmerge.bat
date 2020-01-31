@echo off 
setlocal enabledelayedexpansion

python blvmerge.py

set result_name=result
set ori=%cd%
if not exist !result_name! exit
cd !result_name!
for /d %%i in (*) do (
    echo %%i

    cd %%i
    for /d %%j in (*) do (
        echo %%j
        cd %%j
        ffmpeg -f concat -safe 0 -i merge.txt -c copy ..\%%j.mp4
        cd ..
        rm -rf %%j
    )  
    cd ..
)
cd ..

rem pause