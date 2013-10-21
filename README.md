 siren - the simple CAD viewer
============================================================

 About siren
------------------------------------------------------------

siren is a simple CAD viewer for Microsoft Windows. siren
makes you some useful and quickly operations.

 How to build
------------------------------------------------------------

Building Equipment:

* Open CASCADE 6.6.0
* Microsoft Visual Studio 2008

1. Setup the BAT script for your enviromnent.

    editor tool/occenv.bat
    
    SET "OCCBASE=E:\\occ" # Change this variable!

2. Clone by git the repository of siren follows:

    git clone https:github.com/dyama/siren.git

3. Run the BAT script file with Visual Studio solution file.

    cd siren
    tool/vs9-occ660.bat src/siren.sln

4. Build sirenenv.dll and siren.exe.

 Futures
------------------------------------------------------------

* View a 3D model with mouse operation.
* Save to another 3D CAD file format.

 Usage
------------------------------------------------------------

You can run as follows:

    > siren.exe [filename]

Now, siren is able to read formats as follows;

* IGES
* OpenCASCADE BREP
* STEP

 Thirdparty technorogies
------------------------------------------------------------

* Open CASCADE Technorogy by Open CASCADE S.A.S.
* ISO C9x compliant stdint.h for Visual Studio by Alexander Chemeris.
* mruby by Ruby Association, Include soon.

 License
------------------------------------------------------------

MIT License

 Author
------------------------------------------------------------
dyama, Daisuke YAMAGUCHI <dyama@member.fsf.org>


