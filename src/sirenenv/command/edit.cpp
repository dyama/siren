/**
 * \brief Edit commands
 * THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

#include "Stdafx.h"

/**
 * \brief Erase object
 */
mrb_value erase(mrb_state* mrb, mrb_value self)
{
    mrb_int target;
	int argc = mrb_get_args(mrb, "i", &target);

	::unset(target);
	return mrb_nil_value();
}

/**
 * \brief copy object
 */
mrb_value copy(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}

	// Deep copy
	BRepBuilderAPI_Copy Builder;
	Builder.Perform(hashape->Shape());
	TopoDS_Shape shape = Builder.Shape();

	return mrb_fixnum_value(::set(shape));
}

/**
 * \brief close wire / edge object
 */
mrb_value close(mrb_state* mrb, mrb_value self)
{
	mrb_int src;
	int argc = mrb_get_args(mrb, "i", &src);

	Handle(AIS_Shape) hashape = ::get(src);
	if (hashape.IsNull()) {
		static const char m[] = "No such specified object.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopAbs_ShapeEnum se = hashape->Shape().ShapeType();
	if ( se != TopAbs_WIRE && se != TopAbs_EDGE && se != TopAbs_COMPOUND ) {
		static const char m[] = "Failed to make a closed wire.";
        return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	TopoDS_Shape shape;
	TopoDS_Shape sThis = hashape->Shape();
	try {
		BRepBuilderAPI_MakeWire mw;
		// find first point
		BRepAdaptor_Curve ac;
		gp_Pnt sp, ep;
		TopExp_Explorer exp( sThis, TopAbs_EDGE );
		double tol = 0.01;
		TopoDS_Edge e = TopoDS::Edge( exp.Current() );
		ac.Initialize( e );
		sp = ac.Value( ac.FirstParameter() );
		ep = ac.Value( ac.LastParameter() );
		mw.Add( e );
		if ( e.Orientation() == TopAbs_REVERSED ) sp = ep;
		//find last point
		int count = 0;
		for ( ; exp.More(); exp.Next() )
		{
			if ( exp.Current().IsNull() ) continue;
			e = TopoDS::Edge( exp.Current() );
			mw.Add( e );
			ac.Initialize( e );
			if (e.Orientation() == TopAbs_FORWARD )
				ep = ac.Value( ac.LastParameter() );
			else if (e.Orientation() == TopAbs_REVERSED )
				ep = ac.Value( ac.FirstParameter() );
		}
		if ( !sp.IsEqual( ep, tol ) ) {
			e = BRepBuilderAPI_MakeEdge( ep, sp );
			mw.Add(e);
		}
		ShapeFix_Wire sfw;
		sfw.Load( mw.Wire() );
		sfw.FixClosed();
		shape = sfw.Wire();
		if ( shape.IsNull() )
		{
			static const char m[] = "Failed to make a closed wire.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a closed wire.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(shape));
#if 0

        double qTolerance = 0.1e-3;

	Handle( ShapeExtend_WireData ) wd1 = new ShapeExtend_WireData(); //バッファ1
	gp_Pnt wsp,wep; //全体の終始点
	gp_Pnt sp,ep; //点
	gp_Pnt sp2,ep2; //点
	BRepAdaptor_Curve c1, c2; //カーブ
	int is = 0; //最初のEdgeのIndex
	int ie = 0;
	int num = 0; //エッジ総数
	int all = 0; //中線の数
	int hit = 0; //片方が繋がっていないEdgeの数
	bool fs, fe; //繋がっているかのフラグ

	//まずは全体の終始点を取得
	for ( TopExp_Explorer exp(sThis, TopAbs_EDGE ); exp.More(); exp.Next() )
	{
		TopoDS_Edge e = TopoDS::Edge(exp.Current());
		fs = false;
		fe = false;
		c1.Initialize( e );
		sp = c1.Value(c1.FirstParameter());
		ep = c1.Value(c1.LastParameter());
		for ( TopExp_Explorer exp2(sThis, TopAbs_EDGE ); exp2.More(); exp2.Next() )
		{
			//自身以外を検査
			if ( !e.IsEqual(exp2.Current()) )
			{
				const TopoDS_Edge e2 = TopoDS::Edge(exp2.Current());
				c2.Initialize( e2 );
				sp2 = c2.Value(c2.FirstParameter());
				ep2 = c2.Value(c2.LastParameter());
				if ( sp.IsEqual( sp2, qTolerance ) || sp.IsEqual( ep2, qTolerance ) ) fs = true;
				if ( ep.IsEqual( sp2, qTolerance ) || ep.IsEqual( ep2, qTolerance ) ) fe = true;
				if ( fs && fe ) { all++; break; }
			}
		}
		
		if (hit < 2 && ((!fs && fe) || (fs && !fe)) )
		{// hitカウンタが2未満なら設定
			if (!hit) {
				if (!fs && fe) wsp = sp; else wsp = ep; 
				is = num;
				hit++;
			} else {
				if (!fs && fe) wep = sp; else wep = ep; 
				ie = num;
				hit++;
			}
		}

		// 1本以外で独立したedgeの場合error
		if (num && !fs && !fe)
		{
            printf("");;
		}
		num++;
		e.Orientation( TopAbs_FORWARD ); //向きを統一しておく
		wd1->Add(e);
	}

	//総数が一本だけの場合はそのままセット
	if( num == 1 )
	{
        printf("");;
	}
	
	//修正点がない場合は閉区画として適当な位置から探す
	if( hit < 1 && num == all ) { wsp = sp; is = num; }

	//最初のEdgeを取得
	TopoDS_Edge se = wd1->Edge(is + 1); //!! OCCの要素は1からカウント !!
	num = wd1->NbEdges() - 1;
	BRepAdaptor_Curve sc( se );
	sp = sc.Value(sc.FirstParameter());
	ep = sc.Value(sc.LastParameter());
	//FirstParameterと始点が反転してたら逆にする
	if ( !wsp.IsEqual( sp, qTolerance ) && wsp.IsEqual( ep, qTolerance ) )
	{
		if (se.Orientation() == TopAbs_FORWARD )
		{
			se.Orientation( TopAbs_REVERSED );
		} else {
			se.Orientation( TopAbs_FORWARD );
		}
		gp_Pnt bak = sp;
		sp = ep;
		ep = bak;
	}
	Handle( ShapeExtend_WireData ) wd2 = new ShapeExtend_WireData(); //バッファ2
	wd2->Add( se, 1 );
	bool r; //エッジの反転フラグ
	bool h;
	hit = 0;
	//連続性のある順番で格納していく
	while ( num > 0 )
	{
		for ( int i=1; i <= wd1->NbEdges(); i++ )
		{
			r = false;
			h = false;
			TopoDS_Edge e = wd1->Edge( i );
			if ( !wd2->Index(e) )
			{ //すでに格納したエッジ以外を検査
				c1.Initialize( e );
				sp2 = c1.Value(c1.FirstParameter());
				ep2 = c1.Value(c1.LastParameter());
				if ( ep.IsEqual( sp2, qTolerance ) ) { h = true; }
				else if ( ep.IsEqual( ep2, qTolerance ) )	{ h = true; r = true; }

				if (h) //見つかった
				{
					if (r)
					{ //反転処理
						e.Orientation( TopAbs_REVERSED );
						gp_Pnt bak = sp2;
						sp2 = ep2;
						ep2 = bak;
					} 
					cout << sp.X() << "\t" << sp.Y() << "\t" << sp.Z() << endl;
					cout << ep.X() << "\t" << ep.Y() << "\t" << ep.Z() << "\t" << e.Orientation() << "\t" << r << endl;

					wd2->Add( e ); //バッファに追加
					sp = sp2;	//次に検査する値にセット
					ep = ep2;
					num--; //ひとつ減らす
					break; //for文を抜ける
				}
			}
		}
	hit++;
	if ( hit > 10 ) break; //無限ループ解除
	}
	shape = wd2->Wire();
	if ( shape.IsNull() )
		{
			static const char m[] = "Failed to make a closed wire.";
			return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
		}
	}	catch (...) {
		static const char m[] = "Failed to make a closed wire.";
		return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
	}
	return mrb_fixnum_value(::set(shape));
#endif
}