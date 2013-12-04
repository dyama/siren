/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

// コマンドを便利に実装するための共通関数群

#include "Stdafx.h"
#include "common.h"


/**
 * \brief 
 */
double ar2double(mrb_state* mrb, mrb_value ary)
{
	double res = 0.0;
	mrb_value val = mrb_ary_shift(mrb, ary);

	if (mrb_nil_p(val))
		res = 0.0;
	else if (mrb_float_p(val))
		res = val.value.f;
	else if (mrb_fixnum_p(val))
		res = mrb_fixnum(val);
	else
		throw "value is not numric value.";

	return res;
}

/**
 * \brief 
 */
gp_Pnt* ar2pnt(mrb_state* mrb, mrb_value& ary)
{
	double x = ar2double(mrb, ary);
	double y = ar2double(mrb, ary);
	double z = ar2double(mrb, ary);
	return new gp_Pnt(x, y, z);
}

/**
 * \brief 
 */
gp_Vec* ar2vec(mrb_state* mrb, mrb_value& ary)
{
	double x = ar2double(mrb, ary);
	double y = ar2double(mrb, ary);
	double z = ar2double(mrb, ary);
	return new gp_Vec(x, y, z);
}

/**
 * \brief 
 */
gp_Dir* ar2dir(mrb_state* mrb, mrb_value& ary)
{
	double x = ar2double(mrb, ary);
	double y = ar2double(mrb, ary);
	double z = ar2double(mrb, ary);
	return new gp_Dir(x, y, z);
}

/**
 * \brief 
 */
gp_Ax1* ar2ax1(mrb_state* mrb, mrb_value& pos, mrb_value& dir)
{
	gp_Pnt gpnt = *ar2pnt(mrb, pos);
	gp_Dir gdir = *ar2dir(mrb, dir);
	return new gp_Ax1(gpnt, gdir);
}

/**
 * \brief 
 */
gp_Ax2* ar2ax2(mrb_state* mrb, mrb_value& pos, mrb_value& dir)
{
	gp_Pnt gpnt = *ar2pnt(mrb, pos);
	gp_Dir gdir = *ar2dir(mrb, dir);
	return new gp_Ax2(gpnt, gdir);
}

/**
 * \brief 
 */
gp_Ax3* ar2ax3(mrb_state* mrb, mrb_value& pos, mrb_value& dir)
{
	gp_Pnt gpnt = *ar2pnt(mrb, pos);
	gp_Dir gdir = *ar2dir(mrb, dir);
	return new gp_Ax3(gpnt, gdir);
}

/**
 * \brief OCCのgp_Pntをmrubyの配列オブジェクトに変換する
 */
mrb_value pnt2ar(mrb_state* mrb, const gp_Pnt& rPnt)
{
	mrb_value res[3];
	res[0] = mrb_float_value(mrb, rPnt.X());
	res[1] = mrb_float_value(mrb, rPnt.Y());
	res[2] = mrb_float_value(mrb, rPnt.Z());
	return mrb_ary_new_from_values(mrb, 3, res);
}
