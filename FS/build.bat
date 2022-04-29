SET "TKPATH=../m-ex/MexTK"
SET "FilesPATH=./files"

:: compile main code
"%TKPATH%/MexTK.exe" -ff -i "Ts/test.c" "Ts/special_n.c" "Ts/special_s.c" "Ts/special_lw.c" "Ts/special_hi.c" -s ftFunction -dat "%FilesPATH%/PlTs.dat" -ow 

:: compile item code
::%TKPATH%/MexTK.exe" -ff -item 0 "Ts/item_xxxx.c" -item 2 "Ts/item_yyyy.c" -dat "%FilesPATH%/PlTs.dat" -s itFunction -ow

pause