#pragma once
#include "World.h"

namespace sirenenv {

	class Camera
	{

    protected:
        World* myWorld;
        Handle(V3d_View) myView;

    public:
        Camera(sirenenv::World* aWorld, HWND theWnd, bool persepective);

    public:
        bool  Dump(char *theFileName);
        void  Redraw(void);
        void  MustBeResized(void);
        void  SetComputedMode(bool value);
        void  WindowFitAll(int xmin, int ymin, int xmax, int ymax);
        void  Place(int x, int y, float theZoomFactor);
        void  Zoom(int x1, int y1, int x2, int y2);
        void  Pan(int x, int y);
        void  Rotation(int x, int y);
        void  StartRotation(int x, int y);

        void  Select(int x1, int y1, int x2, int y2);
        void  Select(void);
        void  MoveTo(int x, int y);
        void  ShiftSelect(int x1, int y1, int x2, int y2);
        void  ShiftSelect(void);

        void  FrontView(void);
        void  TopView(void);
        void  LeftView(void);
        void  BackView(void);
        void  RightView(void);
        void  BottomView(void);
        void  AxoView(void);

        float Scale(void);
        void  SetScale(float);
        void  ZoomAllView(void);
        void  Reset(void);

        void  SetBackgroundColor(int R, int G, int B);
        void  BackgroundColor(int& R, int& G, int& B);

    };

    namespace RCamera {
        void cleenup(mrb_state* mrb, void *ptr);
        static struct mrb_data_type cppclassdeftype = { "Camera", RCamera::cleenup };
        mrb_value initialize(mrb_state* mrb, mrb_value self);
        // ---
        mrb_value to_s(mrb_state* mrb, mrb_value self);
        // ---
        void install(mrb_state* mrb);
    }
}
