/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
* WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
* IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
* ---------------------------------------------------------
* AUTHOR: dyama <dyama@member.fsf.org>
*/

#pragma once

#using <mscorlib.dll>
#include "OCCViewer.h"
#include "World.h"
#include "Camera.h"
#include "dotnettype.h"

using namespace System::Runtime::InteropServices;

namespace sirenenv
{
    public ref class Viewer
    {

    private:
        OCCViewer* myOCCViewer;

    protected:
        sirenenv::Camera* myCamera;
        sirenenv::World*  myWorld;

    public:

        Viewer()
        {
            myOCCViewer = NULL;
            myCamera    = NULL;
            myWorld     = NULL;
            return;
        }

        bool InitViewer(System::IntPtr wnd, bool grad, bool is_raytracing, bool is_persepective)
        {
            if (myOCCViewer != NULL)
                return myOCCViewer->InitViewer(wnd.ToPointer(), grad, is_raytracing, is_persepective);
            else
                return false;
        }

        void Redraw(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Redraw();
        }

        void Redraw(int x, int y, int w, int h)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->Redraw(x, y, w, h);
        }

        void MustBeResized(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->MustBeResized();
        }

        void SetComputedMode(bool value)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetComputedMode(value);
        }

        void WindowFitAll(int Xmin, int Ymin, int Xmax, int Ymax)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->WindowFitAll(Xmin, Ymin, Xmax, Ymax);
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

        void ZFitAll(void)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->ZFitAll();
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

        void SetAntialiasing(bool isOn)
        {
            if (myOCCViewer != NULL)
                myOCCViewer->SetAntialiasing(isOn);
        }

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

            char cmd[102400] = {0}; // one line

            for (int i=0; i<str->Length; i++) {
                cmd[i] = (char)str->ToCharArray()[i];
            }

            std::string _errmsg;
#if 1
            int res = myOCCViewer->mruby_exec(cmd, _errmsg);
#else
            cur = myOCCViewer;
            int res = myOCCViewer->myMirb->user_exec(cmd, _errmsg);
#endif

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
