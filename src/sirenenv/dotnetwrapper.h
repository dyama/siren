/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
* WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
* IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
* ---------------------------------------------------------
* AUTHOR: dyama <dyama@member.fsf.org>
*/

#pragma once

#using <mscorlib.dll>
#include "OCCViewer.h"

namespace sirenenv
{
    public enum class NameOfMaterial {
        BRASS,			// 真鍮
        BRONZE,         // 青銅
        COPPER,         // 銅
        GOLD,           // 金
        PEWTER,         // スズ
        PLASTER,        // 石膏
        PLASTIC,        // プラスチック
        SILVER,         // 銀
        STEEL,          // スチール
        STONE,          // 石
        SHINY_PLASTIC,  // 光沢のあるプラスチック
        SATIN,          // サテン
        METALIZED,      // メタライズ
        NEON_GNC,       // ネオンGNC
        CHROME,         // クロム
        ALUMINIUM,      // アルミニウム
        OBSIDIAN,       // 黒曜石
        NEON_PHC,       // ネオンPHC
        JADE,           // ヒスイ
        DEFAULT,        // デフォルト
        UserDefined     // ユーザー定義
    };

    public enum class TypeOfOrientation {
        Xpos,
        Ypos,
        Zpos,
        Xneg,
        Yneg,
        Zneg,
        XposYpos,
        XposZpos,
        YposZpos,
        XnegYneg,
        XnegYpos,
        XnegZneg,
        XnegZpos,
        YnegZneg,
        YnegZpos,
        XposYneg,
        XposZneg,
        YposZneg,
        XposYposZpos,
        XposYnegZpos,
        XposYposZneg,
        XnegYposZpos,
        XposYnegZneg,
        XnegYposZneg,
        XnegYnegZpos,
        XnegYnegZneg
    };

    public enum class NameOfColor {
        BLACK,
        MATRABLUE,
        MATRAGRAY,
        ALICEBLUE,
        ANTIQUEWHITE,
        ANTIQUEWHITE1,
        ANTIQUEWHITE2,
        ANTIQUEWHITE3,
        ANTIQUEWHITE4,
        AQUAMARINE1,
        AQUAMARINE2,
        AQUAMARINE4,
        AZURE,
        AZURE2,
        AZURE3,
        AZURE4,
        BEIGE,
        BISQUE,
        BISQUE2,
        BISQUE3,
        BISQUE4,
        BLANCHEDALMOND,
        BLUE1,
        BLUE2,
        BLUE3,
        BLUE4,
        BLUEVIOLET,
        BROWN,
        BROWN1,
        BROWN2,
        BROWN3,
        BROWN4,
        BURLYWOOD,
        BURLYWOOD1,
        BURLYWOOD2,
        BURLYWOOD3,
        BURLYWOOD4,
        CADETBLUE,
        CADETBLUE1,
        CADETBLUE2,
        CADETBLUE3,
        CADETBLUE4,
        CHARTREUSE,
        CHARTREUSE1,
        CHARTREUSE2,
        CHARTREUSE3,
        CHARTREUSE4,
        CHOCOLATE,
        CHOCOLATE1,
        CHOCOLATE2,
        CHOCOLATE3,
        CHOCOLATE4,
        CORAL,
        CORAL1,
        CORAL2,
        CORAL3,
        CORAL4,
        CORNFLOWERBLUE,
        CORNSILK1,
        CORNSILK2,
        CORNSILK3,
        CORNSILK4,
        CYAN1,
        CYAN2,
        CYAN3,
        CYAN4,
        DARKGOLDENROD,
        DARKGOLDENROD1,
        DARKGOLDENROD2,
        DARKGOLDENROD3,
        DARKGOLDENROD4,
        DARKGREEN,
        DARKKHAKI,
        DARKOLIVEGREEN,
        DARKOLIVEGREEN1,
        DARKOLIVEGREEN2,
        DARKOLIVEGREEN3,
        DARKOLIVEGREEN4,
        DARKORANGE,
        DARKORANGE1,
        DARKORANGE2,
        DARKORANGE3,
        DARKORANGE4,
        DARKORCHID,
        DARKORCHID1,
        DARKORCHID2,
        DARKORCHID3,
        DARKORCHID4,
        DARKSALMON,
        DARKSEAGREEN,
        DARKSEAGREEN1,
        DARKSEAGREEN2,
        DARKSEAGREEN3,
        DARKSEAGREEN4,
        DARKSLATEBLUE,
        DARKSLATEGRAY1,
        DARKSLATEGRAY2,
        DARKSLATEGRAY3,
        DARKSLATEGRAY4,
        DARKSLATEGRAY,
        DARKTURQUOISE,
        DARKVIOLET,
        DEEPPINK,
        DEEPPINK2,
        DEEPPINK3,
        DEEPPINK4,
        DEEPSKYBLUE1,
        DEEPSKYBLUE2,
        DEEPSKYBLUE3,
        DEEPSKYBLUE4,
        DODGERBLUE1,
        DODGERBLUE2,
        DODGERBLUE3,
        DODGERBLUE4,
        FIREBRICK,
        FIREBRICK1,
        FIREBRICK2,
        FIREBRICK3,
        FIREBRICK4,
        FLORALWHITE,
        FORESTGREEN,
        GAINSBORO,
        GHOSTWHITE,
        GOLD,
        GOLD1,
        GOLD2,
        GOLD3,
        GOLD4,
        GOLDENROD,
        GOLDENROD1,
        GOLDENROD2,
        GOLDENROD3,
        GOLDENROD4,
        GRAY,
        GRAY0,
        GRAY1,
        GRAY10,
        GRAY11,
        GRAY12,
        GRAY13,
        GRAY14,
        GRAY15,
        GRAY16,
        GRAY17,
        GRAY18,
        GRAY19,
        GRAY2,
        GRAY20,
        GRAY21,
        GRAY22,
        GRAY23,
        GRAY24,
        GRAY25,
        GRAY26,
        GRAY27,
        GRAY28,
        GRAY29,
        GRAY3,
        GRAY30,
        GRAY31,
        GRAY32,
        GRAY33,
        GRAY34,
        GRAY35,
        GRAY36,
        GRAY37,
        GRAY38,
        GRAY39,
        GRAY4,
        GRAY40,
        GRAY41,
        GRAY42,
        GRAY43,
        GRAY44,
        GRAY45,
        GRAY46,
        GRAY47,
        GRAY48,
        GRAY49,
        GRAY5,
        GRAY50,
        GRAY51,
        GRAY52,
        GRAY53,
        GRAY54,
        GRAY55,
        GRAY56,
        GRAY57,
        GRAY58,
        GRAY59,
        GRAY6,
        GRAY60,
        GRAY61,
        GRAY62,
        GRAY63,
        GRAY64,
        GRAY65,
        GRAY66,
        GRAY67,
        GRAY68,
        GRAY69,
        GRAY7,
        GRAY70,
        GRAY71,
        GRAY72,
        GRAY73,
        GRAY74,
        GRAY75,
        GRAY76,
        GRAY77,
        GRAY78,
        GRAY79,
        GRAY8,
        GRAY80,
        GRAY81,
        GRAY82,
        GRAY83,
        GRAY85,
        GRAY86,
        GRAY87,
        GRAY88,
        GRAY89,
        GRAY9,
        GRAY90,
        GRAY91,
        GRAY92,
        GRAY93,
        GRAY94,
        GRAY95,
        GREEN,
        GREEN1,
        GREEN2,
        GREEN3,
        GREEN4,
        GREENYELLOW,
        GRAY97,
        GRAY98,
        GRAY99,
        HONEYDEW,
        HONEYDEW2,
        HONEYDEW3,
        HONEYDEW4,
        HOTPINK,
        HOTPINK1,
        HOTPINK2,
        HOTPINK3,
        HOTPINK4,
        INDIANRED,
        INDIANRED1,
        INDIANRED2,
        INDIANRED3,
        INDIANRED4,
        IVORY,
        IVORY2,
        IVORY3,
        IVORY4,
        KHAKI,
        KHAKI1,
        KHAKI2,
        KHAKI3,
        KHAKI4,
        LAVENDER,
        LAVENDERBLUSH1,
        LAVENDERBLUSH2,
        LAVENDERBLUSH3,
        LAVENDERBLUSH4,
        LAWNGREEN,
        LEMONCHIFFON1,
        LEMONCHIFFON2,
        LEMONCHIFFON3,
        LEMONCHIFFON4,
        LIGHTBLUE,
        LIGHTBLUE1,
        LIGHTBLUE2,
        LIGHTBLUE3,
        LIGHTBLUE4,
        LIGHTCORAL,
        LIGHTCYAN1,
        LIGHTCYAN2,
        LIGHTCYAN3,
        LIGHTCYAN4,
        LIGHTGOLDENROD,
        LIGHTGOLDENROD1,
        LIGHTGOLDENROD2,
        LIGHTGOLDENROD3,
        LIGHTGOLDENROD4,
        LIGHTGOLDENRODYELLOW,
        LIGHTGRAY,
        LIGHTPINK,
        LIGHTPINK1,
        LIGHTPINK2,
        LIGHTPINK3,
        LIGHTPINK4,
        LIGHTSALMON1,
        LIGHTSALMON2,
        LIGHTSALMON3,
        LIGHTSALMON4,
        LIGHTSEAGREEN,
        LIGHTSKYBLUE,
        LIGHTSKYBLUE1,
        LIGHTSKYBLUE2,
        LIGHTSKYBLUE3,
        LIGHTSKYBLUE4,
        LIGHTSLATEBLUE,
        LIGHTSLATEGRAY,
        LIGHTSTEELBLUE,
        LIGHTSTEELBLUE1,
        LIGHTSTEELBLUE2,
        LIGHTSTEELBLUE3,
        LIGHTSTEELBLUE4,
        LIGHTYELLOW,
        LIGHTYELLOW2,
        LIGHTYELLOW3,
        LIGHTYELLOW4,
        LIMEGREEN,
        LINEN,
        MAGENTA1,
        MAGENTA2,
        MAGENTA3,
        MAGENTA4,
        MAROON,
        MAROON1,
        MAROON2,
        MAROON3,
        MAROON4,
        MEDIUMAQUAMARINE,
        MEDIUMORCHID,
        MEDIUMORCHID1,
        MEDIUMORCHID2,
        MEDIUMORCHID3,
        MEDIUMORCHID4,
        MEDIUMPURPLE,
        MEDIUMPURPLE1,
        MEDIUMPURPLE2,
        MEDIUMPURPLE3,
        MEDIUMPURPLE4,
        MEDIUMSEAGREEN,
        MEDIUMSLATEBLUE,
        MEDIUMSPRINGGREEN,
        MEDIUMTURQUOISE,
        MEDIUMVIOLETRED,
        MIDNIGHTBLUE,
        MINTCREAM,
        MISTYROSE,
        MISTYROSE2,
        MISTYROSE3,
        MISTYROSE4,
        MOCCASIN,
        NAVAJOWHITE1,
        NAVAJOWHITE2,
        NAVAJOWHITE3,
        NAVAJOWHITE4,
        NAVYBLUE,
        OLDLACE,
        OLIVEDRAB,
        OLIVEDRAB1,
        OLIVEDRAB2,
        OLIVEDRAB3,
        OLIVEDRAB4,
        ORANGE,
        ORANGE1,
        ORANGE2,
        ORANGE3,
        ORANGE4,
        ORANGERED,
        ORANGERED1,
        ORANGERED2,
        ORANGERED3,
        ORANGERED4,
        ORCHID,
        ORCHID1,
        ORCHID2,
        ORCHID3,
        ORCHID4,
        PALEGOLDENROD,
        PALEGREEN,
        PALEGREEN1,
        PALEGREEN2,
        PALEGREEN3,
        PALEGREEN4,
        PALETURQUOISE,
        PALETURQUOISE1,
        PALETURQUOISE2,
        PALETURQUOISE3,
        PALETURQUOISE4,
        PALEVIOLETRED,
        PALEVIOLETRED1,
        PALEVIOLETRED2,
        PALEVIOLETRED3,
        PALEVIOLETRED4,
        PAPAYAWHIP,
        PEACHPUFF,
        PEACHPUFF2,
        PEACHPUFF3,
        PEACHPUFF4,
        PERU,
        PINK,
        PINK1,
        PINK2,
        PINK3,
        PINK4,
        PLUM,
        PLUM1,
        PLUM2,
        PLUM3,
        PLUM4,
        POWDERBLUE,
        PURPLE,
        PURPLE1,
        PURPLE2,
        PURPLE3,
        PURPLE4,
        RED,
        RED1,
        RED2,
        RED3,
        RED4,
        ROSYBROWN,
        ROSYBROWN1,
        ROSYBROWN2,
        ROSYBROWN3,
        ROSYBROWN4,
        ROYALBLUE,
        ROYALBLUE1,
        ROYALBLUE2,
        ROYALBLUE3,
        ROYALBLUE4,
        SADDLEBROWN,
        SALMON,
        SALMON1,
        SALMON2,
        SALMON3,
        SALMON4,
        SANDYBROWN,
        SEAGREEN,
        SEAGREEN1,
        SEAGREEN2,
        SEAGREEN3,
        SEAGREEN4,
        SEASHELL,
        SEASHELL2,
        SEASHELL3,
        SEASHELL4,
        BEET,
        TEAL,
        SIENNA,
        SIENNA1,
        SIENNA2,
        SIENNA3,
        SIENNA4,
        SKYBLUE,
        SKYBLUE1,
        SKYBLUE2,
        SKYBLUE3,
        SKYBLUE4,
        SLATEBLUE,
        SLATEBLUE1,
        SLATEBLUE2,
        SLATEBLUE3,
        SLATEBLUE4,
        SLATEGRAY1,
        SLATEGRAY2,
        SLATEGRAY3,
        SLATEGRAY4,
        SLATEGRAY,
        SNOW,
        SNOW2,
        SNOW3,
        SNOW4,
        SPRINGGREEN,
        SPRINGGREEN2,
        SPRINGGREEN3,
        SPRINGGREEN4,
        STEELBLUE,
        STEELBLUE1,
        STEELBLUE2,
        STEELBLUE3,
        STEELBLUE4,
        TAN,
        TAN1,
        TAN2,
        TAN3,
        TAN4,
        THISTLE,
        THISTLE1,
        THISTLE2,
        THISTLE3,
        THISTLE4,
        TOMATO,
        TOMATO1,
        TOMATO2,
        TOMATO3,
        TOMATO4,
        TURQUOISE,
        TURQUOISE1,
        TURQUOISE2,
        TURQUOISE3,
        TURQUOISE4,
        VIOLET,
        VIOLETRED,
        VIOLETRED1,
        VIOLETRED2,
        VIOLETRED3,
        VIOLETRED4,
        WHEAT,
        WHEAT1,
        WHEAT2,
        WHEAT3,
        WHEAT4,
        WHITESMOKE,
        YELLOW,
        YELLOW1,
        YELLOW2,
        YELLOW3,
        YELLOW4,
        YELLOWGREEN,
        WHITE
    };

    public ref class Viewer
    {

    private:
        OCCViewer* myOCCViewer;
    public:

        bool InitViewer(System::IntPtr wnd, bool grad, bool is_raytracing, bool is_persepective)
        {
            if (myOCCViewer != NULL)
                return myOCCViewer->InitViewer(wnd.ToPointer(), grad, is_raytracing, is_persepective);
            else
                return false;
        }

        void RedrawView(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->RedrawView();
        }

        void UpdateView(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->UpdateView();
        }

        void SetDegenerateModeOn(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetDegenerateModeOn();
        }

        void SetDegenerateModeOff(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetDegenerateModeOff();
        }

        void WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->WindowFitAll(Xmin, Ymin, Xmax, Ymax);
        }

        void Place(int x, int y, float zoomFactor)
        {	
            if (myOCCViewer != NULL)
                myOCCViewer->Place(x, y, zoomFactor);
        }

        void Zoom(int x1, int y1, int x2, int y2)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Zoom(x1, y1, x2, y2);
        }

        void Pan(int x, int y)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Pan(x, y);
        }

        void Rotation(int x, int y)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Rotation(x, y);
        }

        void StartRotation(int x, int y)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->StartRotation(x, y);
        }

        void Select(int x1, int y1, int x2, int y2)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Select(x1, y1, x2, y2);
        }

        void Select(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Select();
        }

        void MoveTo(int x, int y)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->MoveTo(x, y);
        }

        void ShiftSelect(int x1, int y1, int x2, int y2)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->ShiftSelect(x1, y1, x2, y2);
        }

        void ShiftSelect(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->ShiftSelect();
        }

        int GetBGColR(void)
        {
            int r, b, g;
            if (myOCCViewer != NULL)
                myOCCViewer->BackgroundColor(r,g,b);
            return r;
        }

        int GetBGColG(void)
        {
            int r, b, g;
            if (myOCCViewer != NULL)
                myOCCViewer->BackgroundColor(r,g,b);
            return g;
        }

        int GetBGColB(void)
        {
            int r, b, g;
            if (myOCCViewer != NULL)
                myOCCViewer->BackgroundColor(r,g,b);
            return b;
        }

        void UpdateCurrentViewer(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->UpdateCurrentViewer();
        }

        void setProjection(TypeOfOrientation dir)
        {
            if (myOCCViewer != NULL) {
                V3d_TypeOfOrientation o = static_cast<V3d_TypeOfOrientation>(dir);
                myOCCViewer->setProjection(o);
            }
        }

        float Scale(void)
        {
            if (myOCCViewer != NULL)
                return myOCCViewer->Scale();
            else
                return -1;
        }

        void SetScale(double f)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->setScale(f);
        }

        void ZoomAllView(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->ZoomAllView();
        }

        void Reset(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->ResetView();
        }

        void SetDisplayMode(int aMode)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetDisplayMode(aMode);
        }

        int GetObjColR(void)
        {
            int r, g, b;
            if (myOCCViewer != NULL)
                myOCCViewer->ObjectColor(r, g, b);
            return r;
        }

        int GetObjColG(void)
        {
            int r, g, b;
            if (myOCCViewer != NULL)
                myOCCViewer->ObjectColor(r, g, b);
            return g;
        }

        int GetObjColB(void)
        {
            int r, g, b;
            if (myOCCViewer != NULL)
                myOCCViewer->ObjectColor(r, g, b);
            return b;
        }

        void SetBackgroundColor(int r, int g, int b)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetBackgroundColor(r, g, b);
        }

        void EraseObjects(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->EraseObjects();
        }

        float GetOCCVersion(void)
        {
            if (myOCCViewer == NULL)
                return 0.0;
            else
                return myOCCViewer->GetVersion();
        }

        void SetMaterial(int theMaterial)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetMaterial(theMaterial);
        }

        void SetTransparency(int TheTrans)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetTransparency(TheTrans);
        }

        void SetAntialiasing(bool isOn)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetAntialiasing(isOn);
        }
/*
        bool TranslateModel(System::String^ filename, int format, bool IsImport)
        {
            if (myOCCViewer == NULL)
                return false;

            int length = filename->Length;

            wchar_t* fname = new wchar_t[length+1];
            for(int i = 0; i<length; i++)
                fname[i] = (wchar_t)filename->ToCharArray()[i];

            fname[length] = L'\0';
            bool res;
            if (IsImport)
            {
                switch(format)
                {
                case 1:
                    res=myOCCViewer->ImportCsfdb(fname);
                    break;
                case 2:
                    res=myOCCViewer->ImportStep(fname);
                    break;
                case 3:
                    res=myOCCViewer->ImportIges(fname);
                    break;
                default:
                    res=false;
                }
            } else 
            {
                switch(format)
                {
                case 2:
                    res=myOCCViewer->ExportStep(fname);
                    break;
                case 3:
                    res=myOCCViewer->ExportIges(fname);
                    break;
                case 4:
                    res=myOCCViewer->ExportVrml(fname);
                    break;
                case 5:
                    res=myOCCViewer->ExportStl(fname);
                    break;
                case 6:
                    res=myOCCViewer->Dump(fname);
                    break;
                default:
                    res=false;
                }
            }
            delete [] fname;
            return res;
        }
*/
        bool IsObjectSelected(void)
        {
            if (myOCCViewer != NULL)
                return myOCCViewer->IsObjectSelected();
            else
                return false;
        }

        int NbSelected(void)
        {
            if (myOCCViewer != NULL)
                return myOCCViewer->NbSelected();
            else
                return false;
        }

        int DisplayMode(void)
        {
            if (myOCCViewer != NULL)
                return myOCCViewer->DisplayMode();
            else return -1;
        }

        void CreateNewView(System::IntPtr wnd, bool grad, bool is_raytracing)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->CreateNewView(wnd.ToPointer(), grad, is_raytracing);
        }

        bool SetAISContext(Viewer^ v)
        {
            if (myOCCViewer != NULL)
                return this->myOCCViewer->SetAISContext(v->GetOCCViewer());
            else
                return false;
        }

        OCCViewer* GetOCCViewer(void)
        {
            return myOCCViewer;
        }

        void InitOCCViewer(void)
        {
            myOCCViewer = new OCCViewer();
        }

        int CharToInt(System::String^ symbol)
        {
            if (myOCCViewer == NULL)
                return -1;
            char s = (char)symbol->ToCharArray()[0];
            return myOCCViewer->CharToInt(s);
        }

        void setHighlightColor(NameOfColor color)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetHighlightColor(static_cast<Quantity_NameOfColor>(color));
            return;
        }

        void setSelectionColor(NameOfColor color)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetSelectionColor(static_cast<Quantity_NameOfColor>(color));
            return;
        }

        // mruby

        int mruby_exec(System::String^ str,[System::Runtime::InteropServices::Out] System::String^% errmsg)
        {

            if (myOCCViewer == NULL || myOCCViewer->myMirb == NULL)
                return -1;

            char cmd[1024] = {0};

            for (int i=0; i<str->Length; i++) {
                cmd[i] = (char)str->ToCharArray()[i];
            }

            std::string _errmsg;
            int res = myOCCViewer->mruby_exec(cmd, _errmsg);

            errmsg = gcnew System::String(_errmsg.c_str());

            return res;
        }

        System::String^ mruby_p()
        {
            System::String^ result = System::String::Empty;

            if (!myOCCViewer)
                return result;

            std::string res;
            myOCCViewer->myMirb->p(1, res);	

            return gcnew System::String(res.c_str());
        }

        bool mruby_isCodeBlockOpen()
        {
            if (!myOCCViewer)
                return false;

            return myOCCViewer->myMirb->isCodeBlockOpen();
        }

        bool xy2xyz(int Xs, int Ys,
            [System::Runtime::InteropServices::Out] System::Double% X,
            [System::Runtime::InteropServices::Out] System::Double% Y,
            [System::Runtime::InteropServices::Out] System::Double% Z,
            bool usePrecision)
        {
            if (!myOCCViewer)
                return false;

            double xx, yy, zz;

            bool res = myOCCViewer->xy2xyz(Xs, Ys, xx, yy, zz, usePrecision);
            if (res) {
                X = xx; Y = yy; Z = zz;
                return true;
            }
            else 
                return false;
        }

    };

}
