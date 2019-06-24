copy $(SolutionDir)..\3rdparty\bin\libcrypto-3.dll $(TargetDir)  /y
copy $(SolutionDir)..\3rdparty\bin\libssl-3.dll $(TargetDir)  /y
copy $(SolutionDir)..\3rdparty\bin\openssl.exe $(TargetDir)  /y
copy $(TargetDir)..\$(Configuration)\Cored.dll $(TargetDir)  /y
copy $(TargetDir)..\$(Configuration)\EventWarpd.dll $(TargetDir)  /y
copy $(TargetDir)..\$(Configuration)\NetWorkd.dll $(TargetDir)  /y