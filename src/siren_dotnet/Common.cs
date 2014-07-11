/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;

namespace siren
{

  public delegate void evfuncMousePickedApply(List<Point3d> points);
  public delegate void evfuncMousePickedCancel();

  public enum ShapeType
  {
    COMPOUND,
    COMPSOLID,
    SOLID,
    SHELL,
    FACE,
    WIRE,
    EDGE,
    VERTEX,
    SHAPE
  };

  /// <summary>
  /// マウス ピッキング 構造体
  /// </summary>
  public class MousePicking
  {
    public evfuncMousePickedApply ApplyEvent = null;
    public evfuncMousePickedCancel CancelEvent = null;
    public int Count = 0;
    public List<Point3d> PickedPoints = null;

    public void init()
    {
      ApplyEvent = null;
      CancelEvent = null;
      Count = 0;
      PickedPoints = null;
    }
  }

  public class ObjectProperty
  {
    [ReadOnly(true)]
    [CategoryAttribute("シェイプ")]
    [DisplayName("タイプ")]
    public string ShapeType { set; get; }

    [ReadOnly(true)]
    [CategoryAttribute("シェイプ")]
    [DisplayName("シェイプID")]
    public int ID { set; get; }

    [ReadOnly(true)]
    [CategoryAttribute("ロケーション")]
    public double X { set; get; }
    [ReadOnly(true)]
    [CategoryAttribute("ロケーション")]
    public double Y { set; get; }
    [ReadOnly(true)]
    [CategoryAttribute("ロケーション")]
    public double Z { set; get; }

    [ReadOnly(true)]
    [CategoryAttribute("範囲(最小)")]
    public double SX { set; get; }
    [ReadOnly(true)]
    [CategoryAttribute("範囲(最小)")]
    public double SY { set; get; }
    [ReadOnly(true)]
    [CategoryAttribute("範囲(最小)")]
    public double SZ { set; get; }

    [ReadOnly(true)]
    [CategoryAttribute("範囲(最大)")]
    public double LX { set; get; }
    [ReadOnly(true)]
    [CategoryAttribute("範囲(最大)")]
    public double LY { set; get; }
    [ReadOnly(true)]
    [CategoryAttribute("範囲(最大)")]
    public double LZ { set; get; }

    public ObjectProperty(
        string type, int id,
        double x, double y, double z,
        double sx, double sy, double sz,
        double lx, double ly, double lz
        )
    {
      int n = 5; // 有効桁数
      ShapeType = type;
      ID = id;
      X = r(x, n); Y = r(y, n); Z = r(z, n);
      SX = r(sx, n); SY = r(sy, n); SZ = r(sz, n);
      LX = r(lx, n); LY = r(ly, n); LZ = r(lz, n);
    }

    private static double r(double v, int n)
    {
      double m = Math.Pow(10, n);
      if (v > 0) {
        return Math.Floor(v * m) / m;
      }
      else {
        return Math.Ceiling(v * m) / m;
      }
    }

  }

  /// <summary>
  /// 共通関数群
  /// </summary>
  public abstract class Common
  {
    /// <summary>
    /// ファイル名から適切なファイルフォーマットを推測する
    /// </summary>
    /// <param name="filename"></param>
    /// <returns></returns>
    public static ModelFormat getFormatByExt(string filename)
    {
      ModelFormat theformat = ModelFormat.UNKNOWN;
      switch (System.IO.Path.GetExtension(filename).ToLower()) {
      case ".brep":
      case ".brp":
      case ".rle":
        theformat = ModelFormat.BREP;
        break;
      case ".csfdb":
        theformat = ModelFormat.CSFDB;
        break;
      case ".step":
      case ".stp":
        theformat = ModelFormat.STEP;
        break;
      case ".iges":
      case ".igs":
        theformat = ModelFormat.IGES;
        break;
      case ".stl":
        theformat = ModelFormat.STL;
        break;
      case ".vrml":
        theformat = ModelFormat.VRML;
        break;
      case ".bmp":
      case ".gif":
      case ".xwd":
        theformat = ModelFormat.IMAGE;
        break;
      default:
        break;
      }
      return theformat;
    }

  }
}
