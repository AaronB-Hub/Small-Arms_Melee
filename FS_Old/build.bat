SET "TKPATH=..\m-ex\MexTK"
SET "CurrDir=%CD%"
SET "FilesPATH=%CurrDir%\files"
SET "MrPATH=%CurrDir%\Mr"
SET "TsPATH=%CurrDir%\Ts"

CD %TKPATH%
:: Reset this variable, because it originally uses relative pathing, but this will use full pathnames
SET "TKPATH=%CD%"

:: ----- Mario Example -----
:: compile main code

	:: \\ Example format from Mario Example
	:: "%TKPATH%MexTK.exe" -ff -i "src/mario.c" -s ftFunction -dat "PlMr.dat" -ow
	:: \\ Example format from Google Doc
	:: MexTK.exe -ff -i "Path to code" -s ftFunction -o "Name of output" -t "ftFunction.txt" -l "melee.link" -q -ow -w -c
	:: \\ Example format from TriWing
	:: "MexTK.exe" -ff -i "Path to codes (multiple .C files)" -s ftFunction -t "<path>\ftFunction.txt" -l "<path>\melee.link" -dat "<path>\PlMr.dat" -ow

::"MexTK.exe" -ff -i "%MrPATH%\mario.c" -s ftFunction -dat "%FilesPATH%\PlMr.dat" -ow

:: compile item code
	:: \\ Example format from Mario Example
	:: "%TKPATH%MexTK.exe" -ff -item 0 "src/item_fireball.c" -item 2 "src/item_cape.c" -dat "PlMr.dat" -s itFunction -ow
	:: \\ Example format from Google Doc
	:: MexTK.exe -ff -item “Article index” "Path to code" -s itFunction -o "Name of output" -t "itFunction.txt" -l "melee.link" -q -ow -w -c

::"MexTK.exe" -ff -item 0 "%MrPATH%\item_fireball.c" -item 2 "%MrPATH%\item_cape.c" -dat "%FilesPATH%\PlMr.dat" -s itFunction -ow





:: ----- Test Character -----
:: compile main code
::"MexTK.exe" -ff -i "%TsPATH%\test.c" "%TsPATH%\special_n.c" "%TsPATH%\special_s.c" -s ftFunction -t "%TKPATH%\ftFunction.txt" -l "%TKPATH%\melee.link" -dat "%FilesPATH%\PlTs.dat" -ow
::"MexTK.exe" -ff -i "%TsPATH%\test.c" -s ftFunction -t "ftFunction.txt" -l "melee.link" -dat "%FilesPATH%\PlTs.dat" -ow
"MexTK.exe" -ff -i "%TsPATH%\test.c" -s ftFunction -dat "%FilesPATH%\PlTs.dat" -ow

:: compile item code
::"MexTK.exe" -ff -item 0 "%TsPATH%\item_testgun.c" -s itFunction -t "%TKPATH%\itFunction.txt" -l "%TKPATH%\melee.link" -dat "%FilesPATH%\PlTs.dat" -ow
"MexTK.exe" -ff -item 0 "%TsPATH%\item_testgun.c" -s itFunction -dat "%FilesPATH%\PlTs.dat" -ow

pause