#include "stdafx.h"
#include "World.h"

namespace sirenenv {

    World::World(void)
    {
        myGraphicDriver = NULL;
        myViewer = NULL;
        myContext = NULL;
        Init();
    }

    bool World::Init(void)
    {
        try {
            // OpenGL グラフィックドライバーを作成
            Handle(Aspect_DisplayConnection) dc;
            myGraphicDriver = new OpenGl_GraphicDriver(dc);
        }
        catch (Standard_Failure) {
            return false;
        }

        // Viewer(三次元空間)を作成
        TCollection_ExtendedString worldname("WorldOfSiren");

        myViewer = new V3d_Viewer(
            myGraphicDriver,          // ドライバー
            worldname.ToExtString(),  // 名前
            "",                       // ドメイン
            1000.0,                   // サイズ
            V3d_XposYnegZpos,         // 軸方向
            Quantity_NOC_GRAY30,      // デフォルト背景色
            V3d_ZBUFFER,              // ビジュアル設定
            V3d_GOURAUD,              // 陰影種別
            V3d_WAIT,                 // アップデート種別
            Standard_True,            // 計算モード
            Standard_False,           // デフォルト計算モード
            V3d_TEX_NONE              // サーフェスディティール種別
            );

        // 照明設定
        myViewer->SetDefaultLights();
        myViewer->SetLightOn();

        // ViewerにAISコンテキスト(形状表現の管理機構)を作成
        myContext = new AIS_InteractiveContext(myViewer);

        // 選択色・ハイライト色
        myContext->SetHilightColor(Quantity_NOC_YELLOW);
        myContext->SelectionColor(Quantity_NOC_RED);

        // grid
        {
            gp_Pnt p(0, 0, 0);
            gp_Vec v(0, 0, 1);
            gp_Ax3 ax(p, v);
            Quantity_Length XOrigin = 0;
            Quantity_Length YOrigin = 0;
            Quantity_Length XStep = 10;
            Quantity_Length YStep = 10;
            Quantity_Length Rotation = 0;
            Quantity_Length XSize = XStep * 20 + 1.0e-7;
            Quantity_Length YSize = YStep * 20 + 1.0e-7;
            Quantity_Length Offset = 0;
            myViewer->SetPrivilegedPlane(ax);
            myViewer->SetRectangularGridValues(XOrigin, YOrigin, XStep, YStep, Rotation);
            myViewer->SetRectangularGridGraphicValues(XSize, YSize, Offset);
            myViewer->ActivateGrid(Aspect_GT_Rectangular, Aspect_GDM_Lines);
        }

        // Viewer を更新
        myContext->UpdateCurrentViewer();

        return true;
    }

    void World::UpdateWorld(void)
    {
        myContext->UpdateCurrentViewer();
    }

    void World::EraseObjects(void)
    {
        for(myContext->InitCurrent(); myContext->MoreCurrent(); myContext->NextCurrent()) {
            myContext->Erase(myContext->Current(), Standard_True);
        }
        myContext->ClearCurrents();
    }

    bool World::IsObjectSelected(void)
    {
        myContext->InitCurrent();
        return myContext->MoreCurrent() != Standard_False;
    }

    Handle(AIS_InteractiveContext) World::GetContext(void)
    {
        return myContext;
    }

    // Boolean World::Add(seabox::occ::VShape^ aVShape)
    // {
    //     Handle(AIS_Shape) hashape = *(aVShape->Get());
    // 	myContext()->SetMaterial(hashape, Graphic3d_NOM_DEFAULT);
    // 	myContext()->SetDisplayMode(hashape, 1, Standard_False);
    //     myContext()->Display(hashape, 1);
    //     myContext()->Activate(hashape);
    //     return true;
    // }


    namespace RWorld {

        mrb_value initialize(mrb_state* mrb, mrb_value self)
        {
            // Initialize data type first, otherwise segmentation fault occurs.
            DATA_TYPE(self) = &cppclassdeftype;
            DATA_PTR(self) = NULL;

            World* p = new World();

            DATA_PTR(self) = p;
            return self;
        }

        void cleenup(mrb_state* mrb, void* ptr)
        {
            World* p = static_cast<World*>(ptr);
            delete p;
        }

        mrb_value to_s(mrb_state* mrb, mrb_value self)
        {
            World* me = static_cast<World*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            char buf[32];
            _snprintf_s(buf, sizeof(buf), "#World<%d>", &me);
            return mrb_str_new_cstr(mrb, buf);
        }

        // ---

        mrb_value init(mrb_state* mrb, mrb_value self)
        {
            World* me = static_cast<World*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            me->Init();
            return mrb_nil_value();
        }

        mrb_value updateworld(mrb_state* mrb, mrb_value self)
        {
            World* me = static_cast<World*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            me->UpdateWorld();
            return mrb_nil_value();
        }

        mrb_value eraseobjects(mrb_state* mrb, mrb_value self)
        {
            World* me = static_cast<World*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            me->EraseObjects();
            return mrb_nil_value();
        }

        mrb_value isobjectselected(mrb_state* mrb, mrb_value self)
        {
            World* me = static_cast<World*>(mrb_get_datatype(mrb, self, &cppclassdeftype));
            mrb_bool res = me->IsObjectSelected() ? TRUE : FALSE;
            return mrb_bool_value(res);
        }

        // ---

        void install(mrb_state* mrb)
        {
            struct RClass *tc = mrb_define_class(mrb, "World", mrb->object_class);
            MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);

            mrb_define_method(mrb, tc, "initialize", initialize, ARGS_NONE());
            mrb_define_method(mrb, tc, "inspect", to_s, ARGS_NONE());
            mrb_define_method(mrb, tc, "to_s", to_s, ARGS_NONE());

            mrb_define_method(mrb, tc, "init", init, ARGS_NONE());
            mrb_define_method(mrb, tc, "updateworld", updateworld, ARGS_NONE());
            mrb_define_method(mrb, tc, "eraseobjects", eraseobjects, ARGS_NONE());
            mrb_define_method(mrb, tc, "isobjectselected", isobjectselected, ARGS_NONE());
        }

    }

}