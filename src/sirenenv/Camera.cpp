#include "stdafx.h"
#include "Camera.h"

namespace sirenenv {

    Camera::Camera(sirenenv::World* aWorld, HWND aWindowHandle, bool persepective)
    {
        myWorld = aWorld;

        if (aWorld->GetContext().IsNull())
            return;

        myView = aWorld->GetContext()->CurrentViewer()->CreateView();

        // ウィンドウとのマッピング
        Handle(WNT_Window) aWNTWindow = new WNT_Window(aWindowHandle);
        myView->SetWindow(aWNTWindow);
        if (!aWNTWindow->IsMapped()) {
            aWNTWindow->Map();
        }

        // View に対するカラー設定
        Quantity_Color color_top(0.00, 0.00, 0.00, Quantity_TOC_RGB);
        Quantity_Color color_btm(0.20, 0.30, 0.45, Quantity_TOC_RGB);
        myView->SetBgGradientColors(color_top, color_btm, Aspect_GFM_VER, Standard_False);

        // トライヘドロン(画面上のXYZ軸表示器)を表示
        myView->TriedronDisplay(Aspect_TOTP_RIGHT_UPPER, Quantity_NOC_WHITE, 0.1, V3d_ZBUFFER);

        // アンチエイリアスの有効
        myView->SetAntialiasingOn();

#if 0
        { // レイヤーのテスト
            Standard_Integer w,h;
            Handle(Aspect_Window) hWin = myView->Window();
            hWin->Size(w,h);
            Handle(Visual3d_Layer) myLayer
                = new Visual3d_Layer(myView->View()->ViewManager(), Aspect_TOL_OVERLAY, Standard_False);

            myLayer->Clear();
            myLayer->SetViewport(w, h);
            // myLayer->SetOrtho(0, w, h, 0, Aspect_TypeOfConstraint-1);
            myLayer->SetOrtho(0, w, h, 0, Aspect_TOC_TOP_LEFT);


            // then you could draw on the given layer
            myLayer->Begin();

            myLayer->SetTransparency(0.5);

            //myLayer->DrawText((Standard_CString)"A", 0.0, 0.0, 40.0);

            glEnable(GL_TEXTURE_2D);
            // LoadGLTextures();
            Standard_Integer X, Y;
            X = 10.0; Y = 15.0;
            // myView->Convert(200, 140, 200, X, Y) ;
            // draw a polyline
            myLayer->BeginPolygon();
            glTexCoord2f(0.0f, 1.0f); myLayer->AddVertex(X, Y, Standard_False);
            glTexCoord2f(1.0f, 1.0f); myLayer->AddVertex(X, Y+20);
            glTexCoord2f(1.0f, 0.0f); myLayer->AddVertex(X+100, Y+20);
            glTexCoord2f(0.0f, 0.0f); myLayer->AddVertex(X+100, Y);
            myLayer->ClosePrimitive();     
            glDisable(GL_TEXTURE_2D);

            // and close the layer and redraw
            myLayer->End();

            myView->Redraw();
        }
#endif

        return;
    }

    bool Camera::Dump(char *theFileName)
    {
        myView->Redraw();
        return myView->Dump(theFileName) != Standard_False;
    }

    void Camera::Redraw(void)
    {
        myView->Redraw();
    }

    void Camera::MustBeResized(void)
    {
        myView->MustBeResized();
    }

    void Camera::SetComputedMode(bool value)
    {
        myView->SetComputedMode(value ? Standard_True : Standard_False);
    }

    void Camera::WindowFitAll(int xmin, int ymin, int xmax, int ymax)
    {
        myView->WindowFitAll(xmin, ymin, xmax, ymax);
    }

    void Camera::Place(int x, int y, float theZoomFactor)
    {	
        myView->Place(x, y, (Quantity_Factor)theZoomFactor);
    }

    void Camera::Zoom(int x1, int y1, int x2, int y2)
    {
        myView->Zoom(x1, y1, x2, y2);
    }

    void Camera::Pan(int x, int y)
    {
        myView->Pan(x, y);
    }

    void Camera::Rotation(int x, int y)
    {
        myView->Rotation(x, y);
    }

    void Camera::StartRotation(int x, int y)
    {
        myView->StartRotation(x, y);
    }

    void Camera::Select(int x1, int y1, int x2, int y2)
    {
        myWorld->GetContext()->Select(x1, y1, x2, y2, myView);
    }

    void Camera::Select(void)
    {
        myWorld->GetContext()->Select();
    }

    void Camera::MoveTo(int x, int y)
    {
        myWorld->GetContext()->MoveTo(x, y, myView);
    }

    void Camera::ShiftSelect(int x1, int y1, int x2, int y2)
    {
        myWorld->GetContext()->ShiftSelect(x1, y1, x2, y2, myView);
    }

    void Camera::ShiftSelect(void)
    {
        myWorld->GetContext()->ShiftSelect();
    }

    void Camera::FrontView(void)
    {
        myView->SetProj(V3d_Xpos);
    }

    void Camera::TopView(void)
    {
        myView->SetProj(V3d_Zpos);
    }

    void Camera::LeftView(void)
    {
        myView->SetProj(V3d_Ypos);
    }

    void Camera::BackView(void)
    {
        myView->SetProj(V3d_Xneg);
    }

    void Camera::RightView(void)
    {
        myView->SetProj(V3d_Yneg);
    }

    void Camera::BottomView(void)
    {
        myView->SetProj(V3d_Zneg);
    }

    void Camera::AxoView(void)
    {
        myView->SetProj(V3d_XposYnegZpos);
    }

    float Camera::Scale(void)
    {
        return (float)myView->Scale();
    }

    void Camera::SetScale(float val)
    {
        myView->SetScale(val);
    }

    void Camera::ZoomAllView(void)
    {
        myView->FitAll();
        myView->ZFitAll();
    }

    void Camera::Reset(void)
    {
        myView->Reset();
    }

    void Camera::SetBackgroundColor(int R, int G, int B)
    {
        myView->SetBackgroundColor(Quantity_TOC_RGB, R/255.,G/255.,B/255.);
    }

    void Camera::BackgroundColor(int& R, int& G, int& B)
    {
        Standard_Real R1;
        Standard_Real G1;
        Standard_Real B1;
        myView->BackgroundColor(Quantity_TOC_RGB, R1, G1, B1);
        R = (int)R1*255;
        G = (int)G1*255;
        B = (int)B1*255;
    }

    namespace RCamera {

        mrb_value initialize(mrb_state* mrb, mrb_value self)
        {
            // Initialize data type first, otherwise segmentation fault occurs.
            DATA_TYPE(self) = &cppclassdeftype;
            DATA_PTR(self) = NULL;

            mrb_value world;
            mrb_int hwnd;
            mrb_bool pers;
            int argc = mrb_get_args(mrb, "oib", &world, &hwnd, &pers);


            // struct mrb_data_type t = { "World", RWorld::cleenup };
            // void* vp = mrb_get_datatype(mrb, world, &t);
            // World* w = static_cast<World*>(vp);
            // World* w = static_cast<World*>(mrb_get_datatype(mrb, world, &RWorld::cppclassdeftype));

            void* vp = mrb_get_datatype(mrb, world, &(RWorld::dt));
            World* w = static_cast<World*>(vp);

            // Camera* p = new Camera(w, (HWND)hwnd, pers != 0);
            Camera* p = NULL;

            DATA_PTR(self) = p;
            return self;
        }

        void cleenup(mrb_state* mrb, void* ptr)
        {
            Camera* p = static_cast<Camera*>(ptr);
            delete p;
        }

        mrb_value to_s(mrb_state* mrb, mrb_value self)
        {
            Camera* me = static_cast<Camera*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            char buf[32];
            _snprintf_s(buf, sizeof(buf), "#Camera<%d>", &me);
            return mrb_str_new_cstr(mrb, buf);
        }

        // ---

        // ---

        void install(mrb_state* mrb)
        {
            struct RClass *tc = mrb_define_class(mrb, "Camera", mrb->object_class);
            MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);

            mrb_define_method(mrb, tc, "initialize", initialize, ARGS_REQ(3));
            mrb_define_method(mrb, tc, "inspect", to_s, ARGS_NONE());
            mrb_define_method(mrb, tc, "to_s", to_s, ARGS_NONE());
        }

    }

}