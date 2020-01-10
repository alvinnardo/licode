@echo off 
setlocal enabledelayedexpansion 

rem %%%%%%%%%%%%%%%%%%%%%%%%%%%%
rem %% format conversion step %%
rem %%%%%%%%%%%%%%%%%%%%%%%%%%%%
set result_name=result
md !result_name!
set ori=%cd%
set res=%ori%\!result_name!
for /d %%i in (*) do ( rem %% change %*% into !*! after enabling delay variable
	rem echo !num! 
	rem set /a num+=1
	rem %% print the name of the first directory
	rem echo %%i 

	rem %% create the first dir of result
	cd !res!
	if %%i NEQ !result_name! md %%i
	cd !ori!

	rem %% save the first dir path
	set orifirst=!ori!\%%i
	rem echo orifirst !orifirst!
	set resfirst=!res!\%%i
	rem echo resfirst !resfirst!

	cd %%i
	for /d %%j in (*) do (
		rem %% print the name of the second directory
		rem echo %%j

		rem %% create the second dir of result
		cd !resfirst!
		md %%j
		set ressecond=!resfirst!\%%j
		cd !orifirst!

		rem %% the method is finding after cd the second dir, so can use the 'ressecond' directly
		cd %%j
		for /r %%k in (*.blv) do (
			rem echo %%k
			set input=%%k

			set /a num=1
			rem %% get the pos of the beginning of filename
			for /l %%m in (-1 -1 -9) do (
				for /l %%n in (-1 -1 -9) do (
					rem echo m %%m n %%n
					if "!input:~%%m, %%n!"=="\" (
						rem echo %%m
						set /a pos_num=%%m+1

						rem %% get the name of file
						for /l %%p in (-1 -1 -9) do (
							rem echo %%p !pos_num!
							if %%p == !pos_num! (
								set num=!input:~%%p, -4!
							)
						)
					)
				)
			)
			rem echo !num!
			rem %% start format conversion
			ffmpeg -i %%k -c copy !ressecond!\video!num!.mp4
		)
		for /r %%k in (*ideo.m4s) do (
			set input_video=%%k
			rem echo %%k

			rem %% get the path to get the audio file
			set input_init=%%k
			set input_path=!input_video:~0, -9!
			set input_audio=!input_path!audio.m4s
			rem echo !input_audio!

			rem %% start format conversion
			ffmpeg -i !input_video! -i !input_audio! -c copy !ressecond!\video.mp4
		)
		cd ..
	)
	cd ..
	
)

rem %%%%%%%%%%%%%%%%%%%%%%%%%%%%
rem %% extract the video file %%
rem %%%%%%%%%%%%%%%%%%%%%%%%%%%%
set res=%cd%\!result_name!
cd !res!
for /d %%a in (*) do (
    cd %%a

    rem %% get the number of dirs
    set /a cnt_dir=0
    for /d %%b in (*) do (
        rem echo %%b
        set /a cnt_dir+=1
    )

    rem %% get the number of files
    set /a cnt_file=0
    for /r %%c in (*.mp4) do (
        set /a cnt_file+=1
    )
    echo !cnt_dir! !cnt_file!

    rem %% record the foot value of files
    set /a sub=1
    if !cnt_dir! == !cnt_file! (

        rem %% move the file to the root dir
        for /r %%d in (*.mp4) do (
            echo %%d
            move /Y %%d !res!\%%a\!sub!.mp4
            set /a sub+=1
        )

        rem remove the dirs
        for /d %%e in (*) do (
            rm -rf %%e
        )
    )

    cd ..
)
cd ..
python JsonRename.py

rem pause

