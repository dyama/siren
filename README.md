 siren - the simple CAD viewer
============================================================

 About siren
------------------------------------------------------------

siren is a simple CAD viewer for Microsoft Windows. siren
makes your some useful and quickly operations.

 How to build
------------------------------------------------------------

Building Equipment:

* Open CASCADE 6.6.0
* Microsoft Visual Studio 2008

1. Clone by git the repository of siren follows:

    git clone https//:github.com/dyama/siren.git

2. Setup the BAT script for your enviromnent.

    editor tool/occenv.bat
    
    SET "OCCBASE=E:\\occ" # Change this variable!
    
Example, Open CASCADE 6.6.0 installed on C:\opencascade\660;
    
    SET "OCCBASE=C:\\opencascade"
    
The path add the version string "660" automaticaly by script.
If your enviroment no matches this case, please link to
install path with symbolic link.

In the same way as;

    editor tool/mruby-vs9-occ660.bat

    SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"

Set MRUBYROOT to the path of mruby installed directory.

3. Run the BAT script file.

    start tool/mruby-vs9-occ660.bat

If you build siren on another environment, you can change
the script calling.

4. Build sirenenv.dll and siren.exe.

 Overviews
------------------------------------------------------------

* View a 3D model with mouse operation.
* Save to another 3D CAD file format.

 Usage
------------------------------------------------------------

You can run follows as;

    > siren.exe [filename]

Now, siren is able to read formats as follows;

* IGES format
* OpenCASCADE BREP format
* STEP format

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

