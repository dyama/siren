/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

using System;
using System.Collections.Generic;
using System.Text;

namespace siren
{
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
            switch (System.IO.Path.GetExtension(filename).ToLower())
            {
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
