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

	Handle( ShapeExtend_WireData ) wd1 = new ShapeExtend_WireData(); //�o�b�t�@1
	gp_Pnt wsp,wep; //�S�̂̏I�n�_
	gp_Pnt sp,ep; //�_
	gp_Pnt sp2,ep2; //�_
	BRepAdaptor_Curve c1, c2; //�J�[�u
	int is = 0; //�ŏ���Edge��Index
	int ie = 0;
	int num = 0; //�G�b�W����
	int all = 0; //�����̐�
	int hit = 0; //�Е����q�����Ă��Ȃ�Edge�̐�
	bool fs, fe; //�q�����Ă��邩�̃t���O

	//�܂��͑S�̂̏I�n�_���擾
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
			//���g�ȊO������
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
		{// hit�J�E���^��2�����Ȃ�ݒ�
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

		// 1�{�ȊO�œƗ�����edge�̏ꍇerror
		if (num && !fs && !fe)
		{
            printf("");;
		}
		num++;
		e.Orientation( TopAbs_FORWARD ); //�����𓝈ꂵ�Ă���
		wd1->Add(e);
	}

	//��������{�����̏ꍇ�͂��̂܂܃Z�b�g
	if( num == 1 )
	{
        printf("");;
	}
	
	//�C���_���Ȃ��ꍇ�͕��Ƃ��ēK���Ȉʒu����T��
	if( hit < 1 && num == all ) { wsp = sp; is = num; }

	//�ŏ���Edge���擾
	TopoDS_Edge se = wd1->Edge(is + 1); //!! OCC�̗v�f��1����J�E���g !!
	num = wd1->NbEdges() - 1;
	BRepAdaptor_Curve sc( se );
	sp = sc.Value(sc.FirstParameter());
	ep = sc.Value(sc.LastParameter());
	//FirstParameter�Ǝn�_�����]���Ă���t�ɂ���
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
	Handle( ShapeExtend_WireData ) wd2 = new ShapeExtend_WireData(); //�o�b�t�@2
	wd2->Add( se, 1 );
	bool r; //�G�b�W�̔��]�t���O
	bool h;
	hit = 0;
	//�A�����̂��鏇�ԂŊi�[���Ă���
	while ( num > 0 )
	{
		for ( int i=1; i <= wd1->NbEdges(); i++ )
		{
			r = false;
			h = false;
			TopoDS_Edge e = wd1->Edge( i );
			if ( !wd2->Index(e) )
			{ //���łɊi�[�����G�b�W�ȊO������
				c1.Initialize( e );
				sp2 = c1.Value(c1.FirstParameter());
				ep2 = c1.Value(c1.LastParameter());
				if ( ep.IsEqual( sp2, qTolerance ) ) { h = true; }
				else if ( ep.IsEqual( ep2, qTolerance ) )	{ h = true; r = true; }

				if (h) //��������
				{
					if (r)
					{ //���]����
						e.Orientation( TopAbs_REVERSED );
						gp_Pnt bak = sp2;
						sp2 = ep2;
						ep2 = bak;
					} 
					cout << sp.X() << "\t" << sp.Y() << "\t" << sp.Z() << endl;
					cout << ep.X() << "\t" << ep.Y() << "\t" << ep.Z() << "\t" << e.Orientation() << "\t" << r << endl;

					wd2->Add( e ); //�o�b�t�@�ɒǉ�
					sp = sp2;	//���Ɍ�������l�ɃZ�b�g
					ep = ep2;
					num--; //�ЂƂ��炷
					break; //for���𔲂���
				}
			}
		}
	hit++;
	if ( hit > 10 ) break; //�������[�v����
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