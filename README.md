 siren - the simple CAD viewer
============================================================

![siren](http://dyama.org/siren/siren_screenshot.png "siren")

![siren raytracing rendering mode](http://dyama.org/wp-content/uploads/occt670-raytracing-sample-300x164.png "siren raytracing rendering mode")

 About siren
------------------------------------------------------------

siren is a simple CAD viewer for Microsoft Windows. siren
makes your some useful and quickly operations.

 How to build
------------------------------------------------------------

Building Equipment:

* Open CASCADE 6.7.0
* Microsoft Visual Studio 2008

1. Clone by git the repository of siren follows:

    git clone https//:github.com/dyama/siren.git

2. Setup the BAT script in tool directory for your enviromnent.
Set env-variable of OCCT and MRUBY installed path.

3. Run the BAT script file.

    start tool/mruby-vs9-occ670.bat

If you build siren on another environment, you can change
the script calling.

4. Build sirenenv.dll and siren.exe with Visual Studio.

 Overviews
------------------------------------------------------------

* View a 3D model with mouse operation.
* Command line based shape modifier.
* Load and save some format of 3D CAD file.

 Usage
------------------------------------------------------------

You can run follows as;

    > siren.exe [filename]

Now, siren is able to read formats as follows;

* IGES format
* OpenCASCADE BREP format
* STEP format
* CSFDB format

 Thirdparty technorogies
------------------------------------------------------------

* Open CASCADE Technorogy by Open CASCADE S.A.S.
* ISO C9x compliant stdint.h for Visual Studio by Alexander Chemeris.
* mruby by Ruby Association

 License
------------------------------------------------------------

MIT License

 Author
------------------------------------------------------------
Main maintener:
    dyama, Daisuke YAMAGUCHI <dyama@member.fsf.org>

Debug and sub maintener:
    kuyon

